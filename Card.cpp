#include "Deck.hpp"
#include "Card.hpp"
#include <string>
#include <iostream>
using namespace std;

//default card
Card::Card()
{
    // If Card is 1D the card is a default card
    rank = '1';
    suit = 'D';
}

//constructor to create a card (set rank \ suit)
Card::Card(char r, char s)
{
    rank = r;
    suit = s;
}

//set existing card to new values
void Card::setCard(char r, char s)
{
    Card::rank = r;
    Card::suit = s;
}

//returns the point value of the card
int Card::getValue()
{
    if (rank == 'A') {
        return 1;
    }
    else if (rank >= '2' && rank <= '9') {
        return rank - '0'; // character to a number.
    }
    else {
        return 10;
    }

}
//show rank and suit
void Card::show()
{
    string rankString;
        switch (rank) {
            case 'A':
                rankString = "A";
                break;
            case 'T':
                if (suit) {
                    rankString = "10";
                } else {
                    rankString = "T";
                }
                break;
            case 'J':
                if (suit) {
                    rankString = "10";
                } else {
                    rankString = "T";
                }
            case 'Q':
                rankString = "Q";
                break;
            case 'K':
                rankString = "K";
                break;
            default:
                rankString = rank;
                break;
        }

        if (suit) {
            cout << rankString << suit << ", ";
        } else {
            cout << rankString << endl;
        }
}
