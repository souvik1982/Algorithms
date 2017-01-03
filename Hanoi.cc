/*-------------------------
Souvik's implementation
of Towers of Hanoi
December 8, 2016
--------------------------*/

#include <iostream>

void move(int nDisks, int pegFrom, int pegTo, int pegAux)
{
  if (nDisks>0)
  {
    move(nDisks-1, pegFrom, pegAux, pegTo);
    std::cout<<"Move "<<pegFrom<<" -> "<<pegTo<<std::endl;
    move(nDisks-1, pegAux, pegTo, pegFrom);
  }
}

int main()
{
  move(4, 1, 2, 3);
  return 0;
}
