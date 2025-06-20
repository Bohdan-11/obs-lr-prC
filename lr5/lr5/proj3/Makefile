CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -O2 $(shell pkg-config --cflags libcurl)
LDFLAGS :=
LDLIBS := $(shell pkg-config --libs libcurl)
TARGET := htmlparser
SRC := main.c htmlutils.c

all: $(TARGET)

$(TARGET): $(SRC:.c=.o)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -DUSE_CURL -c $< -o $@
	
clean:
	$(RM) *.o $(TARGET)