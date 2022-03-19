/**
* Author: Henrique Azevedo
* Email: henrique.aazevedo29@gmail.com
* Date: 19-03-2022
* Desc: Dados gerais.
*
*/

#ifndef dados;
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>



#pragma region Structs


typedef struct Job {
    int id[1];
    struct Operation* operations;
    struct Job* next;
}Job;

typedef struct Operation
{
    int order;
    struct Operation* next;
    //struct OperationMachine* machines;
}Op;

typedef struct OperationMachine {
    struct Job* job;
    int machineId;
    int time;
};

typedef struct Machine {
    int id;
    int isBusy; // 1 está disponivel, 0 está ocupada;
};
#pragma endregion

#pragma region Inicializaçao de funçoes
//jobs
bool ExisteJob(Job* h, int id);
Job* newJob(int id);
Job* InsertJob(Job* h, Job* new);

//operations
bool ExisteOperation(Op* h, int order);
Op* newOperation(int order);
Op* InsertOperation(Op* h, Op* new);



#pragma endregion
#endif