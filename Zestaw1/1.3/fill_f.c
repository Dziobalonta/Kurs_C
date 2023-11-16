#include <stdio.h>
#include "fill_f.h"

void Wypisz(float x, float y,int n)
{
    printf("{ %f,\t%f },\n",x/(n-1),y/(n-1));
}

void Poziomo(int n)
{
    int i;
    float x=0,y=0;
    for(int j=0;j<n/2;j++)
    {
        for(i=0; i<n; i++)
        {
             Wypisz(x,y,n);;
            x++;
        } 
        y++;
        for(i; i>0; i--)
        {
            printf("{ %f,\t%f },\n",(x-1)/(n-1),y/(n-1));
            x--;
        }
        y++;
    }
    if(n%2!=0) 
    {
       for(i=0; i<n; i++)
        {
             Wypisz(x,y,n);
            x++;
        } 
    }
}

void Pionowo(int n)
{
    int i;
    float x=0,y=0;
    for(int j=0;j<n/2;j++)
    {
        for(i=0; i<n; i++)
        {
             Wypisz(x,y,n);
            y++;
        } 
        x++;
        for(i; i>0; i--)
        {
            printf("{ %f,\t%f },\n",x/(n-1),(y-1)/(n-1));
            y--;
        }
        x++;
    }
   if(n%2!=0) 
    {
       for(i=0; i<n; i++)
        {
             Wypisz(x,y,n);
            y++;
        } 
    }
}

void Na_skos(int n)
{
    int i,przekatna=1;
    float x=0,y=0,p;
    for(int k=2;k<n;k++)
    {
        przekatna+=2;
    }
    printf("( %f,\t%f )\n",x,y);                  ///
    y++;                                         ///  Pierwsze 3 zawsze takie same
    Wypisz(x,y,n);                              ///
    y--;
    x++;
    Wypisz(x,y,n);
    p=3;
    x++;
    if(n == 2)                        // Gdy dwa
    {
        y++;
        x--;
        Wypisz(x,y,n);
        return;
    }
    if(n == 3)                      // Gdy trzy
    {
        for(int i=0;i<3;i++)
        {
            Wypisz(x,y,n); 
            x--;
            y++;
        }
        x+=2;
        y--;
        Wypisz(x,y,n);
        x++;
        y--;
        Wypisz(x,y,n);
        y++;
        Wypisz(x,y,n);
        return;

    }
    for(int i=0;i<(przekatna/4)-1;i++)   
    {
        for(int j=0;j<p;j++)
        {
           Wypisz(x,y,n);
           x--;
           y++; 
        }
        p++;
        x++;
        for(int j=p;j>0;j--)
        {
           Wypisz(x,y,n);
           x++;
           y--;
        }
        p++;
        y++;
    }
    if(n%2!=0) // NIEPARZYSTE
    {
        for(int j=0;j<p;j++)
        {
           Wypisz(x,y,n);
           x--;
           y++; 
        }
        p++;
        x++;
        for(int j=p;j>0;j--)
        {
           Wypisz(x,y,n);
           x++;
           y--;
        }
        y++;
        p++;
        for(int j=0;j<p;j++) // linia srodkowa
        {
           Wypisz(x,y,n);
           x--;
           y++; 
        }
        ////////////////////// Druga polowa 
        x+=2;
        y--;
        p--;  
        for(int i=(przekatna/4)+1;i>0;i--)
        {
            for(int j=0;j<p;j++)
            {
                Wypisz(x,y,n);
                x++;
                y--; 
            }
            p--;
            x--;
            y+=2;
            for(int j=p;j>0;j--)
            {
                Wypisz(x,y,n);
                y++;
                x--;
            }
            p--;
            y--;
            x+=2;
        }
    } 
    else // PARZYSTE
    {
        for(int j=0;j<p;j++)
        {
            Wypisz(x,y,n);
            x--;
            y++;
        }
        p++;
        x++;
        for(int j=p;j>0;j--) // linia srodkowa
        {
           Wypisz(x,y,n);
           x++;
           y--;
        }
        ////////////////////// Druga polowa
        y+=2;
        x--;
        p--;
        for(int i=(przekatna/4);i>0;i--)
        {
            for(int j=0;j<p;j++)
            {
                Wypisz(x,y,n);
                x--;
                y++; 
            }
            p--;
            y--;
            x+=2;
            for(int j=p;j>0;j--)
            {
                Wypisz(x,y,n);
                x++;
                y--;
            }
            p--;
            x--;
            y+=2;
        }
        Wypisz(x,y,n);
    }
}

void Spiralnie(int n)
{
    float x=0,y=0;
    int dl = n-1;
    for(int j=0;j<(n/2);j++)
    {
        for (int i = 0; i < dl; i++)                          
        {
             Wypisz(x,y,n);
            y++;
        }
        for (int i = 0; i < dl; i++)
        {
             Wypisz(x,y,n);
            x++;
        }
        for (int i = 0; i < dl; i++)
        {
             Wypisz(x,y,n);
            y--;
        }
        for (int i = 0; i < dl; i++)
        {
             Wypisz(x,y,n);
            x--;
        }
        x++;
        y++;
        dl-=2;
    }
    if (n%2 == 1)
         Wypisz(x,y,n);
}