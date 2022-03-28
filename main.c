/**
* Author: Henrique Azevedo
* Email: henrique.aazevedo29@gmail.com
* Date: 19-03-2022
* Desc: Execução de funções
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "Dados.h"
#include "functions.h"
#include <conio.h>


int main() {

	setlocale(LC_ALL, "Portuguese");

	Job *new = newJob(1);
	Job* two = newJob(7);
	Job *Job1 = NULL;
	Job1 = InsertJobStart(Job1, new);
	Job1 = InsertJobStart(Job1, two);
	
	Operation* nova = newOperation(3);
	Operation* atwo = newOperation(7);
	Operation* hey = newOperation(1);
	Operation* First = NULL;
	First = InsertOperationOnJob(Job1, nova, 1);
	First = InsertOperationOnJob(Job1, atwo, 1);
	First = InsertOperationOnJob(Job1, hey, 7);





}

