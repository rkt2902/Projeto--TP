/**
* Author: Henrique Azevedo
* Email: henrique.aazevedo29@gmail.com
* Date: 19-03-2022
* Desc: Jobs
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"



bool ExisteMachine(Machine* h, int machineId) {
	if (h == NULL) return false;
	Machine* aux = h;
	while (aux != NULL) {
		if (aux->machineId == machineId)
			return true;
		aux = aux->next;
	}
	return false;
}

Machine* newMachine(int machineId, int time) {

	Machine* new = (Machine*)malloc(sizeof(Machine));

	if (new == NULL) // se não houver memória para alocar
	{
		return NULL;
	}

	new->machineId = machineId;
	new->time = time;
	new->next = NULL;

	return new;
}


Machine* InsertMachineOnEnd(Machine* h, Machine* new) {

	if (ExisteMachine(h, new->machineId)) return h;

	if (h == NULL) {
		h = new;
	}
	else {
		Machine* aux = h;
		while (aux->next != NULL) {
			aux = aux->next;
		}

		aux->next = new;
	}
	return h;

}


Job* InsertMachineOnOperation(Job* h, Machine* c,  int id, int order) {
	
	if (h == NULL) return NULL;
	if (c == NULL) return h;

	Job* aux = SearchJob(h, id);
	if (aux && aux->operation->order == order) {
		aux->operation->Machine = InsertMachineOnEnd(aux->operation->Machine, c);
	}
	return NULL;
}





Job* RemoveMachine(Job* h, Machine* c, int id, int machineId) {


	if (h == NULL) return NULL;			//Lista vazia


	if (h->operation->Machine->machineId == machineId) {		//remove no inicio da lista
		Operation* aux = h->operation;
		h->operation = h->operation->next;
		free(aux);
	}
	else
	{
		Machine* aux = h->operation->Machine;
		Machine* auxAnt = aux;
		while (aux && aux->machineId != machineId) {	//procura para revover
			auxAnt = aux;
			aux = aux->next;
		}
		if (aux != NULL) {					//se encontrou, remove
			auxAnt->next = aux->next;
			free(aux);
		}
	}
	return h;


}



