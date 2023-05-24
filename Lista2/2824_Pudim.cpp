#include <iostream>
using namespace std;

// #include <fstream>
// std::ifstream inputFile("input.txt");
// lembrete: qualquer string maior que 4095 tem que usar input -_-
const int MAX = 5005;
int dp[MAX][MAX];

int pudimLCS(const std::string &str1, const std::string &str2)
{
    int tam1 = str1.length(), tam2 = str2.length();
    // caso base
    dp[0][0] = 0;
    // bottom up
    for (int i = 0; i < tam1; i++)
    {
        for (int j = 0; j < tam2; j++)
        {
            if (str1[i] == str2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    return dp[tam1][tam2];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str1, str2;
    std::getline(cin, str1);
    std::getline(cin, str2);

    cout << pudimLCS(str1, str2) << std::endl;

    return 0;
}
