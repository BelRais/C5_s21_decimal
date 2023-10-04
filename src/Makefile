CC+FLAGS = gcc -std=c11 -Wall -Wextra -Werror
GCOV_FLAGS = -L. --coverage -ls21_decimal

OS = $(shell uname)

ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -lm -pthread -lrt -lsubunit
	OPEN_CMD = xdg-open
	MEM_CHECK = valgrind --tool=memcheck --trace-children=yes --track-origins=yes --leak-check=full
else
	CHECK_FLAGS = -lcheck
	OPEN_CMD = open
	MEM_CHECK = leaks --atExit -- ./s21_test
endif

all: clean test gcov_report

test: s21_decimal.a
	$(CC+FLAGS) for_test/check*.c s21_decimal.a main.c $(CHECK_FLAGS) -L. -ls21_decimal -o s21_test
	./s21_test

gcov_report:
	gcc --coverage $(CHECK_FLAGS) for_test/check*.c main.c s21*.c -o ./gcov
	./gcov
	lcov -t "./gcov" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html
	rm -rf *.gcno *gcda *.gcov

s21_decimal.a: s21_decimal.o
	ar rcs libs21_decimal.a *.o
	rm -rf *.o
	ranlib libs21_decimal.a
	cp libs21_decimal.a s21_decimal.a
	cp libs21_decimal.a ls21_decimal.a

s21_decimal.o:
	$(CC+FLAGS) -c s21_*.c

check:
	make test
	CK_FORK=no $(MEM_CHECK) ./s21_test
	make clean

style:
	clang-format -i *.c *.h

check_style:
	cp ../materials/linters/.clang-format ./ 
	clang-format -n *.c *.h
	
clean:
	rm -rf *.o *.a *.gcda *.gcno *.info s21_test

clean_report:
	rm -rf report
