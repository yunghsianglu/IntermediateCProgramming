// fib2.c
long int fib2(int n)
{
  if ((n == 1) || (n == 2))
    {
      return 1;
    }
  long int fna = 1; // as fib(0) now
  long int fnb = 1; // as fib(1) now
  long int fnc;     // to hold the latest value of fib
  n --; // starting at 1, not zero
  while (n > 1)
    {
      fnc = fnb + fna; // the new value
      fna = fnb;
      fnb = fnc; 
      n --;
    }
  return fnc;
}
