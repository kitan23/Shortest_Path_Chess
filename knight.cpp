#include <utility>
#include <vector>
#include <iostream>
#include "tree.h"
#include "queue.h"
#include "node.h"

int DIMENSION_OF_BOARD = 8; 

std::vector<std::pair<int, int>> find_possible_moves(std::pair<int, int> coords)
{
   std::vector<std::pair<int, int>> pssble_moves;
   int x = coords.first;
   int y = coords.second;
   if ((x + 1) < DIMENSION_OF_BOARD)
   {
      if ((y + 2) < DIMENSION_OF_BOARD)
      {
         pssble_moves.emplace_back(std::make_pair(x + 1, y + 2));
      }
      if (y - 2 > -1)
      {
         pssble_moves.emplace_back(std::make_pair(x + 1, y - 2));
      }
   }
   if ((x + 2) < DIMENSION_OF_BOARD)
   {
      if ((y + 1) < DIMENSION_OF_BOARD)
      {
         pssble_moves.emplace_back(std::make_pair(x + 2, y + 1));
      }
      if (y - 1 > -1)
      {
         pssble_moves.emplace_back(std::make_pair(x + 2, y - 1));
      }
    }
    if ((x - 1) > -1)
    {
         if ((y + 2) < DIMENSION_OF_BOARD)
         {
            pssble_moves.emplace_back(std::make_pair(x - 1, y + 2));
         }
         if ((y - 2) > -1)
        {
            pssble_moves.emplace_back(std::make_pair(x - 1, y - 2));
        }
    }
    if ((x - 2) > -1)
    {
        if ((y + 1) < DIMENSION_OF_BOARD)
        {
            pssble_moves.emplace_back(std::make_pair(x - 2, y + 1));
        }
        if ((y - 1) > -1)
        {
            pssble_moves.emplace_back(std::make_pair(x - 2, y - 1));
        }
    }
    return pssble_moves;
}

std::ostream & operator<<(std::ostream & output, std::pair<int,int> object)
{
   output << object.first << " " << object.second << std::endl; 
   return output; 
}

int main()
{
   //Initialize origin with user input as std::pair
   std::cout << "Please enter a starting x coordinate on a " << DIMENSION_OF_BOARD << "x" << DIMENSION_OF_BOARD << " board: ";
   int x;
   std::cin >> x;
   std::cout << "Please enter a starting y coordinate on a " << DIMENSION_OF_BOARD << "x" << DIMENSION_OF_BOARD << " board: ";
   int y;
   std::cin >> y;
   std::pair<int,int> origin_coords = std::make_pair(x,y);
   //Initialize destination with user input as std::pair
   std::cout << "Please enter your destination x coordinate on a " << DIMENSION_OF_BOARD << "x" << DIMENSION_OF_BOARD << " board: ";
   std::cin >> x;
   std::cout << "Please enter your destination y coordinate on a " << DIMENSION_OF_BOARD << "x" << DIMENSION_OF_BOARD << " board: ";
   std::cin >> y;
   std::pair<int,int> destination_coords = std::make_pair(x,y);
   Node* origin = new Node{origin_coords}; 
   Node* destination = new Node{destination_coords}; 
   Node* move = origin; 

   //Initialize tree with root having origin
   Tree tr(origin);

   //Initialize queue
   Queue q;
   //Enqueue origin to queue
   q.enqueue(origin);

   std::vector<std::pair<int,int>> possible_moves; 
   while (move->coords != destination->coords)
   {
      Node* current = q.dequeue(); 
      move = current; 
      possible_moves = find_possible_moves(current->coords); 

      for (int child_index = 0; child_index < possible_moves.size(); child_index++)
      {
         Node* child_node = new Node{possible_moves[child_index], {}, current, nullptr}; 
         tr.add_child(current, child_node); 
         q.enqueue(child_node); 
      }
   }

   std::vector<std::pair<int,int>> shortest_path; 
   while (move != nullptr)
   {
      shortest_path.push_back(move->coords); 
      move = move->parent; 
   }

   std::reverse(shortest_path.begin(), shortest_path.end()); 
   for (std::pair<int,int> coords : shortest_path)
   {
      std::cout << coords; 
   }
}



// BREADTH FIRST INITIALIZATION OF TREE
/*

Initialize move with user input as node
while (move != destination)
{
   Node* current = queue.dequeue()
   find possible move and validate moves (function that returns vector v containing valid moves)
   for (int ind = 0; ind < v; ind++)
   {
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
