#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int d1,d2,m1,m2,a1,a2,edad;
    printf("\n Ingrese la fecha actual:\n");
    printf("\n Día: \t\t");
    scanf("%d",&d2);
    printf("\n Mes: \t\t");
    scanf("%d",&m2);
    printf("\n Año: \t\t");
    scanf("%d",&a2);
    printf("\n Ingrese la fecha de su nacimiento:\n");
    printf("\n Día: \t\t");
    scanf("%d",&d1);
    while(d1!=0)
        {
        printf("\n Mes: \t\t");
        scanf("%d",&m1);
        printf("\n Año: \t\t");
        scanf("%d",&a1);
        edad=a2-a1;
        if(m2<m1||(m1==m2&&d2<d1))
            edad--;
        printf("\n Su edad es: %d \n\n",edad);
        printf("\n Ingrese la fecha de su nacimiento:\n");
        printf("\n Día: \t\t");
        scanf("%d",&d1);
        }
    printf("\n Fin del programa \n\n");
    getch();
    }
