//
//  main.c
//  509.斐波那契数列
//
//  Created by 杜林伟 on 2020/10/20.
//  Copyright © 2020 杜林伟. All rights reserved.
//

#include <stdio.h>
//解法4
int fib4 (int N) {
    if (N <= 1) {
        return N;
    }
    int pre1, pre2;
    pre1 = pre2 = 1;
    
    for (int i = 3; i < N + 1; i++){
        int sum = pre1 + pre2;
        pre2 = pre1;
        pre1 = sum;
    }
    
    return pre1;
}
//解法3
int fib3 (int N) {
    if (N <= 1) {
        return N;
    }
    int memo[N + 1];
    memo[0] = 0;
    memo[1] = memo[2] = 1;
    for (int i = 2; i < N + 1; i++){
        memo[i] = memo[i - 1] + memo[i-2];
    }
    
    return memo[N];
}

//解法2
int helper(int *memo, int n) {
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n <= 1) {
        memo[n] = n;
        return n;
    }
    memo[n] = helper(memo, n-1) + helper(memo, n-2);
    return memo[n];
}

int fib2 (int N) {
    if (N <= 1) {
        return N;
    }
    int memo[N + 1];
    for (int i = 0; i < (N + 1); i++) memo[i] = -1;
    
    return helper(memo, N);
}
//解法1
int fib1 (int N) {
    if (N <= 1) {
        return N;
    }
  
    
    return fib1(N-1) + fib1(N-2);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int N = 11;
    int res1 = fib2(N);
    printf("res1 = %d\n", res1);
    int res4 = fib4(N);
    printf("res4 = %d\n", res4);
    return 0;
}

