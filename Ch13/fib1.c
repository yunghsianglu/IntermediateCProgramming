// fib1.c
long int fib1(int n)
{
  /* Base case */
  if ((n == 1) || (n == 2))
    {
      return 1;
    }
  /* Recursive case */
  return fib(n - 1) + fib(n - 2);
}
