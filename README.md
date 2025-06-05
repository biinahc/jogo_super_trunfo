# Super Trunfo de Países em C

Este projeto implementa uma versão simplificada do jogo Super Trunfo, comparando cartas de países com base em atributos escolhidos pelo usuário. O foco está na aplicação de conceitos de lógica de programação em C, como estruturas de decisão (`if-else`, `switch`), operadores ternários, funções e manipulação de entradas.

## Contexto Acadêmico

Este código foi desenvolvido como parte do desafio "Lógica Super Trunfo" da disciplina de **Introdução à Programação de Computadores**, do curso de **Ciência da Computação** da **Universidade Estácio de Sá**.

O objetivo do desafio é praticar a implementação de lógica de comparação, menus interativos e tratamento de dados em C.

---



## Como Compilar e Executar

Para compilar e executar este programa, você precisará de um compilador C instalado em seu sistema, como o GCC (GNU Compiler Collection), que é comum em sistemas Linux e macOS. No Windows, você pode usar o MinGW ou o WSL (Windows Subsystem for Linux).

**Passos:**

1.  **Salve o Código:** Certifique-se de que o código-fonte esteja salvo em um arquivo chamado `super_trunfo_final.c`.

2.  **Abra o Terminal:** Navegue até o diretório onde você salvou o arquivo usando o terminal (ou prompt de comando).

3.  **Compile o Código:** Execute o seguinte comando para compilar o programa:
    ```bash
    gcc super_trunfo_final.c -o super_trunfo_final
    ```
    *   `gcc`: Chama o compilador GCC.
    *   `super_trunfo_final.c`: É o nome do seu arquivo de código-fonte.
    *   `-o super_trunfo_final`: Especifica o nome do arquivo executável que será gerado (você pode escolher outro nome se preferir).
    *   **Observação:** Em alguns sistemas, pode ser necessário adicionar `-lm` ao final do comando (`gcc super_trunfo_final.c -o super_trunfo_final -lm`) se o código utilizasse funções da biblioteca matemática (`math.h`), embora não seja estritamente necessário para esta versão.

4.  **Execute o Programa:** Após a compilação bem-sucedida (nenhuma mensagem de erro), execute o programa com o comando:
    ```bash
    ./super_trunfo_final
    ```
    *   `./`: Indica que o executável está no diretório atual.

O programa iniciará e solicitará que você escolha os atributos para a comparação.

---



## Como Usar o Programa

Ao executar o programa, você será guiado por menus interativos para escolher os atributos de comparação.

**Atributos Disponíveis para Comparação:**

1.  **População:** Número total de habitantes do país.
2.  **Área (km²):** Extensão territorial do país em quilômetros quadrados.
3.  **PIB (USD):** Produto Interno Bruto nominal em dólares americanos (valor aproximado).
4.  **Pontos Turísticos:** Um índice ou número fictício representando a atratividade turística.
5.  **Densidade Demográfica (hab/km²):** Número de habitantes por quilômetro quadrado. **Regra Especial: O menor valor vence!**

**Fluxo de Interação:**

1.  **Escolha do Primeiro Atributo:** O programa exibirá a lista de atributos numerados. Digite o número correspondente ao primeiro atributo que deseja usar na comparação e pressione Enter.
2.  **Escolha do Segundo Atributo:** O programa exibirá novamente a lista, mas **sem** o atributo que você já escolheu. Digite o número correspondente ao segundo atributo e pressione Enter.
3.  **Resultado:** O programa exibirá uma comparação detalhada para cada atributo escolhido (mostrando os valores de cada país e o vencedor individual) e, em seguida, calculará a soma dos valores dos dois atributos para cada país, declarando o vencedor final da rodada (ou empate).

**Exemplo de Uso:**

```text
Bem-vindo ao Super Trunfo de Países!

--- Escolha um atributo para comparar: ---
1. Populacao
2. Area (km2)
3. PIB (USD)
4. Pontos Turisticos
5. Densidade Demografica (hab/km2) (Menor vence!)
Digite o numero da sua escolha: 1 <--- Usuário digita 1 (População)

--- Escolha o SEGUNDO atributo (diferente do primeiro): ---

--- Escolha um atributo para comparar: ---
2. Area (km2)
3. PIB (USD)
4. Pontos Turisticos
5. Densidade Demografica (hab/km2) (Menor vence!)
Digite o numero da sua escolha: 3 <--- Usuário digita 3 (PIB)

========================================
--- Comparacao Detalhada ---
Carta 1: Brasil
Carta 2: Japao

Atributo 1: Populacao
  Brasil: 214300000
  Japao: 125700000
  Resultado Atributo 1: Brasil

Atributo 2: PIB (USD)
  Brasil: 1920000000000.00
  Japao: 4231000000000.00
  Resultado Atributo 2: Japao

----------------------------------------
--- Resultado Final (Soma dos Atributos Escolhidos) ---
Soma Brasil (Populacao + PIB (USD)): 214300000.00  <-- Nota: Soma direta pode não ser ideal, mas segue o requisito
Soma Japao (Populacao + PIB (USD)): 125700000.00

========================================
>>> VENCEDOR DA RODADA: Brasil! <<<
========================================
```

*(Nota: Os valores de soma no exemplo acima são apenas ilustrativos da lógica de soma direta implementada, não refletindo uma comparação ponderada realista entre população e PIB)*

---

## Guia Passo a Passo: Baixando e Rodando o Jogo

Se você é novo na compilação de programas C, siga estes passos detalhados:

1.  **Obtenha o Código:**
    *   Se você recebeu o código como um arquivo (`super_trunfo_final.c`), salve-o em uma pasta de fácil acesso no seu computador (por exemplo, na sua Área de Trabalho ou em uma pasta chamada `ProjetosC`).
    *   Se o código estiver em uma plataforma como GitHub, você pode baixar o arquivo `.c` diretamente ou clonar o repositório.

2.  **Verifique/Instale um Compilador C (GCC):**
    *   **Linux (Ubuntu/Debian):** Abra o terminal e digite `gcc --version`. Se não estiver instalado, execute: `sudo apt update && sudo apt install build-essential`
    *   **macOS:** Abra o Terminal. Digite `gcc --version`. Se não estiver instalado, ele geralmente solicitará a instalação das Ferramentas de Linha de Comando do Xcode. Siga as instruções. Se não solicitar, instale o Xcode pela App Store e, em seguida, as ferramentas de linha de comando com `xcode-select --install` no terminal.
    *   **Windows:** A maneira mais fácil é instalar o [MinGW-w64](https://www.mingw-w64.org/) (que inclui o GCC) ou usar o [WSL (Windows Subsystem for Linux)](https://learn.microsoft.com/pt-br/windows/wsl/install) para ter um ambiente Linux dentro do Windows.

3.  **Abra o Terminal ou Prompt de Comando:**
    *   **Linux/macOS:** Procure por "Terminal".
    *   **Windows:** Procure por "Prompt de Comando" ou "PowerShell". Se estiver usando WSL, abra o terminal do WSL.

4.  **Navegue até a Pasta do Código:** Use o comando `cd` (change directory) para ir até a pasta onde você salvou o arquivo `super_trunfo_final.c`.
    *   Exemplo (se salvou na Área de Trabalho): `cd Desktop`
    *   Exemplo (se salvou em `ProjetosC` dentro dos seus Documentos): `cd Documents/ProjetosC` (os nomes exatos das pastas podem variar).
    *   Use o comando `ls` (Linux/macOS) ou `dir` (Windows) para listar os arquivos e confirmar que `super_trunfo_final.c` está lá.

5.  **Compile o Código:** No terminal, dentro da pasta correta, digite o comando de compilação:
    ```bash
    gcc super_trunfo_final.c -o super_trunfo_final
    ```
    *   Pressione Enter. Se tudo correr bem, nenhum erro será exibido e um novo arquivo (o executável `super_trunfo_final`) aparecerá na pasta.

6.  **Execute o Jogo:** Agora, digite o comando para rodar o programa:
    *   **Linux/macOS:**
        ```bash
        ./super_trunfo_final
        ```
    *   **Windows (Prompt de Comando/PowerShell):**
        ```bash
        super_trunfo_final.exe
        ```
        (O nome pode ser apenas `super_trunfo_final` dependendo de como o MinGW foi configurado).

7.  **Jogue!** Siga as instruções que aparecerão no terminal para escolher os atributos e ver quem vence a rodada.

---



## Contribuições e Melhorias

Este projeto foi desenvolvido como um exercício acadêmico, mas sinta-se à vontade para fazer um "fork" do código e propor melhorias!

Algumas ideias para evolução:

*   Implementar um sistema de pontuação mais elaborado em vez da soma direta.
*   Adicionar mais cartas (países) ou permitir cadastro pelo usuário.
*   Criar um modo de jogo com um baralho completo e turnos.
*   Melhorar a interface do usuário.

Se tiver sugestões ou encontrar bugs, por favor, abra uma "issue" (se o projeto estiver em uma plataforma como GitHub) ou entre em contato.

---

