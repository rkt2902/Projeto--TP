
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

Operation* newOperation(int order, Machine* h) {

	Operation* new = (Operation*)malloc(sizeof(Operation));

	if (new == NULL) // se não houver memória para alocar
	{
		return NULL;
	}

	new->order = order;
	new->Machine = h;
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
			aux = aux->next;
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
		numoperations++;
	}
	return NULL;
}

Job* RemoveOperation(Job* h, Operation* c, int id, int order) {
	
	
	if (h == NULL) return NULL;			//Lista vazia


	if (h->operation->order == order ) {		//remove no inicio da lista
		Operation* aux = h->operation;
		h->operation = h->operation->next;
		numoperations--;
		free(aux);
	}
	else
	{
		Operation* aux = h->operation;
		Operation* auxAnt = aux;
		while (aux && aux->order != order) {	//procura para revover
			auxAnt = aux;
			aux = aux->next;
			
		}
		if (aux != NULL) {					//se encontrou, remove
			auxAnt->next = aux->next;
			numoperations--;
			free(aux);
		}
	}
	return h;


}

Operation* SearchOperation(Operation* h, int order) {
	if (h == NULL) return NULL;		//lista vazia
	else
	{
		Operation* aux = h;
		while (aux != NULL) {
			if (aux->order == order) {
				return (aux);		//encontrei
			}
			aux = aux->next;
		}
		return NULL;
	}
}