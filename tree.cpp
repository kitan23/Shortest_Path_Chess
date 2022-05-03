#include "tree.h"
#include <utility>
#include <vector>
#include<iostream>

Tree::Tree()
{
   _root = nullptr;
}

Tree::Tree(Node* new_node)
{
   _root = new_node;
}

std::pair<int,int> Tree::get_root_coord()
{
   return _root-> coords;
}

void Tree::add_child(Node*& current, Node*& child)
{
   current->children.push_back(child); 
}

void Tree::print() const 
{
   Node* current = _root; 
   std::cout << current->coords.first << " " << current->coords.second << std::endl; 
   for (size_t i = 0; i < _root->children.size(); ++i)
   {
      current = _root->children[i]; 
      std::cout << current->coords.first << " " << current->coords.second << std::endl; 
   }
}
