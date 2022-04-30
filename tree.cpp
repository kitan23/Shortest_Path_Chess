#include "tree.h"
#include <utility>
#include <vector>

Tree::Tree()
{
   _root = nullptr;
}

Tree::Tree(std::pair<int,int> coords)
{
   _root = new Node{coords, {}, nullptr};
}

std::pair<int,int> Tree::get_root_coord()
{
   return _root->_coordinates;
}
