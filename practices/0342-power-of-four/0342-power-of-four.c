#include <stdbool.h>

bool isPowerOfFour(int n) 
{
    if (n == 1)
    {
        return true;
    }

    if (((n%2) == 1) || (n <= 0))
    {
        return false;
    }

    int countBitset = 0;
    int tmp = 0;
    for (int x = 1; x < 32; x++)
    {
        if (((n >> x) & 1) == 1)
        {
            countBitset++;
            tmp = x;
        }          
    }

    if ((countBitset == 1) && ((tmp%2) == 0))
    {
        return true;
    }

    return false;
}