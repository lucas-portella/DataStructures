#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void imprime_lista (List *list) {

	ListElem *elem = list_head(list);

	printf("Imprimindo lista:\n");
	while (elem) {
		int *data = list_data(elem);
		printf("%d ", *data);
		elem = list_next(elem);
	}
	printf("\n");
}

int main () {
	List *list = list_init (NULL);
	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int tam = 10;

	printf("Inserindo na lista:\n");
	printf("Inserindo elemento %d .. \n", v[0]);
	list_ins_next(list, NULL, v);
	
	ListElem *elem = list_head(list);
	for (int i = 1; i < tam; i++) {
		printf("Inserindo elemento %d .. \n", v[i]);
		list_ins_next(list, elem, &(v[i]));
		elem = list_next(elem);
	}

	imprime_lista (list);	
	list_destroy (list);

	return 0;
}
