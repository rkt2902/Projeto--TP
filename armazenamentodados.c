/**
*  @file armazenamentodados.c
 * @author Henrique Azevedo
 * @email henrique.aazevedo29@gmail.com
 * @date 2022
 * @brief Trabalho Pratico
 *
 *	Armazenamento das Estruturas e dos Dados Inseridos

 * @bug bugs desconhecidos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Dados.h"

/**
*	@brief Ler os dados atravez de um ficheiro de texto
*
*	Lê da memoria dados previamente inseridos em um ficheiro
*
*	@param nomeFicheiro Nome do ficheiro de texto que se pretende ler

*/
Job* Readdatatxt(char* nomeFicheiro)
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
/**
*	@brief Guardar dados num ficheiro de texto
*
*	Guarda em memoria os dados inseridos/carregados.
*
*	@param nomeFicheiro Nome do ficheiro de texto onde se pretende guardar dados.
*   @param h Inicio da Lista

*/
Job* Savedatatxt(char* nomeFicheiro, Job* h) {
	
	if (h == NULL) return false;

	char c[100];
	FILE* fp = NULL;

	fp = fopen(nomeFicheiro, "w");
	if (fp == NULL) {
		perror("Erro ao abrir o ficheiro\n");
		getche();
		return(-1);
	}

	Job* aux = h;
	while(aux){
		
	Operation* aux1 = aux->operation;
	int l = 1;
			if (l == 1) {
				fprintf(fp,"%d,%d\n", aux->id, numoperations);
				l++;
				
						}
			if (l > 1) {
				
				while (aux1) {
					Machine* aux2 = aux1->Machine;
					int nummach = CountMachines(aux, aux->id, aux1->order);
					fprintf(fp,"%d,%d", aux1->order, nummach);

					while(aux2) {
						fprintf(fp,"(%d,%d)", aux2->machineId, aux2->time);
						aux2 = aux2->next;
					}

					
					fprintf(fp, "\n");
				aux1 = aux1->next;
				
				}		
					}
	aux = aux->next;
	}








	fclose(fp);
	return true;
}
/**
*	@brief Guardar dados num ficheiro Binario
*
*	Guarda em memoria os dados inseridos/carregados.
*
*	@param nomeFicheiro Nome do ficheiro de texto onde se pretende guardar dados.
*   @param h Inicio da Lista

*/
Job* SavebinFile(char* nomeFicheiro, Job* h) {
	FILE* fp;

	if (h == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	//grava n registos no ficheiro
	Job* aux = h;
	
	
	JobFile auxjob;	//para gravar em ficheiro!
	OperationFile auxoperation;
	MachineFile auxmachine;

	while (aux) {		
		Operation* aux1 = aux->operation;
		auxjob.id = aux->id;
		fwrite(&auxjob, sizeof(JobFile), 1, fp);

		while (aux1) {
			Machine* aux2 = aux1->Machine;
			auxoperation.order = aux1->order;
			fwrite(&auxoperation, sizeof(OperationFile), 1, fp);
			
			while (aux2){
				auxmachine.machineId = aux2->machineId;
				auxmachine.time = aux2->time;
				fwrite(&auxmachine, sizeof(MachineFile), 1, fp);
				aux2 = aux2->next;

			}

			aux1 = aux1->next;
		}
		aux = aux->next;
	}
	fclose(fp);
	return true;

}
/**
*	@brief Ler os dados atravez de um ficheiro binario
*
*	Lê da memoria dados previamente inseridos em um ficheiro
*
*	@param nomeFicheiro Nome do ficheiro de texto que se pretende ler

*/
Job* ReadbinFile(char* nomeFicheiro) {
	FILE* fp;
	Job* h = NULL;
	Operation* t = NULL;
	Machine* m = NULL;



	Job* aux;
	int j = 0;
	if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
	JobFile auxJob;
	while (fread(&auxJob, sizeof(JobFile), 1, fp) ) {
		OperationFile auxOp;
		aux = newJob(auxJob.id);
		h = InsertJobEnd(h, aux);
		
			while (fread(&auxOp, sizeof(OperationFile), 1, fp) ) {
				Operation* aux1;
				MachineFile auxmach;
				aux1 = newOperation(auxOp.order, NULL);
				t = InsertOperationOnJob(h, aux1, h->id);
				int i = 0;
					while (fread(&auxmach, sizeof(MachineFile), 1, fp)) {
						
						Machine* aux2;
						aux2 = newMachine(auxmach.machineId, auxmach.time);
						m = InsertMachineOnOperation(h, aux1, aux2, h->id, aux1->order);
						i++;
						if (i == 2 && j<3){
						j++;
							break;
						}
					}
					
			}

	}
	

	fclose(fp);
	return h;
}
