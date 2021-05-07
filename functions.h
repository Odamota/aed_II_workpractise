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

typedef struct _neededPartsList
{
	char * part_num;

	struct _neededPartsList * next;
} NeededPartsList;



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


void printMainMenu();

//função para aceder e guardar na lista Ligada Parts_Sets as informações do ficheiro tsv
Parts_Sets * getPartsSetsContents(char * file, Parts_Sets * PartsSets_List);

//função para aceder e guardar na lista Ligada Parts as informações do ficheiro tsv
Parts * getPartsContents(char *file, Parts *Parts_List);

//função para aceder e guardar na lista Ligada Sets as informações do ficheiro tsv
Sets * getSetsContents(char *file, Sets *SetsList);

//função para verificar as peças de um determinado tipo em set (testar)
Parts * getPartsFromSet( Parts_Sets * SetsPartsList, Parts * PartsList, char *classpart, char*setCode);

//Função que percorre a lista de PartsSets (ligação) e Parts para listar as partes necessárias para um Set
//iter
void getAllPartsFromSet(Parts_Sets * PartsSetsList,  Parts * PartsList, char * setNumber);

void printAllParts(Parts * PartsList, Parts_Sets * PartsSetList);

//void interpreter( char option, Sets * SetsList, Parts * PartsList, Parts_Sets * PartsSetsList);


Parts *insere_Parts(Parts *Parts_List,char *part_num, char *nome, char* class_part, int stock_available);

Parts * RemovePartsByClass(Parts * list, char * type);
Parts_Sets *insere_PartsSets(Parts_Sets *PartsSets_List, char * set_number, int quantity, char * part_num);
Sets * getSetFromTheme(Sets * SetsList, char *search, int SetFromThemeCounter);


Sets * RemoveSetsByTheme(Sets * list, char * type);

Parts *insere_PartsinList(Parts *PartsList,char *nome, char *part_num, int stockAvailable, char * class_part);

Parts * PartSearch( Parts * lst, char * searchCode);
Parts * changeStockinPart(Parts * PartsList, char * partToChange, int newStock);
Sets *insere_Set(Sets *SetsList,char *setnumber, char *nome, int year, char * theme);
Sets * Insert_Sort_Set(Sets * SetsList, char *setnumber, char *nome, int year, char * theme);

void ListaPartsfromSet( Parts_Sets * SetsPartsList, char * setCode); 
void showCurrentStockAvailable();

void listarPartsSets(Parts_Sets *lst);

//Listagem de Lista de SETS
void listarSets(Sets *lst);

//Listagem de Lista de PARTS
void listarParts(Parts *lst);


//função que guarda numa lista de parts os códigos de peças necessárias para um set
void GetSetPartsListFromSetCode( Parts * PartsList, Parts_Sets * PartsSetsList, char * searchSetCode, char * searchTheme);

int gettotalpieces( Parts_Sets * lst, char * SetCode);
#endif