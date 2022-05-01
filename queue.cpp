#include "queue.h"
#include <vector> // for children
#include <utility> // for coordinates
#include <iostream>

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
Node* Queue::dequeue()
{
   Node* next_ptr = nullptr;
   if (!empty())
   {
      Node* dequeued = _head;
      next_ptr = _head->next;
      _head = next_ptr;
      _size--;
      return dequeued;
   }
   
   return nullptr;
}

bool Queue::empty() const
{
   if (_head == nullptr)
   {
      return true;
   }
   return false;
}

void Queue::print() const 
{
   if (_head == nullptr)
   {
      std::cout << "The queue is empty" << std::endl; 
   }
   else 
   {
      Node* cur = _head; 
      while (cur != _tail)
      {
         std::cout << cur->coords.first << " " << cur->coords.second << std::endl; 
         cur = cur->next; 
      }
      std::cout << cur->coords.first << " " << cur->coords.second << std::endl; 
   }
}
