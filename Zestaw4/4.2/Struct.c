/* Tomasz Dziób,  22.01.2023, tom.dziob@student.uj.edu.pl

Program obliczający funkcyjnie wektor siły grawitacyjnej wykorzystując wskaźniki i struktury które trzymają  dane o masie,
wektorze 3D opisującym położenie i wektorze 3D zawierającym prędkość cząstki.

-->Instrukcja kompilacji:

gcc Struct.c -o Struct -lm
./Struct

-->Spodziewany wynik:

Dla pliku "Plummer_4.dat":

+0.048841297489890      -0.211025728793176      -0.063585171635068
-0.255251655044438      -0.019774364179025      -0.093578444145219
+0.142716267049368      +0.246273382770180      -0.120716908707502
+0.063694090505180      -0.015473289797980      +0.277880524487789

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define G 6.674e-11
#define G 1.0

typedef struct 
{
        double mas;
        double pos[3];
        double vel[3];
}cialo;

typedef struct 
{
    double x,y,z;
}Vector3D;

Vector3D Dodaj(Vector3D a, Vector3D b)
{
    Vector3D c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}

void Wczytaj(FILE * filePointer,cialo * planeta)
{
    fscanf(filePointer, "%lf %lf %lf %lf %lf %lf %lf",&planeta->mas, &planeta->pos[0], &planeta->pos[1], &planeta->pos[2], &planeta->vel[0], &planeta->vel[1], &planeta->vel[2]);
    // printf("%+lf \t %+lf \t %+lf \t %+lf \t %+lf \t %+lf \t %+lf \t\n",planeta->mas, planeta->pos[0], planeta->pos[1], planeta->pos[2], planeta->vel[0], planeta->vel[1], planeta->vel[2]);
}

Vector3D Sila_grawitacji(cialo * punkt1,cialo * punkt2)
{
    double F0=0, F1=0, F2=0;
    Vector3D Sila;
    Vector3D Roznica = {punkt1->pos[0] - punkt2->pos[0],
                        punkt1->pos[1] - punkt2->pos[1],
                        punkt1->pos[2] - punkt2->pos[2]};
    double DlWek = sqrt(Roznica.x * Roznica.x + Roznica.y * Roznica.y + Roznica.z * Roznica.z);
    double WekSilGraw = -G * punkt1->mas * punkt2->mas / (DlWek * DlWek * DlWek);
    Sila.x = WekSilGraw * Roznica.x;
    Sila.y = WekSilGraw * Roznica.y;
    Sila.z = WekSilGraw * Roznica.z;
    return Sila;
}

int main()
{
    FILE * fpointer;
    Vector3D Sila, SilaTotal;
    int n=0;
    fpointer = fopen("Plummer_4.dat","r");
    fscanf(fpointer,"%d",&n);
    cialo Tablica[n];
    for(int i=0;i<n;i++)
        Wczytaj(fpointer,&Tablica[i]);
    fclose(fpointer);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j)
            {
                Sila.x = 0.0; Sila.y = 0.0; Sila.z = 0.0;
            }else
                Sila = Sila_grawitacji(&Tablica[i],&Tablica[j]);
            SilaTotal = Dodaj(SilaTotal,Sila);
        }
        printf("%+.15lf\t%+.15lf\t%+.15lf\n",SilaTotal.x,SilaTotal.y,SilaTotal.z);
        SilaTotal.x = 0.0; SilaTotal.y = 0.0; SilaTotal.z = 0.0;
    }
    return 0;
}