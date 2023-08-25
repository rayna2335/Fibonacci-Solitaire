#ifndef Deck_hpp
#define Deck_hpp
#include "Card.hpp"
#include <stdio.h>
using namespace std;

class Deck
{
private:
    Card cardDeck[52];
    int numCards;
    int top = 0;


public:
    Deck();
    Card deal();
    void resetDeck();
    void shuffle();
    bool isEmpty();
    void show();
    
};

#endif /* Deck_hpp */
