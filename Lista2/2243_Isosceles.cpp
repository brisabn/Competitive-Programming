#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int col;
    std::cin >> col;

    std::vector<int> colunas(col);
    for (int &coluna : colunas)
        std::cin >> coluna;

    std::vector<int> esq(col, 1);
    for (int i = 1; i < col; ++i)
        esq[i] = std::min(colunas[i], esq[i - 1] + 1);

    std::vector<int> dir(col, 1);
    for (int i = col - 2; i >= 0; --i)
        dir[i] = std::min(colunas[i], dir[i + 1] + 1);

    int triangulo = 0;
    for (int i = 0; i < col; ++i)
        triangulo = std::max(triangulo, std::min(esq[i], dir[i]));

    std::cout << triangulo << std::endl;

    return 0;
}
