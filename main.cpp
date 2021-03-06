#include "Sorting.h"
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

void output(string algorithm, Sorting abc, int array[]);
void randomOutput();

int main(int argc, char* argv[]) {
/*
  ifstream file;
  file.open(argv[1]);

  int maxIndex = 0;
  int temp = 0;

  while(file >> temp) {
    maxIndex++;
  }
  file.clear(); //clears eof/fail bits
  file.seekg(0, ios::beg); //goes back to beginning of file

  int* table = new int[maxIndex];
  for(int a = 0; a < maxIndex; a++) {
    file >> table[a];
  }

  Sorting test;

  //merge and quick is shifted over by 1 for some reason when comapred to the other sorts

  //test.Selection(table, maxIndex);
  //test.Mergesort(table, 0, maxIndex - 1);
  //test.Heapsort(table, maxIndex);
  //test.QuickFP(table, 0, maxIndex - 1);
  //test.QuickRP(table, 0, maxIndex - 1);
  for(int i = 1; i < 6; i++) {
    cout << table[i] << endl;
  }
  cout << table[maxIndex - 1] << endl;

  cout << test.GetComparisons() << endl;
  file.close();
  delete[] table;

  return 0;
*/

        cout << "Would you like to use input from text or random numbers?" << endl;
    cout << "text (t) random input (r): " << endl;

    string input;
    getline(cin, input);

    if (0 == input.compare("t")) {
        cout << "Selection-sort (s) Merge-sort (m) Heap-sort (h) Quick-sort-fp (q)";
        cout << " Quick-sort-rp (r)" << endl;

        cout << "Enter the algorithm: ";
        string algorithm;

        getline(cin, algorithm);

        Sorting abc;

        int *array = new int[10000];

        ifstream infile;
        infile.open(argv[1]);

        int num = 0;

        //puts numbers from file into array
        while (infile >> array[num]) {
            num++;
        }

        infile.close();

        output(algorithm, abc, array);
    } else if (0 == input.compare("r")) {
        randomOutput();
    }
    return(EXIT_SUCCESS);

}

void output(string algorithm, Sorting abc, int array[]) {

    //prompt
    if (0 == algorithm.compare("s")) {
        abc.Selection(array, 10000);
        for (int i = 0; i < 10000; i++) {
            cout << " " << array[i];
            if (i % 20 == 0) {
                cout << endl;
            }
        }
        cout << endl;

        cout << "#Selection-sort comparisons: " << abc.GetComparisons();
        cout << endl;
    } else if (0 == algorithm.compare("m")) {

        abc.Mergesort(array, 0, 10000);
        for (int i = 1; i <= 10000; i++) {
            cout <<" " << array[i];
            if (i % 20 == 0) {
                cout << endl;
            }
        }
        cout << endl;
        cout << "#MergeSort comparisons: " << abc.GetComparisons();
        cout << endl;

    } else if (0 == algorithm.compare("h")) {

        abc.Heapsort(array, 10000);
        for (int i = 0; i < 10000; i++) {
            cout <<" " << array[i];
            if (i % 20 == 0) {
                cout << endl;
            }
        }
        cout << endl;
        cout << "#HeapSort comparisons: " << abc.GetComparisons();
        cout << endl;

    } else if (0 == algorithm.compare("q")) {

        abc.QuickFP(array, 0, 10000);
        for (int i = 0; i <= 10000; i++) {
            cout << " " << array[i];
            if (i % 20 == 0) {
                cout << endl;
            }
        }
        cout << endl;
        cout << "#QuickSort-fp comparisons: " << abc.GetComparisons();
        cout << endl;

    } else if (0 == algorithm.compare("r")) {

        abc.QuickRP(array, 0, 10000);
        for (int i = 0; i <= 10000; i++) {
            cout << " " << array[i];
            if (i % 20 == 0) {
                cout << endl;
            }
        }
        cout << endl;
        cout << "#QuickSort-rp comparisons: " << abc.GetComparisons();
        cout << endl;
    }

}

void randomOutput() {

    cout << "Size of input: ";
    string inputsize;

    getline(cin, inputsize);

    int size;

    size = stoi(inputsize);

    int *randomArray = new int[size];

    //creates array of random numbers from 0 - size
    cout << "Array being used: " << endl;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        randomArray[i] = rand() % size;
        cout << " " << randomArray[i];
        if (i % 20 == 0 && (i != 0)) {
            cout << endl;
        }
    }

    cout << endl;
    cout << "Which Sorting algorithm would you like to use?" << endl;
    cout << "Selection-sort (s) Merge-sort (m) Heap-sort (h) Quick-sort-fp (q)";
    cout << " Quick-sort-rp (r)" << endl;
    cout << "Algorithm: ";

    string user;
    getline(cin, user);

    Sorting def;

    if (0 == user.compare("s")) {
        def.Selection(randomArray, size);

        cout << endl;
        cout << "#Selection-sort comparisons: " << def.GetComparisons();
        cout << endl;
    } else if (0 == user.compare("m")) {

        def.Mergesort(randomArray, 0, size);

        cout << endl;
        cout << "#MergeSort comparisons: " << def.GetComparisons();
        cout << endl;

    } else if (0 == user.compare("h")) {

        def.Heapsort(randomArray, size);

        cout << endl;
        cout << "#HeapSort comparisons: " << def.GetComparisons();
        cout << endl;

    } else if (0 == user.compare("q")) {

        def.QuickFP(randomArray, 0, size);

        cout << endl;
        cout << "#QuickSort-fp comparisons: " << def.GetComparisons();
        cout << endl;

    } else if (0 == user.compare("r")) {

        def.QuickRP(randomArray, 0, size);

        cout << endl;
        cout << "#QuickSort-rp comparisons: " << def.GetComparisons();
        cout << endl;
    }
}
