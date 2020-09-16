#include <stdio.h>
#include <stdlib.h>
//递归
//时间复杂O(2^n)    空间复杂O(n)
int ClimbStairs_1(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return ClimbStairs_1(n - 1) + ClimbStairs_1(n - 2);
}
//动态规划 数组法 时间复杂O(n)    空间复杂O(n)
int ClimbStairs_2(int n)
{
    int *a = malloc(sizeof(int) * n);
    a[0] = 1;
    a[1] = 2;
    for (int i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i-2];
    }
    return a[n-1];
}
//动态规划 中间量法 时间复杂O(n)    空间复杂O(1)
int ClimbStairs_3(int n)
{
    int a = 0, b = 0, c = 1;
   
    for (int i = 1; i <= n; i++)
    {
        a = b;
        b = c;
        c = a + b;
    }
    return c;
}
int main(int argc, const char *argv[])
{
    // insert code here...
    printf("爬楼梯问题\n");
    int reslut = 0;

    reslut = ClimbStairs_1(6);
    printf("1 - %d\n", reslut);

     reslut = ClimbStairs_2(6);
     printf("2 - %d\n", reslut);
    reslut = ClimbStairs_3(6);
    printf("3 - %d\n", reslut);
    return 0;
}
