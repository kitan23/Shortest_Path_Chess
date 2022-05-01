#include <utility>
#include <vector>
#include <iostream>
#include "tree.h"
#include "queue.h"


int main()
{
   //PSEUDOCODE FOR ALGORITHM
   // look for destination node while initializing tree of possible moves

   //Initialize origin with user input as std::pair
   std::cout << "Please enter a starting x coordinate on a 4x4 board: ";
   int x;
   std::cin >> x;
   std::cout << "Please enter a starting y coordinate on a 4x4 board: ";
   int y;
   std::cin >> y;
   // int x = 0; 
   // int y = 0; 
   std::pair<int,int> origin = std::make_pair(x,y);

   //Initialize tree with root having origin
   Tree tr(origin);
   // Test to see if this works
   std::cout << tr.get_root_coord().first << " " << tr.get_root_coord().second << std::endl;

   //Initialize queue
   Queue q;
   //Enqueue origin to queue
   q.enqueue(origin);
   q.enqueue(std::make_pair(1,2)); 
   Node* deq = q.dequeue(); 
   q.print(); 
   std::cout << deq->coords.first << " " << deq->coords.second << std::endl; 

   //Initialize destination with user input as std::pair
   std::cout << "Please enter your destination x coordinate on the 4x4 board: ";
   std::cin >> x;
   std::cout << "Please enter your destination y coordinate on the 4x4 board: ";
   std::cin >> y;
   //Commenting this out because makefile does not allow unused variables
   //std::pair<int,int> destination = std::make_pair(x,y);

   // BREADTH FIRST INITIALIZATION OF TREE



}



// BREADTH FIRST INITIALIZATION OF TREE
/*

Initialize move with user input as node
while (move != destination)
{
   Node* current = queue.dequeue()
   for (int ind = 0; ind < 8; ind++)
   {
       find possible move
       validate possible move
       if (possible move)
       {
         add to tree (where current is parent of possible move)
         add to queue
       }
   }
}*/

// BACK TRAVERSAL
/* Node* current = destination node that is found
Initialize vector to store nodes that indicate shortest path
while (current != nullptr) since the parent of root node is nullptr
{
   add current to vector
   current = current->parent
}
reverse the vector and print the shortest path b/w origin and destination

*/
