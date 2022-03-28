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



#pragma region Structs




typedef struct Machinefree {
    int id;
    int isBusy; // 1 est� disponivel, 0 est� ocupada;
};

typedef struct Machine {
    int machineId;
    int time;
    struct Machine* next;
}Machine;


typedef struct Operation{
    int order;  //ordem da opera�ao
    Machine* Machine; //todas as maquinas da opera�ao
    struct Operation* next; //Liga�ao para a prox opera�ao
}Operation;

typedef struct Job {
    int id;  //id do job
    struct Operation* operation; //Todas as opera�oes do Job
    struct Job* next; //Liga�ao ao proximo job
}Job;



#pragma endregion


bool ExisteJob(Job* h, int id);
Job* newJob(int id);
Job* InsertJobStart(Job* h, Job* new);
Job* InsertJobEnd(Job* h, Job* new);
Job* RemoveJob(Job* h, int id);
Job* SearchJob(Job* h, int id);

Job* RemoveOperation(Job* h, Operation* c, int id, int order);
bool ExisteOperation(Operation* h, int order);
Operation* newOperation(int order, Machine* h);
Operation* InsertOperationEnd(Operation* h, Operation* new);
Job* InsertOperationOnJob(Job* h, Operation* c, int id);
Machine* InsertMachineOnEnd(Machine* h, Machine* new);
Job* InsertMachineOnOperation(Job* h, Machine* c, int id, int order);
bool ExisteMachine(Machine* h, int machineId);
Machine* newMachine(int machineId, int time);

Job* RemoveMachineOnOperation(Job* h, Machine* c, int id, int order);
Job* RemoveMachine(Job* h, Machine* c, int id, int machineId);
#endif