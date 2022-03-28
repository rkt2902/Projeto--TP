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
    int isBusy; // 1 está disponivel, 0 está ocupada;
};

typedef struct Machine {
    int machineId;
    int time;
    struct Machine* next;
}Machine;


typedef struct Operation{
    int order;  //ordem da operaçao
    Machine* Machine; //todas as maquinas da operaçao
    struct Operation* next; //Ligaçao para a prox operaçao
}Operation;

typedef struct Job {
    int id;  //id do job
    struct Operation* operation; //Todas as operaçoes do Job
    struct Job* next; //Ligaçao ao proximo job
}Job;



#pragma endregion


bool ExisteJob(Job* h, int order);
Job* newJob(int order);
Job* InsertJobStart(Job* h, Job* new);
Job* InsertJobEnd(Job* h, Job* new);
Job* RemoveJob(Job* h, int order);
void MostraJob(Job* h);
Job* SearchJob(Job* h, int id);s


bool ExisteOperation(Operation* h, int order);
Operation* newOperation(int order);
Operation* InsertOperationStart(Operation* h, Operation* new);
Operation* InsertOperationEnd(Operation* h, Operation* new);
Operation* RemoveOperation(Operation* h, int order);
void MostraOperation(Operation* h);
Job* InsertOperationOnJob(Job* h, Operation* c, int id);

#endif