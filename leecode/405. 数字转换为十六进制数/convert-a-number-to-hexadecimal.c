// 栈的思想应用:
// 指的是利用栈的特性(先进后出)去解决问题,那么什么问题适合用栈思想解决了?
//1. 数据是线性的
//2. 问题中常常涉及到数据的来回比较,匹配问题;例如,每日温度,括号匹配,字符串解码,去掉重复字母等问题.
//3. 问题中涉及到数据的转置,例如进制问题.链表倒序打印问题等
//4. 注意并不是说栈思想只是一个解决的的参考思想.并不是万能的.它适用于以上这样的情况下去解决问题;
//利用栈思想解决问题时,首先需要透彻的解析问题之后,找到问题解决的规律.才能使用它解决;
//思想只有指导作用,遇到不同的题目,需要个例分析.在基本思想上去找到解决问题之道;
#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 顺序栈结构 */
typedef struct
{
    SElemType data[MAXSIZE];
    int top; /* 用于栈顶指针 */
} SqStack;

//4.1 构建一个空栈S
Status InitStack(SqStack *S)
{

    S->top = -1;
    return OK;
}

//4.2 将栈置空
Status ClearStack(SqStack *S)
{

    //疑问: 将栈置空,需要将顺序栈的元素都清空吗?
    //不需要,只需要修改top标签就可以了.
    S->top = -1;
    return OK;
}

//4.3 判断顺序栈是否为空;
Status StackEmpty(SqStack S)
{
    if (S.top == -1)
        return TRUE;
    else
        return FALSE;
}

//4.4 返回栈的长度
int StackLength(SqStack S)
{
    return S.top + 1;
}

//4.5 获取栈顶
Status GetTop(SqStack S, SElemType *e)
{
    if (S.top == -1)
        return ERROR;
    else
        *e = S.data[S.top];

    return OK;
}

//4.6 插入元素e为新栈顶元素
Status PushData(SqStack *S, SElemType e)
{

    //栈已满
    if (S->top == MAXSIZE - 1)
    {
        return ERROR;
    }

    //栈顶指针+1;
    S->top++;
    //将新插入的元素赋值给栈顶空间
    S->data[S->top] = e;

    return OK;
}

//4.7 删除S栈顶元素,并且用e带回
Status Pop(SqStack *S, SElemType *e)
{

    //空栈,则返回error;
    if (S->top == -1)
    {
        return ERROR;
    }

    //将要删除的栈顶元素赋值给e
    *e = S->data[S->top];
    //栈顶指针--;
    S->top--;

    return OK;
}

//4.8 从栈底到栈顶依次对栈中的每个元素打印
Status StackTraverse(SqStack S)
{
    int i = 0;
    printf("此栈中所有元素");
    while (i <= S.top)
    {
        printf("%d ", S.data[i++]);
    }
    printf("\n");
    return OK;
}

void conversion_8(int num)
{
    SqStack S;
    InitStack(&S);
    while (num)
    {
        PushData(&S, num % 8);
        num = num / 8;
    }

    SElemType e;

    while (!StackEmpty(S))
    {
        Pop(&S, &e);
        printf("%d", e);
    }
}
void conversion_16(int num)
{
    SqStack S;
    InitStack(&S);
    while (num)
    {
        PushData(&S, num % 16);
        num = num / 16;
    }

    SElemType e;

    while (!StackEmpty(S))
    {
        Pop(&S, &e);
        printf("%d", e);
    }
}

int main(int argc, const char *argv[])
{
    // insert code here...
    printf("Hello, World!\n");

    conversion_16(1348);
    return 0;
}