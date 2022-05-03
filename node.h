// Header file for declaration of struct Node

#ifndef NODE_H
#define NODE_H

struct Node
{
   std::pair <int, int> coords;
   std::vector<Node*> children;
   Node* parent;
   Node* next;
};

#endif
