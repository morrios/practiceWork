//
//  main.c
//  322.零钱兑换
//
//  Created by 杜林伟 on 2020/10/20.
//  Copyright © 2020 杜林伟. All rights reserved.
//

#include <stdio.h>
int min(int x, int y) {
    return x < y ? x : y;
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
    int res = coinChange2(conins, 3, 100);
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
