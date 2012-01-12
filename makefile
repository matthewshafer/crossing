CC = gcc
CFLAGS = -g -O2 -lcurl
OBJECTS = crossingcli.o crossing.o

cross : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o cross

crossingcli.o : crossingcli.c
	$(CC) $(CFLAGS) -c crossingcli.c

crossing.o : lib/crossing.c
	$(CC) $(CFLAGS) -c lib/crossing.c
