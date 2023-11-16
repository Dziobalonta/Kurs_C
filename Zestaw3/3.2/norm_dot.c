/* Tomasz Dziób,  02.12.2022, tom.dziob@student.uj.edu.pl

Program obliczajacy funkcyjnie euklidesowa norme kazdego z wektorow oraz iloczyn skalarny wektorow.
Wczytywane sa dwa wektory N-wymiarowe ktore nastepnie sa wypelniane liczbami  pseudo losowymi 
typu double nie wiekszymi niz 100.

-->Instrukcja kompilacji:

gcc norm_dot.c -o norm_dot -lm
./norm_dot 3

-->Spodziewany wynik:

Tablica A:
64.278293
78.504972
17.825261

Euklidesowa norma wektora:
103.016840

Tablica B:
13.093983
99.167803
17.309894

Euklidesowa norma wektora:
101.515210

Iloczyn skalarny wektorow:
8935.377788

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int n=0;

void Wypisz(double *tab)
{
    for(int i=0;i<n;i++)
         printf("%lf\n",tab[i]);
    printf("\n");
 
}

void Losuj(double *tab)
{
    for(int i=0;i<n;i++)
       tab[i] = 100 * ((double)rand()) / ((double)RAND_MAX);
}

void Norm(double *tab1)
{
    double suma=0;
    printf("Euklidesowa norma wektora:\n");
    for(int i=0;i<n;i++)
    {
        suma+=pow(tab1[i],2);
    }
    printf("%lf\n",sqrt(suma));
    printf("\n");
}

void Dot(double *tab1,double *tab2)
{
    double suma=0;
    printf("Iloczyn skalarny wektorow:\n");
    for(int i=0;i<n;i++)
        suma+=tab1[i]*tab2[i]; 
    printf("%lf\n",suma);
}

int main(int argc, char *argv[])
{
    n=atoi(argv[1]);
    double A[n],B[n];
    srand(time(NULL));
    Losuj(&A[0]);
    Losuj(&B[0]);
    printf("Tablica A:\n");
    Wypisz(&A[0]);
    Norm(&A[0]);
    printf("Tablica B:\n");
    Wypisz(&B[0]);
    Norm(&B[0]);
    Dot(&A[0],&B[0]);
    
    return 0;
}