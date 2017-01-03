/* --- ---
Souvik's smart O(n^2) solution to Deian's problem.
Improves from O(n^3) brute force, to O(n^2 log(n)) semi-smart, to O(n^2) smart solution
Tuesday, Dec 13, 2016
--- --- */

#include <iostream>
#include <vector>
#include <cstdlib> //for random numbers 
#include <time.h>

// Useful for debug
void printVector(std::vector<int> *v)
{
  for (unsigned int i=0; i<v->size(); ++i) std::cout<<v->at(i)<<" ";
  std::cout<<std::endl;
}

// Brute force O(n^3) algorithm
unsigned int bruteCount(std::vector<int> *v, int x)
{
  unsigned int total=0;
  for (unsigned int i=0; i<v->size(); ++i)
  {
    for (unsigned int j=i+1; j<v->size(); ++j)
    {
      for (unsigned int k=j+1; k<v->size(); ++k)
      {
        if (v->at(i)+v->at(j)+v->at(k)<=x) 
        {
          // std::cout<<v->at(i)<<", "<<v->at(j)<<", "<<v->at(k)<<std::endl;
          ++total;
        }
        
      }
    }
  }
  return total;
}

std::vector<int> merge(std::vector <int> v1, std::vector<int> v2)
{
  std::vector<int> v_output;
  unsigned int i_v1=0, i_v2=0;
  while (i_v1<v1.size() && i_v2<v2.size())
  {
    if (v1.at(i_v1)<v2.at(i_v2))
    {
      v_output.push_back(v1.at(i_v1));
      ++i_v1;
    }
    else
    {
      v_output.push_back(v2.at(i_v2));
      ++i_v2;
    }
  }
  while (i_v1<v1.size())
  {
    v_output.push_back(v1.at(i_v1));
    ++i_v1;
  }
  while (i_v2<v2.size())
  {
    v_output.push_back(v2.at(i_v2));
    ++i_v2;
  }
  return v_output;
}

std::vector<int> mergeSort(std::vector<int> v)
{
  std::vector<int> v1, v2;
  for (unsigned int i=0; i<int(v.size())/2; ++i) v1.push_back(v.at(i));
  for (unsigned int i=int(v.size())/2; i<v.size(); ++i) v2.push_back(v.at(i));
  
  if (v1.size()>1) v1=mergeSort(v1);
  if (v2.size()>1) v2=mergeSort(v2);
  
  std::vector<int> v3;
  v3=merge(v1, v2);
  return v3;
}

// An order O(n^2) algorithm
unsigned int smartCount(std::vector<int> *v, int x)
{
  unsigned int total=0;
  for (unsigned int i=0; i<v->size(); ++i)
  {
    unsigned int i_lo=i+1;
    unsigned int i_hi=v->size()-1;
    int a=v->at(i);
    while (i_hi>i_lo)
    {
      int b=v->at(i_lo);
      int c=v->at(i_hi);
      if ((a+b+c)<=x) 
      {
        total+=(i_hi-i_lo);
        ++i_lo;
      }
      else if ((a+b+c)>x) --i_hi;
    }
  }
  return total;
}

int main()
{
  //Fill vector with random numbers                                                                                                         
  std::vector<int> v;
  for(int i=0; i<10; ++i) v.push_back(rand()%100);

  //Print                                                                                                                                   
  printVector(&v);
  
  // Brute force count
  int x=100;
  std::cout<<"Number of 3 numbers with sum less than "<<x<<" using the brute force O(n^3) algorithm is "<<std::endl;
  std::cout<<bruteCount(&v, x)<<std::endl;
  
  // Faster method
  // First merge sort
  std::vector<int> m=mergeSort(v);
  std::cout<<"Sorted vector: "<<std::endl;
  printVector(&m);
  std::cout<<"Number of 3 numbers with sum less than "<<x<<" using an O(n^2) algorithm is "<<std::endl;
  std::cout<<smartCount(&m, x)<<std::endl;
  
  return 0;
}
