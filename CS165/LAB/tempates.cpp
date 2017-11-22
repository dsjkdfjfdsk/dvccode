#include <iostream>
#include <string>
using namespace std;

template<class T>

void rotate(T array[], int size){
    T temp = array[size-1], temp2;
    for(int i = 0; i< size; i++)
    {
            temp2 = array[i];
            array[i] = temp;
            temp = temp2;
    }
}

template <class B>
void display(B array[], int size)
{
    
    for(int i = 0; i < size; i++)
    {
        cout << array[i];
    }
    cout << endl;
}

int main()
{
    int arrayN[] = {1, 3, 5, 7};
    char arrayL[] = {'a','b','c','d','e'};
    
    rotate<int>(arrayN, 4);
    display<int>(arrayN, 4);
    
    rotate<char>(arrayL, 4);
    display<char>(arrayL, 4);

}



