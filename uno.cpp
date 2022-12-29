#include "uno.h"

//! CURRENTLY TRANSLATING INTO ENGLISH & DOCUMENTING THE CODE

int main() {

    // TODO: finish implementing "special cards" (+2, +4, change color, change turn, block, etc)

    // refill the main_deck (main_deck is the cards deck where players are going to pick cards at the end of their turn)
    for (int color = 0; color <= 3; ++color) {
        for (int number = 0; number <= 9; ++number) {
            card testcard = { color, number };
            main_deck.push_back(testcard);
            main_deck.push_back(testcard);
        }
    }

    // shuffles the deck
    shuffle(main_deck);

    #ifdef DEBUG
        std::cout << "debug | prints each card after shuffling: ";
        for (unsigned int i = 0; i < deck.size(); ++i)
            std::cout << idcolor[deck[i].color] << ' ' << deck[i].number << " - ";
    #endif

    int numOfPlayers;                                                    // ask for the number of players in the game
    std::cout << "\nChoose the number of players: ";
    std::cin >> numOfPlayers;
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    players_decks.resize(numOfPlayers);                                  // resize our vector to the needed size

    for (int i = 0; i < numOfPlayers; ++i) {                             // gives 7 cards to each player (2 loops needed)
        for (int j = 0; j < startcards; ++j) {                          
            players_decks[i].push_back(main_deck[main_deck.size() - 1]); // put each card into the player's deck
            main_deck.pop_back();                                        // then we pop from the main deck
        }
    }

    // we pop 1 card from the main deck and put in the "table" since we need 1 card to start the game
    lastcard = main_deck.back();
    main_deck.pop_back();

    // main loop
    while (!flag) {
        int tt=0;
        for (; tt < numOfPlayers; ++tt) {
            players(tt);
            checkvictory(tt);
        }
        if (tt == numOfPlayers - 1)
            tt=0;
    }
}



// those are just placeholders:

// red = 0, green = 1, blue = 2, yellow = 3

//    //debug, stampa le carte totali nel deck:
//    std::cout << std::endl << "carte totali nel deck dopo aver dato la mano: " << deck.size() << std::endl << std::endl;
//    //debug, stampa tutte le carte, una per una, del mazzo:
//    for (unsigned int i=0; i<deck.size(); i++)
//        std::cout << idcolor[deck[i].color] << " " << deck[i].number << " - ";
