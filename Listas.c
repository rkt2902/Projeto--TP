/**
* Author: Henrique Azevedo
* Email: henrique.aazevedo29@gmail.com
* Date: 19-03-2022
* Desc: listas dos jobs
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"

int readjobs(int id) {
	
	FILE* ptr = fopen("jobs.txt", "r");

	if (ptr == NULL) {
		printf("no such file.");
		return 0;
	}

	fscanf(ptr, "%d", &id);
	printf("%d", id);
	return id;
	
}


#pragma region jobs

bool ExisteJob(Job* h, int id) {
	if (h == NULL) return false;
	Job* aux = h;
	while (aux != NULL) {
		if (aux->id == id)
			return true;
		aux = aux->next;
	}
	return false;
}

Job* newJob(int id) {

	Job* new = (Job*)malloc(sizeof(Job));

	if (new == NULL) // se não houver memória para alocar
	{
		return NULL;
	}

	new->id, id;
	new->operations = NULL;
	new->next = NULL;

	return new;
}



Job* InsertJob(Job* h, Job* new)
{
	if (ExisteJob(h, new->id)) return h;

	if (h == NULL){
		h = new;
	}
	else {
		Job* aux = h;
		while (aux->next != NULL) {
			new->next = aux;
		}
		
		aux->next = new;
	}
	return h;
}

#pragma endregion


#pragma region operations

bool ExisteOperation(Op* h, int order) {
	if (h == NULL) return false;
	Op* aux = h;
	while (aux != NULL) {
		if (aux->order == order)
			return true;
		aux = aux->next;
	}
	return false;
}

Op* newOperation(int order) {

	Op* new = (Op*)malloc(sizeof(Op));

	if (new == NULL) // se não houver memória para alocar
	{
		return NULL;
	}

	new->order = order;
	new->next = NULL;

	return new;
}



Op* InsertOperation(Op* h, Op* new)
{
	if (ExisteOperation(h, new->order)) return h;

	if (h == NULL){
		h = new;
	}
	else {
		Op* aux = h;
		while (aux->next != NULL) {
			new->next = aux;
		}
		
		aux->next = new;
	}
	return h;
}

#pragma endregion
