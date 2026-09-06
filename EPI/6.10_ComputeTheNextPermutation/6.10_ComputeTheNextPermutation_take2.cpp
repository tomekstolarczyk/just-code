#include <vector>
#include <algorithm> // std::reverse
#include <iostream>

std::vector<int> permute(std::vector<int> &p)
{

    // 1 znajdujemy pierwsza liczbe idac od tylu ktora jest mniejsza niz jej poprzednik
    int i = p.size() - 2;
    while (i >= 0 && p[i] > p[i + 1])
    {
        i--;
    }

    // 2 edge case - max mozliwa permuatcja
    if (i == -1)
    {
        return {};
    }

    // 3 znajdujemy w ogonie najmniejsza liczbe pod swapa - taka ktora jest najmniejsza ale wieksza niz pivot
    // przy czym wiemy ze ogon jest w porzadku rosnacym
    int j = p.size() - 1;
    while (p[i] >= p[j])
    {
        j--;
    }

    // 4 dokonujemy swapa
    std::swap(p[i], p[j]);

    // 5 rev tail
    std::reverse(p.begin() + i + 1, p.end());

    // 6 the returnes
    return p;
}

int main()
{
    std::vector<int> p = {1, 0, 3, 2};

    std::vector<int> result = permute(p);

    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << (i + 1 < result.size() ? ", " : "");
    }
    std::cout << "]\n";

    return 0;
}