CC=gcc
CFLAGS=-Wall -std=c11 -g -O0

unit_test: snode.c snode.h slist.h slist.c unit_test.c 
	$(CC) $(CFLAGS) snode.c slist.c unit_test.c -o unit_test

clean:
	rm -f *.o snode_test song_list unit_test
