/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) 
{
    // Allocate memory for the result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    // Initialize the result array with 1s
    for (int i = 0; i < numsSize; i++)
    {
        result[i] = 1;
    }

    // Prefix
    int leftProduct = 1;
    for (int i = 0; i < numsSize; i++)
    {
        result[i] *= leftProduct;
        leftProduct *= nums[i];
    }

    // Suffix
    int rightProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return result;    
}