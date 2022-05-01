#ifndef TREE_H
#define TREE_H

#include <vector> // for children
#include <utility> // for coordinates
#include "node.h"

class Tree
{
public:
   Tree();
   Tree(std::pair<int,int> coords);
   std::pair<int,int>get_root_coord();
private:
   Node* _root;
};

#endif
