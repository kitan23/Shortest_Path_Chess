#ifndef QUEUE_H
#define QUEUE_H

#include <vector> // for children
#include <utility> // for coordinates
#include "node.h"

class Queue
{
public:
   Queue();
   void enqueue(const std::pair<int, int> item);
   std::pair<int,int> dequeue();
   bool empty() const;
private:
   Node* _head;
   Node* _tail;
   size_t _size;
};

#endif
