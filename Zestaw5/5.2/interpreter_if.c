/* Tomasz Dziób,  28.12.2022, tom.dziob@student.uj.edu.pl

Program wykonujacy dzialania arytmetyczne zapisane w ONP na ulamkach zwyklych.
Uzywa do tego shared libraries zawieracjacych dane operacje arytmetyczne tworzone z pliku liczby_wymierne.c
W kodzie uzyta zostala funkcja wczytujaca linie tesktu oraz szukajaca slasha w ulamku,
stworzone na blokach decyzyjnych if else.

-->Instrukcja kompilacji:

chmod +x compile_if.sh
./compile_if.sh

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

int Find_slash(char *Tab)
{
    char *wynik, znak = '/';
    int index;
    wynik = strchr(Tab,znak);
    index = (int)(wynik - Tab);
    return index;

}

void String_split(char *s,int index, char *licz,char *mian)
{
    int len = strlen(s);
    if(index<len)
    {
        for (int i = 0; i < index; i++)
            licz[i] = s[i];
        licz[index] = '\0';

        for (int i = index+1; i <= len; i++)
            mian[i-index-1] = s[i];
        
    }
}

liczba_wymierna Convert(char *Tab)
{
    liczba_wymierna a;
    char mian[80],licz[80];
    int slash;
    slash = Find_slash(Tab);
    String_split(Tab,slash,licz,mian);
    a.licznik = atoi(licz);
    a.mianownik = atoi(mian);
    return a;
}


int main()
{
    FILE * fpointer;
    char line[128][80];
    liczba_wymierna dzialanie;
    fpointer = fopen("Rownanie.txt","r");
    int i=0, idzialanie;
    printf("Wczytane dzialanie:\n");
    while (!feof(fpointer))
    {
        fscanf(fpointer,"%s",line[i]);
        printf("%s\n", line[i]);
        i++;
    }
    int len = i;
    fclose(fpointer);
    for (int i = 0; i < len; i++)
    {
        if(!strcmp(line[i],"MUL"))
        {
           if(onstack < 2)
           { 
                printf("Blad!\n");
                break;
            
           }
           dzialanie = Mnozenie(stack[onstack-2],stack[onstack-1]);
           Pop(); Pop();
           Push(dzialanie);
        }else if(!strcmp(line[i],"ADD"))
        {
           if(onstack < 2)
           { 
                printf("Blad!\n");
                break;
            
           }
           dzialanie = Dodawanie(stack[onstack-2],stack[onstack-1]);
           Pop(); Pop();
           Push(dzialanie);
        }else if(!strcmp(line[i],"SUB"))
        {
           if(onstack < 2)
           { 
                printf("Blad!\n");
                break;
            
           }
           dzialanie = Odejmowanie(stack[onstack-2],stack[onstack-1]);
           Pop(); Pop();
           Push(dzialanie);
        } else if(!strcmp(line[i],"DVD"))
        {
           if(onstack < 2)
           { 
                printf("Blad!\n");
                break;
            
           }
           dzialanie = Dzielenie(stack[onstack-2],stack[onstack-1]);
           Pop(); Pop();
           Push(dzialanie);
        }else if(!strcmp(line[i],"SQR"))
        {
           if(onstack < 1)
           { 
                printf("Blad!\n");
                break;
            
           }
           dzialanie = Kwadrat(stack[onstack-1]);
           Pop();
           Push(dzialanie);
        }else if(!strcmp(line[i],"INV"))
        {
           if(onstack < 1)
           { 
                printf("Blad!\n");
                break;
            
           }
           dzialanie = Odwrocenie(stack[onstack-1]);
           Pop();
           Push(dzialanie);
        }else if(!strcmp(line[i],"NEG"))
        {
           if(onstack < 1)
           { 
                printf("Blad!\n");
                break;
            
           }
           dzialanie = Negacja(stack[onstack-1]);
           Pop();
           Push(dzialanie);
        }else
        {
            Push(Convert(line[i]));
        }           
    }
    if(dzialanie.mianownik == 0) printf("Blad! Nie mozna dzielic przez zero.\n");
    else printf("Wynik: %d/%d\n",dzialanie.licznik,dzialanie.mianownik);
    return 0;
}