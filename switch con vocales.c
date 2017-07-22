#include<stdio.h>
#include<conio.h>
void main()
    {
    int cont,cc,cb,cd,cg,i,por;
    char var;
    cont=0;
    cc=cb=cd=cg=0;
    for(i=0;i<20;i++)
        {
        printf("\n Ingrese caracter: \t\t");
        fflush(stdin);
        scanf("%c",&var);
        switch(var)
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':cont++;
                     break;
            case 'c':cc++;
                     break;
            case 'd':cd++;
                     break;
            case 'g':cg++;
                     break;
            case 'b':cb++;
                     break;
            }
        }
    por=cont*100/20;
    printf("\n El porcentaje de vocales es %d \% \n",por);
    printf("\n Cantidad de:\n\n \t C:%d \t D:%d \t G:%d \t B:%d \n\n",cc,cd,cg,cb);
    getch();
    }
