#include <stdlib.h>
#include <stdint.h>

/*
    TABLE_SIZE appoximately 2 times the maximum number of elements (10^4) to reduce collisions.
*/
#define TABLE_SIZE 20011

typedef struct Node
{
    int key;              // key = nums[i]
    int value;            // value = index i
    struct Node* next;    // used when a collision occurs
} Node;

static Node* hashTable[TABLE_SIZE];

/*
    Hash function: 
    Takes a key and returns a hash value or hash code.
*/
static uint32_t hash(int key) 
{
    uint32_t x = (uint32_t)key;

    // Simple bit mixing for better hash distribution
    x ^= x >> 16;

    return x;
}

/*
    getIndex function:
    Uses the hash value to calculate the bucket index.

    This is the formula:
    index = hash(key) % number_of_buckets
*/
static int getIndex(int key) 
{
    uint32_t hashValue = hash(key);

    int index = hashValue % TABLE_SIZE;

    return index;
}

/*
    initHashTable function:
    Initializes the hash table.
*/
static void initHashTable(void) 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        hashTable[i] = NULL;
    }
}

/*
    clearHashTable function:
    Clears the hash table to prevent memory leaks.
*/
static void clearHashTable(void) 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        Node* cur = hashTable[i];

        while (cur != NULL) 
        {
            Node* temp = cur;
            cur = cur->next;
            free(temp);
        }

        hashTable[i] = NULL;
    }
}

/*
    insert function:
    Adds a key-value pair to the hash table.

    In the Two Sum problem:
    key   = nums[i]
    value = i
*/
static int insert(int key, int value) 
{
    int index = getIndex(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        return 0;
    }

    newNode->key = key;
    newNode->value = value;

    /*
        Insert the new node at the beginning of the linked list at the bucket index.
    */
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    return 1;
}

/*
    find function:
    Searches for a key in the hash table.

    If found: returns the Node*
    If not found: returns NULL
*/
static Node* find(int key) 
{
    int index = getIndex(key);

    Node* cur = hashTable[index];

    while (cur != NULL) 
    {
        if (cur->key == key) 
        {
            return cur;
        }

        cur = cur->next;
    }

    return NULL;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    initHashTable();

    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) 
    {
        int need = target - nums[i];

        Node* found = find(need);

        if (found != NULL) 
        {
            int* ans = (int*)malloc(2 * sizeof(int));

            if (ans == NULL) 
            {
                clearHashTable();
                return NULL;
            }

            ans[0] = found->value;
            ans[1] = i;
            *returnSize = 2;

            clearHashTable();

            return ans;
        }

        if (insert(nums[i], i) == 0) 
        {
            clearHashTable();
            return NULL;
        }
    }

    clearHashTable();

    return NULL;
}