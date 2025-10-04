#include "unity.h"
#include <stdio.h>
#include <setjmp.h>

int Unity_tests_run = 0;
int Unity_tests_failed = 0;
jmp_buf Unity_RestoreEnv;

void UnityBegin(const char* filename) {
    (void)filename;
    Unity_tests_run = 0;
    Unity_tests_failed = 0;
    printf("Unity test run begins\n");
    printf("---------------------------------------------------\n");
}

void UnityEnd(void) {
    printf("---------------------------------------------------\n");
    printf("%d Tests %d Failures %d Ignored\n", Unity_tests_run, Unity_tests_failed, 0);
    printf(Unity_tests_failed ? "FAIL\n" : "OK\n");
}

void UnityRunTest(void (*test_func)(void), const char* test_name, int line_number) {
    (void)line_number;
    printf("TEST(%s)", test_name);
    Unity_tests_run++;
    if (setjmp(Unity_RestoreEnv) == 0) {
        test_func();
        printf(" PASS\n");
    } else {
        Unity_tests_failed++;
        printf(" FAIL\n");
    }
}

void UnityAssert(int condition, int line, const char* file, const char* message) {
    if (!condition) {
        printf("\nFAIL: %s:%d: %s\n", file, line, message);
        longjmp(Unity_RestoreEnv, 1);
    }
}