
/**
* Author: Henrique Azevedo
* Email: henrique.aazevedo29@gmail.com
* Date: 19-03-2022
* Desc: listas
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"





bool ExisteOperation(Operation* h, int order) {
	if (h == NULL) return false;
	Operation* aux = h;
	while (aux != NULL) {
		if (aux->order == order)
			return true;
		aux = aux->next;
	}
	return false;
}

Operation* newOperation(int order) {

	Operation* new = (Operation*)malloc(sizeof(Operation));

	if (new == NULL) // se não houver memória para alocar
	{
		return NULL;
	}

	new->order = order;
	new->Machine = NULL;
	new->next = NULL;

	return new;
}

Operation* InsertOperationEnd(Operation* h, Operation* new)
{
	if (ExisteOperation(h, new->order)) return h;

	if (h == NULL) {
		h = new;
	}
	else {
		Operation* aux = h;
		while (aux->next != NULL) {
			new->next = aux;
		}

		aux->next = new;
	}
	return h;
}



Job* InsertOperationOnJob(Job* h, Operation* c, int id) {
	if (h == NULL) return NULL;
	if (c == NULL) return h;

	Job* aux = SearchJob(h, id);
	if (aux) {
		aux->operation = InsertOperationEnd(aux->operation, c);
	}
	return NULL;
}






Operation* RemoveOperation(Operation* h, int order) {

	if (h == NULL) return NULL;			//Lista vazia
	if (!ExisteOperation(h, order)) return h;	//se não existe

	Operation* aux = h;
	Operation* auxAnt = NULL;

	//localizar registo a eliminar
	while (aux && aux->order != order) {
		auxAnt = aux;
		aux = aux->next;
	}
	if (auxAnt == NULL) {	//Eliminar à cabeça
		h = h->next;
		free(aux);
	}
	else					//Elimiar no meio
	{
		auxAnt->next = aux->next;
		free(aux);
	}
	return h;
}



