#include <iostream>
#include <vector>
#include <fstream>
#include "paging.h"

struct File{                      //Struct que armazena as informações do arquivo de entrada
    std::vector<int> arr;
    int n;
};

struct File ReadFile( std::string filename )          //Função que vai ler o arquivo de entrada
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

  if( argc == 1 )                         //Verifica se foi passado algum argumento
    filename = "Data/input.txt";
  else
    filename = argv[1];

  struct File f1 = ReadFile( filename );  //Chamada da função para ler o arquivo

  Paging p1( f1.arr, f1.n );    //Cria o objeto de paginação

  return 0;
}
