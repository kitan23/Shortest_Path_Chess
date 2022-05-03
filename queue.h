// Header file for declaration of class Queue

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
private:
   Node* _head;
   Node* _tail;
   size_t _size;
};

#endif
