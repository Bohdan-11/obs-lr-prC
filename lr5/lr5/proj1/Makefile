CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -O2 # флаги компиляции
LDFLAGS :=
LDLIBS := -lm # связываем с math lib, если нужны математические функции
# Список исходников и целевой исполняемый файл
SRC := main.c data.c
OBJ := $(SRC:.c=.o)
TARGET := proj1
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LDLIBS)
# Правило для создания .o из .c (можно опустить, GNU Make имеет неявное правило)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ) $(TARGET)