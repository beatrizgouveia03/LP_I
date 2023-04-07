#include <vector>
#include <string>
#include <sstream>
#include <iostream>

bool existeCombinacao(std::vector<int> base, int target)
{
    int tam = base.size();
    std::vector<int> elementos;

    for (int i = 1; i < (1 << tam); ++i)
    {
        int soma = 0;
        elementos.clear();

        for (int j = 0; j < tam; ++j)
        {
            if (i & (1 << j))
            {
                soma += base[j];
                elementos.push_back(base[j]);
            }
        }
        if (soma == target)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    std::vector<int> v;
    std::string entry;
    int target, num;

    std::cout << "Informe o vetor completo (separado por espaços):\n";
    getline(std::cin, entry);
    std::istringstream ss(entry);

    while (ss >> num)
    {
        v.push_back(num);
    }

    std::cout << "Informe o valor a ser obtido:\n";
    std::cin >> target;

    if (existeCombinacao(v, target))
    {
        std::cout << "Sim\n";
    }
    else
    {
        std::cout << "Não\n";
    }
}