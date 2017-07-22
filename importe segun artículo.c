#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cod,cant,imp;
    printf("\n\n Ingrese código y cantidad. Confirme con enter c/u. \n\n");
    scanf("%d%d",&cod,&cant);
    if(cod==1||cod==10||cod==100)
        imp=cant*10;
    else
        if(cod==2||cod==22||cod==222)
            imp=cant/10*65+cant%10*7;
        else
            if(cod==3||cod==33)
                if(cant>10)
                    imp=cant*3*9/10;
                else
                    imp=cant*3;
            else
                if(cod==4||cod==44)
                    imp=cant;
                else
                    printf("\n\n Código erróneo \n\n");
    printf("\n\n Artículo:%d \t Cantidad:%d \t Importe:%d \n\n",cod,cant,imp);
    getch();
    }
