CC := gcc

OBJ := func_in.o bst.o avl.o ht.o

CFLAGS := -std=c99 -Wall -pedantic -ggdb

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

main.exe: $(OBJ) main.o
	$(CC) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) *.o *.exe *.config *.creator *.creator.user *.files *.includes
