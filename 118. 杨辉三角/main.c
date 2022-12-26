//
//  main.c
//  118. 杨辉三角
//
//  Created by 杜林伟 on 2020/9/17.
//  Copyright © 2020 杜林伟. All rights reserved.
//

#include<stdio.h>
int** generate(int numRows, int* returnSize){
    
    *returnSize = numRows;
    
    int **res = (int **)malloc(sizeof(int*)*numRows);
    
    for (int i = 0; i < numRows; i++) {
        res[i] = (int *)malloc(sizeof(int)*(i+1));
        res[i][0] = 1;
        res[i][i] = 1;
        for (int j = 1; j < i; j++) {
            res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
    }
    
    return res;
    
    
}
 int main(){
    printf("杨辉三角问题\n");
    int numRows = 5;
    int returnSize;
    int **returnResult;
    
    returnResult =  generate(numRows, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0;  j<=i; j++) {
            printf(" %d ",returnResult[i][j]);
        }
        printf("]\n");
    }
     return 0;
 }
