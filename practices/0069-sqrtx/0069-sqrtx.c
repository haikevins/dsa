int mySqrt(int x) 
{
    if (x == 0 || x == 1)
    {
        return x;
    }

    int left = 1;
    int right = x;
    int ans = 0;

    while (left <= right)
    {
        /*
            To avoid overflow, we calculate mid as:
                mid = left + (right - left) / 2
            instead of:
                mid = (left + right) / 2
        */
        int mid = left + (right - left) / 2;

        /*
            No use mid * mid because it may cause overflow.
            Instead of checking:
                mid * mid <= x
            we check:
                mid <= x / mid
        */
        if (mid <= x / mid)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}