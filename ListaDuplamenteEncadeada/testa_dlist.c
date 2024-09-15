#include <stdio.h>
#include "dlist.h"

/* caso esteja em um sistema operacional unix-like,
	mantenha o define abaixo em 1. Caso contrario,
	defina-o	com 0. 
*/
#define UNIX_OS 1

/* caso esteja em um sistema operacional windows
	mantenha o define abaixo em 1. Caso contrario, 
	defina-o	com 0. 
*/
#define WINDOWS_OS 0

void imprime_dlist ( DList *dlist ) {
	int i = 0;
	DListElem *elem;

	if (!dlist)
		return;

	printf("Impressão da lista sentido HEAD->TAIL\n");
	
	elem = dlist_head(dlist);

	if (!elem)
		printf("Lista vazia!\n");
		
	while (elem) {
		int *data = (int*) dlist_data (elem);
		printf("Nodo %d : %d\n", i++, *data);	
		elem = dlist_next (elem);
	}
	
	printf("Total: %d nodos na lista.\n", i);
	printf("Quantidade de nodos descritos na lista: %d\n\n", dlist->size);
	return;	
}

void imprime_dlist_contrario ( DList *dlist ) {
	int i = 0;
	int tam = dlist_size (dlist);
	DListElem *elem;

	if (!dlist)
		return;

	printf("Impressão da lista sentido TAIL->HEAD\n");
	
	elem = dlist_tail(dlist);

	if (!elem)
		printf("Lista vazia!\n");

	while (elem) {
		int *data = (int*) dlist_data (elem);
		printf("Nodo %d : %d\n", tam - 1 - i, *data);	
		i++;
		elem = dlist_prev (elem);
	}
	
	printf("Total: %d nodos na lista.\n", i);
	printf("Quantidade de nodos descritos na lista: %d\n\n", dlist->size);
	return;	
}

void pausa_teste () {
	char c;
	printf("\n\nDIGITE ENTER PARA CONTINUAR\n\n");
	scanf("%c", &c);
	
	if (WINDOWS_OS)
		system("cls");
	else if (UNIX_OS)
		system("clear");
}

DListElem *busca_elemento ( DList *dlist, int chave ) {
	DListElem *elem;

	if (!dlist)
		return NULL;

	elem = dlist_head(dlist);
	while (elem) {
		int *data = (int*) dlist_data(elem);
		if (*data == chave)
			return elem;
		elem = dlist_next(elem);
		
	}
	
	return elem;
}

int main () {
	DList *dlist = dlist_init (NULL);
	DListElem *elem = NULL;
	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int valor_nodo;


	printf("TESTE 1: inserção de 0 a 9 no INICIO da lista:\n");
	for (int i = 0; i < 10; i++) 
		dlist_ins_next (dlist, NULL, &v[i]);
	imprime_dlist (dlist);
	imprime_dlist_contrario (dlist);
	pausa_teste();
	
	printf("TESTE 2: caminho na lista sentido HEAD->TAIL\n");
	printf("Deve imprimir os numeros de 9 a 0:\n");
	elem = dlist_head(dlist);
	while (elem) {
		int *data = (int*) dlist_data (elem);
		printf("%d ", *data);
		elem = dlist_next(elem);
	}
	printf("\n");
	pausa_teste();
	
	printf("TESTE 3: remoção de todos os elementos um por um a partir do FINAL da lista\n");
	for (int i = 0; i < 10; i++) {
		int* removido;
		dlist_remove (dlist, dlist_head(dlist), (void**) &removido);
		printf("Dado %d removido do inicio da lista\n", *removido);
		printf("A lista deve conter %d elementos\n", 9 - i);
		imprime_dlist(dlist);
	}
	pausa_teste();

	printf("TESTE 4: inserção de 0 a 9 no FINAL da lista:\n");
	for (int i = 0; i < 10; i++) 
		dlist_ins_prev (dlist, NULL, &v[i]);
	imprime_dlist (dlist);
	imprime_dlist_contrario (dlist);
	pausa_teste();

	printf("TESTE 5: caminho na lista sentido TAIL->HEAD\n");
	printf("Deve imprimir os numeros de 9 a 0:\n");
	elem = dlist_tail(dlist);
	while (elem) {
		int *data = (int*) dlist_data (elem);
		printf("%d ", *data);
		elem = dlist_prev(elem);
	}
	printf("\n");
	pausa_teste();

	printf("TESTE 6: remoção de todos os elementos um por um a partir do FINAL da lista\n");
	for (int i = 0; i < 10; i++) {
		int* removido;
		dlist_remove (dlist, dlist_tail(dlist), (void**) &removido);
		printf("Dado %d removido do final da lista\n", *removido);
		printf("A lista deve conter %d elementos\n", 9 - i);
		imprime_dlist(dlist);
	}
	pausa_teste();

	/* insercao no final da lista de 0 a 9 para o teste 7*/ 
	for (int i = 0; i < 10; i++) 
		dlist_ins_prev (dlist, NULL, &v[i]);

	printf("TESTE 7: remoção ITERATIVA dos elementos\n");
	printf("Selecione o valor do dado cujo nodo você deseja excluir, ou -1 para encerrar o teste.\n");
	imprime_dlist(dlist);
	printf("Digite o valor a se retirar da lista: ");
	scanf("%d", &valor_nodo);
	while (valor_nodo != -1 && dlist_size (dlist) != 0) {
		int *data;
		elem = busca_elemento (dlist, valor_nodo);
		if (elem) {
			dlist_remove(dlist, elem, (void**) &data);
			printf("Nodo com chave %d removido!", *data);
		}
		else 
			printf("Elemento não encontrado na lista.\n");
		pausa_teste();
		imprime_dlist(dlist);
		if (dlist_size(dlist) != 0) {
			printf("Digite o valor a se retirar da lista: ");
			scanf("%d", &valor_nodo);
		}
	}
	pausa_teste();
	printf("Teste Finalizado!\n");

	dlist_destroy (dlist);
	return 0;
}
