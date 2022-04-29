#include "tree.h"
#include <utility>
#include <vector>

Tree::Tree()
{
   _root = nullptr;
}

Tree::Tree(std::pair<int,int> coords)
{
   Node* new_node = new Node{coords};
   _root = new_node;
}

Tree::Tree(Tree other)
{
   _root = other.get_root();
}

std::pair<int,int> Tree::get_root_coord()
{
   return _root->_coordinates;
}
