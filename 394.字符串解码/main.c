//
//  main.c
//  394.字符串解码
//
//  Created by 杜林伟 on 2020/9/16.
//  Copyright © 2020 杜林伟. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
题目: 字符串编码LeetCode-中等
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
例如:
s = "3[a]2[bc]", 返回 "aaabcbc".z

s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
*/


/*
 例如:12[a]为例;

 */
char *decodeString(char *s) {
    int strLen = (int)strlen(s);
    int stackSize = 50;
    char *stack = (char*)malloc(sizeof(char) * stackSize);
    int top = -1;
    for (int i = 0; i < strLen; i++) {
        if (s[i] != ']') {
            if (top == stackSize - 1) {
                stack = (char *)realloc(stack, sizeof(char) * (stackSize += 50));
            }
            stack[++top] = s[i];
            printf("#① 没有遇到']'之前# top = %d\n",top);
        }else{
           //top这里走到一个片段最大值，是】前一个字符
            //遍历到【就是要展开的字符
            int topTemp = -1;
            int tempSize = 10;
            char *temp = (char*)malloc(sizeof(char) *tempSize);
            while (stack[top] != '[') {
                if (topTemp == tempSize - 1) {
                    temp = realloc(temp, sizeof(char) * (tempSize += 10));
                }
                temp[++topTemp] = stack[top];
                top --;
            }
            printf("#② 开始获取要复制的字符信息之后 # top = %d\n",top);
            printf("#② 开始获取要复制的字符信息之后 # topTemp = %d\n",topTemp);
            //接下来找出 数字 ‘1’ ‘2’
            int curTop = top;

            top --;//跳过【
            char strOfInt[11];
            while (top != -1 && stack[top] >= '0' && stack[top] <= '9') {
                top--;
            }
            printf("#③ 开始获取数字,数字位置下限 # top = %d\n",top);

            for (int j = top + 1; j < curTop; j++) {
                strOfInt[j - (top + 1)] = stack[j];
            }
            strOfInt[curTop - (top + 1)] = '\0';
            int curNum = atoi(strOfInt);
            for (int k = 0; k < curNum; ++k) {
                int kk = topTemp;
                while (kk != -1) {
                    if (top == stackSize -1) {
                        stack = realloc(stack, sizeof(char) * (stackSize += 50));
                    }
                    stack[++top] = temp[kk--];
                }
            }
            free(temp);
            temp = NULL;
        }
    }
    char *nas = (char*)realloc(stack, sizeof(char) * (top + 1));
    nas[++top] = '\0';
    free(stack);
    return nas;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("字符串编码问题!\n");
    
    char *s ;
    s = decodeString("3[b]2[4[r]]");
    printf("字符编码后的结果: %s\n\n\n\n",s);
    printf("\n");

    return 0;
}
