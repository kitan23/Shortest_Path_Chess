#include <utility>
#include <vector>
#include <iostream>
#include "tree.h"


int main()
{
   Tree tr; 
   std::pair<int,int> roots = std::make_pair(1,2); 
   tr(roots); 
   std::cout << tr.get_root() << std::endl; 
   
}
