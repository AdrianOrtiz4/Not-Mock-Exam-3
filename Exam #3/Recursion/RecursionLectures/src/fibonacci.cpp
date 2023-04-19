#include <iostream>

/*
 * The sequence of numbers where the first two numbers are 0 and 1, 
 * with each subsequent number being defined as the sum of the previous 
 * two numbers in the sequence.
 * 
 * note: the input parameter is the position in the sequence
 */

long recFibonacci(long n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return recFibonacci(n-1) + recFibonacci(n-2);
}

long iterFibonacci(long n)
{
    long f0 = 0;
    long f1 = 1;
    long fn;
    for (long i = 2; i < n; i++)
    {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    return fn;
    
}

long iterFibonacciHelper(long f0, long f1, long n)
{
    if(n == 0) return f0;
    return iterFibonacciHelper(f1, f0+f1, n-1);
    
}
long iterFibonacci2(long n)
{
    return iterFibonacciHelper(0, 1, n);
}

using namespace std;
int main(int argc, char const *argv[])
{
    for (int k = 0; k < 100; k++)
    {
        cout << "iterFibonacci(" << k << ") = " << iterFibonacci2(k) << endl;
    }
    return 0;
}
