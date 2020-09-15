#include <stdio.h>
#include <stdlib.h>
int *dailyTemperatures_1(int *T, int TSize, int *returnSize)
{
    int *result = (int *)malloc(sizeof(int) * TSize);
    result[TSize - 1] = 0;
    *returnSize = TSize;
    for (int i = 0; i < TSize - 1; i++)
    {
        if (i > 0 && T[i] == T[i - 1])
        {
            result[i] = result[i - 1];
        }
        else
        {
            for (int j = i + 1; j < TSize; j++)
            {
                if (T[j] > T[i])
                {
                    result[i] = j - i;
                    break;
                }
                if (j == TSize - 1)
                {
                    result[i] = 0;
                }
            }
        }
    }
    return result;
}

int *dailyTemperatures_2(int *T, int TSize, int *returnSize)
{
    int *result = (int *)malloc(sizeof(int) * TSize);
    *returnSize = TSize;
    result[TSize - 1] = 0;
    for (int i = TSize - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < TSize; j += result[j])
        {
            if (T[i] < T[j])
            {
                result[i] = j - i;
                break;
            }
            else
            {
                if (result[j] == 0)
                {
                    result[i] = 0;
                    break;
                }
            }
        }
    }
    return result;
}
int *dailyTemperatures_3(int *T, int TSize, int *returnSize)
{
    int *result = (int *)malloc(sizeof(int) * TSize);
    int *result_index = (int *)malloc(sizeof(int) * TSize);
    *returnSize = TSize;
    int top = 0;
    for (int i = 0; i < TSize; i++)
    {
        result[i] = 0;
    }

    for (int i = 0; i < TSize; i++)
    {
        while (top > 0 && T[i] > T[result_index[top - 1]])
        {
            result[result_index[top - 1]] = i - result_index[top - 1];
            top--;
        }
        result_index[top] = i;
        top++;
    }

    return result;
}

int main(int argc, const char *argv[])
{
    // insert code here...
    printf("每日温度问题!\n");

    // int test[10] = {5, 7, 8, 2};
    int test[10] = {73, 74, 75, 71, 69, 72, 76, 73};
    //              1   1   4   2   1   1   0   0
    //int test[10]= {73, 74, 75, 75, 69, 72, 76, 73};
    //int  test[10]= {73, 74, 75, 71, 69, 78, 76, 73};
    int *result;
    int returnSize;
    result = dailyTemperatures_3(test, 8, &returnSize);
    //result = dailyTemperatures_2(test, 8, &returnSize);
    // result = dailyTemperatures_3(test, 4, &returnSize);

    printf("\n");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", test[i]);
    }
    printf("\n");

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}