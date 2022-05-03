// File for implementation of functions defined in class declaration of Tree

#include "tree.h"
#include <utility> // for coordinates
#include <vector> // for children

/**
 * Constructor method that is called when an object of this class is created and a new node is passed as an argument,
 * initializing root of the Tree
 * @param new_node: a new node to be added to the Tree data structure
 */
Tree::Tree(Node* new_node)
{
   _root = new_node;
}

/**
 * Adds a node to the tree as the child of current node
 * @param current: the node which will be the parent of the node being added
 * @param child: the node that will be added to the tree
 */
void Tree::add_child(Node*& current, Node*& child)
{
   current->children.push_back(child);
}
