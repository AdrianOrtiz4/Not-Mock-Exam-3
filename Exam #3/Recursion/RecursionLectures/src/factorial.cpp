#include <iostream>

/*
 * The factorial function (symbol: !) says 
 * to multiply all whole numbers from our 
 * chosen number down to 1.
 *
 * e.g. 5! = 5*4*3*2*1 = 1*2*3*4*5
 * 5! = 5*4!
*/

long iterFactial(long n) // Integer 64 bits
{ 
    long factorial = 1;
    for (long i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
    
}

long recFactial(long n)
{
    if(n == 0) return 1;
    return n * recFactial(n-1);
}

using namespace std;
int main(int argc, char const *argv[])
{
    recFactial(5);
    for (int k = 0; k < 20; k++)
    {
        cout << "IterFactorial(" << k << ") = " << iterFactial(k) << endl;
    }

    for (int k = 0; k < 20; k++)
    {
        cout << "RecFactorial(" << k << ") = " << recFactial(k) << endl;
    }
    
    return 0;
}