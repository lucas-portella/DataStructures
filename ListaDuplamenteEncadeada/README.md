# Implementação de Lista Duplamente Encadeada Genérica em C
Baseado na implementação apresentada no livro _Dominando Algoritmos com C_, de Kyle Loudon.
---

## dlist.h
O arquivo `dlist.h` contém a interface para o uso da lista duplamente encadeada, e `dlist.c` contém
sua implementação.

Esta implementação permite que qualquer tipo de dado seja guardado na Lista Duplamente Encadeada.
Para dados alocados dinâmicamente, o usuário deve fornecer um ponteiro para uma função responsável 
por liberar a memória utilizada, ao chamar a função `dlist_init ( void (*destroy) (void *data) )`. 
Caso os dados guardados na lista encadeada sejam alocados estaticamente, deve-se passar o parâmetro 
*NULL* na chamada da função acima. 

Para mais informações sobre a utilização deste módulo, consultar o arquivo `dlist.h`.
---

## testa_dlist.c
Neste diretório consta também o arquivo `testa_dlist.c` que contém um teste para as funções básicas
da Estrutura de Dados de Lista Duplamente Encadeada. Você pode adaptar este arquivo para testar a lista
utilizando os tipos de dados da sua escolha.

No cabeçalho deste arquivo, existem dois `define` que devem ser alterados a depender do seu sistema operacional.
Caso esteja em um ambiente Unix-like, seja Linux ou Macintosh, não precisa fazer nada, pois o arquivo já está
configurado para esta opção.

Caso esteja operando em um sistema operacional Windows, altere as configurações como especificado no cabeçalho 
do arquivo `testa_dlist.c`.
---

## makefile
Também consta neste diretório um arquivo `makefile`, constando instruções para compilação dos arquivos `dlist.c`
e `testa_dlist.c`. Caso possua a ferramenta GNU make instalada, basta digitar o comando `make all`
estando neste diretório para realizar a compilação automatica. 
Caso contrário, certifique-se de compilar o arquivo `dlist.c` e linká-lo para compilar o arquivo `testa_dlist.c`.
