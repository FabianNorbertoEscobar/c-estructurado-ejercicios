#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
{
setlocale(LC_CTYPE,"Spanish");
int n, ceros, sumpos, sumneg, contpos, contneg, i;
float m, prompos, promneg;
ceros=0, sumpos=0, sumneg=0, contpos=0, contneg=0;
printf("\n Ingrese un número entero positivo para indicar cuántos valores reales deben ser pedidos: \n\n\t");
scanf("%d",&n);
if(n!=0)
    printf("\n Ingrese %d valores reales: \n\n",n);
for (i=1; i<=n; i++)
    {
    scanf("%f",&m);
        if(m==0)
            ceros++;
        else
            if(m>0)
                {
                sumpos+=m;
                contpos++;
                }
            else
                {
                sumneg+=m;
                contneg++;
                }
      }
if(contpos==0)
       printf("\n No hay números positivos \n\n");
else
   {
   prompos=sumpos/contpos;
   printf("\n Promedio de números positivos: %f \n\n",prompos);
   }

if(contneg==0)
       printf("\n No hay números negativos \n\n");
else
   {
   promneg=sumneg/contneg;
   printf("\n Promedio de números negativos: %f \n\n",promneg);
   }
printf("\n Cantidad de ceros: %d \n\n",ceros);
getch();
}
