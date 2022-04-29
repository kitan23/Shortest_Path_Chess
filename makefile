CFLAGS=-Wall -Werror -Wfatal-errors 

knight: knight.o tree.o queue.o
	g++ -o knight knight.o tree.o queue.o 

knight.o: knight.cc queue.cc tree.cc
	g++ -c $(CFLAGS) knight.cc

queue.o: queue.cc queue.h
	g++ -c $(CFLAGS) queue.cc

tree.o: tree.cc tree.h 
	g++ -c $(CFLAGS) tree.cc

clean:
	rm -rf *.o knight 