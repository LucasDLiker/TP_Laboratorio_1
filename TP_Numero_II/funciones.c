#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#include "arrayEmpleados.h"

/** \brief Funcion que recibe un mensaje y devuelve un numero entero
 *
 * \param mensaje
 * \param
 * \return devuelve un entero
 *
 */

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}

char getChar(char mensaje [])
{
    char auxiliar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);
    return auxiliar;

}

/** \brief verifica si el valor recibido solo contiene letras.-
 *
 * \param str: array con la cadena a ser analizada.-
 * \return 1 si solo ' ' contiene letras, 0 si no es asi.-
 *
 */


int onlyLetters(char str[])
{
    int i;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief verifica si el valor recibido solo contiene numeros.-
 *
 * \param str: array con la cadena a ser analizada.-
 * \return 1 si solo ' ' contiene numeros, 0 si no es asi.-
 *
 */


int onlyNumbers(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}


//numero aleatorio

char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand(time(NULL));
    return desde + (rand() % (hasta +1 - desde));
}


void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", input);
}

/** \brief Se le pide al usuario un texto y lo devuelve
 *
 * \param mensaje: el texto a ser mostrado
 * \param input: vector donde el texto sera cargado
 * \return 1: si el texto solo contiene letras / 0 si no es asi
 *
 */


int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(onlyLetters(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/** \brief Se le pide al usuario un texto y lo devuelve
 *
 * \param mensaje: el texto a ser mostrado
 * \param input: vector donde el texto sera cargado
 * \return 1: si el texto solo contiene numeros / 0 si no es asi
 *
 */


int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(onlyNumbers(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
