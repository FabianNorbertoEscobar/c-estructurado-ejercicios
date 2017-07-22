#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
void main()
{
setlocale(LC_CTYPE,"Spanish");
char aceptor[40]="Se agregó lo siguiente",dador[]=", me agregué";
printf("\n Las cadenas por separado son: \n\t %s\n\t %s",aceptor,dador);
strcat(aceptor,dador);
printf("\n Las cadenas unificadas son: \n\t %s \n",aceptor);
getch();
}
