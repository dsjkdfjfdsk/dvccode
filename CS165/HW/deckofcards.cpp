//Deck of Cards HW #5
//Ethan Chiu
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum Suit {clubs=0, diamonds, hearts, spades};
class Card {
    private:
        int number;
        string description;
        Suit suit;
    
    public:
        Card()
        {
        }
        void setNumber(int yourNumber)
        {
            number = yourNumber;
        }
        void setDescription(string yourDescription)
        {
            description = yourDescription;
        }
        void setSuit(Suit yourSuit)
        {
            suit = yourSuit;
        }
        int getNumber()
        {
            return number;
        }
        string getDescription()
        {
            return description;
        }
        Suit getSuit()
        {
            return suit;
        }
        bool operator<(const Card& c){
            //spades > hearts > diamonds > clubs
            if (this->suit < c.suit)
            {
                return true;
            }
            else if (c.suit == this->suit)
            {
                if(this->number < c.number)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else {
                return false;
            }
        }
};

class Deck
{
    private:
        Card cards[52];
        Card hand1[5];
        Card hand2[5];
        Card hand3[5];
        Card hand4[5];
        Card hands[20];
    public:
        Deck()
        {
        }
        void initialize()
        {
             string a;
             Suit currentSuit;
             int i = 0;
             string description;
             for (int c = 1; c <= 4; c++) {
                switch (c) {
                case 1:
                    a = "spades";
                    currentSuit = spades;
                    break;
                case 2:
                    a = "hearts";
                    currentSuit = hearts;
                    break;
                case 3:
                    a = "diamonds";
                    currentSuit = diamonds;
                    break;
                case 4:
                    a = "clubs";
                    currentSuit = clubs;
                    break;
                default:
                    cout << "errors";
                    break;
                }
                for (int k = 1; k <= 13; k++) {
                    cards[i].setSuit(currentSuit);
                    cards[i].setNumber(k);
                    description = to_string(k) + " of " + a;
                    cards[i].setDescription(description);
                    i++;
                }
            }
        }
        void shuffle()
        {
            for (int i=0; i<52; i++) {
                int r = rand() % 52;  // generate a random position
                Card temp = cards[i]; 
                cards[i] = cards[r]; 
                cards[r] = temp;
            }
        }
        void deal()
        {
            for (int i = 0; i < 5; i++)
            {
                hand1[i]=cards[i];
                hands[i]=cards[i];
            }
            for (int i = 0; i < 5; i++)
            {
                hand2[i]=cards[i+5];
                hands[i+5]=cards[i+5];
            }
            for (int i = 0; i < 5; i++)
            {
                hand3[i]=cards[i+10];
                hands[i+10]=cards[i+10];
            }
            for (int i = 0; i < 5; i++)
            {
                hand4[i]=cards[i+15];
                hands[i+15]=cards[i+15];
            }
        }
        void sortHand(Card* a)
        {
            Card temp;
            bool unsorted = true;
            while(unsorted)
            {
                unsorted = false;
                for(int i = 0; i <5; i++)
                {
                    if(a[i]<a[i+1])
                    {
                        temp = a[i];
                        a[i] = a[i+1];
                        a[i+1] = temp;
                        unsorted = true;
                    }
                }
            }
            
        }
        void sort()
        {
            sortHand(hand1);
            sortHand(hand2);
            sortHand(hand3);
            sortHand(hand4);
            for (int i = 0; i < 5; i++)
            {
                hands[i]=hand1[i];
            }
            for (int i = 0; i < 5; i++)
            {
                hands[i+5]=hand2[i];
            }
            for (int i = 0; i < 5; i++)
            {
                hands[i+10]=hand3[i];
            }
            for (int i = 0; i < 5; i++)
            {
                hands[i+15]=hand4[i];
            }
        }
        void display()
        {
            cout << "HAND 1        HAND 2        HAND 3        HAND 4" << endl;
            for(int a = 0; a < 20; a=a+5)
            {
                cout << hands[a].getDescription() << "  ";
            }
            cout << endl;
            for(int b = 1; b < 20; b+=5)
            {
                cout << hands[b].getDescription()<< "  ";
            }
            cout << endl;
            for(int c = 2; c < 20; c+=5)
            {
                cout << hands[c].getDescription()<< "  ";
            }
            cout << endl;
            for(int d = 3; d < 20; d+=5)
            {
                cout << hands[d].getDescription() << "  ";
            }
            cout << endl;
            for(int e = 4; e < 20; e+=5)
            {
                cout << hands[e].getDescription() << "  ";
            }
            cout << endl;
        }
};

int main()
{
    //Set Variables
    srand(time(0));  
    Deck deck;
    deck.initialize();
    deck.shuffle();
    deck.deal();
    deck.sort();
    deck.display();
    

  
}





