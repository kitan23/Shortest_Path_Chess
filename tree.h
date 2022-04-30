#ifndef TREE_H
#define TREE_H

#include <vector> // for children
#include <utility> // for coordinates

class Tree
{
public:
   Tree();
   Tree(std::pair<int,int> coords);
   std::pair<int,int>get_root_coord();
private:
   struct Node
   {
       std::pair <int, int> _coordinates;
       std::vector<Node> children;
       Node* parent;
   };
   Node* _root;
};

#endif
