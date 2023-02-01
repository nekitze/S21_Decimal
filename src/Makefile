CC = gcc
CFLAGS = -Wall -Werror -Wextra
LD_S21_DECIMAL_FLAGS = -L. -ls21_decimal -lm

SOURCES = $(wildcard ./functions/*)
OBJECTS = $(patsubst ./functions/%.c, %.o, $(SOURCES))


all: 
	$(CC) $(CFLAGS) *.c *.h ./functions/*.c -o test -lm

mytest: mytest.c s21_decimal.a
	$(CC) $< $(LD_S21_DECIMAL_FLAGS) -o $@

s21_decimal.a: $(OBJECTS)
	ar rc $@ $^
	ranlib $@
	cp s21_decimal.a libs21_decimal.a

%.o: functions/%.c
	$(CC) -c $^ -o $@

clean:
	rm -rf *.o *.a test *.gcda *.gcno html_report report.info mytest
