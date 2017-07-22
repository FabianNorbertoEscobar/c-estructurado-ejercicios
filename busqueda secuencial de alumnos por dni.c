#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define tope 100
int cargarvectores(int[],char[][30]);
int busquedasecuencial(int[],int,int);
int validadato(int,int,int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int vdoc[tope],cant,pos,dni;
char vnom[tope][30];
printf("\n Realice la carga de los DNI y los nombres \n de los alumnos del curso: \n Se finaliza la carga con DNI igual a cero\n");
cant=cargarvectores(vdoc,vnom);
printf("\n Realice la búsqueda de alumnos por DNI \n Se finaliza la búsqueda con DNI igual a cero\n");
do
    {
    printf("\n Ingrese un DNI para ver si pertenece al curso:\n\n\t");
    scanf("%d",&dni);
    }
while(!validadato(dni,0,100000000));
while(dni!=0)
    {
    pos=busquedasecuencial(vdoc,cant,dni);
    if(pos!=-1)
        printf("\n\n El nombre de la persona con DNI %d es: %s \n",dni,vnom[pos]);
    else
        printf("\n\n No existe un alumno con ese DNI en el curso \n");
    do
    {
    printf("\n Ingrese un DNI para ver si pertenece al curso:\n\n\t");
    scanf("%d",&dni);
    }
while(!validadato(dni,0,100000000));
    }
getch();
}
int cargarvectores(int vdoc[],char vnom[][30])
{
int dni,i;
char nomb[30];
i=0;
do
    {
    printf("\n\n Ingrese un DNI de un alumno del curso:\n\n\t");
    fflush(stdin);
    scanf("%d",&dni);
    }
while(!validadato(dni,0,100000000));
while(dni!=0 && i<tope)
    {
    vdoc[i]=dni;
    fflush(stdin);
    printf("\n Ingrese el nombre del alumno con el DNI ingresado, máximo 30 caracteres:\n\n\t");
    gets(nomb);
    strcpy(vnom[i],nomb);
    i++;
do
    {
    printf("\n\n Ingrese un DNI de un alumno del curso:\n\n\t");
    fflush(stdin);
    scanf("%d",&dni);
    }
while(!validadato(dni,0,100000000));
    }
return i;
}
int busquedasecuencial(int vdoc[],int ce,int x)
{
int p,i;
p=-1;
i=0;
while(i<ce && p==-1)
    {
    if(vdoc[i]==x)
        p=i;
    i++;
    }
return p;
}
int validadato(int x,int li,int ls)
{
if(x>=li && x<=ls)
    return 1;
else
    return 0;
}
