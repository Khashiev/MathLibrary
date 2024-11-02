ABS_FUNK+=s21_abs
ABS_FUNK+=s21_fabs
POW_FUNK+=s21_exp
POW_FUNK+=s21_log
POW_FUNK+=s21_pow
POW_FUNK+=s21_sqrt
ROUND_FUNK+=s21_floor
ROUND_FUNK+=s21_fmod
ROUND_FUNK+=s21_ceil
TRIG_FUNK+=s21_sin
TRIG_FUNK+=s21_cos
TRIG_FUNK+=s21_tan
B_TRIG_FUNK+=s21_acos
B_TRIG_FUNK+=s21_asin
B_TRIG_FUNK+=s21_atan

#################  DO NOT CHANGE BELOW  #################
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
#GCOVFLAG = -fprofile-arcs -ftest-coverage
LFLAGS =
BUILD_DIR = build/
UNIT_TESTS_DIR = unit_tests/
ABS_DIR = abs/
BACK_TRIG_DIR = back-trig/
POW_DIR = pow-log-sqrt/
ROUND_DIR = rounding/
TRIG_DIR = trig/
TARGETS+=$(addprefix $(ABS_DIR), $(ABS_FUNK))
TARGETS+=$(addprefix $(BACK_TRIG_DIR), $(B_TRIG_FUNK))
TARGETS+=$(addprefix $(POW_DIR), $(POW_FUNK))
TARGETS+=$(addprefix $(ROUND_DIR), $(ROUND_FUNK))
TARGETS+=$(addprefix $(TRIG_DIR), $(TRIG_FUNK))
TARGETS_OBJ=$(addsuffix .o, $(TARGETS))
TEST_OBJ=$(addprefix $(UNIT_TESTS_DIR), $(addsuffix _test.o, $(TARGETS)))


all: s21_math.a

s21_math.a: $(TARGETS_OBJ)
	ar rc $@ $(addprefix $(BUILD_DIR), $(TARGETS_OBJ))
	ranlib $@

test: s21_math.a $(TEST_OBJ)
	$(CC) $(LFLAGS) $(CFLAGS) $(addprefix $(BUILD_DIR), $(TEST_OBJ)) $(UNIT_TESTS_DIR)s21_math_tests_runner.c $(UNIT_TESTS_DIR)common_test.c  -o s21_math_test.out s21_math.a `pkg-config --cflags --libs check` -lm

gcov_report: CFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: LFLAGS += -fprofile-arcs
gcov_report: test
	CK_FORK=no ./s21_math_test.out
	lcov -t "report"  -o report.info -c -d .
	genhtml -o "html_report" report.info
	open html_report/index.html

style:
	clang-format -style=Google -i $(addsuffix .c, $(TARGETS)) $(addprefix $(UNIT_TESTS_DIR), $(addsuffix .c, $(TARGETS)))

style_check:
	clang-format -style=Google -n $(addsuffix .c, $(TARGETS)) $(addprefix $(UNIT_TESTS_DIR), $(addsuffix .c, $(TARGETS)))
	clang-format -i *.h $(addsuffix .c, $(TARGETS)) $(addprefix $(UNIT_TESTS_DIR), $(addsuffix .c, $(TARGETS))) $(UNIT_TESTS_DIR)s21_math_tests_runner.c $(UNIT_TESTS_DIR)common_test.c $(UNIT_TESTS_DIR)common_test.h

style_check:
	clang-format -n *.h $(addsuffix .c, $(TARGETS)) $(addprefix $(UNIT_TESTS_DIR), $(addsuffix .c, $(TARGETS))) $(UNIT_TESTS_DIR)s21_math_tests_runner.c $(UNIT_TESTS_DIR)common_test.c $(UNIT_TESTS_DIR)common_test.h
	clang-format -style=Google -n $(addsuffix .c, $(TARGETS)) $(addprefix $(UNIT_TESTS_DIR), $(addsuffix .c, $(TARGETS)))

%.o: %.c
	mkdir -p $(BUILD_DIR)$(@D)
	$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$@

clean:
	-rm -rf $(BUILD_DIR)
	-rm s21_math.a
	-rm s21_math_test.out
	-rm -rf html_report
	-rm report.info
	-rm *.gcda
	-rm *.gcno
