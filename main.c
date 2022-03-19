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
#include <conio.h>


int main() {


	int id = readjobs();

	Job* jobs = NULL;
	Job* job = newJob(id);
	jobs = InsertJob(jobs, job);




   


}


