// ConsoleApplication8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,pair<string, int>>> fillVector();

int main()
{
    vector<pair<int, pair<string, int>>> a = fillVector();
    vector<pair<int, pair<string, int>>>::iterator pos;

    for (pos = a.begin(); pos < a.end(); pos++)
    {
        std::cout << (*pos).first << " " << (*pos).second.first << " " << (*pos).second.second << "\n";
    }

}

std::vector<pair<int, pair<string, int>>> fillVector()
{
    vector<pair<int, pair<string, int>>> test;
    pair<int, pair<string, int>> p;

    for (int i=0, j = 0;  i <= 5;i++, j *= 2)
    {
        p.first = i;
        p.second.first = "haha";
        p.second.second = j;

        test.push_back(p);
    }

    return test;


}
