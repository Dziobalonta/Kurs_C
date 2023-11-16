/* Tomasz Dziób,  08.12.2022, tom.dziob@student.uj.edu.pl

Program generujący funkcyjnie tablicę wartości dla podanej funkcji w przedziale [0,1] oraz obliczjący funkcyjnie całkę oznaczoną.

Program wykonuje się dla 3 przykładowych funkcji z biblioteki math.h czyli dla sin, cos oraz tan.

-->Instrukcja kompilacji:

gcc for_py.c -o for_py -lm
./for_py

-->Spodziewany wynik:

Dla funkcji sin:
0.000000        0.000000
0.100000        0.099833
0.200000        0.198669
0.300000        0.295520
0.400000        0.389418
0.500000        0.479426
0.600000        0.564642
0.700000        0.644218
0.800000        0.717356
0.900000        0.783327
1.000000        0.841471

Dla funkcji cos:
0.000000        1.000000
0.100000        0.995004
0.200000        0.980067
0.300000        0.955336
0.400000        0.921061
0.500000        0.877583
0.600000        0.825336
0.700000        0.764842
0.800000        0.696707
0.900000        0.621610
1.000000        0.540302

Dla funkcji sqrt:
0.000000        0.000000
0.100000        0.316228
0.200000        0.447214
0.300000        0.547723
0.400000        0.632456
0.500000        0.707107
0.600000        0.774597
0.700000        0.836660
0.800000        0.894427
0.900000        0.948683
1.000000        1.000000

*/
#include <stdio.h>
#include <math.h>
#include <limits.h>

void Table(double (*f)(double),double x_start, double x_end , double dx)
{
    for(int i=0; i<=(x_end-x_start)/dx; i++)
    {
        if (isinf(f(x_start+i*dx)))
        {
                printf("%lf\tUndefined\n", x_start+i*dx);
        } else
                printf("%lf\t%lf\n", x_start+i*dx, f(x_start+i*dx) );
    }
}

double n_integrate(double (*f)(double),double x_start, double x_end , double dx)
{
    double sum=0.0;
    for(int i=0; i<=(x_end-x_start)/dx; i++)
        sum+=f(x_start+i*dx);

    sum+= 0.5*f(x_start) +  0.5*f(x_end);

    return sum*dx;
}

int main()
{
    double (*Funkcje[])(double) = {sin,cos,sqrt,exp,cbrt,tan,fabs,asin,acos,sinh,erf,lgamma,log2};
    char Fun[13][10] = {"sin","cos","sqrt","exp","cbrt","tan","fabs","asin","acos","sinh","erf","lgamma","log2"};
    for (int i = 0; i < 13; i++)
    {
        printf("Dla funkcji %s:\n",Fun[i]);
        Table(Funkcje[i],0.0,1.0,0.1);
        printf("\n");
    }
    return 0;
}