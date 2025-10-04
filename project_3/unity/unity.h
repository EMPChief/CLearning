#ifndef UNITY_FRAMEWORK_H
#define UNITY_FRAMEWORK_H

#include <stdio.h>
#include <setjmp.h>

extern int Unity_tests_run;
extern int Unity_tests_failed;
extern jmp_buf Unity_RestoreEnv;

void UnityBegin(const char* filename);
void UnityEnd(void);
void UnityRunTest(void (*test_func)(void), const char* test_name, int line_number);
void UnityAssert(int condition, int line, const char* file, const char* message);

#define TEST_ASSERT(cond) UnityAssert((cond), __LINE__, __FILE__, "Assertion failed: " #cond)
#define RUN_TEST(test_func) UnityRunTest(test_func, #test_func, __LINE__)

#endif