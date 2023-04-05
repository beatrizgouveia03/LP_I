#include <iostream>
#include <sstream>
#include <Pessoa.h>
#include <vector>

int main() {
    std::vector<Pessoa> pessoas;
    std::string entrada;
    bool fim = false;
    int acao;

    pessoas = configuracaoInicial();

    while(!fim) {
        std::cout << "Escolha uma acao: \n 1-Cadastrar nova pessoa\n 2-Obter info de uma pessoa\n 3-Comparar pessoas\n 4-Imprimir pessoa\n 5-Sair\n";
        getline(std::cin, entrada);

        std::istringstream ss(entrada);
        ss >> acao;

        switch (acao)
        {
        case 1:
            cadastrarPessoa(&pessoas);
            break;
        case 2:
            obterInfo(pessoas);
            break;
        case 3: 
            compararPessoas(pessoas);
            break;
        case 4: 
            imprimirPessoa(pessoas);
            break;
        case 5:        
        default:
            fim = true;
            break;
        }
    }


    return 0;
}