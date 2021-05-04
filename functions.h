#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//           INSTITUTO POLITÉCNICO DO CÁVADO E DO AVE
//                          2020/2021
//             ENGENHARIA DE SISTEMAS INFORMÁTICOS
//                    ALGORITMOS E ESTRUTURAS DE DADOS
//
//				  [ ARTUR MENDES - Nº 14870 ]
//             [  INTERPRETADOR DA DADOS LEGO  ]
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


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

//lista ligada p/ exercício 5 e 6 
typedef struct _neededList
{
	char * part_num;
	int quantity;
	char * theme;
	int year;
	struct _neededList * next;
} PartsInfoList;


/* 
typedef struct _partsByme {
	char *part_num;

	struct PartsList *next;
} PartsList;
*/

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//            HEADER DE FUNÇÕES
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void initialize_program();

void program_ready();

void printMenu();


Parts_Sets * getPartsSetsContents(char * file, Parts_Sets * PartsSets_List);

Parts * getPartsContents(char *file, Parts *Parts_List);

Sets * getSetsContents(char *file, Sets *SetsList);

Parts * getPartsFromSet( Parts_Sets * SetsPartsList, Parts * PartsList, char *classpart, char*setCode);

Parts_Sets * getAllPartsFromSet(Parts_Sets * PartsSetsList, char * setNumber);

void printAllParts(Parts * PartsList, Parts_Sets * PartsSetList);




Parts *insere_Parts(Parts *Parts_List,char *part_num, char *nome, char* class_part, int stock_available);

Parts_Sets *insere_PartsSets(Parts_Sets *PartsSets_List, char * set_number, int quantity, char * part_num);
Sets * getSetFromTheme(Sets * SetsList, char *search);

Parts *insere_PartsinList(Parts *PartsList,char *nome, char *part_num, int stockAvailable, char * class_part);

Parts * PartSearch( Parts * lst, char * searchCode);

Sets *insere_Set(Sets *SetsList,char *setnumber, char *nome, int year, char * theme);

void ListaPartsfromSet( Parts_Sets * SetsPartsList, char * setCode); 

void listarPartsSets(Parts_Sets *lst);

//Listagem de Lista de SETS
void listarSets(Sets *lst);


#endif