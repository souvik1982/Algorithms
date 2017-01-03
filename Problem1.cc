#include <iostream>

void Problem1()
{
  unsigned int total=0;
  for (unsigned int i=1; i<1000; ++i)
   if (i%3==0 || i%5==0) total+=i;
  std::cout<<"total = "<<total<<std::endl;
}
