//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//           INSTITUTO POLITÉCNICO DO CÁVADO E DO AVE
//                          2020/2021
//             ENGENHARIA DE SISTEMAS INFORMÁTICOS
//                    ALGORITMOS E ESTRUTURAS DE DADOS
//
//				  [ ARTUR MENDES - Nº 14870 ]
//             [  INTERPRETADOR DA DADOS LEGO  ]
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define _CRT_SECURE_NO_WARNINGS
#define MALLOC(t) (t*)malloc(sizeof(t))

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <locale.h>
#include <assert.h>
#include <malloc.h>
#include "functions.h"


int StockAvailable =0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//            FUNÇÕES //{}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



void initialize_program() {
	printf("Bem-Vindo\n");
	printf("O programa está a efetuar a leitura dos ficheiros\n");
}

void program_ready()
{
	printf("Concluído!\n");
}

void  GetSetPartsListFromSetCode( Parts * PartsList, Parts_Sets * PartsSetsList, char * searchSetCode, char * searchClass)
{
	//printf("Got in void functions");
	Parts * returnList = MALLOC(Parts);
	Parts_Sets * auxList = MALLOC(Parts_Sets); 
	for ( ; PartsSetsList ; PartsSetsList = PartsSetsList->next ) 
	{
		if(strcmp(PartsSetsList->set_num, searchSetCode) == 0 )
		{	
				//	auxList = insere_PartsSets(auxList, PartsSetsList->set_num, PartsSetsList->quantity, PartsSetsList->part_num);
			for ( ; PartsList ; PartsList = PartsList->next ) 
			{
				if(strcmp(PartsList->class_part, searchClass) == 0 )
					//insere part in new partsList e retorna essa lista
					returnList = insere_Parts( returnList, PartsList->part_num, PartsList->nome, PartsList->class_part, PartsList->stock_available);
//					
				printf("\nNome:%s\nPeça Nº-> %s\nTema: %s\nStock-> %i\n\n", PartsList->nome, PartsList->part_num, PartsList->class_part, PartsList->stock_available);	
			}
		}
	}
	
}

Sets  * RemoveSetsByTheme(Sets * list, char * theme)
{
	Sets * aux = list;

	if(aux && strcmp(aux->theme, them) ==0 )
	{
		list = list->next;
		free(aux->set_name);
		free(aux->setnumber);
		free(aux->theme);
		free(aux->year);
		free(aux);
	}	else if(aux){
		for( ; aux->next; aux = aux->next) {
			if(strcmp(aux->next->theme, theme) == 0) 
			{
				Parts * ToDelete = aux->next;
				aux->next = ToDelete->next;
				free(ToDelete->nome);
				free(ToDelete->part_num);
				free(ToDelete->class_part);
				free(ToDelete->theme);
				//free(ToDelete->stock_available);
				free(ToDelete);
			}
		}
	}
	return list;
}
//{}


Parts * RemovePartsByClass(Parts * list, char * type)
{
	Parts * aux = list;

	if(aux && strcmp(aux->class_part, type) ==0 )
	{
		list = list->next;
		free(aux->nome);
		free(aux->part_num);
		free(aux->class_part);
		//free(aux->stock_available);
		free(aux);
	}	else if(aux){
		for( ; aux->next; aux = aux->next) {
			if(strcmp(aux->next->class_part, type) == 0) 
			{
				Parts * ToDelete = aux->next;
				aux->next = ToDelete->next;
				free(ToDelete->nome);
				free(ToDelete->part_num);
				free(ToDelete->class_part);
				//free(ToDelete->stock_available);
				free(ToDelete);
			}
		}
	}
	return list;
}
//{}
void printMainMenu()
{


printf("\n\n**Introduza uma das seguintes opções:***\n");
printf("1-> Obter os conjuntos de um tema.\n");
printf("2-> Procurar Peças por tipo de um Conjunto.\n");
printf("3-> Peças necessárias para um Set.\n");
printf("4-> Saber o total de peças em stock\n");
printf("5-> Total de peças por Set.\n");
printf("6-> Peça mais usada.\n");
printf("7-> Conjuntos Construíveis (stock existente).\n");


printf("\n*--------Operações--------* \n");
printf("\n\n**Introduza uma das seguintes opções:***\n");
printf("A-> Alterar o stock de uma peça.\n");
printf("B-> Adicionar ao stock.\n");
printf("T-> Remover todas as peças de um tipo..\n");
printf("X-> Remover todas os Sets de um tema.\n");
printf("Z-> Listar todos Conjuntos.\n");

printf("\n0-> Voltar ao menu principal.\n");
printf("*----------------------*\n");


}

//inserir dados na lista de Parts 
Parts *insere_PartsinList(Parts *PartsList,char *nome, char *part_num, int stockAvailable, char * class_part) {
    Parts *nova 			= MALLOC(Parts);
    nova->class_part 		= strdup(class_part);   // char *tmp = malloc(strlen(nome)); strcpy(tmp, nome); return tmp; 
    nova->part_num 	 		= strdup(part_num);
	nova->stock_available 	= stockAvailable;
    nova->next 				= PartsList;
    return nova;
}

//for acess parts_sets.tsv file contents
Parts_Sets * getPartsSetsContents(char * file, Parts_Sets * PartsSets_List)
{
	char  set_number[100], part_number[100], temp_quantity[100];
	int quantity;
 	FILE * fh = fopen(file, "r");
	int counter = 0;

	while (!feof(fh))
	{
		counter++;
		fscanf(fh, "%[^\t]\t%[^\t]\t%[^\n]\n", set_number, temp_quantity, part_number);
		quantity = atoi(temp_quantity);
		//printf("\nSet Nº-> %s \nQuantidade-> %d \nParte Nº-> %s \n", set_num, quantity, part_num );

		if(counter > 1)
		PartsSets_List = insere_PartsSets(PartsSets_List, set_number, quantity, part_number);
	}	

	return PartsSets_List;
}


// for access parts.tsv file contents
Parts * getPartsContents(char *file, Parts *Parts_List) 
{
	char  part_num[100], name[100], class[100], temp_stock[100];
	int stock;
	FILE * fh = fopen(file, "r");
	int counter = 0;

	while(!feof(fh))
	{
		counter++;
		fscanf(fh, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", part_num, name, class, temp_stock);
		stock = atoi(temp_stock);
		//printf("\nParte Nº-> %s \nNome-> %s \nClasse-> %s \nStock-> %d \n", part_num, name, class, stock );
	
		if(counter > 1)
		{
			StockAvailable = StockAvailable + stock;
			Parts_List = insere_Parts(Parts_List, part_num, name, class, stock);
		}
		
	}
	return Parts_List;
}


//for acess sets.tsv file contents
Sets * getSetsContents(char *file, Sets *SetsList)
{
char set_num[100], name[100], theme[100], year[100];
int temp_year;
FILE * fh = fopen(file, "r");
int counter = 0;
while(!feof(fh))
{
	counter++;
	fscanf(fh, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", set_num, name, year, theme);
	temp_year = atoi(year); // Using atoi() to convert date to integer
	//printf("\nThe value of y : %d", y);

	//printf("\nSet Nº-> %s \nNome-> %s \nAno-> %s \nTema-> %s \n", set_num, name, year, theme );
	if(counter > 1)
	SetsList = Insert_Sort_Set(SetsList, set_num, name, temp_year,theme);
}
fclose(fh);
return SetsList;
}

void showCurrentStockAvailable(){
	printf("Total de Peças contadas: %i\n", StockAvailable);
	printf("Prima uma tecla para voltar...");
	getchar();
}
//
Parts * getPartsFromSet( Parts_Sets * SetsPartsList, Parts * PartsList, char *classpart, char*setCode)
{
	Parts * tempParts = MALLOC(Parts);
	for( ; SetsPartsList; SetsPartsList = SetsPartsList->next) {
		for( ; PartsList; PartsList = PartsList->next) {
			if(strcmp(SetsPartsList->part_num, classpart) == 0 && strcmp(PartsList->class_part, classpart ) == 0)
			{
				tempParts = insere_Parts(tempParts, PartsList->part_num, PartsList->nome, PartsList->class_part, PartsList->stock_available);
				//funcao inserepart adiciona a uma lista de PArtes apenas as partes com o tipo desejado
			}
		}
	}		
	return tempParts;
}


//Function to get all parts from a set in a list and list that Parts Info
//{}
void getAllPartsFromSet(Parts_Sets * PartsSetsList,  Parts * PartsList, char * setNumber)
{
	//funcao não está a guardar na lista as partes certas, verificar
	Parts_Sets * TempPartsSetsList = MALLOC(Parts_Sets);

	for ( ; PartsSetsList; PartsSetsList->next) 
	{
		if(strcmp(PartsSetsList->set_num, setNumber) == 0)
		{
			//insert Part Num in PartsList;
			
			for ( ; PartsList; PartsList->next)
			{
					if(strcmp( PartsList->part_num,PartsSetsList->part_num ) == 0)
					{		
						printf("\nNome-> %s\nCódigo: %s\nTipo: %s\nStock Disponível: %s\nQuantidade necessária %i",PartsList->nome, PartsList->part_num, PartsList->class_part, PartsList->stock_available, PartsSetsList->quantity);	
					}
			}

			//TempPartsSetsList = insere_PartsSets(TempPartsSetsList, PartsSetsList->set_num, PartsSetsList->quantity, PartsSetsList->part_num );
			
		}
	}

	//return TempPartsSetsList;
}



//Function to list all parts from a set Number
//finish and testing
void printAllParts(Parts * PartsList, Parts_Sets * PartsSetList)
{
	//
	for( ; PartsList; PartsList->next)
		for( ; PartsSetList; PartsSetList->next)
	{
		if(strcmp(PartsList->part_num, PartsSetList->part_num) == 0) 
		{
			printf("\nPeça nº->%s\nNome->%s\nTipo->%s\nStock Disponível->%i\nQuantidade->%i\n", PartsList->part_num, PartsList->nome, PartsList->class_part, PartsList->stock_available, PartsSetList->quantity);

		}		
	}
}

//inserir dados na lista de Partes (parts.tsv)
Parts *insere_Parts(Parts *Parts_List,char *part_num, char *nome, char* class_part, int stock_available) {
	Parts *nova				= MALLOC(Parts);
    nova->nome 				= strdup(nome);   // char *tmp = malloc(strlen(nome)); strcpy(tmp, nome); return tmp; 
    nova->part_num 			= strdup(part_num);
	nova->class_part 		= strdup(class_part);
	nova->stock_available 	= stock_available;
    nova->next 				= Parts_List;
    return nova;
}


//inserir dados na lista de Partes_Sets (parts_sets.tsv)
Parts_Sets *insere_PartsSets(Parts_Sets *PartsSets_List, char * set_number, int quantity, char * part_num) {
	Parts_Sets *nova		= MALLOC(Parts_Sets);
    nova->set_num 			= strdup(set_number);   // char *tmp = malloc(strlen(nome)); strcpy(tmp, nome); return tmp; 
    nova->part_num 			= strdup(part_num);
	nova->quantity 			= quantity;
    nova->next 				= PartsSets_List;
    return nova;
}

//Procura na SetList pelo nome do tema e devolve lista apenas com os pesquisados
Sets * getSetFromTheme(Sets * SetsList, char *search, int SetFromThemeCounter)
{
	 Sets * SearchSetList = MALLOC(Sets);
	for ( ; SetsList ; SetsList = SetsList->next ) {
			if((SetsList->theme) && (SetsList->setnumber) && strcmp(SetsList->theme, search) == 0 ) 
            {
				SetFromThemeCounter++ ;
				//printf("\n%s\n%s", SetsList->set_name, SetsList->year);
				SearchSetList = Insert_Sort_Set(SearchSetList, SetsList->setnumber, SetsList->set_name, SetsList->year, SetsList->theme);
			}
        }
	
	return SearchSetList;
}

//altera o stock existente na lista de Peças (Parts)
Parts * changeStockinPart(Parts * PartsList, char* partToChange, int newStock)
{
	for( ; PartsList; PartsList = PartsList->next)
	{
		if(strcmp(PartsList->part_num, partToChange) == 0) {
			PartsList->stock_available = newStock;
			break;
		}
	}
	return PartsList;
//{}	

}

//{}	
//Função p/ exercício 5
int gettotalpieces( Parts_Sets * lst, char * SetCode)
{
	int counter = 0;

	for( ; lst ; lst = lst->next)
	{
		if(strcmp(lst->set_num, SetCode) == 0)
		{
			counter == counter +1;
		}
	}
	return counter;

}


//Search for part Function
Parts * PartSearch( Parts * lst, char * searchCode) 
{
	if(!lst || strcmp(searchCode, lst->part_num) == 0)
	{
		return lst;
	}else {
		return PartSearch(lst->next, searchCode);
	}	
}

//inserir dados na lista de Sets de forma ordenada
Sets * Insert_Sort_Set(Sets * SetsList, char *setnumber, char *nome, int year, char * theme)
{
	Sets * novo = MALLOC(Sets);
	novo->setnumber = setnumber;
	novo->year = year;
	novo->set_name = nome;
	novo->theme = theme;
	//novo->next = SetsList;

	if(!SetsList || novo->year < SetsList->year)
	{	
		novo->next = SetsList;
		SetsList = novo;
	} 
	else
	{	
		Sets * aux = SetsList;
			while(aux->next && novo->year > aux->next->year)
			aux = aux->next;
		novo->next 	= aux->next;
		aux->next 	= novo;
	}
	return SetsList;
	//{	}
}

//inserir dados na lista de Sets (sets.tsv)
Sets *insere_Set(Sets *SetsList,char *setnumber, char *nome, int year, char * theme) {
    Sets *nova 			= MALLOC(Sets);
    nova->set_name 		= strdup(nome);   // char *tmp = malloc(strlen(nome)); strcpy(tmp, nome); return tmp; 
    nova->setnumber 	= strdup(setnumber);
	nova->theme 		= strdup(theme);
	nova->year 			= year;
    nova->next 			= SetsList;
    return nova;
}


// funcao q lista Lista de Parts de um Set
//Terminar e testar (exercício 2)
void ListaPartsfromSet( Parts_Sets * SetsPartsList, char * setCode)  
{
	Parts_Sets * tempList = MALLOC(Parts_Sets);
	for( ; SetsPartsList; SetsPartsList->next) 
	{ 
		if(strcmp(SetsPartsList->set_num, setCode) == 0)
		{
			//insere_PartSets(tempList, SetsPartsList->set_num, SetsPartsList->part_num. SetsPartsList->quantity);
			//testar o q fica na templist
			
			//listarPartsSets(tempList);

		}
	}
}

//Listagem de Parts_Sets
void listarPartsSets(Parts_Sets *lst) {
        for ( ; lst ; lst = lst->next ) {
            printf("\nSet Nº->%s\nQuantidade->%s\nPart_Num->%s\n\n", lst->set_num, lst->quantity, lst->part_num);
        }
        printf("\n");
} 

//Listagem de Lista de Partes
void listarParts(Parts *lst) {
        for ( ; lst ; lst = lst->next ) {
            printf("\nNome->%s\nPeça Nº->%s\nTipo->%s\nStock->%d\n", lst->nome, lst->part_num, lst->class_part, lst->stock_available);
        }
        printf("\n");
} 



//Listagem de Lista de SETS
void listarSets(Sets *lst) {
	if(!lst)
	{printf("A lista não contém dados");} 
        for ( ; lst ; lst = lst->next ) {
            printf("\nSet Nº->%s\nNome->%s\nTema->%s\nAno->%d\n", lst->setnumber, lst->set_name, lst->theme, lst->year);
        }
        printf("\n");
} 

