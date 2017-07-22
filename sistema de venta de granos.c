#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float imp,caj,tarj,tot,iva,net;
    char cod;
    printf("\n SISTEMA DE VENTA DE GRANOS \n");
    printf("\n Ingrese el importe: \n\n\t");
    scanf("%f",&imp);
      fflush(stdin);
    printf("\n Ingrese el código: \n\n\t");
    scanf("%c",&cod);
    cod=toupper(cod);
        caj=0;
        tarj=0;
    while(cod!='F')
        {
        if(cod=='C')
            {
            net=imp-imp*30/100;
            caj+=net;
            }
        else
            if(cod=='E')
                {net=imp-imp*10/100;
                caj+=net;
                }
            else
                if(cod=='T')
                    {
                    net=imp+imp*12/100;
                    tarj+=net;
                    }
                else printf("\n Código erroneo \n\n");
        printf("\n Ingrese el importe: \n\n\t");
        scanf("%f",&imp);
          fflush(stdin);
        printf("\n Ingrese el código: \n\n\t");
        scanf("%c",&cod);
         cod=toupper(cod);
        }
    tot=caj+tarj;
    iva=tot*21/100;
    printf("\n\n Efectivo en caja: %f \n\n Ventas con tarjeta: %f \n\n Total de ventas: %f \n\n Importe del IVA: %f \n",caj,tarj,tot,iva);
    getch();
    }
