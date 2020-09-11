//
//  main.c
//  003--每日温度
//
//  Created by CC老师 on 2019/10/14.
//  Copyright © 2019年 CC老师. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
/*

 LeetCode:
 题目: 根据每日气温列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置0来代替。例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
 
 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 解题关键: 实际上就是找当前元素 从[i,TSize] 找到大于该元素时. 数了几次. 首先最后一个元素默认是0,因为它后面已经没有元素了.
 */

/*
 暴力法1:
 1. 从左到右开始遍历,从第一个数到最后一个数开始遍历. 最后一个数因为后面没有元素,默认是0,不需要计算;
 2. 从[i+1,TSize]遍历,每个数直到找到比它大的数,数的次数就是对应的值;
 
 思路:
 1.创建一个result 结果数组.
 2.默认reslut[TSize-1] = 0;
 3.从0个元素遍历到最后一个元素[0,TSize-1];
    A.如果当前i >0 并且当前的元素和上一个元素相等,则没有必要继续循环. 则判断一下result[i-1]是否等于0,如果等于则直接将result[i] = 0,否则将result[i] = result[i-1]-1;
    B.遍历元素[i+1,TSize]
        如果当前T[j]>T[i],则result[i] = j-i;
        如果当前T[j]已经是最后一个元素,则默认result[i] = 0;
 
 */
int  *dailyTemperatures_1(int* T, int TSize, int* returnSize){
    
    int *result = (int *)malloc(sizeof(int) * TSize);
    *returnSize = TSize;
    result[TSize-1] = 0;
    
    for(int i = 0;i < TSize-1;i++)
        if(i>0 && T[i] == T[i-1])
            result[i] = result[i-1] == 0?0:result[i-1]-1;
        else{
            for (int j = i+1; j < TSize; j++) {
                if(T[j] > T[i]){
                    result[i] = j-i;
                    break;
                }
                if (j == TSize-1) {
                    result[i] = 0;
                }
            }
        }
    
    return result;
}

/*
 跳跃对比:
 1. 从右到左遍历. 因为最后一天的气温不会再升高,默认等于0;
 2. i 从[TSize-2,0]; 从倒数第二天开始遍历比较. 每次减一;
 3. j 从[i+1,TSize]遍历, j+=result[j],可以利用已经有结果的位置进行跳跃,从而减少遍历次数
 -若T[i]<T[j],那么Result = j - i;
 -若reuslt[j] == 0,则表示后面不会有更大的值,那么当前值就应该也是0;
 
 思路:
 1.创建一个result 结果数组.
 2.默认reslut[TSize-1] = 0;
 3.从TSize-2个元素遍历到第一个元素[TSize-2,0];
 4.从[i+1,TSize]遍历,j+=result[j];
    -若T[i]<T[j],那么Result = j - i;
    -若reuslt[j] == 0,则表示后面不会有更大的值,那么当前值就应该也是0;
 
 */

int  *dailyTemperatures_2(int* T, int TSize, int* returnSize){
    
    int *result = (int *)malloc(sizeof(int) * TSize);
    *returnSize = TSize;
    result[TSize-1] = 0;
    
    for (int i=TSize-2; i >= 0; i--) {
        for (int j = i+1; j < TSize; j+=result[j]) {
            if (T[i] < T[j]) {
                result[i] = j-i;
                break;
            }else
            {
                if (result[j] == 0) {
                    result[i] = 0;
                    break;
                }
            }
        }
    }
    
    return result;
}


/*
 思路:
 1. 初始化一个栈(用来存储索引),value数组
 2. 栈中存储的是元素的索引值index;
 3. 遍历整个温度数组从[0,TSize];
    (1).如果栈顶元素<当前元素,则将当前元素索引index-栈顶元素index,计算完毕则将当前栈顶元素移除,将当前元素索引index 存储到栈中; 出栈后,只要栈不为空.继续比较,直到栈顶元素不能满足T[i] > T[stack_index[top-1]]
 (2).如果当前的栈为空,则直接入栈;
 (3).如果当前的元素小于栈顶元素,则入栈
 (4).while循环结束后,当前元素也需要入栈;
 
 

 */
int* dailyTemperatures_3(int* T, int TSize, int* returnSize) {
    
    int* result = (int*)malloc(sizeof(int)*TSize);
    // 用栈记录T的下标。
    int* stack_index = malloc(sizeof(int)*TSize);
    *returnSize = TSize;
    // 栈顶指针。
    int top = 0;
    int tIndex;
    
    for (int i = 0; i < TSize; i++)
        result[i] = 0;
    
    for (int i = 0; i < TSize; i++) {
        printf("\n循环第%d次,i = %d\n",i,i);
       
        // 若当前元素大于栈顶元素，栈顶元素出栈。即温度升高了，所求天数为两者下标的差值。
        while (top > 0 && T[i] > T[stack_index[top-1]]) {
            tIndex = stack_index[top-1];
            result[tIndex] = i - tIndex;
            top--;
            printf("tIndex = %d; result[%d] = %d, top = %d \n",tIndex,tIndex,result[tIndex],top);
        }
        
        // 当前元素入栈。
        stack_index[top] = i;
        printf("i= %d;  StackIndex[%d] = %d ",i,top,stack_index[top]);
        top++;
        
        printf(" top = %d \n",top);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("每日温度问题!\n");
    
//    int test[10]= {5,7,8,2};
    int test[10]= {73, 74, 75, 71, 69, 72, 76, 73};
    //int test[10]= {73, 74, 75, 75, 69, 72, 76, 73};
    //int  test[10]= {73, 74, 75, 71, 69, 78, 76, 73};
    int  *result;
    int  returnSize;
    
    // result = dailyTemperatures_1(test, 8, &returnSize);
    //result = dailyTemperatures_2(test, 8, &returnSize);
    result = dailyTemperatures_3(test, 8, &returnSize);
    
    printf("\n");
    for (int i = 0; i < returnSize;i++ ) {
        printf("%d ",test[i]);
    }
    printf("\n");
    
    for (int i = 0; i < returnSize;i++ ) {
        printf("%d ",result[i]);
    }
    printf("\n");
    
    return 0;
}
