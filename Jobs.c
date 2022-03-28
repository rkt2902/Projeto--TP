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
	
	
	Job* newjob = (Job*)malloc(sizeof(Job));

	if (newjob == NULL) // se n�o houver mem�ria para alocar
	{
		return NULL;
	}

	newjob->id = id;
	newjob->operation = NULL;
	newjob->next = NULL;
	

	return newjob;
}


Job* InsertJobStart(Job* h, Job* new) {
	
	if (ExisteJob(h, new->id)) return h;	

	if (h == NULL)		
	{
		h = new;
	}
	else
	{
		new->next = h;	
		h = new;
	}
	return h;
}

Job* Insertmiddle(Job* h, Job* new) {

	if (ExisteJob(h, new->id)) return h;

	if (h == NULL)
	{
		h = new;
	}
	else
	{
	
		//falta isto tolo
	}
	return h;

}

Job* InsertJobEnd(Job* h, Job* new)
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

Job* SearchJob(Job* h, int id) {
	if (h == NULL) return NULL;		//lista vazia
	else
	{
		Job* aux = h;
		while (aux != NULL) {
			if (aux->id == id) {
				return (aux);		//encontrei
			}
			aux = aux->next;
		}
		return NULL;
	}
}


Job* RemoveJob(Job* h, int id) {

	if (h == NULL) return NULL;			//Lista vazia
	if (!ExisteJob(h, id)) return h;	//se n�o existe

	Job* aux = h;
	Job* auxAnt = NULL;

	//localizar registo a eliminar
	while (aux && aux->id != id) {
		auxAnt = aux;
		aux = aux->next;
	}
	if (auxAnt == NULL) {	//Eliminar � cabe�a
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


void MostraJob(Job* nodo) {
	if (nodo != NULL)
	{
		printf("id= %d\n", nodo->id);

	}

}


void MostraLista(Job* h) {
	Job* aux = h;
	while (aux != NULL) {		
		MostraJob(aux);
		aux = aux->next;
	}
}





bool ExisteJob(Job* h, int id);
Job* newJob(int id);
Job* InsertJobStart(Job* h, Job* new);
