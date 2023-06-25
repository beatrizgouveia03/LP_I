# Concordo - Clone do Discord

Concordo é um sistema inspirado no Discord, porém funciona apenas em modo texto, sem recursos de rede. O projeto foi implementado em C++ e utiliza os seguintes recursos:

- Herança e Classes abstratas
- Manipulação de Arquivos
- Standard Template Library (STL) com uso do vector

## Funcionalidades Implementadas

O sistema Concordo possui as seguintes entidades:

- Usuários: contém informações de uma conta no sistema.
- Servidores: com vários canais.
  - CanalTexto: herda de Canal e contém várias mensagens.
    - Mensagens: escritas por usuários, com data/hora.
  - CanalVoz: herda de Canal e guarda apenas a última mensagem postada.
  
O sistema é operado através de comandos de uma única linha, compostos por um comando seguido de parâmetros. Cada comando é interpretado, processado e gera uma saída de acordo com o resultado do processamento.

O projeto está dividido em três partes, cada uma com suas funcionalidades específicas.

### Parte 1

Na primeira parte do projeto, foram implementados os comandos relacionados a Usuários, Servidores e a criação de Canais. Nessa parte, ainda não é possível entrar em um canal, nem enviar/ler mensagens dentro dele.

### Comandos da Parte 1:

**A1 - Se não estiver logado (Assim que entra no sistema)**

- A1.1 - Sair do sistema: `quit`
- A1.2 - Criar usuário: `create-user <email> <senha_sem_espaços> <nome com espaços>`
- A1.3 - Entrar no sistema: `login <email> <senha>`

**A2 - Interações básicas com Servidores (Se estiver logado)**

- A2.1 - Desconectar do Concordo: `disconnect`
- A2.2 - Criar servidores: `create-server <nome>`
- A2.3 - Mudar a descrição do servidor: `set-server-desc <nome> "<descrição>"`
- A2.4 - Setar código de convite para o servidor: `set-server-invitecode <nome> <codigo>`
- A2.5 - Listar servidores: `list-servers`
- A2.6 - Remover servidor: `remove-server <nome>`
- A2.7 - Entrar em um servidor: `enter-server <nome>`
- A2.8 - Sair de um servidor: `leave-server`
- A2.9 - Listar pessoas no servidor: `list-participants`

## Pré-requisitos
Antes de começar, certifique-se de ter instalado algum dos seguintes componentes em seu sistema:

- Compilador C++ (como o g++ ou clang++)
- CMake (somente se estiver utilizando o CMake para compilar)

## Compilação e execução usando CMake

1. Acesse o diretório raiz do projeto, onde está localizado o arquivo CMakeLists.txt.
2. Crie um diretório de compilação (por exemplo, "build") e acesse-o:
   ```
   mkdir build
   cd build
   ```
3. Gere os arquivos de configuração do CMake dentro do diretório de compilação:
   ```
   cmake ..
   ```
4. Execute o comando make para compilar o programa:
   ```
   make
   ```
   Isso irá compilar o código fonte e gerar o arquivo executável.
   
5. Após a compilação bem-sucedida, a partir do diretório de compilação, execute o seguinte comando no terminal para iniciar o programa Concordo:
   ```
   ./concordo
   ```
   Você poderá interagir com o programa através dos comandos disponíveis.

## Compilação e execução com Compilador C++

Se você não estiver utilizando o CMake para compilar o programa Concordo e estiver lidando diretamente com os arquivos de origem, siga as etapas abaixo:

1. Acesse o diretório raiz do projeto, onde estão localizados os arquivos de origem.
2. Compile o código fonte utilizando o compilador C++. Suponha que o arquivo principal do programa seja `main.cpp`. Execute o seguinte comando no terminal:
   ```
   g++ main.cpp user.cpp server.cpp system.cpp message.cpp channel.cpp channelText.cpp channelVoice.cpp -o concordo
   ```
   Isso irá compilar o código fonte e gerar um arquivo executável chamado `concordo`.

3. Após a compilação bem-sucedida, a partir do diretório onde o arquivo executável `concordo` foi gerado, execute o seguinte comando no terminal:
   ```
   ./concordo
   ```
   Isso iniciará a execução do programa Concordo, e você poderá interagir com ele através dos comandos disponíveis.

Certifique-se de seguir a documentação fornecida com os detalhes de todos os comandos disponíveis e sua sintaxe correta para realizar as operações desejadas dentro do programa Concordo. 

## Testando o Executável com o Arquivo de Teste

1. Certifique-se de ter compilado o programa Concordo conforme as instruções mencionadas anteriormente, seja utilizando o CMake ou compilando diretamente sem o CMake.

2. No diretório onde o executável `concordo` foi gerado, verifique se há um arquivo chamado `command.in`. Esse arquivo contém uma série de comandos que podem ser usados para testar o programa.

3. Abra um terminal e navegue até o diretório onde o executável `concordo` está localizado.

4. Execute o seguinte comando para redirecionar a entrada do arquivo `command.in` para o programa Concordo:
   ```
   ./concordo < ../command.in
   ```
   Isso redirecionará o conteúdo do arquivo `command.in` como entrada para o programa Concordo. O programa executará os comandos presentes no arquivo e exibirá os resultados correspondentes no terminal.

5. Observe a saída gerada pelo programa Concordo e verifique se está correta de acordo com os comandos presentes no arquivo `command.in`.

O arquivo `command.in` pode ser personalizado de acordo com os testes que você deseja realizar. Cada linha do arquivo representa um comando que pode ser reconhecido pelo programa Concordo.

Certifique-se de utilizar a sintaxe correta dos comandos e seguir a documentação fornecida com o programa Concordo para entender a estrutura e os detalhes de cada comando suportado.

Lembrando que o arquivo `command.in` é apenas uma opção conveniente para automatizar os testes e não é estritamente necessário. Você também pode interagir com o programa diretamente no terminal, fornecendo comandos manualmente.