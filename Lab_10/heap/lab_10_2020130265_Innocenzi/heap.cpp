//--------------------------------------------------------------------
//
//  Laboratory 13                                             heap.cpp
//
//  Actual implementation of class in the Heap ADT
//--------------------------------------------------------------------

#include "heap.h"
#include <iostream>
using namespace std;
//--------------------------------------------------------------------


template<class DT>
Heap<DT>::Heap(int maxNumber)
:maxSize(maxNumber)
{
    dataItems = new DT[maxNumber];
}

template < class DT >
Heap<DT>::~Heap()
{
    clear();
}

//--------------------------------------------------------------------

template < class DT >
void Heap<DT>::insert(const DT& newElement)
{
    if (size >= maxSize){
        std::cout << "Could not insert new element, maxed size of heap reached." << std::endl;
        
    }
    else{
    size++;
    int n = size - 1;
    dataItems[n] = newElement;
    
        while(n != 0 && dataItems[(n-1)/2].pty() < dataItems[n].pty()){
            std::swap(dataItems[n], dataItems[(n-1)/2]);
            n = (n-1)/2;
        }
    }
}

template < class DT >
DT Heap<DT>::removeMax()
{
    if (size == 1){
        size--;
        return(dataItems[0]);
    }
    
    DT root = dataItems[0];
    dataItems[0] = dataItems[size-1];
    size--;
    
    int n = size;
    while(n != 0 && dataItems[(n-1)/2].pty() < dataItems[n].pty()){
        std::swap(dataItems[n], dataItems[(n-1)/2]);
        n = (n-1)/2;
    }
    return root;
}

template < class DT >
void Heap<DT>::clear()
{
    size = 0;
    delete [] dataItems;
}

//--------------------------------------------------------------------

template < class DT >
bool Heap<DT>::isEmpty() const
{
    return(size == 0);
}

template < class DT >
bool Heap<DT>::isFull() const
{
    return (size == maxSize);
}

//--------------------------------------------------------------------

template < class HD >
void Heap<HD>:: showStructure () const

// Outputs the priorities of the data in a heap in both array
// and tree form. If the heap is empty, outputs "Empty heap". This
// operation is intended for testing/debugging purposes only.

{
    int j;   // Loop counter

    cout << endl;
    if ( size == 0 )
       cout << "Empty heap" << endl;
    else
    {
       cout << "size = " << size << endl;       // Output array form
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ )
           cout << dataItems[j].pty() << "\t";
       cout << endl << endl;
       showSubtree(0,0);                        // Output tree form
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void Heap<DT>:: showSubtree ( int index, int level ) const

// Recursive partner of the showStructure() function. Outputs the
// subtree (subheap) whose root is stored in dataItems[index]. Argument
// level is the level of this dataItems within the tree.

{
     int j;   // Loop counter

     if ( index < size )
     {
        showSubtree(2*index+2,level+1);        // Output right subtree
        for ( j = 0 ; j < level ; j++ )        // Tab over to level
            cout << "\t";
        cout << " " << dataItems[index].pty();   // Output dataItems's pty
        if ( 2*index+2 < size )                // Output "connector"
           cout << "<";
        else if ( 2*index+1 < size )
           cout << "\\";
        cout << endl;
        showSubtree(2*index+1,level+1);        // Output left subtree
    }
}
