#include "tree.h"
#include <utility>
#include <vector>

Tree::Tree()
{
   _root = nullptr;
}

Tree::Tree(Node* root)
{
   _root == root;
}

Tree::Tree(Tree other)
{
   _root = other.get_root();
}

Tree::get_root()
{
   return _root;
}
