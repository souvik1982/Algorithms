#include <iostream>

unsigned int conjugate(unsigned int n)
{
  unsigned int conj=0;
  for (unsigned int i=1; i<n/2+1; ++i)
    if (n%i==0) conj+=i;
  return conj;
}

int main()
{
  unsigned int total=0;
  for (unsigned int i=1; i<=10000; ++i)
  {
    unsigned int conjugate_i=conjugate(i);
    if (conjugate_i!=i)
    {
      if (conjugate(conjugate_i)==i) 
      {
        std::cout<<i<<" "<<conjugate(i)<<std::endl;
        total+=i;
      }
    }
  }
  std::cout<<" Sum of amicable numbers = "<<total<<std::endl;
}
