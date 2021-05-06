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


int SetFromThemeCounter = 0;

//main function
int main(int argc, char **argv)
{
	//printf("This is the first test! And it succeeded.\n");
	
	initialize_program();

	Sets * SetsList = getSetsContents("sets.tsv", SetsList);
	Parts * PartsList = getPartsContents("parts.tsv", PartsList);
	Parts_Sets * PartsSetsList = getPartsSetsContents("parts_sets.tsv", PartsSetsList);

	//listarSets(SetsList);
	program_ready();
	char option;

	do {
		printMainMenu();		
		//printOperationsMenu
		printf("Introduza uma opção:");
		scanf("%c",&option);

		//interpreter(option, SetsList, PartsList, PartsSetsList);
		char  search_theme[20];
		char searchSetCode[20];
		char searchPartType[20];
		char partToChange[20];
		char TypeToRemove[20];
		int newStock;
		switch(option)
		{
			case '0':
				system("cls || clear");
				printf("\nObrigado!\n");
				exit(1);
				break;
			case '4':
				system("cls || clear");
				//adicionar funcao getstockavailable
				showCurrentStockAvailable();
				
				break;
			case '1':
				system("cls || clear");
				
				printf("Que tema pretende procurar?\n");
				scanf("%s", &search_theme);
				printf("\nA procurar por -> %s", search_theme);
				printf("\nPesquisando Sets com tema: %s\nAguarde um momento\n", search_theme);
				SetFromThemeCounter = 0;
				Sets * SearchSetList = getSetFromTheme(SetsList, search_theme, SetFromThemeCounter);
				
				printf("\n Encontramos %i conjuntos disponíveis para %s:\n", &SetFromThemeCounter, search_theme);	
				//char listbool;
				//printf("\nPretende ver a lista de Sets de %s? (s/n): ", search_theme);
				//scanf("%s", &listbool);
				//if(listbool == 's' ||  listbool == 'S')
					listarSets(SearchSetList);
					printf("\nPrima uma tecla para continuar...");
					getchar();
					break;
			case '2':
				system("cls || clear");
				printf("Pesquisa de peças por tipo (e tema)\n");
				printf("\nCódigo do conjunto que procura?\n");
				scanf("%s", &searchSetCode);
				printf("Tipo de peça que procura?\n");
				scanf("%s", &searchPartType);
				Parts * NeededPartsList = MALLOC(Parts);

				GetSetPartsListFromSetCode( PartsList ,PartsSetsList, searchSetCode, searchPartType);
				
				printf("Prima uma tecla para continuar...");
				getchar();
							
				//listarParts(NeededPartsList);
				//segmentation error
				break;

			case '3':
			//get all parts for a set
				system("cls || clear");
				printf("\nPeças necessárias para um conjunto\n");
				printf("Código do Set que pretende: ");
				scanf("%s", &searchSetCode);
				printf("A procurar por peças para o conjunto %s", &searchSetCode);
				getAllPartsFromSet(PartsSetsList, PartsList, searchSetCode);
				
				printf("Prima uma tecla para continuar...");
				getchar();
				break;
			case 'Z':
				listarSets(SetsList);
				break;
			case 'A':
				//alterar o stock de uma peça
				system("cls || clear");
				printf("\nQual a peça que pretende alterar?");
				scanf("%s", &partToChange);
				printf("\nStock Atual:");
				scanf("%s", &newStock );
				PartsList = changeStockinPart(PartsList, partToChange, newStock);
				printf("\nConcluído!\nPrima uma tecla para continuar e gravar os dados...");
				//savePartsData(PartsList);
			break;
			case 'X':
				system("cls || clear");
				printf("\nQual o tipo que pretende remover?");
				scanf("%s", &TypeToRemove );
				PartsList = RemovePartsByClass(PartsList, TypeToRemove);
				printf("\nConcluído\nPrima qualquer tecla para continuar");
				getchar();

			default:
			break;
		}


		//opsinterpreter();
	} while(option != 0); 	
	return 0;
} 
/* 
printOperationsMenu();
printf("Introduza uma opção:");
scanf("%c",&option);

switch (option)
{
	case '1':
	//alterar o stock de uma peça
	break;
	case '2':
	//adicionar ao stock
	break;
	case '3':
	//Remover todas as peças por tipo
	case '4':
	//Remover todos os sets de um tema
	break;
	case '5':
		
		break;
	case '0':
		system("cls || clear");
		break;
	default:
		printf("\nIntroduza uma opção válida");
	break;

}

*/