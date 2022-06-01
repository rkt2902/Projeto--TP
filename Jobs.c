/**
*  @file Jobs.c
 * @author Henrique Azevedo
 * @email henrique.aazevedo29@gmail.com
 * @date 2022
 * @brief Trabalho Pratico
 *
 *	Opera�oes responsaveis pela Cria��o/Modifica�ao da Estrutura Dinamica ligada aos Jobs.

 * @bug bugs desconhecidos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"


/**
* @brief Verifica se job existe. Se existir devolve Bool!
* @param [in] h		Inicio da Lista
* @param [in] id	c�digo do job a procurar
* @return	True/False
*/
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
/**
*	@brief Cria novo Job.
*
*	Aloca mem�ria necess�ria para armazenar um Job em mem�ria
*
*	@param id ID do Job
*
*/
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
/**
* @brief Insere um novo Job no in�cio da estrutura
* @param [in] h		Inicio da Lista
* @param [in] new	Novo Job a inserir
* @return	Inicio da Lista
*/
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
/**
* @brief Insere Job no final da lista
* @param [in] h		Inicio da Lista
* @param [in] nnew	Novo Job a inserir
* @return	Inicio da Lista
*/
Job* InsertJobEnd(Job* h, Job* new)
{
	if (ExisteJob(h, new->id)) return h;

	if (h == NULL){
		h = new;
	}
	else {
		Job* aux = h;
		while (aux->next != NULL) {
			aux = aux->next;
		}
		
		aux->next = new;
	}
	return h;
}/**
* @brief Verifica se Job existe. Se existir devolve endere�o Job!
* @param [in] h		Inicio da Lista
* @param [in] id	ID do Job a procurar
* @return	Apontador para Job encontrado
*/
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
/**
* @brief Altera tipo de Job
* @param [in]	h	Apontador para inicio da Lista
* @param [in]	id	ID do Job a alterar
* @return	Apontador para Lista
*/
Job* ChangeJob(Job* h, int id, Job* new) {
	if (h == NULL) return NULL;
	if (new == NULL) return h;

	Job* aux = SearchJob(h, id);
	if (aux) {
		aux->id = new->id;
	}
	return h;
}
/**
* @brief Remove Job. 
* @param [in]	h	Apontador para inicio da Lista
* @param [in]	id	ID do Job a alterar
* @return	Apontador para Lista
*/
Job* RemoveJob(Job* h, int id) {

	if (h == NULL) return NULL;			//Lista vazia
//if (!ExisteJogo(h, cod)) return h;	//se n�o existe

	if (h->id == id) {		//remove no inicio da lista
		Job* aux = h;
		h = h->next;
		free(aux);
	}
	else
	{
		Job* aux = h;
		Job* auxAnt = aux;
		while (aux && aux->id != id) {	//procura para revover
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




