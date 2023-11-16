/* Tomasz Dziób,  23.12.2022, tom.dziob@student.uj.edu.pl

Program obliczający funkcyjnie P potęgę macierzy o wymiarach N x N uzywając do tego typu integer.
Pierwszym argumentem programu jest rozmiar N a drugim potega P.
Macierz jest wypelniana liczbami pseudo losowymi mniejszymi lub rownymi 25.

-->Instrukcja kompilacji:

gcc macierze_int.c -o macierze_int 
./macierze_int 5 3

-->Spodziewany wynik:

Wygenerowana macierz:
12      1       4       17      23
8       22      15      20      7
5       7       1       13      1
12      10      2       23      6
20      2       7       9       8

Ta sama macierz podniesiona do 3 potegi:
35514   18672   13535   48437   31264
43650   35829   21830   69160   34860
18315   13928   8666    27893   14360
35740   24580   15892   52319   28544
30395   15412   11405   39007   23873

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Wypelnij(int n,int Tab[n][n])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            Tab[i][j]=(rand() % 25) + 1;
}

void Wypisz(int n,int Tab[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d", Tab[i][j]);
            if(j<n-1) printf("\t");
        }
        printf("\n");
    }

}

void Mnozenie(int n,int Tab1[n][n],int Tab2[n][n],int Wynik[n][n])
{
    for(int i=0;i<n;i++)
    {  
        for(int j=0;j<n;j++)
        {
            Wynik[i][j]=0;
            for(int k=0;k<n;k++)
            {
                Wynik[i][j] += Tab1[i][k] * Tab2[k][j];
            } 
        }
        
    }
}

void Potega(int n,int p,int Tab[n][n])
{
    if(p == 0)
    { 
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i == j) Tab[i][j]=1;
                else Tab[i][j]=0;
            }
        return;
    }
    if(p == 1) return;
    int Wynik[n][n],Temp[n][n];
    Mnozenie(n,Tab,Tab,Temp);
    for(int i=2;i<p;i++)
    {
        Mnozenie(n,Temp,Tab,Wynik);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            Tab[i][j] = Wynik[i][j];
        }   
    }
}

int main(int argc,char *argv[])
{
    int N = atoi(argv[1]), P = atoi(argv[2]);
    if (N<2)
    {
        printf("Podaj wieksza macierz!");
        return 0;
    }
    int Macierz[N][N];
    srand(time(NULL));
    Wypelnij(N,Macierz);
    printf("Wygenerowana macierz:\n");
    Wypisz(N,Macierz);
    printf("\nTa sama macierz podniesiona do %d potegi:\n",P);
    Potega(N,P,Macierz);
    Wypisz(N,Macierz);
    return 0;
}