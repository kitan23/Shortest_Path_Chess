#ifndef TREE_H
#define TREE_H

#include <vector> // for children
#include <utility> // for coordinates

class Queue
{
public:
   Queue(); 
   void enqueue(); 
   void dequeue()
private:
   struct Node
   {
      std::pair <int, int> _coordinates;
      std::vector<Node> children;
      Node* parent; 
   }
   Node* _root;
};

#endif
