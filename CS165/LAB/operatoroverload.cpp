#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Switch two arr spots
void swap(string a[], int i, int j){
  string temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

// return index of max word
int findMaxIndex(string a[], int lastIndex){
  int index = 0;
  string max = a[index];
  for(int i=1; i<= lastIndex; i++){
    if (a[i].compare(max) <= 0){
      index = i;
      max = a[index];
    }
  }
  return index;
}


// sort strings in array in descending ordr
void selectionSort(string a[], int size){
  for(int i=size-1; i>=0; i--){
    swap( a, i, findMaxIndex(a, i) );
  }
}

int main()
{
    const int SIZE = 20;
    
    string name[SIZE] =
    {"Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim",
    "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
    "Allison, Jeff", "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
    "Moretti, Bella", "Wu, Hong", "Patel, Renee", "Harrison, Rose",
    "Smith, Cathy", "Conroy, Pat", "Kelly, Sean", "Holland, Beth"};
    
    selectionSort(name, SIZE);
    for(int i=SIZE-1; i>=0; i--)
    {
        cout << name[i] << endl;
    }

    
}



