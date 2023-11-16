int Fib_i(int n)
{
    if(n == 0) return n;
    if(n == 1) return n;
    if(n>1) return Fib_i(n-1) + Fib_i(n-2);
}

double Fib_f(int n)
{
    if(n == 0) return 0.0;
    if(n == 1) return 1.0;
    if(n>1) return Fib_f(n-1) + Fib_f(n-2);
}