CC    = g++
CFLAGS  =
TARGET1 = p0.cpp
TARGET2 = tree.cpp
OBJS1     = p0.o tree.o
OBJS2     =
LIBOBJS =
LIBS =
MYLIBS =

.SUFFIXES: .c .o

all: $(TARGET1) $(TARGET2)

p0: $(OBJS1)
$(CC) $(CFLAGS) $(OBJS1) -o $@


.c.o:
$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
/bin/rm -f *.o *~ $(TARGET1) $(TARGET2)
