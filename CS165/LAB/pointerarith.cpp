// Pointer Arithmetic
#include <iostream>
#include <string>

using namespace std;

void pointerArithmetic(int *array, int size, double &average, int &high, int &low)
{
    high = *(array);
    low = *(array);
    for(int i = 0; i < size; i++)
    {
        if(*(array+i) > high)
        {
            high = *(array+i);
        }
        if(*(array+i) < low)
        {
            low = *(array+i);
        }
        average += *(array+i);
    }
    average = average / size;
}

int main()
{
    int arr[] = {2, 3, 4, 1};
    
    int* p;
    double average = 0.0;
    int high, low = 0;
    p = arr;

    int size = 4;

    pointerArithmetic(p, size, average, high, low);

    cout << "Average: " << average << endl;
    cout << "High: " << high << endl;
    cout << "Low: " << low << endl;
}



