#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

#define MIN_JAAR 1600
#define MAX_JAAR 3000
#define MIN_CATEGORIE 1
#define MAX_CATEGORIE 10
#define AANTALBOEKEN 5

#define  titelEnAuteur first   
#define titel first
#define auteur second

#define  jaarEnType second   
#define jaar first
#define genre second

typedef pair<string, string> titel_auteur;
typedef pair<int, int> jaar_genre;
typedef pair <titel_auteur, jaar_genre> boek;

vector<boek> leesBoekGegevens();
int leesInt(string msg, string errmsg, int min, int max);
string leesString(string);
string printBoekenLijst(vector<boek>);

int main()
{
    vector<boek> boekenlijst = leesBoekGegevens();
    cout << printBoekenLijst(boekenlijst);
}

string printBoekenLijst(vector<boek> b)
{
    vector<boek>::iterator pos;
    ostringstream os;
    int index;

    for (pos = b.begin(), index=1; pos < b.end(); pos++,index++)
    {
        os << "boek nummer : " << index << "\n";
        os << (*pos).titelEnAuteur.titel << '\n';
        os << (*pos).titelEnAuteur.auteur << '\n';
        os << (*pos).jaarEnType.jaar << '\n';
        os << (*pos).jaarEnType.genre << '\n';
    }

    return os.str();
}

string leesString(string msg)
{
    string tekstinvoer;
    cout << msg << "  ";
    getline(cin,tekstinvoer);
    return tekstinvoer;
}


int leesInt(string msg,string errmsg,int min, int max)
{
    int getalinvoer;
    bool inperr = true;
    cout << msg << "["<<min<<" , " << max <<"]  :";
    do
    {
        cin >> getalinvoer;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errmsg << "\n";
            cout << msg << "[" << min << " , " << max << "]  :";
        }
        else
        {
            if ((min <= getalinvoer) & (getalinvoer <= max))
            {
                inperr = false;
            }
            else
            {
                cout << "waarde ligt buiten de grenzen \n";
            }
        }
    } while (inperr);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return getalinvoer;
}

vector<boek> leesBoekGegevens()
{
    vector<boek> boeken;
    boek eenboek;
  
    for (int boeknummer = 1; boeknummer < AANTALBOEKEN; boeknummer++)
    {
        eenboek.titelEnAuteur.titel=leesString("Titel : ");
        eenboek.titelEnAuteur.auteur=leesString("Auteur : ");
        eenboek.jaarEnType.jaar=leesInt("Jaar van uitgave ", "Geef een geldige waarde in!\n", MIN_JAAR, MAX_JAAR);
        eenboek.jaarEnType.genre = leesInt("Boekcategorie ", "Geef een geldige waarde in!\n", MIN_CATEGORIE, MAX_CATEGORIE);
        boeken.push_back(eenboek);
    }

    return boeken;
}
