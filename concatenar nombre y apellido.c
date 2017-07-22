#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>
void main()
{
    setlocale(LC_CTYPE,"Spanish");
	char nombre[50],aux[50],ap[50];
	int i,j=0;
	printf("\n Ingrese el nombre: \n\n");
	fflush(stdin);
	gets(nombre);
	printf("\n Ingrese el apellido: \n\n");
	fflush(stdin);
	gets(ap);
	strcat(nombre," ");
	strcat(nombre,ap);
	strcpy(aux,nombre);
	system("cls");
		for(i=0;i<50;i++)
	{
		aux[i]=toupper(aux[i]);
	}
	printf("\n\n El nombre es: %s\n\n",aux);
	printf("\n Tamaño: %d \n\n",strlen(aux));
	getch ();
}
