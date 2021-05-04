//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//           INSTITUTO POLITÉCNICO DO CÁVADO E DO AVE
//                          2020/2021
//             ENGENHARIA DE SISTEMAS INFORMÁTICOS
//                    ALGORITMOS E ESTRUTURAS DE DADOS
//
//				  [ ARTUR MENDES - Nº 14870 ]
//             [  INTERPRETADOR DA DADOS LEGO  ]
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Desabilita warnings de funções não seguras (fopen, sscanf, etc...)
#define _CRT_SECURE_NO_WARNINGS
#define MALLOC(t) (t*)malloc(sizeof(t))

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "functions.h"




//main function
int main(int argc, char **argv)
{

	printf("This is the first test! And it succeeded.\n");
	
	initialize_program();
	Sets * SetsList = getSetsContents("sets.tsv", SetsList);
	Parts * PartsList = getPartsContents("parts.tsv", PartsList);


	//listarSets(SetsList);
	program_ready();
	char option;

	do {
		printMenu();
		printf("Introduza uma opção:");
		scanf("%c",&option);

		switch(option)
		{
			case '0':
				return 0;
				break;
			default:
			break;
		}
	} while(option != 0); 	
	return 0;
} 