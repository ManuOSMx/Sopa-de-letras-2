#include<stdio.h>
#define N 20
#define M 20

void mostrar_sopa(char sopa[N][M]);
int buscar_palabra_horizontal(char sopa[N][M], char pal[M+1], int fil, int col);
int cad_iguales (char pal1[], char pal2[]);
int longitud_pal (char pal[]);
void buscar(char *pal,char mat[N][M]);
void main()
{
    int fila, columna;
    char pal[M];

    char sopa[N][M] =
    {
        'a', 'j', 'k', 's', 'l', 'n', 'r','a', 'c', 'd', 'p', 'q', 'm', 'n','v', 'b', 'c', 'k', 'm', 'l',
        'b', 'i', 'l', 'r', 'u', 'o', 'p','a', 's', 'd', 'f', 'g', 'h', 'j','k', 'l', 'z', 'x', 'c', 's',
        'c', 'h', 'm', 'q', 'v', 'i', 'f','y', 't', 'r', 'q', 'w', 't', 'z','a', 'p', 'w', 'h', 'e', 'f',
        'd', 'g', 'n', 'p', 'w', 'z', 'l','u', 'i', 's', 'e', 's', 'a', 'y','t', 'q', 'p', 'j', 'd', 'c',
        'e', 'f', 'n', 'o', 'x', 'y', 'a','h', 'g', 'e', 'j', 'z', 'x', 'w','s', 'r', 'o', 'g', 'b', 'a',
        'a', 'j', 'k', 's', 'l', 'n', 'r','a', 'c', 'd', 'p', 'q', 'm', 'n','v', 'b', 'c', 'k', 'm', 'l',
        'b', 'i', 'l', 'r', 'u', 'o', 'p','a', 's', 'd', 'f', 'g', 'h', 'j','k', 'l', 'z', 'x', 'c', 's',
        'c', 'h', 'm', 'q', 'v', 'i', 'u','y', 't', 'r', 'q', 'w', 't', 'z','a', 'p', 'w', 'h', 'e', 'f',
        'd', 'g', 'n', 'p', 'w', 'z', 'l','u', 'i', 's', 'e', 's', 'a', 'y','t', 'q', 'p', 'j', 'd', 'c',
        'e', 'z', 's', 'o', 'd', 'y', 't','h', 'j', 'e', 'j', 'z', 'x', 'w','s', 'r', 'o', 'g', 'b', 'a',
        'a', 'j', 'k', 's', 'l', 'n', 'r','a', 'c', 'd', 'p', 'q', 'm', 'n','v', 'b', 'c', 'k', 'm', 'l',
        'b', 'i', 'l', 'r', 'u', 'o', 'p','a', 's', 'd', 's', 'i', 'h', 'j','k', 'l', 'z', 'x', 'c', 's',
        'c', 'i', 'm', 'q', 'v', 'i', 'u','y', 't', 'r', 'q', 'w', 't', 'z','a', 'p', 'w', 'h', 'e', 'f',
        'd', 'n', 'n', 'p', 'w', 'z', 'l','u', 'i', 's', 'e', 'n', 'a', 'd','t', 'q', 'p', 'j', 'd', 'c',
        'e', 't', 'n', 'o', 'x', 'y', 'e','s', 'l', 'e', 'j', 'o', 'x', 'o','s', 'r', 'o', 'g', 'b', 'a',
        'a', 'j', 'k', 's', 'l', 'n', 'r','a', 'c', 'd', 'p', 'q', 'm', 'n','v', 'b', 'c', 'k', 'm', 'l',
        'b', 'i', 'l', 'r', 'u', 'o', 'p','i', 'f', 'd', 'f', 'g', 'h', 'j','k', 'l', 'z', 'x', 'c', 's',
        'c', 'h', 'm', 'q', 'v', 'i', 'u','y', 't', 'r', 'q', 'w', 't', 'z','a', 'p', 'w', 'h', 'e', 'f',
        'd', 'g', 'n', 'p', 'w', 'z', 'l','u', 'i', 's', 'e', 's', 'a', 'y','t', 'q', 'p', 'j', 'd', 'c',
        'e', 'f', 'n', 'o', 'x', 'y', 'a','h', 'g', 'e', 'j', 'z', 'x', 'w','s', 'r', 'o', 'g', 'b', 'a',
    };


    mostrar_sopa(sopa);

    printf("\nIntroduce una palabra, de %d caracteres como maximo: ", M);
    gets(pal);


    for(fila=0; fila<N; fila++)
    {
        for(columna=0; columna<M; columna++)
        {
            if(buscar_palabra_horizontal(sopa, pal, fila, columna)==1)
                printf("\nHORIZONTAL:Esta en la fila %d y en la columna %d: hacia la derecha", fila+1, columna+1);

            else if(buscar_palabra_horizontal(sopa, pal, fila, columna)==2)
                printf("\nHORIZONTAL: Esta en la fila %d y en la columna %d: hacia la izquierda", fila+1, columna+longitud_pal(pal));
        }
    }
	system("PAUSE");
}

//calcula la longitud de una palabra que recibe como parámetro
int longitud_pal (char pal[M])
{
    int i;

    for(i=0; pal[i] != '\0'; i++);

    return i;

}

//compara dos palabras que recibe como parámetros,
// devuelve: 1 si son iguales y 0 si no lo son
int cad_iguales (char pal1[M], char pal2[M])
{
    int i, enc=1;

    for(i=0; pal1[i]!='\0' && pal2[i]!='\0' && enc; i++)
    {
        if(pal1[i]!=pal2[i])
            enc=0;
    }

    return enc;
}

//Función que permite al usuario mostrar la sopa de letras centrada
void mostrar_sopa(char sopa[N][M])
{
    int i, j;

    for(i=0; i<N; i++)
    {


        for(j=0; j<M; j++)
            printf("%2c", sopa[i][j]);
        printf("\n");
    }
}

//Busca la palabra horizontalmente a partir de una posición de la matriz que
//recibe como parametro
//Devuelve 0 si no la ha encontrado, 1 si la encuentra de izquierda a derecha y 2 si la encuentra de derecha a izquierda
int buscar_palabra_horizontal(char sopa[N][M], char pal[M+1], int fil, int col)
{
    int i, resul=1, resul2=2;

    char pal2[M+1]="", pal3[M+1]="";

    if (M-col<longitud_pal(pal))
       return 0;

    for(i=0; pal[i]!='\0'; i++)
        pal2[i]=sopa[fil][col+i];

    for(i=0; pal[i]!='\0'; i++)
        pal3[i]=pal2[longitud_pal(pal2)-i-1];


    if(cad_iguales(pal, pal2))
        resul=1;
    else if(cad_iguales(pal, pal3))
        resul=2;
    else resul = 0;

    return resul;
}
