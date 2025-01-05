#include <stdio.h>          //incluyendo libreria para entrada y salida standard
#include <stdlib.h>         //incluyendo libreria standard para ejecutar funciones del sistema
#include <string.h>         //incluyendo libreria para manejar cadenas de caracteres
#include "letras.h"         //incluyendo libreria creada por mi con las letras que se van a utilizar
#define SCR_H 24            //definiendo lo alto de la pantalla
#define SCR_W 80            //definiendo el ancho de la pantalla

void vaciarTexto(){         //llenamos de espacios vacios(32) nuestra pantalla para su correcto funcionamiento
    for(int i=0;i<SCR_H;i++){
        for(int j=0;j<SCR_W;j++){
            pantalla[i][j]=32;
        }
    }
}

void agregarLetra(int x, int y, int letra[6][5]){   //inserta la letra correspondiente en nuestra pantalla
    for(int i=0;i<6;i++){
        for(int j=0;j<5;j++){
            pantalla[i+y][j+x]=letra[i][j];
        }
    }
}

void agregarPalabra(char palabra[16], int y){       //inserta una palabra en nuestra pantalla
    int len = strlen(palabra);
    int x = (SCR_W-(len*6))/2;
    int l = 0;
    while(l<len){
        switch(palabra[l]){
            case 'A':
                agregarLetra(x,y,A);
                break;
            case 'M':
                agregarLetra(x,y,M);
                break;
            case 'I':
                agregarLetra(x,y,I);
                break;
            case 'G':
                agregarLetra(x,y,G);
                break;
            case 'O':
                agregarLetra(x,y,O);
                break;
            case 'P':
                agregarLetra(x,y,P);
                break;
            case 'R':
                agregarLetra(x,y,R);
                break;
            case 'D':
                agregarLetra(x,y,D);
                break;
        }
        x+=6;
        l++;
    }
}

void agregarTexto(char palabra1[16], char palabra2[16]){        //inserta 2 palabras en nuestra pantalla
    agregarPalabra(palabra1, 6);
    agregarPalabra(palabra2, 14);
}

void imprimirTexto(){                           //imprime lo que tenemos preparado en nuestra pantalla
    for(int i=0;i<SCR_H;i++){
        for(int j=0;j<SCR_W;j++){
            printf("%c",pantalla[i][j]);
        }
        printf("\n");
    }
}

void mostrarImagen(char imagen[32]){            //abre el visor de imagenes geeqie con nuestra imagen
    char comando[64];
    char visor[32];
    strcpy(visor,"geeqie ");
    strcpy(comando, visor);
    strcat(comando, imagen);
    system(comando);
}

int main(){                                     //funcion principal
    char parentesco[16];                        //cadena para guardar el parentesco
    char imagen[32];                            //cadena para guardar el nombre de la imagen
    char rol[16];                               //cadena para guardar el rol

    system("clear");                            //limpiando la consola de comandos
    printf("Parentesco: ");                     //Indica que debemos ingresar el parentesco
    scanf("%s",parentesco);                     //Escanea el input de la consola de comandos
    printf("Rol: ");                            //Indica que debemos ingresar el rol
    scanf("%s",rol);                            //Escanea el input de la consola

    vaciarTexto();                              //limpiamos la pantalla con espacios vacios
    agregarTexto(parentesco,rol);               //agregamos texto a la pantalla
    imprimirTexto();                            //imprimimos el texto agregado

    strcpy(imagen, parentesco);                 //agregamos el parentesco
    strcat(imagen, rol);                        //y el rol
    strcat(imagen, ".png");                     //mas la extension de la imagen
    mostrarImagen(imagen);                      //y la mostramos en pantalla

    return 0;                                   //retornamos 0 osea sin errores.
}
