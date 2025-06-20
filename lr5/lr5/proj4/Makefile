CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -O2
LDLIBS := -lm # на случай, если понадобятся математические функции
TARGET := linmath
SRC := main.c linalg.c

all: $(TARGET)

$(TARGET): $(SRC:.c=.o)
	$(CC) $^ -o $@ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) *.o $(TARGET)