/*
    example: s = "abcd", t = "abcde"
    result = 0

    result ^= 'a' => result = 0 ^ 'a' = 'a'
    result ^= 'b' => result = 'a' ^ 'b' = 'c'
    result ^= 'c' => result = 'c' ^ 'c' = 0
    result ^= 'd' => result = 0 ^ 'd' = 'd'

    result ^= 'a' => result = 'd' ^ 'a' = 'e'
    result ^= 'b' => result = 'e' ^ 'b' = 'd'
    result ^= 'c' => result = 'd' ^ 'c' = 'f'
    result ^= 'd' => result = 'f' ^ 'd' = 'a'
    result ^= 'e' => result = 'a' ^ 'e' = 'e'
    
    return result = 'e'
*/

char findTheDifference(char* s, char* t) 
{
    char result = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        result ^= s[i];
    }

    for (int i = 0; t[i] != '\0'; i++)
    {
        result ^= t[i];
    }

    return result;
}