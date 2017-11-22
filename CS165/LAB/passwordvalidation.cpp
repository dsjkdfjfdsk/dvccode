// password validation EThan Chiu
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{

    char str[80];
    bool password = true;
    
    cout << "Enter password: ";

    cin.getline(str, 80);
    
    //check length
    if(strlen(str) < 8)
    {
        cout << "Password too short. Needs to be longer than 8" << endl;
        password = false;
    }
    
    //Check if there is a number
    bool thereIsNumber = false;
    for(int i = 0; i < strlen(str); i++)
    {
        if(isdigit(str[i]))
        {
            thereIsNumber = true;
            break;
        }
    }
    if(!thereIsNumber)
    {
        cout << "Include a number in your password" << endl;
        password = false;        
    }
    
    //Contains at least one upper and one lower case
    bool lowerCase = false;
    bool upperCase = false;
    for(int b = 0; b < strlen(str); b++)
    {
        if(isupper(str[b]))
        {
            upperCase = true;
        }
        if(islower(str[b]))
        {
            lowerCase = true;
        }
    }
    if(!(lowerCase && upperCase))
    {
        if(!lowerCase && !upperCase)
        {
            cout << "Needs both upper case and lower case letters" << endl;
        }
        else if(!lowerCase)
        {
            cout << "Needs a lower case letter" << endl;
        }
        else
        {
            cout << "Needs an upper case letter" << endl;
        }
        password = false;
    }
    
    //Check if password contains one of these special characters: !@#$%&*:;
    bool specialChar = false;
    for(int c = 0; c < strlen(str); c++)
    {
        switch(str[c])
        {
            case '!':
            case '@':
            case '#':
            case '$':
            case '%':
            case '&':
            case '*':
            case ':':
                specialChar = true;
        }
    }
    if(!specialChar)
    {
        cout << "Password needs  one of these special characters: !@#$%&*:" << endl;
        password = false;
    }
    
    //Output if password is good
    if(password)
    {
        cout << "Password meets reqs" << endl;
    }
    
    
}



