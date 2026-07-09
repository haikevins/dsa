#include <stdbool.h>

int getNext(int n)
{
    int sum = 0;

    while (n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n)
{
    int slow = n;
    int fast = n;

    /*
        example: 19 → 82 → 68 → 100 → 1 → 1 → 1 ...
    */
    do
    {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    while (slow != fast);

    return (slow == 1);
}