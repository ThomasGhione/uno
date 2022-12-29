#include "uno.h"

// function needed to shuffle the deck
void shuffle (std::vector<card>& deck) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::shuffle(deck.begin(), deck.end(), e);
}

// this function print the last card on the "table"
void flastcard() {
    std::cout << "\nl'ultima carta giocata e': " << idcolor[lastcard.color] << " " << lastcard.number << "\n\n";
}

void mano(int tt) {
    std::cout << "Mano del giocatore numero " << tt+1 << ": ";
        for (unsigned int j=0; j<players_decks[tt].size(); j++) { //ciclo carte nelle mani
            std::cout << idcolor[players_decks[tt][j].color] << " " << players_decks[tt][j].number << " - ";
        } std::cout << "\n";
}

//far passare dentro void players e void checkvictory una variabile a che corrisponde al numero di giocatori
void players(int tt) {
    int cdrop = 0;
    int x=-3;
    std::cout << "Turno del giocatore numero " << tt+1 << "\nPer finire il turno digitare -1, per pescare digitare -2\n";
    flastcard();

    while (x != -1) {
        mano(tt);
        std::cout << "usare l'indice per dire quale carta vuoi giocare: ";
        std::cin >> x;
        
        if (players_decks[tt][x].color == lastcard.color || players_decks[tt][x].number == lastcard.number) {
            lastcard.color = players_decks[tt][x].color;
            lastcard.number = players_decks[tt][x].number;
            players_decks[tt].erase(players_decks[tt].begin()+x);
            std::cout << '\n';
        }
        if (x == -2) {  //da fixare col cdrop
            players_decks[tt].push_back(main_deck[main_deck.size()-1]);
            main_deck.pop_back();
            break;
        }
        if (cdrop == 0) {
            players_decks[tt].push_back(main_deck[main_deck.size()-1]);
            main_deck.pop_back();
            break; 
        }
    }
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
void checkvictory(int tt) {
    if (players_decks[tt].size()==0) {
        std::cout << "il giocatore " << tt << " ha vinto!";
        flag = true;
    }
}