#include "Practica2.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<conio.h>
//#include<windows.h>

int main(){
	Nodo *UCL=NULL;
	VerQueu(UCL);
	
	printf("\n\tUEFA Champions League: \n\nClasificated:\n");
	//UCL=push(UCL, 296, "Ajax", "Netherlands");
	//UCL=push(UCL, 813, "Barcelona", "Spain");
	//UCL=Insertar(UCL, 483, "Dormund", "Germany");
	//UCL=InsertarPosicion(UCL, 925, "Liverpool", "England", 3);
	
	//UCL=Borrar(UCL);
	//UCL=BorrarFinal(UCL);
	
	//UCL=Change(UCL, 1, 550, "AC Milan", "Italy");
	//Select(UCL, "Ajax" , "Bayern Munchen", 878, "Germany");
	VerQueu(UCL);
	
	//MoveOn(UCL);
	int op, op1, op2, op3, opm;
	char opc;
	int value, pos, ps;
	char name[50], country[50];
	do{
	printf("\n\tMain menu\n      --------------\n1. Insert team\n2. Erase team\n3. Read File Object\n4. Save File Object\n5. Show teams\n6. Replace\n7. Leave\n\nSelect an opcion: ");
	scanf("%i", &op);
	//int value, pos;
	//char name[15], country[15];
	switch(op){
		case 1:
			do{
			//int value, pos;
			//char name[15], country[15];
			printf("\n\tInsert options: \n       -----------------\n1. Beginning\n2. At the end\n3. Certain position\n4. Leave\n\nSelect an option ");
			scanf("%i", &op1);
			if(op1==4)
				break;
			printf("\nWhich team do you add? ");
			scanf("%s", &name);
			printf("\nValue: ");
			scanf("%i", &value);
			printf("\nCountry: ");
			scanf("%s", &country);
			switch(op1){
				case 1:
					printf("Equipo: %s", name);
					UCL=push(UCL, value,name,country);
					break;
				case 2:
					UCL=Insertar(UCL, value, name, country);
					break;
				case 3:
					printf("\nPosition: ");
					scanf("%i", &pos);
					UCL=InsertarPosicion(UCL, value, name, country, pos);
					break;
				}
			}while(op1==2||op1==1||op1==3);
			printf("\nPress enter lo leave");
			
			getch();
			system("cls");
			break;
		case 2:
			do{
			printf("\n\tErase options\n1. Beginning\n2. At the end\n3. Erase position\n4. Leave\n\nSelect an option ");
			scanf("%i", &op2);
			if(op2==4)
				break;
			switch(op2){
				case 1:
					UCL=Borrar(UCL);
					break;
				case 2:
					UCL=BorrarFinal(UCL);
					break;
				case 3:
					printf("\nPosition you wish erase: ");
					scanf("%i", &ps);
					UCL=Eliminar(UCL,ps);
					break;
				}
			}while(op2==2||op2==1||op2==3);
			printf("\nPress enter lo leave");
			getch();
			system("cls");
			break;
		case 3:
			system("cls");
			printf("Reading file...\n\n\tClasifiqued teams\n");
			//ReadFile(UCL);
			view(UCL);
			printf("\n\n\tPress enter lo leave");
			getch();
			system("cls");
			break;
		case 4:
			printf("\nSaved file");
			SaveToFile(UCL);
	
			printf("\nPress enter lo leave");
			
			getch();
			system("cls");
			break;
		case 5:
			do{
				printf("\n\t Moving options at the list\n\t----------------------------\n1. Show all \n2. Move on\n3. Leave\n\nSelect option: ");
				scanf("%i", &opm);
				if(opm==3)
					break;
				switch(opm){
					case 1:
						VerQueu(UCL);
						break;
					case 2:
						MoveOn(UCL);
						//getch();
						//system("cls");
						break;
				}
			}while(opm==1||opm==2);
			//VerQueu(UCL);
			printf("\nPress enter lo leave");
			getch();
			system("cls");
			break;
		case 6:
			do{
			printf("\n\tChange options\n        -----------------\n1. Change instead of existing team\n2. Change by certain position\n3. Leave\n\nSelect option: ");
			scanf("%i", &op3);
			char name3[15], country3[15], old[15];
			int value3, pos;
			if(op3==3){
				break;
			}
			printf("\nNew: ");
			scanf("%s", &name3);
			printf("\nValue: ");
			scanf("%i", &value3);
			printf("\nCountry: ");
			scanf("%s", &country3);
			
			switch(op3){
				case 1:
					printf("\nTeam you wish change: ");
					scanf("%s", &old);
					Select(UCL,old,name3,value3,country3);
					break;
				case 2:
					printf("\nPosition you wish change: ");
					scanf("%i", &pos);
					UCL=Change(UCL,pos,value3,name3,country3);
					break;
			}
			}while(op3<3);		
			break;
		}
	}while(op<7);
	
	getch();
	return 0;
}
