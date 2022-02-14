#include "TupleTest.h"

int main()
{
    vector<boek> boekenlijst = leesBoekGegevens();
    cout << printBoekenLijst(boekenlijst);
}

string printBoekenLijst(vector<boek> b)
{
    ostringstream os;
    string titel, auteur;
    int jaar,genre;
    int index=1;

    for ( boek tuple : b)
    {
        std::tie(titel, auteur, jaar, genre) = tuple;
        os << "boek nummer : " << index << endl;
        os << "================================" << endl;
        os << titel << endl;
        os << auteur << endl;
        os << jaar << endl;
        os << genre << endl;
        index++;
    }

    return os.str();
}

string leesString(string msg)
{
    string tekstinvoer;
    cout << msg << "  ";
    getline(cin, tekstinvoer);
    return tekstinvoer;
}

int leesInt(string msg, string errmsg, int min, int max)
{
    int getalinvoer=0;
    bool inperr = true;
    cout << msg << "[" << min << " , " << max << "]  :";
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

    string titel, auteur;
    int jaar,genre;

    for (int boeknummer = 1; boeknummer <= AANTALBOEKEN; boeknummer++)
    {
        titel = leesString("Titel : ");
        auteur = leesString("Auteur : ");
        jaar = leesInt("Jaar van uitgave ", "Geef een geldige waarde in!\n", MIN_JAAR, MAX_JAAR);
        genre = leesInt("Boekcategorie ", "Geef een geldige waarde in!\n", MIN_CATEGORIE, MAX_CATEGORIE);

        //tuple samenstellen
        boek eenboek (titel, auteur, jaar, genre);

        //tuple opslaan in vector
        boeken.push_back(eenboek);
    }

    return boeken;
}
