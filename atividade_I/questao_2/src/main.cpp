#include "utilities.cpp"

int main()
{
    Zoo z1 = configuraçãoInicial();
    std::string entrada;
    bool fim = false;
    int acao;

    while (!fim)
    {
        std::cout << "Escolha uma ação: \n 1-Cadastrar animal\n 2-Pesquisar animais por espécie\n 3-Retirar animal por idade\n 4-Listar animais\n 5-Sair\n";
        getline(std::cin, entrada);

        std::istringstream ss(entrada);
        ss >> acao;

        switch (acao)
        {
        case 1:
            adicionarAnimal(&z1);
            break;
        case 2:
            pesquisarEspecie(z1);
            break;
        case 3:
            removerIdade(&z1);
            break;
        case 4:
            listarAnimais(z1);
            break;
        case 5:
        default:
            fim = true;
            break;
        }
    }

    return 0;
}