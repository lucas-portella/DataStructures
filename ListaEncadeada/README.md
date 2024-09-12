# Implementação de Lista Encadeada Genérica em C
---
Baseado na implementação apresentada no livro _Dominando Algoritmos com C_, de Kyle Loudon.

Esta implementação permite que qualquer tipo de dado seja guardado na Lista Encadeada. Para dados alocados
dinâmicamente, o usuário deve fornecer um ponteiro para uma função responsável por liberar a memória utilizada,
ao chamar a função `list_init ( void (*destroy) (void *data) )`. Caso os dados guardados na lista encadeada sejam
alocados estaticamente, deve-se passar o parâmetro *NULL* na chamada da função acima. Para mais informações sobre
a utilização deste módulo, consultar o arquivo `list.h`.

Também consta neste diretório um arquivo `makefile`, constando instruções para compilação dos arquivos `list.c`
e `testa_lista.c`. Caso possua a ferramenta GNUmake instalada, digite o comando `make all` estando neste diretório
para realizar a compilação automatizada. Caso contrário, certifique-se de compilar o arquivo `list.c` e linká-lo
para compilar o arquivo `testa_lista.c`.
