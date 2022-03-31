/**
*  @file Operations.c
 * @author Henrique Azevedo
 * @email henrique.aazevedo29@gmail.com
 * @date 2022
 * @brief Trabalho Pratico
 *
 *	Opera�oes responsaveis pela Cria��o/Modifica�ao da Estrutura Dinamica ligada �s Opera�oes.

 * @bug bugs desconhecidos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"




/**
* @brief Verifica se a opera�ao existe. Se existir devolve Bool!
* @param [in] h		Inicio da Lista
* @param [in] order	c�digo do Operation a procurar
* @return	True/False
*/
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
/**
*	@brief Cria nova Operation.
*
*	Aloca mem�ria necess�ria para armazenar um Operation em mem�ria
*
*	@param order Ordem da Operation
*
*/
Operation* newOperation(int order, Machine* h) {

	Operation* new = (Operation*)malloc(sizeof(Operation));

	if (new == NULL) // se n�o houver mem�ria para alocar
	{
		return NULL;
	}

	new->order = order;
	new->Machine = h;
	new->next = NULL;

	return new;
}
/**
* @brief Insere Operation no final da lista
* @param [in] h		Inicio da Lista
* @param [in] new	Nova Operation a inserir
* @return	Inicio da Lista
*/
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
}/**
* @brief Insere Operation no final da Lista dentro de um Job
* @param [in] h		Inicio da Lista de Jobs
* @param [in] hc	Inicio da Lista de Opera�oes
* @param [in] id	id do Jobs onde � desejado inserir opera�ao
* @return	NULL
*/
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
/**
* @brief Altera tipo de Operation
* @param [in]	h	Apontador para inicio da Lista de Jobs
* @param [in]	order	Ordem da Operation a alterar
*  @param [in]	c	Apontador para inicio da Lista  Nova de Opera�oes que pretende alterar
* @return	Apontador para Lista de Jobs
*/
Job* ChangeOperation(Job* h, int order, Operation* new) {

	if (h == NULL) return NULL;
	if (new == NULL) return h;

	Job* aux = h;

	while (aux) {

		Operation* aux1 = aux->operation;

		while (aux1) {

			if (aux1->order == order) {

				aux1->order = new->order;
			}
			aux1 = aux1->next;
		}
		aux = aux->next;
	}

	return h;
}
/**
* @brief Remove Operation.
* @param [in]	h	Apontador para inicio da Lista de JObs
* @param [in]	c	Apontador para inicio da Lista de Operations
* @param [in]	id	Ordem do id do Job da Operation.
* @param [in]	order	Ordem do Operation a remover.
* @return	Apontador para Lista
*/
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
/**
* @brief Procura operation
* @param [in]	h	Apontador para inicio da Lista
* @param [in]	order	Order do Operation a alterar
* @return	Apontador para Lista 
*/
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