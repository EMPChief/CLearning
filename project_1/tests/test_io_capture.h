#ifndef TEST_IO_CAPTURE_H
#define TEST_IO_CAPTURE_H

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Minimal helpers for redirecting stdin/stdout to controlled buffers so we can
 * exercise interactive functions deterministically in unit tests.
 *
 * Usage:
 *   io_begin("input\nlines\n");
 *   function_under_test();
 *   char *out = io_end_and_read();  // caller must free(out)
 */

typedef struct {
  int saved_stdin_fd;
  int saved_stdout_fd;
  int in_fd;
  int out_fd;
  char in_path[64];
  char out_path[64];
  FILE *in_fp;
  FILE *out_fp;
} io_ctx;

static io_ctx IO_CTX;

static void io_begin(const char *input_buf) {
  IO_CTX.saved_stdin_fd = dup(fileno(stdin));
  IO_CTX.saved_stdout_fd = dup(fileno(stdout));
  if (IO_CTX.saved_stdin_fd == -1 || IO_CTX.saved_stdout_fd == -1) {
    perror("dup");
    exit(EXIT_FAILURE);
  }

  strcpy(IO_CTX.in_path, "/tmp/inXXXXXX");
  IO_CTX.in_fd = mkstemp(IO_CTX.in_path);
  if (IO_CTX.in_fd == -1) {
    perror("mkstemp(in)");
    exit(EXIT_FAILURE);
  }
  if (input_buf && *input_buf) {
    ssize_t written = write(IO_CTX.in_fd, input_buf, (size_t)strlen(input_buf));
    (void)written;
  }
  if (lseek(IO_CTX.in_fd, 0, SEEK_SET) == -1) {
    perror("lseek(in)");
    exit(EXIT_FAILURE);
  }

  strcpy(IO_CTX.out_path, "/tmp/outXXXXXX");
  IO_CTX.out_fd = mkstemp(IO_CTX.out_path);
  if (IO_CTX.out_fd == -1) {
    perror("mkstemp(out)");
    exit(EXIT_FAILURE);
  }

  if (dup2(IO_CTX.in_fd, fileno(stdin)) == -1) {
    perror("dup2(stdin)");
    exit(EXIT_FAILURE);
  }
  if (dup2(IO_CTX.out_fd, fileno(stdout)) == -1) {
    perror("dup2(stdout)");
    exit(EXIT_FAILURE);
  }

  IO_CTX.in_fp = fdopen(IO_CTX.in_fd, "r+");
  IO_CTX.out_fp = fdopen(IO_CTX.out_fd, "r+");
  if (\!IO_CTX.in_fp || \!IO_CTX.out_fp) {
    perror("fdopen");
    exit(EXIT_FAILURE);
  }
}

static char *io_end_and_read(void) {
  fflush(stdout);

  if (dup2(IO_CTX.saved_stdin_fd, fileno(stdin)) == -1) {
    perror("restore stdin");
    exit(EXIT_FAILURE);
  }
  if (dup2(IO_CTX.saved_stdout_fd, fileno(stdout)) == -1) {
    perror("restore stdout");
    exit(EXIT_FAILURE);
  }

  fflush(IO_CTX.out_fp);
  if (fseek(IO_CTX.out_fp, 0, SEEK_END) \!= 0) {
    perror("fseek(end)");
    exit(EXIT_FAILURE);
  }
  long size = ftell(IO_CTX.out_fp);
  if (size < 0) {
    perror("ftell");
    exit(EXIT_FAILURE);
  }
  if (fseek(IO_CTX.out_fp, 0, SEEK_SET) \!= 0) {
    perror("fseek(start)");
    exit(EXIT_FAILURE);
  }

  char *buffer = (char *)malloc((size_t)size + 1);
  if (\!buffer) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  size_t read_bytes = fread(buffer, 1, (size_t)size, IO_CTX.out_fp);
  buffer[read_bytes] = '\0';

  fclose(IO_CTX.in_fp);
  fclose(IO_CTX.out_fp);
  close(IO_CTX.saved_stdin_fd);
  close(IO_CTX.saved_stdout_fd);

  unlink(IO_CTX.in_path);
  unlink(IO_CTX.out_path);

  return buffer;
}

#endif // TEST_IO_CAPTURE_H