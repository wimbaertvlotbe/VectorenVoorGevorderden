#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include <tuple>

#define MIN_JAAR 0
#define MAX_JAAR 3000
#define MIN_CATEGORIE 1
#define MAX_CATEGORIE 10
#define AANTALBOEKEN 2

using namespace std;


//boekgegevens opslaan in tuple : titel, auteur, jaartal, genre
typedef tuple<string, string, int, int> boek;

//functieprototypes
vector<boek> leesBoekGegevens(void);
int leesInt(string msg, string errmsg, int min, int max);
string leesString(string);
string printBoekenLijst(vector<boek>); 
