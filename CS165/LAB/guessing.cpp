// guessing Ethan Chiu
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    unsigned seed;
    seed = time(0);
    srand(seed);
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    int count = 0;
    
    do 
    {
        count++;
        
        cout << "What's your guess? ";
        cin >> userGuess; 
        cin.ignore(1000,10);
        
        if (userGuess > randomNumber)
        {
            cout << "Too high, try again" << endl;
        }
        else if (userGuess < randomNumber)
        {
            cout << "Too low, try again" << endl;
        }
        else
        {
            cout << "Congratulations! You figured out my number in " << count << " tries" << endl;
        }
    } while (userGuess != randomNumber);
}


