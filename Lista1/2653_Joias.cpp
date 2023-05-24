#include <algorithm>
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    string joia;
    list<string> tesouro;

    while (cin >> joia)
    {
        bool found = (std::find(tesouro.begin(), tesouro.end(), joia) != tesouro.end());

        if (!tesouro.empty())
        {
            if (!found)
            {
                tesouro.push_back(joia);
            }
        }
        else
            tesouro.push_back(joia);
    }
    cout << tesouro.size() << endl;

    return 0;
}