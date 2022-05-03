// File for implementation of functions defined in class declaration of Queue

#include "queue.h"
#include <vector> // for children
#include <utility> // for coordinates

/**
 * No-argument constructor method that is automatically called when an object of this class is created,
 * initializing attributes of the object
 */
Queue::Queue()
{
   _head = nullptr;
   _tail = nullptr;
   _size = 0;
}

/**
 * Enqueues an item i.e. adds it to the back of the queue
 * @param item: the data item that is going to be added to the queue
 */
void Queue::enqueue(Node* new_node)
{
   if (empty())
   {
      _head = new_node;
   }
   else
   {
      _tail->next = new_node;
   }
   _tail = new_node;
   _size++;
}

/**
 * Dequeues an item i.e. removes it from the front of the queue
 * @return the data in the dequeued element if the queue is not empty
 */
Node* Queue::dequeue()
{
   if (!empty())
   {
      Node* dequeued = _head;
      _head = _head->next;
      _size--;
      return dequeued;
   }
   return nullptr;
}

/**
 * Checks whether queue is empty or not
 * @return whether _head is nullptr i.e. if there are no
 * nodes in the queue
 */
bool Queue::empty() const
{
   if (_head == nullptr)
   {
      return true;
   }
   return false;
}
