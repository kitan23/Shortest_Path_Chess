CFLAGS=-Wall -Werror -Wfatal-errors -std=c++17

knight: knight.o tree.o queue.o
	g++ -o knight knight.o tree.o queue.o

knight.o: knight.cpp queue.h tree.h
	g++ -c $(CFLAGS) knight.cpp

queue.o: queue.cpp queue.h
	g++ -c $(CFLAGS) queue.cpp

tree.o: tree.cpp tree.h
	g++ -c $(CFLAGS) tree.cpp

clean:
	rm -rf *.o knight
