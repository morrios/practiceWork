//
//  main.c
//  322.零钱兑换
//
//  Created by 杜林伟 on 2020/10/20.
//  Copyright © 2020 杜林伟. All rights reserved.
//
/*
 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

 你可以认为每种硬币的数量是无限的。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/coin-change
 */
#include <stdio.h>
int min(int x, int y) {
    return x < y ? x : y;
}

int coinChange3(int* coins, int coinsSize, int amount){
    if (amount == 0) {
        return 0;;
    }
    int dp[amount + 1];
    dp[0] = 0;
    for (int i = 1; i < amount + 1; i ++) {
        dp[i] = amount + 1;
        for (int j = 0; j < coinsSize; j++) {
            int coin = coins[j];
            if (i - coin < 0) {
                continue;
            }
            printf("dp[%d] = %d\n", i, dp[i]);

            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}



int dp(int* coins, int coinsSize, int amount, int *value){
    
    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return -1;
    }
    if (value[amount] != -2) {
        return value[amount];
    }
    int res = INT16_MAX;
    for (int i = 0; i < coinsSize; i ++) {
        int sub = dp(coins, coinsSize, amount - coins[i], value);
        if (sub == -1) {
            continue;
        }
        res = min(res, sub + 1);
    }
    value[amount] = (res == INT16_MAX) ? -1 : res;
    return value[amount];
}

int coinChange2(int* coins, int coinsSize, int amount){
    int v[amount + 1];
    for (int i = 0; i < (amount + 1); i++) {
        v[i] = -2;
    }
    return dp(coins, coinsSize, amount, v);
}

int coinChange1(int* coins, int coinsSize, int amount){
    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return -1;
    }
    int res = INT16_MAX;
    for (int i = 0; i < coinsSize; i++) {
        int sub = coinChange1(coins, coinsSize, amount - coins[i]);
        if (sub == -1) {
            continue;
        }
        res = min(res, sub + 1);
    }
    return res == INT16_MAX ? -1 : res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int conins[3] = {1,2,5};
    int res = coinChange3(conins, 3, 100);
    printf("res = %d \n", res);
    return 0;
}


/*

F(S) = F(S - C) + 1
F(S) = min F(S - Ci) + 1
 
 F(4) = F(2) + 1 //
    = F(3) + x
    = F(1) + x
 */
