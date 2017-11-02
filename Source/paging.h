#ifndef PAGING_H
#define PAGING_H

#include <iostream>
#include <vector>

class Paging{

public:

    Paging( std::vector<int> arr, const int n );

    void FIFO( std::vector<int> arr, const int n );

    bool Verification( int arr, int a[], const int n );

    void OTM( std::vector<int> arr, const int n );

    int ChooseWorstOTM( std::vector<int> arr, int b[], const int i, const int n );

    void LRU( std::vector<int> arr, int n );

    int ChooseWorstLRU( const int c[], const int n );
};

#endif
