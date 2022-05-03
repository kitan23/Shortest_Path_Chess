// Header file for declaration of class Tree

#ifndef TREE_H
#define TREE_H

#include <vector> // for children
#include <utility> // for coordinates
#include "node.h"

class Tree
{
public:
   Tree(Node* new_node);
   void add_child(Node*& current, Node*& child);
private:
   Node* _root;
};

#endif
