// Rayna Maruyama
// CECS 325 - 02
// Prog 1 - Fibonacci Solitaire
// 02/14/2023

// I certify that this program is my owon original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.


#include "Deck.hpp"
#include <iostream>

using namespace std;

// All possible fibonacci number in a deck of cards. Max 360
bool isFibo(int n){
    int array[12] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233};
    for(int i = 0; i < 12; i++){
        if(n == array[i])
            return true;
    }
    return false;
}


int main() {
    Deck myDeck;
    Card card;
    int choice = 0;
    bool fiboNum = false;
    int games = 0;
    
    // constant for menu choices
    const int create = 1,
            shuffle = 2,
            display = 3,
            play = 4,
            win = 5,
            exit = 6;
    
    while (choice != exit){
        // Display the menu and get the choice
        cout << "Welcome to Fibonacci Solitaire" << endl;
        cout << "1) Create New Deck\n";
        cout << "2) Shuffle Deck\n";
        cout << "3) Display Deck\n";
        cout << "4) Play Fibo Solitaire\n";
        cout << "5) Win Fibo Solitaire\n";
        cout << "6) Exit\n";
        cin >> choice;
    
    
        //Responds to the users menu selection
        if(choice == create){
            myDeck.show();
            
            cout << endl;
            cout << "New deck has been created." << endl;
            cout << endl;
        }
    
        //shuffles the deck of cards
        else if (choice == shuffle){
            cout<< "shuffling.." << endl;
            myDeck.shuffle();
            cout << endl;
        }
    
        //displays the deck of cards
        else if (choice == display){
            myDeck.show();
            cout << endl;
            cout << endl;
        }
    
        //plays the Fibonacci Solitaire
        else if (choice == play){
            cout << endl;
            cout << "Playing Fibonacci Solitaire !!!" << endl << endl;
                            
            int sum = 0;
            int piles = 1;
            
            while(myDeck.isEmpty() != true){
                Card temp = myDeck.deal();
                temp.show();
                sum += temp.getValue();
                
                if(isFibo(sum) == true){
                    piles++;
                    fiboNum = true;
                    cout << "Fibo: " << sum << endl;
                    sum = 0;
                }
                else{
                    fiboNum = false;
                }
            }
            // show that user wins if the last pile is a fibo and display te number of times games were played.
            if(fiboNum == true){
                cout << "Winner in " << piles << " piles" << endl << endl;
                myDeck.resetDeck();
                myDeck.shuffle();
                games++;
                cout << "games played: " << games << endl;
            }
            // show that the last piles is not a fibo number and show how many piles were made.
            else{
                cout << "Last pile is NOT a fibo: " << sum << endl << endl;
                cout << "Loser in " << piles << " piles!" << endl << endl;
            }
            games++;
            myDeck.resetDeck();
            myDeck.shuffle();
        }
    
        
        
        // keep running until the user wins the game.
        else if (choice == win)
        {
            int sum = 0;
            int piles = 1;
            bool fiboNum = false;

                while(myDeck.isEmpty() != true){
                    Card temp = myDeck.deal();
                    temp.show();
                    sum += temp.getValue();
                    if (isFibo(sum) == true) {
                        piles++;
                        fiboNum = true;
                        cout << "Fibo: " << sum << endl;
                        sum = 0;
                    }
                }
                if (fiboNum == true) {
                    cout << "Fibo: " << sum << endl;
                    cout << "Winner in " << piles << " piles!" << endl << endl;
                    myDeck.resetDeck();
                    myDeck.shuffle();
                }
                else {
                    myDeck.resetDeck();
                    myDeck.shuffle();
                }

        }
        
        
        // exit the game
        else if (choice == exit)
        {
            cout << "Program ended..." << endl;
            return 0;
        }
        else
        {
            cout << "invalid" << endl;
            break;
        }
    }
    return 0;
}
