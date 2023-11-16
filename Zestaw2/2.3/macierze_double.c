/* Tomasz Dziób,  23.12.2022, tom.dziob@student.uj.edu.pl

Program obliczający funkcyjnie P potęgę macierzy o wymiarach N x N uzywając do tego typu double.
Pierwszym argumentem programu jest rozmiar N a drugim potega P.
Macierz jest wypelniana liczbami pseudo losowymi mniejszymi lub rownymi 25.

-->Instrukcja kompilacji:

gcc macierze_double.c -o macierze_double 
./macierze_double 5 3

-->Spodziewany wynik:

Wygenerowana macierz:
9.624012        2.526932        11.912900       22.195349       5.363628     
13.313700       6.094546        23.356579       10.770745       15.393537    
10.042115       10.686819       12.047182       14.379559       1.754814     
3.180029        5.745872        22.533342       1.198614        8.185827     
5.568865        3.981903        12.778100       9.624775        5.861843     

Ta sama macierz podniesiona do 3 potegi:
19801.930455    16377.450421    37373.386948    27539.716331    14191.742466 
26462.576396    21509.037540    53635.786324    36713.751478    20923.745795 
20535.218454    16728.358874    39517.705522    29115.735268    15111.571832 
16601.021636    12976.114269    33727.231095    22844.847705    13622.313529 
14913.914124    12070.639439    29083.845137    20733.131038    11316.315828 

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Wypelnij(int n,double Tab[n][n])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            Tab[i][j]= 25 * (float)rand()/(float)(RAND_MAX);
}

void Wypisz(int n,double Tab[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%lf", Tab[i][j]);
            if(j<n-1) printf("\t");
        }
        printf("\n");
    }

}

void Mnozenie(int n,double Tab1[n][n],double Tab2[n][n],double Wynik[n][n])
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

void Potega(int n,int p,double Tab[n][n])
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
    double Wynik[n][n],Temp[n][n];
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
    double Macierz[N][N];
    srand(time(NULL));
    Wypelnij(N,Macierz);
    printf("Wygenerowana macierz:\n");
    Wypisz(N,Macierz);
    printf("\nTa sama macierz podniesiona do %d potegi:\n",P);
    Potega(N,P,Macierz);
    Wypisz(N,Macierz);
    return 0;
}