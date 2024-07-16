#ifndef _PRACTICA2_H_
#define _PRACTICA2_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

typedef struct _Nodo{
	int team_value;
	char Club_Name[50];
	char Natal_Country[50];
	struct _Nodo *siguiente;
	struct _Nodo *anterior;
}Nodo;

typedef struct _Nodo2{
	int team_value;
	char Club_Name[50];
	char Natal_Country[50];
	struct _Nodo *siguiente;
	struct _Nodo *anterior;
}Nodo2;

Nodo *memoria(int entrada, char entrada1[50], char entrada2[50]){
	Nodo *nuevo;
		nuevo = (Nodo *)malloc(sizeof(Nodo));
				
		nuevo->team_value=entrada;
		strcpy(nuevo->Club_Name,entrada1);
		strcpy(nuevo->Natal_Country,entrada2);
		
		nuevo->siguiente=NULL;
		nuevo->anterior=NULL;
		
		return nuevo;
}
Nodo *push(Nodo *principio, int entrada, char entrada1[50], char entrada2[50]){
	Nodo *nuevo;
	nuevo=memoria(entrada, entrada1, entrada2);
		if(principio!=NULL){	
				nuevo->siguiente=principio;	
				principio->anterior=nuevo;		
			}
	return nuevo;
}
Nodo *Insertar(Nodo *principio, int dato, char dato1[50], char dato2[50]){
	Nodo *nuevo, *auxiliar;
	nuevo=memoria(dato, dato1, dato2);
	auxiliar=principio;
	if(auxiliar==NULL){
			principio=nuevo;		
	}
	else{
		while(auxiliar->siguiente!=NULL){
			auxiliar=auxiliar->siguiente;
		}
	auxiliar->siguiente=nuevo;	
	nuevo->anterior=auxiliar;
	}
	return principio;
}

void VerQueu(Nodo *principio){
	if(principio == NULL){
		printf("\nEmpty list\n");
	}
	else{
		while(principio != NULL){
			printf("\nTeam name: %s\nFrom: %s\nTeam value: %i mill. €\n\n", principio->Club_Name, principio->Natal_Country, principio->team_value);
			principio=principio->siguiente;
		}
	}
}
void MoveOn(Nodo *principio){
	char op;
	if(principio==NULL){
		printf("\nEmpty, nothing to show you\nLeaving...");
		
	}
	else{
	printf("\n\n\t-------------------------------------------------------------------------\n\n");
	printf("\nCurrent Team: %s\n\tFrom: %s\n\tTeam value: %i mill. €", principio->Club_Name, principio->Natal_Country, principio->team_value);
	printf("\n\n\tMove into Next one(n) or Previous one(p), as you want to leave press l... ");
	do{ 
		printf("\n\n\tMove into: ");
		scanf("%s", &op);
		switch(op){
			case 'n':
				if(principio->siguiente!=NULL){
					principio=principio->siguiente;
					printf("\n\tTeam s: %s\n\tFrom: %s\n\tTeam value: %i mill. €", principio->Club_Name,principio->Natal_Country,principio->team_value);			
				}
				else{
					printf("\n\tList's Limit, remaining at %s", principio->Club_Name);
				}
				break;
			case 'p':
				if(principio->anterior!=NULL){
					principio=principio->anterior;
					printf("\n\tTeam a: %s\n\tFrom: %s\n\tTeam value: %i  mill. €", principio->Club_Name,principio->Natal_Country,principio->team_value);			
				}
				else{
					printf("\n\tList's Limit, remaining at %s", principio->Club_Name);
				}
				break;
		}
	}while(op!='l');
	}
}
Nodo *Borrar(Nodo *principio){
	Nodo *eraser;
	if(principio==NULL){
		return NULL;
	}else{
		eraser=principio;
		principio=principio->siguiente;
		principio->anterior=NULL;
		free(eraser);
	}
	return principio;
}
int tamanio(Nodo *principio){
	int contador = 0;
	if(principio == NULL){
		return contador;
		}
	Nodo *Tempo = principio;
	while(Tempo != NULL){
		contador++;
		Tempo = Tempo->siguiente;
	}
	return contador;
}

Nodo *InsertarPosicion(Nodo *Primero, int dato, char dato1[50], char dato2[50], int Pos){
	Nodo *nuevo, *aux;
	nuevo=memoria(dato, dato1, dato2);
	aux=Primero;
	int i=0, l=tamanio(Primero);
	
	if(Primero==NULL){
		Primero=nuevo;
	}
	else{
		if(Pos==1){
			Primero=push(Primero, dato, dato1, dato2);
		}
		else{
			if((Pos>1)&&(Pos<=l)){
				for(i=0;i<(Pos-1);i++){
					aux=aux->siguiente;
			}
				nuevo->anterior=aux->anterior;
				nuevo->siguiente=aux;
				aux->anterior->siguiente=nuevo;
				aux->anterior=nuevo;
			}
			else if(Pos==l){
				Primero=Insertar(Primero,dato,dato1,dato2);
			}
			else
				printf("\n\nInvalid position\n");
		}
	}
	return Primero;
}
Nodo *Eliminar(Nodo *Primero, int position)
{
    Nodo *tempNode=Primero;
    Nodo *eliminatedNode=Primero;
    int size=tamanio(Primero);
    int i=0;
    if(tempNode==NULL)
    {
    	printf("\nEmpty list\n");
	}
	else
	{
		if((position<1)||(position>size))
		{
			printf("\ntype position");
		}
		else if((position>1)&&(position<=size))
		{
			for(i=1;i<position;i++)
			{
				eliminatedNode=eliminatedNode->siguiente;
				if(i!=position-1)
				{
					tempNode=tempNode->siguiente;
				}
			}
			tempNode->siguiente=eliminatedNode->siguiente;
			eliminatedNode->siguiente->anterior=tempNode;
			free(eliminatedNode);
		}
		else if(position==1)
		{
			Primero=Borrar(Primero);
		}
	}
	return Primero;
}
Nodo *BorrarFinal(Nodo *Principio){
	if(Principio!=NULL){
		Nodo *aux;
		aux=Principio;
		if(aux->siguiente!=NULL){
			while(aux->siguiente->siguiente!=NULL){
				aux=aux->siguiente;
			}
			free(aux->siguiente);
			aux->siguiente=NULL;			
		}
		else{
			Principio=NULL;
		}
	}
	else{
		printf("\nEmpty\n");
	}
	return Principio;
}

Nodo *Change(Nodo *Primero, int pos, int value, char value1[50], char value2[50]){
	if(Primero!=NULL){
		if(pos<=tamanio(Primero)){
			printf("\n\nHere is okay");
			Nodo *aux, *nuevo;
			nuevo=memoria(value, value1, value2);
			int i;
			aux=Primero;
			if(pos>1){
				for(i=2;i<pos;i++){
					aux=aux->siguiente;
				}
				//printf("\n\nAux: %i Principio: %i Nuevo: %i\n\n", aux->dato, Primero->dato, nuevo->dato);
				nuevo->siguiente=aux->siguiente->siguiente;
				free(aux->siguiente);
				aux->siguiente=nuevo;
				nuevo->anterior=aux;
				aux->siguiente->siguiente->anterior=nuevo;
				
			}else if(pos==1){
			nuevo->siguiente=aux->siguiente;
			aux->siguiente=nuevo;
			//printf("\n\nAux: %i Principio: %i Nuevo: %i\n\n", aux->dato, Primero->dato, nuevo->dato);
			Primero=Borrar(Primero);
			}
			else{
				printf("\n\nInvalid position 2\n\n");
			}
		}
		else{
			printf("\n\nInvalid position 1\n\n");
		}
		//printf("\nDone change!\n");
	}
	else{
		printf("\n\nEmpty\n\n");
	}		
	
	return Primero;
}
void Select(Nodo *Principio, char old[50], char new_club[50], int new_value, char new_country[50]){
	Nodo *aux;
	aux=Principio;
	if(aux!=NULL){
		while(aux->siguiente!=NULL){
			//printf("\n\tDato: %s y entrada: %s", aux->Club_Name, old);
			if(strcmp(old,aux->Club_Name)==0){
				strcpy(aux->Club_Name,new_club);
				strcpy(aux->Natal_Country,new_country);
				aux->team_value=new_value;
				break;
			}
			aux=aux->siguiente;
			if(strcmp(aux->Club_Name,old)==0){
				strcpy(aux->Club_Name,new_club);
				strcpy(aux->Natal_Country,new_country);
				aux->team_value=new_value;
				break;
			}
		}
		
	}else{
		printf("\n\nError, empty queu\n\n");
	}	
} 
void SaveToFile(Nodo *Primero){
	Nodo *aux;
	aux=Primero;
	FILE *Arch;
	Arch=fopen("ArchivoUCL.txt","w");
	//fprintf(Arch, "\n\tFootball Clubs\n");
	while(aux!=NULL){
		fprintf(Arch,"\n%s %s %i",aux->Club_Name,aux->Natal_Country,aux->team_value);
		aux=aux->siguiente;
	}
	fclose(Arch);
}
void ReadFile(Nodo *primero){
	Nodo *aux;
	aux=primero;
	FILE *arch;
	char car;
	arch=fopen("ArchivoUCL.txt","r");
	do{
		car=fgetc(arch);
		printf("%c", car);
	}while(feof(arch)==0);
	fclose(arch);
}
//---------------------------------------------------------
Nodo *Union(Nodo *a, Nodo *b){
	while(a->siguiente!=NULL){
		a=a->siguiente;
		
	}
	while(b->anterior!=NULL){
		b=b->anterior;
	}
	printf("\na: %s y b: %s", a->Club_Name,b->Club_Name);
	a->siguiente=b;
	b->anterior=a;
	return a;
}
Nodo *prin;
void view(Nodo *primero){
	FILE *f;
	Nodo *aux;
	f=fopen("ArchivoUCL.txt","r");
	if(f==NULL){
		printf("\nError de apertura");
	}
	char car;
	int num;
	char cad[50];
	char cad2[50];
	
	while(feof(f)==0){
		//car=fgetc(f);
		fscanf(f, "%s%s%i", &cad, &cad2, &num);
		//printf("%s %s %i\n", cad,cad2,num);
		prin=Insertar(prin,num,cad,cad2);
		}
	fclose(f);
	VerQueu(prin);
	
	int con=0;
	char cada[50];
	char cad2a[50];
	int cad3a;
	int k;
	printf("\n\nLinked list?\n1. Si  2. No  ");
	scanf("%i",&k);
	
	if(k==1){
		primero=Union(primero, prin);
	}
	//VerQueu(primero);
	printf("\n\nScaned correctly...");
	
}	

#endif

