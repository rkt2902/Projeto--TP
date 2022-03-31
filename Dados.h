/**
* Author: Henrique Azevedo
* Email: henrique.aazevedo29@gmail.com
* Date: 19-03-2022
* Desc: Dados gerais.
*
*/

#pragma once
#ifndef dados;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int numoperations;
int nummachines;



#pragma region Structs

/**
 * @brief Estrutura para armazenar uma Machine sem apontador.
 *
 * Um jogo cont�m um machineId (@@machineId), Tempo (@@time).
 */
typedef struct MachineFile {
    int machineId;
    int time;

}MachineFile;
/**
 * @brief Estrutura para armazenar uma Operation sem apontador.
 *
 * Um jogo cont�m uma order (@@order).
 */
typedef struct OperationFile {
    int order;

}OperationFile;

/**
 * @brief Estrutura para armazenar um Job sem apontador.
 *
 * Um jogo cont�m um Identificador (@@id).
 */
typedef struct JobFile {
    int id;
}JobFile;



/**
 * @brief Estrutura para armazenar uma Machine
 *
 * Uma Maquina cont�m um MachineId (@@machineId), tempo (@@time).
 * Cont�m apontador para pr�xima MAchine
 */

typedef struct Machine {
    int machineId;
    int time;
    struct Machine* next;
}Machine;

/**
 * @brief Estrutura para armazenar uma Operation
 *
 * Uma Operation cont�m um Order(@@order)
 *  Contem apontador para Lista das Maquinas.
 * Cont�m apontador para pr�xima opera�ao.
 */

typedef struct Operation{
    int order;  //ordem da opera�ao
    Machine* Machine; //todas as maquinas da opera�ao
    struct Operation* next; //Liga�ao para a prox opera�ao
}Operation;
/**
 * @brief Estrutura para armazenar um Job.
 *
 * Um Job cont�m um Id(@@id)
 *  Contem apontador para Lista das Operation
 * Cont�m apontador para pr�ximo job.
 */
typedef struct Job {
    int id;  //id do job
    struct Operation* operation; //Todas as opera�oes do Job
    struct Job* next; //Liga�ao ao proximo job
}Job;




#pragma endregion

#pragma region Functions 
//Job Functions
bool ExisteJob(Job* h, int id);
Job* newJob(int id);
Job* InsertJobStart(Job* h, Job* new);
Job* InsertJobEnd(Job* h, Job* new);
Job* RemoveJob(Job* h, int id);
Job* SearchJob(Job* h, int id);
Job* ChangeJob(Job* h, int id, Job* new);


//Operation Functions
Job* RemoveOperation(Job* h, Operation* c, int id, int order);
bool ExisteOperation(Operation* h, int order);
Operation* newOperation(int order, Machine* h);
Operation* InsertOperationEnd(Operation* h, Operation* new);
Job* InsertOperationOnJob(Job* h, Operation* c, int id);
Operation* SearchOperation(Operation* h, int order);
Job* ChangeOperation(Job* h, int order, Operation* new);

//Machine Functions
Machine* InsertMachineOnEnd(Machine* h, Machine* new);
Job* InsertMachineOnOperation(Job* h, Operation* t, Machine* c, int id, int order);
bool ExisteMachine(Machine* h, int machineId);
Machine* newMachine(int machineId, int time);
Job* Changemachine(Job* h, int machineid, Machine* new);
Job* RemoveMachine(Job* h, Machine* c, int id, int machineId);

//Read and Save
Job* Savedatatxt(char* nomeFicheiro, Job* h);
Job* Readdatatxt(char* nomeFicheiro);
Job* SavebinFile(char* nomeFicheiro, Job* h);
Job* ReadbinFile(char* nomeFicheiro);


//Get Machine Data
int getmintime(Job* h);
int getmaxtime(Job* h);
int getavgtime(Job* h);
int CountMachines(Job* h, int id, int order);

#pragma endregion

#endif