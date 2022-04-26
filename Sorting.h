#ifndef Sorting_h
#define Sorting_h

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Sorting {
private:
  int comparisons;
  
public:
  Sorting();
  void Selection(int table[], int maxIndex);
  void Merge(int table[]);
  void Heap(int table[]);
  void QuickFP(int table[], int first, int last);
  void QuickRP(int table[], int first, int last);
  
  void Swap(int *x, int *y);
  void Split(int table[], int first, int last);
  int GetComparisons();
};

#endif
