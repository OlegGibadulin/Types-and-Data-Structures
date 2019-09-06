CC := gcc

OBJ := array_actions.o list_actions.o f_in.o

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
