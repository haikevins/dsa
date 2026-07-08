void sortColors(int* nums, int numsSize) 
{
    int countColor[3] = {0};
    
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            countColor[0]++;
        }
        else if (nums[i] == 1)
        {
            countColor[1]++;
        }
        else
        {
            countColor[2]++;
        }
    }

    int index = 0;
    for (int i = 0; i < countColor[0]; i++)
    {
        nums[index++] = 0;
    }
    for (int i = 0; i < countColor[1]; i++)
    {
        nums[index++] = 1;
    }
    for (int i = 0; i < countColor[2]; i++)
    {
        nums[index++] = 2;
    }
}