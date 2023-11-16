double Silnia_f(int n)
{
    return (n>0) ? n*Silnia_f(n-1) : 1.0;
}

long long Silnia_i(int n)
{
    return (n>0) ? n*Silnia_i(n-1) : 1;
}