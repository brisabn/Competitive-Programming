#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool containsSubstring(const string &link, const string &zelda)
{
    // muda tudo pra minusculo
    string linkinho = link;
    transform(linkinho.begin(), linkinho.end(), linkinho.begin(), ::tolower);
    string zeldinha = zelda;
    transform(zeldinha.begin(), zeldinha.end(), zeldinha.begin(), ::tolower);

    size_t bolado = linkinho.find(zeldinha); // hmmm função útil
    // testar com regex dps (aulas do mário)
    return (bolado != string::npos);
}

int main()
{
    string hylian; // hehe
    getline(cin, hylian);

    string zelda = "zelda";
    cout << ((containsSubstring(hylian, zelda)) ? "Link Bolado" : "Link Tranquilo") << endl;

    return 0;
}
