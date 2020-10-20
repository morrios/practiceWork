//
//  main.c
//  53.最大子序和
//
//  Created by 杜林伟 on 2020/10/20.
//  Copyright © 2020 杜林伟. All rights reserved.
//
/*
 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

 示例:

 输入: [-2,1,-3,4,-1,2,1,-5,4]
 输出: 6
 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 进阶:

 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/maximum-subarray
 */

#include <stdio.h>
int min(int x, int y) {
    return x < y ? x : y;
}
int getMax(int x, int y) {
    return x > y ? x : y;
}
/*
 第一个子组合是以第一个数字结尾的连续序列，也就是 [-2]，最大值-2

 第二个子组合是以第二个数字结尾的连续序列，也就是 [-2,1], [1]，最大值1

 第三个子组合是以第三个数字结尾的连续序列，也就是 [-2,1,3], [1,3], [3]，最大值4

 以此类推。。。
 */
//F(n) = MAX(F(n-1) + ai, ai);


int maxSubArray1(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        nums[i] = getMax(nums[i-1]+nums[i], nums[i]);
        max = getMax(max, nums[i]);
    }
    return max;
}
//f(n) = MAX(f(n-1), f(n-1)+num)
//-1,2,3,-3,   1

int maxSubArray(int* nums, int numsSize){
  //-2,1,-3
    if (numsSize == 0) {
        return 0;
    }
    int res = nums[0];
    int max = res;
    for (int i = 0; i < numsSize - 1; i++) {
        int res1 = nums[i];
        int max1 = res1;
        for (int j = i + 1; j < numsSize; j++) {
            res1 = res1 + nums[j];
            max1 = getMax(max1, res1);
        }
        max = getMax(max, max1);
    }
    return getMax(max, nums[numsSize -1]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
//    int nums[9] = {-2,1,-3,4,-1,2,1,-5,4};
//    int res = maxSubArray1(nums, 9);
    int nums[5] = {-2,3,2,-1,-2};
    int res = maxSubArray1(nums, 5);
//    int N = 9;
//    int nums[9] = {-2,1,-3,4,-1,2,1,-5,4};
//    int res = maxSubArray1(nums, N);
    printf("结果：%d\n", res);
    return 0;
}
