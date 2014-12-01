TARGET = demo
OBJS = demo.o
DEPS = sl_list.h

CC = gcc
DEBUG = -DDEBUG -g
CFLAGS = -ansi -pedantic -Wall
LFLAGS = -Wall

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $@.o

debug: CFLAGS += $(DEBUG)
debug: LFLAGS += $(DEBUG)
debug: $(TARGET)

.PHONY: indent
indent:
	-indent \
	-nbad -nbap -bbo -bc -br -brs -c33 -cd33 -cdb -ce -ci4 -cli0 \
	-cp33 -di16 -fc1 -fca -hnl -i8 -ip8 -l75 -lp -npcs -nprs -psl \
	-saf -sai -saw -sc -nsob -nss -ts8 \
	demo.c sl_list.c sl_list.h

.PHONY: doc
doc:
	-doxygen

.PHONY: clean
clean:
	-rm *.o
	-rm $(TARGET)
	-rm demo
	-rm *~
