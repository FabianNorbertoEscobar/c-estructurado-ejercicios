#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define tope 80
int cargarvectores(int[],int[],int[]);
void promedio(float[],int[],int[],int);
void ordenarmayor(int[],int[],int[],float[],int);
void mostrar(int[],int[],int[],float[],int);
float porcentajemayores(float[],int,int);
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int dni[tope],parcial1[tope],parcial2[tope],ce,per;
    float prom[tope];
    printf("\n\n Ingrese los DNI y las notas de los parciales de cada alumno (máximo 80 alumnos)\n finalizando la carga con DNI igual a cero \n\n");
    ce=cargarvectores(dni,parcial1,parcial2);
    if(ce!=0)
        {
        promedio(prom,parcial1,parcial2,ce);
        ordenarmayor(dni,parcial1,parcial2,prom,ce);
        printf("\n\n DNI \t 1er PARCIAL \t 2do PARCIAL \t PROMEDIO \n");
        mostrar(dni,parcial1,parcial2,prom,ce);
        per=porcentajemayores(prom,ce,7);
        if(per!=0)
            printf("\n\n El porcentaje de alumnos que promocionó es %8.2f \n\n",per);
        else
            printf("\n\n El porcentaje de alumnos que promocionó es cero \n\n");
        }
    else
        printf("\n\n No hay alumnos \n\n");
    getch();
    }
int cargarvectores(int dni[],int p1[],int p2[])
    {
    int dni1,p11,p21,i;
    i=0;
    do
        {
        printf("\n\n Ingrese el DNI del alumno número %d: \n\n",i+1);
        scanf("%d",&dni1);
        printf("\n\n Ingrese la nota del primer parcial del alumno número %d: \n\n",i+1);
        scanf("%d",&p11);
        printf("\n\n Ingrese la nota del segundo parcial del alumno número %d: \n\n",i+1);
        scanf("%d",&p21);
        }
    while(!validadato(dni1,0,99999999)||!validadato(p11,1,10)||!validadato(p21,1,10));
    while(dni1!=0&&i<tope)
        {
        dni[i]=dni1;
        p1[i]=p11;
        p2[i]=p21;
        i++;
        do
            {
            printf("\n\n Ingrese el DNI del alumno número %d: \n\n",i+1);
            scanf("%d",&dni1);
            printf("\n\n Ingrese la nota del primer parcial del alumno número %d: \n\n",i+1);
            scanf("%d",&p11);
            printf("\n\n Ingrese la nota del segundo parcial del alumno número %d: \n\n",i+1);
            scanf("%d",&p21);
            }
        while(!validadato(dni1,0,99999999)||!validadato(p11,1,10)||!validadato(p21,1,10));
        }
    return i;
    }
void promedio(float prom[],int p1[],int p2[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        prom[i]=(p1[i]+p2[i])/2;
    }
void ordenarmayor(int dni[],int p1[],int p2[],float pr[],int ce)
    {
    int j,i,pm,aux2,aux3,aux4;
    float aux1;
    for(j=1;j<ce;j++)
        {
        pm=j-1;
        for(i=j;i<ce;i++)
            if(pr[i]>pr[pm])
                pm=i;
        aux1=pr[pm];
        pr[pm]=pr[j-1];
        pr[j-1]=aux1;
        aux2=dni[pm];
        dni[pm]=dni[j-1];
        dni[j-1]=aux2;
        aux3=p1[pm];
        p1[pm]=p1[j-1];
        p1[j-1]=aux3;
        aux4=p2[pm];
        p2[pm]=p2[j-1];
        p2[j-1]=aux4;
        }
    }
void mostrar(int dni[],int p1[],int p2[],float prom[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        printf("\n %d \t %d \t %d \t %f",dni[i],p1[i],p2[i],prom[i]);
    }
float porcentajemayores(float prom[],int ce,int x)
    {
    int i,cont;
    float pr;
    cont=0;
    for(i=0;i<ce;i++)
        if(prom[i]>x)
            cont++;
    if(cont!=0)
        pr=cont*100/ce;
    else
        pr=0;
    return pr;
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
