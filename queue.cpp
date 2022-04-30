#include "queue.h"
#include <vector> // for children
#include <utility> // for coordinates

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
void Queue::enqueue(const std::pair<int, int> item)
{
   Node* new_node = new Node{item, {}, nullptr}; // making node using coordinates
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
std::pair<int, int> Queue::dequeue()
{
   Node* next_ptr = nullptr;
   if (!empty())
   {
      std::pair<int,int> dequeued = _head->coords;
      next_ptr = _head->next;
      delete _head; // deletes previous _head from memory
      _head = next_ptr;
      _size--;
      return dequeued;
   }
   std::pair<int,int> invalid = std::make_pair(-1,-1);
   return invalid;
}

bool Queue::empty() const
{
   if (_head == nullptr)
   {
      return true;
   }
   return false;
}
