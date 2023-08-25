
#include "Card.hpp"
#include "Deck.hpp"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

//construct -> create 52 cards (AceofSpade, hearts, diamond, and clubs)
Deck::Deck()
{
    char rank[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char suit[] = {'S', 'H', 'D', 'C'};

    int current_rank = 0;
    int current_suit = 0;
    
    for(int i = 0; i < 51; i++){
      cardDeck[i].setCard(rank[current_rank], suit[current_suit]);
      current_rank++;
      if (current_rank == 13){
        current_suit+= 1;
        current_rank = 0;
        }
    }
    top = 0;
}


// reset the deck
void Deck::resetDeck()
{
    char rank[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char suit[] = {'S', 'H', 'D', 'C'};

    int current_rank = 0;
    int current_suit = 0;
    
    for(int i = 0; i < 51; i++){
      cardDeck[i].setCard(rank[current_rank], suit[current_suit]);
      current_rank++;
      if (current_rank == 13){
        current_suit+= 1;
        current_rank = 0;
        }
    }
    top = 0;
   
}

Card Deck :: deal()
{
    if(top < 52){
        int temp = top;
        top++;
        return cardDeck[temp];
    }
    else{
        top = 0;
        shuffle();
        int temp = top;
        top++;
        return cardDeck[temp];
    }
}



//shuffles the card
void Deck::shuffle(){
    srand(time(NULL));

    for (int i = 0; i < 52; i++)
    {
        int x = rand() % 52;
        Card temp = cardDeck[i];
        cardDeck[i] = cardDeck[x];
        cardDeck[x] = temp;
    }
}


//true if Deck is empty, False if not
bool Deck::isEmpty(){
    if(top != 51)
        return false;
    else
        return true;
}

//show all cards (13 columns,4 row)
void Deck::show(){
    int current_column = 0;
    
    for (int i = 0; i < 52; i++)
    {
        if(current_column == 13){
          cout << "" << endl;
          current_column = 0;
        }
        cardDeck[i].show();
        current_column += 1;
    }

    
}
