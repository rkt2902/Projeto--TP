/**
*  @file main.c
 * @author Henrique Azevedo
 * @email henrique.aazevedo29@gmail.com
 * @date 2022
 * @brief Trabalho Pratico
 *
 *	Manipulação Das estruturas dinamicas de dados.

 * @bug bugs desconhecidos.
*/

#include <stdio.h>
#include <stdlib.h>
#include "Dados.h"
#include "functions.h"
#include <conio.h>


int main() {

	setlocale(LC_ALL, "Portuguese");
	
	Job* Job1 = Readdatatxt("data.txt");
	
	//Job* Job1 = ReadbinFile("datab.bin");

	int min = getmintime(Job1);
	int max = getmaxtime(Job1);
	int avg = getavgtime(Job1);

	
	//SavebinFile("datab.bin", Job1);
	
	Savedatatxt("data.txt", Job1);

	int c = CountMachines(Job1, 1, 1);
	

	
}

