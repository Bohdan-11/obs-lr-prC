CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -O2 -D_WIN32
LDFLAGS :=
LDLIBS := -lws2_32

TARGETS := server.exe client.exe
OBJS_server := server.o net_utils.o
OBJS_client := client.o net_utils.o

all: $(TARGETS)

server.exe: $(OBJS_server)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

client.exe: $(OBJS_client)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.exe