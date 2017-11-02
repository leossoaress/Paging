#include "paging.h"

Paging::Paging( std::vector<int> arr, const int n )
{
  FIFO( arr, n );

  OTM( arr, n );

  LRU( arr, n );
}

void Paging::FIFO( std::vector<int> arr, const int n )
{
  int *b = new int[n];
  int j = 0, k = 0;

  for( int i = 0; i < n; ++i )
    b[i] = -1;

  for( unsigned int i = 0; i < arr.size(); ++i )
  {
    if( Verification( arr[i], b, n ) )
    {
      continue;
    }
    else
    {
      b[k%n] = arr[i];
      j++;
      k++;
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

  for( int i = 0; i < n; ++i )
    b[i] = -1;

  for( unsigned int i = 0; i < arr.size(); ++i )
  {
    if( Verification( arr[i], b, n) )
    {
      continue;
    }
    else
    {
      //std::cout << arr[i] << std::endl;
      if( b[k%n] == -1 )
      {
        b[k%n] = arr[i];
      }
      else
      {
        int l = ChooseWorstOTM( arr, b, i, n );
        b[l] = arr[i];
      }
      j++;
      k++;
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

  for( int i = 0; i < n; ++i )
  {
    b[i] = -1;
    c[i] = 0;
  }

  for( unsigned int i = 0; i < arr.size(); ++i )
  {
    for( int l = 0; l < n; ++l )
        c[l]++;

    if( Verification( arr[i], b, n) )
    {
        for( int h = 0; h < n; ++h )
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
      if( b[k%n] == -1 )
      {
        b[k%n] = arr[i];
        c[k%n] = 0;
      }
      else
      {
          int p = ChooseWorstLRU( c, n );
          b[p] = arr[i];
          c[p] = 0;
      }
      j++;
      k++;
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
