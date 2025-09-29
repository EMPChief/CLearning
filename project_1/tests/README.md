Testing library/framework used: None detected in repository; leveraging a custom lightweight assert-based harness.

How to run:
  make -C project_1 test

Details:
- Tests focus on interactive routines defined in project_1/test_calculations.c.
- stdin/stdout are captured with POSIX dup2/mkstemp to validate prompts and formatted outputs.
- No external dependencies introduced; compilation uses the existing gcc + CFLAGS configuration.