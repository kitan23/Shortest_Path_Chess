#ifndef QUEUE_H
#define QUEUE_H

#include <vector> // for children
#include <utility> // for coordinates
#include "node.h"

class Queue
{
public:
   Queue();
   void enqueue(Node* item);
   Node* dequeue();
   bool empty() const;
   void print() const; 
private:
   Node* _head;
   Node* _tail;
   size_t _size;
};

#endif
