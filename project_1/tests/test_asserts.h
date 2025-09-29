#ifndef TEST_ASSERTS_H
#define TEST_ASSERTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int tests_run = 0;
static int tests_failed = 0;

static void report_result(const char *name, int passed) {
  tests_run++;
  if (passed) {
    fprintf(stderr, "[ OK ] %s\n", name);
  } else {
    tests_failed++;
    fprintf(stderr, "[FAIL] %s\n", name);
  }
}

#define ASSERT_TRUE(cond) do { if (\!(cond)) return __LINE__; } while (0)
#define ASSERT_STREQ(a, b) do { if (strcmp((a), (b)) \!= 0) return __LINE__; } while (0)
#define ASSERT_CONTAINS(haystack, needle) \
  do { if (strstr((haystack), (needle)) == NULL) return __LINE__; } while (0)

#define RUN_TEST(fn)                                        \
  do {                                                      \
    int _line = fn();                                       \
    if (_line == 0) {                                       \
      report_result(#fn, 1);                                \
    } else {                                                \
      fprintf(stderr, "  at %s:%d\n", __FILE__, _line);     \
      report_result(#fn, 0);                                \
    }                                                       \
  } while (0)

#define TEST_SUMMARY()                                      \
  do {                                                      \
    fprintf(stderr, "\nTests run: %d, Failures: %d\n",      \
            tests_run, tests_failed);                       \
    return tests_failed ? EXIT_FAILURE : EXIT_SUCCESS;      \
  } while (0)

#endif // TEST_ASSERTS_H