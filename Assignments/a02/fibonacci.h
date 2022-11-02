int *la;

int iterative_fibonacci(int n)
{
    int first = 0, second = 1;
    int nth_fib = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i < 2)
        {
            nth_fib = i;
        }
        else
        {
            nth_fib = first + second;
            first = second;
            second = nth_fib;
        }
    }
    la = &nth_fib;
    return nth_fib;
}

int recursive_fibonacci(int n)
{
    int fib;
    if (n == 0)
    {
        fib = 0;
    }
    else if (n == 1)
    {
        fib = 1;
    }
    else
    {
        fib = recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
    }
    la = la < &fib ? la : &fib;
    return fib;
}