#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>


//id color
const int red = 0;
const int green = 1;
const int blue = 2;
const int yellow = 3;
const int special = 4;
const std::string idcolor[5] = {"red", "green", "blue", "yellow", "special"};
const int plustwo = 10;
const int plusfour = 11;
const int block = 12;
const int reverse = 13;
const int changecolor = 14;
const std::string idnumber[15] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+2", "+4", "block", "reverse", "changecolor"};
//costante carte iniziali
const int startcards = 7; 
bool flag = false;

//struct card
struct card {
    int color;
    int number;
}; // a card is made of a color and a number, each color has an ID which is an int


std::vector<card> main_deck;                         
std::vector <std::vector <card>> players_decks; // vector di giocatori contenente vector di carte (mani)
card lastcard;



void shuffle (std::vector<card> &);
void flastcard ();
void mano (int);
void players (int);
void checkvictory (int);