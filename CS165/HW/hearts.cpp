//Deck of Cards HW #5
//Ethan Chiu
enum Suit {clubs=0, diamonds, hearts, spades};
#include <iostream>
#include <string>
#include <fstream>
#include "Card.h"
#include "Deck.h"
using namespace std;

//Player class
class Player
{
    private:
        int score;
        Card cards[13];
    public:
		Player(){};	
		
		//Count points
		void countPoints()
		{
			for(int i = 0; i < 13; i++)
			{
				if(cards[i].getSuit() == hearts)
				{
					score += 1;
				}
				if(cards[i].getNumber() == 12 & cards[i].getSuit() == spades)
				{
					score += 13;
				}
			}
		};
		
		void setPoints(int a)
		{
			score = a;
		}
		
		//score to 0
		void resetScore()
		{
			score = 0;
		};
		
		//output score
		int getScore()
		{
			return score;
		}
};

int main()
{
    //Set Variables
    srand(time(0));  
    bool done = false;
    Deck deck;
    deck.initialize();
    Player players[4];
    
    //Get user input
    while(!done)
    {
		cout << "Do you want to shuffle, deal, or end?";
		string userinput;
		getline(cin, userinput);
		if(userinput == "shuffle")
		{
			deck.shuffle();
		}
		else if (userinput == "deal")
		{
			deck.deal();
			deck.sort();
			deck.display();
			done = true;
		}
		else if (userinput =="end")
		{
			done = true;
		}
		else
		{
			cout << "Sorry I don't understand that";
		}
	}
	
	//Play game of hearts
	int currentPlayer = 1;
	bool inPlay = true;
	//Check to see which player has 2 of clubs
	int cardNum;
	for(int i = 0; i < 52; i++)
	{
		if(deck.cards[i].getSuit() == clubs && deck.cards[i].getNumber() == 2)
		{
			cardNum = i;
		};
	}
	if(cardNum < 13)
	{
		currentPlayer = 1;
	}
	else if(cardNum < 26)
	{
		currentPlayer = 2;
	}
	else if(cardNum < 39)
	{
		currentPlayer = 3;
	}
	else
	{
		currentPlayer = 4;
	}
	
	//Start round
	while(inPlay)
	{
		//Initialize values
		Suit leadSuit;
		Card cardsSubmitted[4];
		
		//First player leads


		//Get cards for other players
		int chosenCardIndex;
		for(int i = 0; i < 4; i++)
		{
			if(i == 0)
			{
				cout << "Player " << to_string(currentPlayer) << " turn" << endl;
				cout << "Enter card position you want to dispose: ";
				cin >> chosenCardIndex;
				switch(currentPlayer)
				{
					case 1:
						leadSuit = deck.hand1[chosenCardIndex].getSuit();
						cardsSubmitted[currentPlayer-1] = deck.hand1[chosenCardIndex];
						break;
					case 2:
						leadSuit = deck.hand2[chosenCardIndex].getSuit();
						cardsSubmitted[currentPlayer-1] = deck.hand2[chosenCardIndex];
						break;
					case 3:
						leadSuit = deck.hand3[chosenCardIndex].getSuit();
						cardsSubmitted[currentPlayer-1] = deck.hand3[chosenCardIndex];
						break;
					case 4:
						leadSuit = deck.hand4[chosenCardIndex].getSuit();
						cardsSubmitted[currentPlayer-1] = deck.hand4[chosenCardIndex];
						break;
				}
			}
			else
			{	
				cout << "Player " << to_string(currentPlayer) << " turn" << endl;
				bool validity = false;
				while(!validity)
				{
					cout << "Enter card position you want to dispose: ";
					
					//Chosen Card
					cin >> chosenCardIndex;
					cin.ignore(1000,10);
					chosenCardIndex -= 1;
					
					//See what hand is associated with the player
					switch(currentPlayer)
					{
						case 1:
							cardsSubmitted[currentPlayer-1] = deck.hand1[chosenCardIndex];
							break;
						case 2:
							cardsSubmitted[currentPlayer-1] = deck.hand2[chosenCardIndex];
							break;
						case 3:
							cardsSubmitted[currentPlayer-1] = deck.hand3[chosenCardIndex];
							break;
						case 4:
							cardsSubmitted[currentPlayer-1] = deck.hand4[chosenCardIndex];
							break;
					}
					//See if card is valid
					try
					{
						if(cardsSubmitted[currentPlayer-1].getSuit() != leadSuit)
						{
							throw cardsSubmitted[currentPlayer-1].getSuit();
						}
						else
						{
							validity = true;
						}
					}
					catch(Suit a)
					{
						validity = false;
						cout << "Incorrect suit" << endl;
					}
					/*
					if()
					{
						validity = true;
					}
					else
					{
						validity = false;
						cout << "Not a valid card" << endl;
					}
					*/
				}
				
				//Delete card from hand
				Card a;
					switch(currentPlayer)
					{
						case 1:
							deck.hand1[chosenCardIndex] = a;
							break;
						case 2:
							deck.hand2[chosenCardIndex] = a;
							break;
						case 3:
							deck.hand3[chosenCardIndex] = a;
							break;
						case 4:
							deck.hand4[chosenCardIndex] = a;
							break;
					}
				
				//Analyze to see if card fits value
			}

			
			currentPlayer += 1;
			if (currentPlayer > 4)
			{
				currentPlayer = 1;
			}
		}
		
		//Find highest card 
		int largestCardIndex;
		int temp = cardsSubmitted[0].getNumber();
		for(int i = 0; i < 4; i ++)
		{
			if(cardsSubmitted[i].getNumber()>temp)
			{
				largestCardIndex = i;
				temp = cardsSubmitted[i].getNumber();
			}
		}
		
		//Winner takes all => add to Player score
		int points;
		for(int i = 0; i < 4; i++)
		{
			if(cardsSubmitted[i].getSuit() == hearts)
			{
				points += 1;
			}
			if(cardsSubmitted[i].getNumber() == 12 & cardsSubmitted[i].getSuit() == spades)
			{
				points += 13;
			}
		}
		players[largestCardIndex].setPoints(points);
		
		cout << endl;
	}
	
	
}







