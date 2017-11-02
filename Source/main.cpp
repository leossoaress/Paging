#include <iostream>
#include <vector>
#include <fstream>
#include "paging.h"

struct File{
    std::vector<int> arr;
    int n;
};

struct File ReadFile( std::string filename )
{
  std::fstream file( filename, std::ios_base::in );

  struct File f;
  std::vector<int> arr;

  int q=0, x=0;

  file >> q;

  while( file >> x )
    arr.push_back(x);

  f.arr = arr;
  f.n = q;

  return f;
}


int main( int argc, char *argv[] )
{

  std::string filename;

  if( argc == 1 )
    filename = "Data/input.txt";
  else
    filename = argv[1];

  struct File f1 = ReadFile( filename );

  Paging p1( f1.arr, f1.n );

  return 0;
}
