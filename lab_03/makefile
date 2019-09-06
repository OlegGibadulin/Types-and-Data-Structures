CC := gcc

CFLAGS := -std=c99 -Wall -pedantic -ggdb

OBJ := f_in.o f_add.o f_effectiveness.o f_generate.o f_multiplication.o f_show.o

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

main.exe: $(OBJ) main.o
	$(CC) $^ -o $@

test.exe: $(OBJ) test.o
	$(CC) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) *.o *.exe *.config *.creator *.creator.user *.files *.includes
