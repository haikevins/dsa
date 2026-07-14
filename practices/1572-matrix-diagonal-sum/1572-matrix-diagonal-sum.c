int diagonalSum(int** mat, int matSize, int* matColSize) 
{
    int sum = 0;

    for (int i = 0; i < matSize; i++) 
    {
        sum += mat[i][i]; // Primary diagonal
        sum += mat[i][matSize - 1 - i]; // Secondary diagonal
    }

    // If the matrix size is odd, subtract the middle element once
    if (matSize % 2 == 1) 
    {
        sum -= mat[matSize / 2][matSize / 2];
    }

    return sum;    
}