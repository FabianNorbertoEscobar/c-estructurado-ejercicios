#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define N 18
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cont,ordmay,ordmen,i;
    float acum,tmp,may,men;
    cont=0;
    acum=0;
    for(i=0;i<N;i++)
        {
        printf("\n Ingrese la temperatura %d: \t\t",i+1);
        scanf("%f",&tmp);
        if(i==0||tmp>may)
            {
            may=tmp;
            ordmay=i+1;
            }
        if(i==0||tmp<men)
            {
            men=tmp;
            ordmen=i+1;
            }
        if(tmp<0)
            {
            cont++;
            acum+=tmp;
            }
        }
    printf("\n\n Mayor:%.2f \t Orden mayor:%d \t Menor:%.2f \t Orden menor:%d \n\n",may,ordmay,men,ordmen);
    if(cont>0)
        printf("\n El promedio de las temperaturas negativas es: %.2f \n\n",acum/cont);
    else
        printf("\n No hubo temperaturas negativas \n\n");
    getch();
    }
