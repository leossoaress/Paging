#include "paging.h"

Paging::Paging( std::vector<int> arr, const int n )       
{
  FIFO( arr, n );       //Chama o algoritmo FIFO

  OTM( arr, n );        //Chama o algoritmo ótimo

  LRU( arr, n );        //Chama o algoritmo LRU
}

void Paging::FIFO( std::vector<int> arr, const int n )
{
  int *b = new int[n];
  int j = 0, k = 0;

  for( int i = 0; i < n; ++i )      //Seta todos os quadros inicialmente para vazio
    b[i] = -1;

  for( unsigned int i = 0; i < arr.size(); ++i )    //Para cada página arr[i]
  {
    if( Verification( arr[i], b, n ) )    //Verifica se a pagina já está na memória
    {
      continue;     //Se estiver na memória, continua para a próxima página
    }
    else      //Caso contrário
    {
      b[k%n] = arr[i];    //Substitui pagina da vez pela que é necessária
      j++;                //Contador de falhas
      k++;                //Diz que vai ser a próxima página que sera substituida
    }
  }
  std::cout << "FIFO " << j << std::endl;
}

bool Paging::Verification( int a, int b[], const int n )
{
    for( int i = 0; i < n; ++i )
    {
      if( b[i] == a )
        return true;
    }
    return false;
}

void Paging::OTM( std::vector<int> arr, const int n )
{
  int *b = new int[n];
  int j = 0, k = 0;

  for( int i = 0; i < n; ++i )      //Seta todos os quadros inicialmente para vazio
    b[i] = -1;

  for( unsigned int i = 0; i < arr.size(); ++i )    //Para cada página arr[i]
  {
    if( Verification( arr[i], b, n) )     //Verifica se a pagina já está na memória
    {
      continue;   //Se estiver na memória, continua para a próxima página
    }
    else
    {
      if( b[k%n] == -1 )      //Se o quadro estiver vazio, pode colocar a página
      {
        b[k%n] = arr[i];
      }
      else      //Caso contrário
      {
        int l = ChooseWorstOTM( arr, b, i, n );       //Achar a pagina presente nos quadros, que vai demorar mais a ser utilizada
        b[l] = arr[i];                                //Substituir a página atual pela que será menos utilizada
      }
      j++;    //Contador de falhas
      k++;    //Diz que vai ser a próxima página que sera substituida
    }
  }

  std::cout << "OTM " << j << std::endl;
}

int Paging::ChooseWorstOTM( std::vector<int> arr, int b[], const int m, const int n )
{
  int k = 0;
  int *c = new int[n];

    for( int i = 0; i < n; ++i )
    {
      k=0;

      for( unsigned int j = m+1; j < arr.size(); ++j )
      {
        if( b[i] == arr[j] )
        {
            break;
        }
        else
        {
          k++;
        }
      }

      c[i] = k;
    }

    int max = 0;
    for( int i = 1; i < n; ++i )
    {
      if( c[i] > c[max] )
        max = i;
    }

    return max;
}

void Paging::LRU( std::vector<int> arr, int n )
{
  int *b = new int[n];
  int *c = new int[n];

  int j = 0, k = 0;

  for( int i = 0; i < n; ++i )     //Seta todos os quadros inicialmente para vazio, e o tempo inicial para zero
  {
    b[i] = -1;
    c[i] = 0;
  }

  for( unsigned int i = 0; i < arr.size(); ++i )    //Para cada página arr[i]
  {
    for( int l = 0; l < n; ++l )      //Incrementa o tempo de todas as páginas que estão nos quadros
        c[l]++;

    if( Verification( arr[i], b, n) )   //Verifica se a pagina já está na memória
    {
        for( int h = 0; h < n; ++h )    //Quando a pagina está na memória, seta o tempo para zero
        {
          if( b[h] == arr[i] )
          {
            c[h] = 0;
            break;
          }
        }
        continue;
    }
    else
    {
      if( b[k%n] == -1 )         //Se o quadro estiver vazio, pode colocar a página e zera o tempo dessa pagina
      {
        b[k%n] = arr[i];
        c[k%n] = 0;
      }
      else      //Caso contrário
      {
          int p = ChooseWorstLRU( c, n );   //Achar a pagina presente nos quadros, que não foi utilizada recentemente
          b[p] = arr[i];                    //Substituir a página atual pela que foi não utilizada recentemente
          c[p] = 0;                         //Seta o tempo da pagina para zero
      }
      j++;        //Contador de falhas
      k++;        //Diz que vai ser a próxima página que sera substituida
    }
  }

  std::cout << "LRU " << j << std::endl;
}

int Paging::ChooseWorstLRU( const int c[], const int n )
{
  int max = 0;
  for( int i = 1; i < n; ++i )
  {
    if( c[i] > c[max] )
      max = i;
  }

  return max;
}
