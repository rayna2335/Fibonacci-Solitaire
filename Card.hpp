//
//  Card.hpp (interface) - what things are available


#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
using namespace std;

class Card
{
private:
    int top = 0;
    char rank;
    char suit;

public:
    Card();
    Card(char r, char s);
    void setCard(char r, char s);
    int getValue();
    void show();
};

#endif /* Card_hpp */
