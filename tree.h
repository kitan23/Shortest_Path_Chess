#ifndef TREE_H
#define TREE_H

#include <vector> // for children
#include <utility> // for coordinates
#include "node.h"

class Tree
{
public:
   Tree();
   Tree(Node* new_node);
   std::pair<int,int>get_root_coord();
   void add_child(Node*& current, Node*& child); 
   void print() const; 
private:
   Node* _root;
};

#endif
