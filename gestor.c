/**
*  @file gestor.c
 * @author Henrique Azevedo
 * @email henrique.aazevedo29@gmail.com
 * @date 2022
 * @brief Trabalho Pratico
 *
 *	Funçoes com o objetivo de gerir e verificar como funcionam as operaçoes.

 * @bug bugs desconhecidos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Dados.h"

/**
*	@brief  Determinar a quantidade minima de tempo pra completar um Job
*
*	Devolve o tempo minimo pra completar um job
*
*	@param h Inicio da Lista
*
*/
int getmintime(Job* h) {
	int result = 0;

	Operation* Op = h->operation;

	if (Op == NULL) return result;
	while (Op) {
		Machine* MACH = Op->Machine;

		int maxtime = MACH->time;
		MACH = MACH->next;

		while (MACH) {
			int time = MACH->time;

			if (maxtime > time) maxtime = time;

			MACH = MACH->next;
		}

		result += maxtime;
		Op = Op->next;
	}
	return result;
}
/**
*	@brief  Determinar a quantidade maximo de tempo pra completar um Job
*
*	Devolve o tempo maximo pra completar um job
*
*	@param h Inicio da Lista
*
*/
int getmaxtime(Job* h) {
	int result = 0;

	Operation* Op = h->operation;

	if (Op == NULL) return result;
	while (Op) {
		Machine* MACH = Op->Machine;

		int maxtime = MACH->time;
		MACH = MACH->next;

		while (MACH) {
			int time = MACH->time;

			if (maxtime < time) maxtime = time;

			MACH = MACH->next;
		}

		result += maxtime;
		Op = Op->next;
	}
	return result;
}
/**
*	@brief  Determinar a quantidade media de tempo pra completar um Job
*
*	Devolve o tempo medio pra completar um job
*
*	@param h Inicio da Lista
*
*/
int getavgtime(Job* h) {
	if (h == NULL) return NULL;

	int min = getmintime(h);
	int max = getmaxtime(h);

	return ((min + max) / 2);
}

