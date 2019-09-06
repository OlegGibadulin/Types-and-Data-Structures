CC := gcc

CFLAGS := -std=gnu99 -Wall -pedantic -ggdb

OBJ := f_in.o f_actions_array.o f_actions_list.o f_allocation.o f_free.o

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
