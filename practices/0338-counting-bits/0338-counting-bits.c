int* countBits(int n, int* returnSize) 
{
    int* ans = (int*)malloc((n + 1) * sizeof(int));

    *returnSize = n + 1;

    ans[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        /*
            example: i = 5 (binary 101)
            i >> 1 = 2 (binary 10)
            ans[2] = 1 (result of 2)
            i & 1 = 1 (last bit of 5)
            ans[5] = 1 + 1 = 2
        */
        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
}