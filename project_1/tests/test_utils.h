#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stddef.h>

// Captures stdout while providing 'input' to stdin, runs 'fn', and writes
// captured output into outbuf (null-terminated). Returns number of bytes written.
int capture_io_run(void (*fn)(void), const char* input, char* outbuf, size_t outcap);

#endif