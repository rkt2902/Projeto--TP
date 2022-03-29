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
	
	



	Job* Job1 = Readdatafromfile("data.txt");
	
	
	printf("%d", numoperations);
	printf("%d", nummachines);


	/*Job* new = newJob(1);
	Job *two = newJob(2);
	Job *novo = newJob(3);
	Job* seven = newJob(7);

	Job *Job1 = NULL;
	Job1 = InsertJobEnd(Job1, new);
	Job1 = InsertJobEnd(Job1, two);
	Job1 = InsertJobEnd(Job1, novo);
	Job1 = InsertJobEnd(Job1, seven);

	//Machine* primeira = newMachine(5, 3);

	Operation* nova = newOperation(1, NULL);
	Operation* atwo = newOperation(2, NULL);
	Operation* aatwo = newOperation(3, NULL);
	Operation* hey = newOperation(4, NULL);
	Operation* First = NULL;

	First = InsertOperationOnJob(Job1, nova, 1);
	First = InsertOperationOnJob(Job1, atwo, 1);
	First = InsertOperationOnJob(Job1, aatwo, 1);
	First = InsertOperationOnJob(Job1, hey, 1);

	//First = RemoveOperation(Job1, First, 1, 2);



	Machine* um = newMachine(1, 1);
	Machine* uma = newMachine(2, 2);
	Machine* ums = newMachine(3, 3);
	Machine* umd = newMachine(4, 4);
	Machine* aaa = NULL;

	aaa = InsertMachineOnOperation(Job1, um, 1, 1);
	aaa = InsertMachineOnOperation(Job1, uma, 1, 1);
	aaa = InsertMachineOnOperation(Job1, ums, 1, 1);
	aaa = InsertMachineOnOperation(Job1, umd, 1, 1);


	aaa = RemoveMachine(Job1, uma, 1, 2);//??*/

	
}

