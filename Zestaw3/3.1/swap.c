/* Tomasz Dziób,  24.11.2022, tom.dziob@student.uj.edu.pl

Program zamieniający funkcyjnie wartości dwóch zmiennych

-->Instrukcja kompilacji:

gcc swap.c -o swap 
./swap

-->Spodziewany wynik:

a=3.141593      b=2.718282
a=2.718282      b=3.141593

*/
#include <stdio.h>
#include <math.h>

void swap(double *a, double *b)
{
    double zamiana;

    zamiana=*a;
    *a=*b;
    *b=zamiana;

}

int main()
{
    double a = M_PI;
    double b = M_E;
    printf("a=%lf\tb=%lf\n",a,b);
    swap(&a,&b);
    printf("a=%lf\tb=%lf\n",a,b);
    return 0;
}