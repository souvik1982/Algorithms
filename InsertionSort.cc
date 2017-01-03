#include <iostream>
#include <vector>
#include <cstdlib> //for random numbers
#include <time.h>                                                                                                     

void print_vector(std::vector<int> *v)
{
  for (unsigned int i=0; i<v->size(); ++i) std::cout<<v->at(i)<<" ";
  std::cout<<std::endl;
}

void swapLeft(std::vector<int> *v, unsigned int index)
{
  if (index>0)
  {
    int temp=v->at(index-1);
    v->at(index-1)=v->at(index);
    v->at(index)=temp;
  }
}

std::vector<int> insertionSort(std::vector<int> v)
{
  std::vector<int> v_sorted;
  v_sorted.push_back(v.at(0));
  for (unsigned int i=1; i<v.size(); ++i)
  {
    int key=v.at(i);
    v_sorted.push_back(v.at(i));
    unsigned int i_key=v_sorted.size()-1;
    while (i_key>0)  
    {
      if (key<v_sorted.at(i_key-1))
      {
        swapLeft(&v_sorted, i_key);             
        --i_key;                   
      }              
      else i_key=0;
    }
  }
  return v_sorted;
}

int main()
{
  //Fill vector with random numbers                                                                                                         
  std::vector<int> v;
  for(int i=0; i<10000; ++i) v.push_back(rand()%100);

  //Print                                                                                                                                   
  print_vector(&v);
  
  //Merge sort 
  std::cout<<"SORTED"<<std::endl;
  clock_t t=clock();                                                                                                                             
  std::vector<int> m = insertionSort(v);
  t=clock()-t;

  //Print                                                                                                                                   
  print_vector(&m);
  std::cout<<"Timing for "<<v.size()<<" elements = "<<t<<" CLKs"<<std::endl;
  
  return 0;
}
    
