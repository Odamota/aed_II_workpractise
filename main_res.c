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

int StockAvailable =0;
int SetFromThemeCounter = 0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//            Estruturas de Dados Para Sets, Parts e Parts_Sets
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef struct _parts {
		char *nome;
		char *part_num;
		char *class_part;
		int stock_available;
		struct _parts *next;
} Parts;

typedef struct _parts_sets {
	char * set_num;
	int quantity;
	char * part_num;
	struct _parts_sets *next;

} Parts_Sets;

typedef struct _sets {
	int year;
	char *set_name;
	char *setnumber;
	char *theme;
	struct _sets *next;
} Sets;

typedef struct _partsByme {
	char *part_num;

	struct PartsList *next;
} PartsList;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//            FUNÇÕES //{}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//lista informações do Set
/*
void  ListSetInfo( Parts_Sets * Sets_PartsList, char * setCode, Parts * PartsList, Sets * SetsList)
{
	Parts_Sets * SetsPartsToShow = MALLOC(Parts_Sets);
	for( ; Sets_PartsList ; Sets_PartsList->next)
	{
		
		if(strcmp( Sets_PartsList->set_num, setCode) == 0 )
		{
			SetsPartsToShow = insere_PartsSets(SetsPartsToShow, Sets_PartsList->set_num, Sets_PartsList->quantity, Sets_PartsList->part_num);
		}
	}
	for ( ; SetsPartsToShow; SetsPartsToShow->next)
	{
		if(strcmp(SetsPartsToShow->set_num,))
		{
		}
	}
	

}
*/






//main function
int main(int argc, char **argv)
{
	
	initialize_program();
	char option;
	char setCode[20];
	char  search_theme[20];
	char  classPart[20];
	//Parts_Sets *Parts_Sets_List = NULL;
	//Parts * Parts_List = NULL;

	Sets * SetsList  = getSetsContents("sets.tsv" ,SetsList);
	Parts * PartsList = getPartsContents("parts.tsv" ,PartsList);
	Parts_Sets  * Sets_PartsList = getPartsSetsContents("parts_sets.tsv",Sets_PartsList);
	//inserir leitura dos ficheiros
	//parts.tsv; sets.tsv; parts_sets.tsvM
	do{
		printMenu();
		//printf("Total de Peças contadas: %i\n", StockAvailable);
		printf("Introduza uma opção:\n");
		scanf("%c",&option);
			
		//interpreter(option, SetsList, PartsList, Sets_PartsList);	
		switch(option)
		{
			case '1':
				printf("Que tema pretende procurar?\n");
				//ordenar por ano
				scanf("%s", &search_theme);
				printf("\nA procurar por -> %s", search_theme);
				printf("\nPesquisando Sets com tema: %s\nAguarde um momento\n", search_theme);
				SetFromThemeCounter = 0;
				Sets * SearchSetList = getSetFromTheme(SetsList, search_theme);
				printf("\n Encontramos %i conjuntos disponíveis para %s:\n", &SetFromThemeCounter, search_theme);
				listarSets(SearchSetList);
				break;
			case '2':
				printf("***********************PEÇAS POR TIPO DE SET********************************\n");
				printf("Que tipo de peça procura?\n");
				
				scanf("%s", &classPart);
				printf("Qual é o código do conjunto que procura?\n");
				
				scanf("%s", &setCode);
				//testar
				Parts * SearchbyTipeList = getPartsFromSet(Sets_PartsList, PartsList, classPart, setCode );
				//definir função getPartsFromSet 
				//printf("Peças para o conjunto %s", setCode);
				//listarParts(PartsList, SearchbyTipeList);
				break;
			case '3':
				printf("********************************PEÇAS PARA UM CONJUNTO/SET***************************\n");
				printf("Qual é o conjunto que procura? ");

				scanf("%s", &setCode);
				//when setCode is defined search in list of parts/sets
				//Search by Set
				printf("\nPeças para o conjunto %s:\n", setCode);
				//ListaPartsfromSet(Sets_PartsList, SetCode);
				break;
			case '4':
				printf("Neste momento estão disponíveis %i peças.", StockAvailable);
				break;
			case '5':
				printf("********************************PEÇAS DE UM SET***************************\n");
				printf("Qual é o Set que procura?");
				scanf("%s", &setCode);
				printf("\nPeças para o Set %s", setCode);
				Parts_Sets * ReturnList = getAllPartsFromSet(Sets_PartsList, setCode);
				printAllParts(PartsList, ReturnList);
				//ListSetInfo(Sets_PartsList, setCode, PartsList, SetsList);

				//receber o Código do Set específico
				break;
				case '6':
				printf("Peça usada em mais sets");
				
				break;
			case '7':
				printf("Conjuntos construíveis com o stock");
				break;
			case 'a':
				//nothing
				break;
			case 'b':
				//nothing
				break;
			case 'c':
				//nothing
				break;
			case 'd':
				//nothing
				break;
				default:
				printf("Escolha uma opção válida por favor.\n");
				break;
		}	
	}while(option != 0);

	return 0;
}
