#include "test_utils.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// Use temp files under project_1/tests to avoid permission issues
static int write_all(int fd, const char* buf, size_t len) {
    size_t off = 0;
    while (off < len) {
        ssize_t w = write(fd, buf + off, len - off);
        if (w <= 0) return -1;
        off += (size_t)w;
    }
    return 0;
}

int capture_io_run(void (*fn)(void), const char* input, char* outbuf, size_t outcap) {
    if (\!outbuf || outcap == 0) return -1;

    char in_tmpl[]  = "project_1/tests/.inXXXXXX";
    char out_tmpl[] = "project_1/tests/.outXXXXXX";

    int in_fd  = mkstemp(in_tmpl);
    int out_fd = mkstemp(out_tmpl);
    if (in_fd < 0 || out_fd < 0) return -1;

    if (input && *input) {
        if (write_all(in_fd, input, strlen(input)) \!= 0) { close(in_fd); close(out_fd); return -1; }
        lseek(in_fd, 0, SEEK_SET);
    }

    int saved_stdin  = dup(fileno(stdin));
    int saved_stdout = dup(fileno(stdout));

    // Redirect stdin/stdout using freopen for stdio compatibility
    FILE* fin  = freopen(in_tmpl, "r", stdin);
    FILE* fout = freopen(out_tmpl, "w", stdout);
    (void)fin; (void)fout;

    // Execute function
    fn();

    fflush(stdout);

    // Restore stdio
    if (saved_stdout >= 0) { dup2(saved_stdout, fileno(stdout)); close(saved_stdout); }
    if (saved_stdin  >= 0) { dup2(saved_stdin,  fileno(stdin));  close(saved_stdin);  }

    // Read captured output
    FILE* rf = fopen(out_tmpl, "r");
    size_t n = 0;
    if (rf) {
        n = fread(outbuf, 1, outcap - 1, rf);
        outbuf[n] = '\0';
        fclose(rf);
    } else {
        outbuf[0] = '\0';
    }

    // Cleanup
    close(in_fd);
    close(out_fd);
    unlink(in_tmpl);
    unlink(out_tmpl);

    return (int)n;
}