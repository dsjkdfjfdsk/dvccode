// prime number ethan chiu
#include <iostream>
#include <string>

using namespace std;

bool isPrime(int number);

int main()
{
  int number;
    
  cout << "Prime number: ";
  cin >> number;
  cin.ignore(1000,10);
  
  if (isPrime(number))
  {
    cout << number << " is prime" << endl;
  }
  else 
  {
    cout << number << " is NOT prime" << endl;
  }
  return 0;

}

bool isPrime(int number)
{
    for(int i = number - 1; i > 1; i--)
    {
        if(number%i==0)
            return false;
    }
    if(number != 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


