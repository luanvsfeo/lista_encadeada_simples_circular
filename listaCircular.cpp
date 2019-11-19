#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 
#include <conio.h> 
struct no{ int valor; struct no *pro;};
struct listaSimples{ struct no *ini; };


void mostrar(struct listaSimples *inicio);
void incluir(struct listaSimples *inicio,int v);
void excluirInicio(struct listaSimples *inicio);
void excluirEspecifico(struct listaSimples *inicio,int v);
void pesquisar(struct listaSimples *inicio,int v);
void alterar(struct listaSimples *inicio,int va,int vn);
void excluirFim(struct listaSimples *inicio);
void linhas();

int main(void) { 
struct listaSimples *adm_lista;
 adm_lista = (struct listaSimples*)malloc(sizeof(struct listaSimples)); 
 adm_lista->ini = NULL; 
 int op = -2; 
 int v,vn;
linhas();printf("\xDC");printf("\xDC");
printf("\n\xDB ---------MENU-------- \xDB\n"); 
printf("\xDB 1- Adicionar          \xDB\n\xDB 2- Excluir o primeiro \xDB\n\xDB 3- Mostra lista       \xDB\n"); 
printf("\xDB 4- Alterar valor      \xDB\n\xDB 5- Pesquisar valor    \xDB\n\xDB 6- Excluir especifico \xDB\n"); 
printf("\xDB 7- Excluir o ultimo   \xDB\n\xDB 0- Sair               \xDB\n\xDB");
linhas();printf("\xDB\n\n");
while (op!=0){ 

printf("Opcao:"); 
scanf("%d",&op); 

switch(op){

 case 1: 
	 	printf("Informe o valor que sera incluso na lista: "); 
	 	scanf("%d",&v); 
	 	incluir(adm_lista, v); 
 	break;
 case 2: 
 		excluirInicio(adm_lista); 
 	break;
 case 3: 
 		mostrar(adm_lista); 
 	break;
 case 4: 
 		printf("Informe o valor que sera alterado na lista: "); 
 		scanf("%d",&v); 
 		printf("Informe o novo valor: "); 
 		scanf("%d",&vn); 
 		alterar(adm_lista, v, vn); 
 	break;
 case 5: 
		printf("Informe o valor que sera pesquisado na lista: "); 
		scanf("%d",&v); 
		pesquisar(adm_lista,v); 
	 break;
 case 6: 
		printf("Informe o valor que sera excluido na lista: "); 
		scanf("%d",&v); 
		excluirEspecifico(adm_lista,v); 
	 break;
 case 7:
 		excluirFim(adm_lista); 	 
	break; 
	 
 case 0: 
 break;
 
 default:
 	printf("\nopcao invalida");
 } /*system("cls");windows Clrscr(); */ }
  return 0;}


void incluir(struct listaSimples *inicio,int v){ 
struct no *novo,*p; 
novo = (struct no*)malloc(sizeof(struct no)); 
novo->valor = v; 
novo->pro = NULL;

 if(inicio->ini == NULL){ 
	 inicio->ini = novo; 
	 novo->pro= inicio->ini; 
 }else{ 
	 p = inicio->ini; 
	 while(p->pro != inicio->ini){ 
	 	p=p->pro; 	
	 } 
	 p->pro = novo; 
	 novo->pro = inicio->ini; 
 }}

void mostrar(struct listaSimples *inicio){ 
struct no *p; 
p=inicio->ini; 
printf("\nAtual estado da lista\n"); 
if(p == NULL){ 
	printf("Lista vazia\n"); 
}else if(p->pro == p){ 
	printf("%d\n",p->valor); 
}else{ 
	printf("%d\n",p->valor); 
	p = p->pro; 
	while (p != inicio->ini ){ 
	printf("%d\n",p->valor); 
	p = p->pro;
	 } 
	 }}

void pesquisar(struct listaSimples *inicio,int v){ 
struct no *p; 
p=inicio->ini;

if(p == NULL){ 
	printf("Lista vazia\n"); 
 }else if(p->valor == v){ 
 printf("valor : %d\n",p->valor);
  }else{
   p = p->pro;
    while ( p != inicio->ini){ 
	if(p->valor == v){ 
	printf("valor : %d\n",p->valor);
	 break; } 
	 p = p->pro; } }}

void alterar(struct listaSimples *inicio,int va,int vn){ 
struct no *p; 
p=inicio->ini; 

if(p == NULL){ 
	printf("Lista vazia\n"); 
 }else if(p->valor == va){ 
	p->valor = vn; 
}else{ 
	p = p->pro; 
	while ( p != inicio->ini){ 
		if(p->valor == va){ 
			p->valor = vn; 
			break; 
		} 
	p = p->pro; }
}}


void excluirInicio(struct listaSimples *inicio){ 
struct no *p,*ini,*novoIni; 
p=inicio->ini; 
ini = p; 
 if(p == NULL){ 
	printf("Lista vazia\n"); 
 }else if(p->pro == p){ 
	free(ini); 
	inicio->ini = NULL;
 }else{ 
	 p = p->pro; 
	 while (p->pro != inicio->ini ){ 
	 	p = p->pro; 
	} 
	 novoIni = ini->pro; 
	 inicio->ini = novoIni; 
	 p->pro = inicio->ini; 
	 free(ini);
}}

void excluirFim(struct listaSimples *inicio){ 
struct no *p,*ini,*novoFim; 
p=inicio->ini; 
ini = p; 
if(p == NULL){ 
	printf("Lista vazia\n"); 
 }else if(p->pro == p){ 
	free(ini); 
	inicio->ini = NULL;
 }else{ 
	 p = p->pro; 
	 while (p->pro->pro != inicio->ini ){ 
	 	p = p->pro; 
	} 
	 novoFim = p;
	 p = p->pro ;
	 novoFim->pro = inicio->ini ;
	 free(p);

}}


void excluirEspecifico(struct listaSimples *inicio,int v){
 /* funciona com os itens entre primeiro e ultimo */ 
 struct no *p,*ini,*excluir; 
 p=inicio->ini; 
 ini = p; 
 if(p == NULL){ 
	printf("Lista vazia\n"); 
 }else if(p->pro == p && p->valor == v){ 
	 free(ini); 
	 inicio->ini = NULL; 
 }else{ 
	 p = p->pro; 
	 while (p->pro != inicio->ini ){ 
		 if(p->valor == v){  
		 excluir = p; 
		 break; 
		 } 
		 p = p->pro;
		} 
	 p=ini;
	 while (p->pro != excluir ){ 
	 	p = p->pro; 
		}
	 p->pro = excluir->pro;
	  free(excluir);
 }}
 
 
 void linhas(){
 	int i=0;
 	do{
 		printf("\xDC");
 		i++;
	 }while(i<23);
 	
 }
