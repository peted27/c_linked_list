TARGET = libcadt.a
OBJS = sl_list.o
DEPS = sl_list.h

CC = gcc
DEBUG = -DDEBUG -g
CFLAGS = -ansi -pedantic -Wall
LFLAGS = -Wall

AR = ar
RANLIB = ranlib

$(TARGET): $(OBJS)
	rm -f $@
	$(AR) rcu $@ $(OBJS)
	$(RANLIB) $@

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

demo: $(OBJS) $(TARGET)
	$(CC) -c -o $@.o $@.c $(CFLAGS)
	$(CC) -o $@ $@.o $(TARGET)

debug: CFLAGS += $(DEBUG)
debug: LFLAGS += $(DEBUG)
debug: $(TARGET)

.PHONY: indent
indent:
	-astyle --style=bsd --align-pointer=name --max-code-length=75 \
	--max-instatement-indent=60 *.c *.h
	-rm -f *.orig

.PHONY: doc
doc:
	-doxygen

.PHONY: clean
clean:
	-rm *.o
	-rm $(TARGET)
	-rm demo
