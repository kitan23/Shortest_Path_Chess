#ifndef TREE_H
#define TREE_H

#include <vector> // for children
#include <utility> // for coordinates

class Tree
{
public:
   Tree();
   Tree(std::pair<int,int> coordinates);
   Tree(Tree &other);
   std::pair<int,int>get_root();
private:
   struct Node
   {
       std::pair <int, int> _coordinates;
       std::vector<Node> children;
       Node* parent; 
       Node(std::pair<int,int> coords)
       {
          _coordinates = coords, 
          parent = nullptr; 
       }
   };
   Node* _root;
};

#endif
