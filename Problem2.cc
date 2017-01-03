#include <iostream>

void Problem2()
{
  unsigned int n1=1;
  unsigned int n2=2;
  unsigned int total;
  unsigned int sumEven=0;
  
  while (total<=4e6)
  {
    total=n1+n2;
    n1=n2;
    n2=total;
    if (n1 % 2==0) sumEven+=n1;
  }
  
  std::cout<<"sumEven = "<<sumEven<<std::endl;
}
