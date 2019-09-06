CC := gcc$

CFLAGS := -std=c99 -Wall -Werror -pedantic

OBJ := f_in1.o f_in2.o f_count.o f_out.o

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
	$(RM) *.o *.exe *.config *.creator *.creator.user *.files *.includes
