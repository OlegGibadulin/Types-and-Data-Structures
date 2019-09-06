CC := gcc$

CFLAGS := -std=c99 -Wall -Werror -pedantic

OBJ := f_in.o f_add.o f_load.o f_table.o f_show.o f_save.c f_remove.o f_search.o f_key.o f_sort.o

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

main.exe : $(OBJ) main.o
	$(CC) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) *.o *.exe*.config *.creator *.creator.user *.files *.includes
