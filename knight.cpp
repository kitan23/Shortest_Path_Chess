/**
 * CS-102 Project 08: Finds the shortest path of a knight on a chess board from one point to another. Takes
 * origin coordinates and destination coordinates as user input before finding the shortest path between the
 * two positions on the board.
 * @file knight.cpp
 * @authors Kien Tran, Shraddha Datta
 * @date May 03 2022
 */

#include <utility> // for coordinates
#include <vector>
#include <iostream>
#include "tree.h"
#include "queue.h"
#include "node.h"

#define DIMENSION_OF_BOARD 8

/**
 * Finds all possible and valid moves that a knight can make from a certain position on the board
 * @param a pair of coordinates indicating the position of the knight on the board
 * @return a vector of all possible coordinates where the knight can move to from current location
 */
std::vector<std::pair<int, int>> find_possible_moves(const std::pair<int, int> coords)
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

/**
 * Reverses a vector of pairs of coordinates
 * @param coordinates: a vector of pairs of coordinates
 * @return the reversed vector of pairs of coordinates
 */
std::vector<std::pair<int,int>> reverse(std::vector<std::pair<int,int>> coordinates)
{
   for (size_t ind = 0; ind < coordinates.size()/2; ind++)
   {
      std::pair<int,int> start = coordinates[ind];
      std::pair<int,int> temp = start;
      coordinates[ind] = coordinates[coordinates.size()-ind - 1];
      coordinates[coordinates.size()-ind - 1] = temp;
   }
   return coordinates;
}


/**
 * Overloads operator << so that contents of a pair of integers can be output using std::cout
 * @param output: the output stream to write to
 * @param object: pair of integers whose contents are to be output
 * @return output: the output stream after it has been written to
 */
std::ostream & operator<<(std::ostream & output, const std::pair<int,int> object)
{
   output << object.first << " " << object.second << std::endl;
   return output;
}

// Controls the operation of the program
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

   // Initialize tree with root having origin
   Tree tr(origin);

   // Initialize queue
   Queue q;
   // Enqueue origin to queue
   q.enqueue(origin);

   std::vector<std::pair<int,int>> possible_moves;

   // Breadth first initialization of tree until we find destination node
   while (move->coords != destination->coords)
   {
      Node* current = q.dequeue();
      move = current;
      possible_moves = find_possible_moves(current->coords);

      for (size_t child_index = 0; child_index < possible_moves.size(); child_index++)
      {
         Node* child_node = new Node{possible_moves[child_index], {}, current, nullptr};
         tr.add_child(current, child_node);
         q.enqueue(child_node);
      }
   }

   // Initialize vector shortest_path and store nodes from destination point to origin using parent pointer
   std::vector<std::pair<int,int>> shortest_path;
   while (move != nullptr)
   {
      shortest_path.push_back(move->coords);
      move = move->parent;
   }

   // Reverse the vector shortest path and print its contents
   shortest_path = reverse(shortest_path);
   for (std::pair<int,int> coords : shortest_path)
   {
      std::cout << coords;
   }
}
