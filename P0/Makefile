CC    = g++
CFLAGS  =
TARGET1 = P0
TARGET2 = tree
OBJS1     = p0.o tree.o
OBJS2     =
LIBOBJS =
LIBS =
MYLIBS =

.SUFFIXES: .c .o

all: $(TARGET1) $(TARGET2)

P0: $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o $@


.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	/bin/rm -f *.o *~ *.inorder *.preorder *.postorder  $(TARGET1) $(TARGET2)
