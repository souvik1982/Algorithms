#include <iostream>

void Problem6()
{
  double nSum=0;
  double n2Sum=0;
  for (unsigned int i=1; i<=100; ++i)
  {
    nSum+=i;
    n2Sum+=i*i;
  }
  std::cout<<"Diff = "<<int(nSum*nSum-n2Sum)<<std::endl;
}
  
