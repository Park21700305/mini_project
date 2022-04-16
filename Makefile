#21700305_박지성

CC = gcc
CFLAGS = -W -Wall
TARGET = manager
DTARGET = manager_debug
OBJECTS = main.c manager.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^ 
clean:
	rm *.o manager manager_debug
