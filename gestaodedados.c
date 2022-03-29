/**
* Author: Henrique Azevedo
* Email: henrique.aazevedo29@gmail.com
* Date: 19-03-2022
* Desc: Dados
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Dados.h"



Job* Readdatafromfile(char* nomeFicheiro)
{
	char c[100];
	FILE* fp = NULL;
	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) {
		perror("Erro ao abrir o ficheiro\n");
		getche();
		return(-1);
	}

	int l = 1;
	int linesop = 0;
	Job* Job1 = NULL;
	Operation* First = NULL;
	Machine* machines = NULL;
	int id;

	while (fscanf(fp, "%[^\n] ", c) != EOF) {
		if (l == 1){
			int numoperation;
			int x = sscanf(c, "%d,%d\0", &id, &numoperation);
			linesop = numoperation;

			Job* new = newJob(id);
			Job1 = InsertJobEnd(Job1, new);

			l++;
			continue;
		}
		if (linesop > 0) {
			int order, nmachines;
			int x = sscanf(c, "%d,%d(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)\0", &order, &nmachines);
			
			Operation* nova = newOperation(order, NULL);
			First = InsertOperationOnJob(Job1, nova, id);
			
			int i = 1;
			for (i; i <= nmachines; i++) {
				int machineid, time;

				if (i == 1){
					int x = sscanf(c, "%*d,%*d(%d,%d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)\0", &machineid, &time);
						Machine* Mach = newMachine(machineid, time);
						machines = InsertMachineOnOperation(Job1, nova, Mach, id, order);
				}
				else if (i == 2) {
					int x = sscanf(c, "%*d,%*d(%*d,%*d)(%d,%d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)\0", &machineid, &time);
					Machine* Mach = newMachine(machineid, time);
					machines = InsertMachineOnOperation(Job1, nova, Mach, id, order);
				}
				else if (i == 3) {
					int x = sscanf(c, "%*d,%*d(%*d,%*d)(%*d,%*d)(%d,%d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)\0", &machineid, &time);
					Machine* Mach = newMachine(machineid, time);
					machines = InsertMachineOnOperation(Job1, nova, Mach, id, order);
				}
				else if (i == 4) {
					int x = sscanf(c, "%*d,%*d(%*d,%*d)(%*d,%*d)(%*d,%*d)(%d,%d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)\0", &machineid, &time);
					Machine* Mach = newMachine(machineid, time);
					machines = InsertMachineOnOperation(Job1, nova, Mach, id, order);
				}
				else if (i == 5) {
					int x = sscanf(c, "%*d,%*d(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%d,%d)(%*d,%*d)(%*d,%*d)(%*d,%*d)\0", &machineid, &time);
					Machine* Mach = newMachine(machineid, time);
					machines = InsertMachineOnOperation(Job1, nova, Mach, id, order);
				}
				else if (i == 6) {
					int x = sscanf(c, "%*d,%*d(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%d,%d)(%*d,%*d)(%*d,%*d)\0", &machineid, &time);
					Machine* Mach = newMachine(machineid, time);
					machines = InsertMachineOnOperation(Job1, nova, Mach, id, order);
				}
				else if (i == 7) {
					int x = sscanf(c, "%*d,%*d(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%d,%d)(%*d,%*d)\0", &machineid, &time);
					Machine* Mach = newMachine(machineid, time);
					machines = InsertMachineOnOperation(Job1, nova, Mach, id, order);
				}
				else if (i == 8) {
					int x = sscanf(c, "%*d,%*d(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%*d,%*d)(%d,%d)\0", &machineid, &time);
					Machine* Mach = newMachine(machineid, time);
					machines = InsertMachineOnOperation(Job1, nova, Mach, id, order);
				}
			
			}



			linesop--;
			continue;
		}
	}
	fclose(fp);
	
	return Job1;
}


