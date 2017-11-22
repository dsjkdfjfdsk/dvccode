//Exceptions EThan Chiu
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Passsword
{
    private:
        char str[80];
    public:
        class BadPassword
        {
            public:
                string errorMessage;
                BadPassword(string a)
                {
                    errorMessage = a;
                };
        };
        string getPassword()
        {
            char str[80];
            cout << "Enter password: ";
            cin.getline(str, 80);
            /*
            try{
                checkLength();
                thereIsNumber();
                lowerUpper();
                specialCharacter();
                cout << "Password meets reqs" << endl;
            }
            catch(string a){
                cout << a << endl;
            }
            */
            checkLength();
            thereIsNumber();
            lowerUpper();
            specialCharacter();
            cout << "Password meets reqs" << endl;
            return str;
        }
        
        //Check length
        void checkLength()
        {
            //check length
            if(strlen(str) < 8)
            {
                throw BadPassword("Password too short. Needs to be longer than 8");
            }
        }
        
        //Check if there is a number
        void thereIsNumber()
        {
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
                throw BadPassword("Include a number in your password");     
            }
        }
        
        //Contains at least one upper and one lower case
        void lowerUpper()
        {
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
                    throw BadPassword("Needs both upper case and lower case letters");
                }
                else if(!lowerCase)
                {
                    throw BadPassword("Needs a lower case letter");
                }
                else
                {
                    throw BadPassword("Needs an upper case letter");
                }
            }
        }
        
        //Check if password contains one of these special characters: !@#$%&*:
        void specialCharacter()
        {
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
                throw BadPassword("Password needs  one of these special characters: !@#$%&*:");
            }
        }

};



int main()
{
    Passsword a;
    string userValue;
    try
    {
       userValue = a.getPassword();
       cout << "You entered " << userValue << endl;
    }
    catch (Passsword::BadPassword userValue)
    {
       cout << "Value is invalid: " << userValue.errorMessage;
    }
}





