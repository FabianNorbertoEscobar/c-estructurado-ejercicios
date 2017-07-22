#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info1
    {
    int cp;
    char des[36];
    int car;
    int modp;
    int st;
    };
int main()
{
FILE *pf;
struct info1 aux;
pf=fopen("empresa6.dat","rb");
if(pf==NULL)
    {
        puts("\n Error al abrir el archivo, archivo inexistente");
        exit (0);
    }
fread(&aux,sizeof(struct info1),1,pf);
while(!feof(pf))
    {
        printf("\n Codigo: %d \t Descripcion: %s \t Caracteristica: %d \n Modelo: %d \t Stock: %d \n",aux.cp,aux.des,aux.car,aux.modp,aux.st);
        fread(&aux,sizeof(struct info1),1,pf);
    }
fclose(pf);
;
return 0;
}
