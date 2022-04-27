#ifndef TREE_H
#define TREE_H

#include <vector> // for children
#include <utility> // for coordinates

class Tree()
{
public:
   Tree();
   Tree(Node* root);
   Tree(Tree other);
   get_root();
private:
   struct Node
   {
       std::pair <int, int> _coordinates;
       std::vector<Node> children;
   }
   Node* _root;
};

#endif
