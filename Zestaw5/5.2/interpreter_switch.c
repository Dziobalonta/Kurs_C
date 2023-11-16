
/* Tomasz Dziób,  21.01.2022, tom.dziob@student.uj.edu.pl

Program wykonujacy dzialania arytmetyczne zapisane w ONP na ulamkach zwyklych.
Uzywa do tego shared libraries zawieracjacych dane operacje arytmetyczne tworzone z pliku liczby_wymierne.c

-->Instrukcja kompilacji:

chmod +x compile_switch.sh
./compile_switch.sh

-->Spodziewany wynik:

Wczytane dzialanie:
1/137
SQR
2/9
SUB
INV
Wynik: -168921/37529

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liczby_wymierne.h"

liczba_wymierna stack[128];
int onstack = 0;

void Push(liczba_wymierna a)
{
    if(onstack == 128)
    {
        printf("Stos zostal przepelniony!\n");
        return;
    }
    stack[onstack] = a;
    onstack++;
}

liczba_wymierna Pop()
{
    liczba_wymierna wynik = stack[onstack];
    if(onstack == 0)
    {
        printf("Stos jest pusty!\n");
    }
    else
    {
        wynik = stack[onstack-1];
        onstack--;
    }
    return wynik;
}

enum Operacje
{
    MUL=238,
    ADD=201,
    SUB=234,
    DVD=222,
    SQR=246,
    INV=237,
    NEG=218,
};

int Hashowanie(char *line)
{
    return (int)line[0]+(int)line[1]+(int)line[2];
}

int main()
{
    FILE * fpointer;
    char line[128];
    liczba_wymierna dzialanie;
    fpointer = fopen("Rownanie.txt","r");
    int i=0, idzialanie;
    printf("Wczytane dzialanie:\n");
    while (!feof(fpointer))
    {
        fscanf(fpointer,"%s",line);
        switch(Hashowanie(line))
        {
        case MUL:
            if(onstack < 2)
            {
                printf("Blad!\n");
                break;

            }
            dzialanie = Mnozenie(stack[onstack-2],stack[onstack-1]);
            Pop(); Pop();
            Push(dzialanie);
            break;
        case ADD:
            if(onstack < 2)
            {
                printf("Blad!\n");
                break;

            }
            dzialanie = Dodawanie(stack[onstack-2],stack[onstack-1]);
            Pop(); Pop();
            Push(dzialanie);
            break;
        case SUB:
            if(onstack < 2)
            {
                printf("Blad!\n");
                break;

            }
            dzialanie = Odejmowanie(stack[onstack-2],stack[onstack-1]);
            Pop(); Pop();
            Push(dzialanie);
            break;
        case DVD:
            if(onstack < 2)
            {
                printf("Blad!\n");
                break;

            }
            dzialanie = Dzielenie(stack[onstack-2],stack[onstack-1]);
            Pop(); Pop();
            Push(dzialanie);
            break;
        case SQR:
            if(onstack < 1)
            {
                printf("Blad!\n");
                break;

            }
            dzialanie = Kwadrat(stack[onstack-1]);
            Pop();
            Push(dzialanie);
            break;
        case INV:
            if(onstack < 1)
            {
                printf("Blad!\n");
                break;

            }
            dzialanie = Odwrocenie(stack[onstack-1]);
            Pop();
            Push(dzialanie);
            break;
        case NEG:
            if(onstack < 1)
            {
                printf("Blad!\n");
                break;

            }
            dzialanie = Negacja(stack[onstack-1]);
            Pop();
            Push(dzialanie);
        default :
            fseek(fpointer,-strlen(line),SEEK_CUR);
            fscanf(fpointer,"%d/%d",&dzialanie.licznik,&dzialanie.mianownik);
            Push(dzialanie);
            break;
        }
        printf("%s\n", line);
        i++;
    }
    fclose(fpointer);
    if(dzialanie.mianownik == 0) printf("Blad! Nie mozna dzielic przez zero.\n");
    else printf("Wynik: %d/%d\n",dzialanie.licznik,dzialanie.mianownik);
    return 0;
}