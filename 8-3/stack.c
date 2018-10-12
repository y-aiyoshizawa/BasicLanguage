#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _stack {
    int  size;
    int  sp;      // stack pointer
    int *value;   // stack 本体
};
static struct _stack stack;

void InitStack(int size)
{
    stack.size = size;
    stack.sp   = 0;
    stack.value = (int *)malloc(sizeof(int) * size);
}

void TermStack()
{
    if (stack.value != NULL) {
        free(stack.value);
        stack.value = NULL;
    }
}

void push(int value)
{
    if (stack.sp >= stack.size) {
        printf("-- error: stack full, can't push %d --\n",value);
        return;
    }

    stack.value[stack.sp++] = value;
}

int pop()                     // 演習問題
{
	if(stack.sp == 0){
        return -1;
	}
    return stack.value[--stack.sp];
}

void PrintAllStack()          // 演習問題
{
    int i;
    for(i = stack.sp - 1; i >= 0 ; i--){
        printf("stack[$d] = $d\r\n",i,stack.value[i];
    }
}

void main()
{
    int value;
    char buff[100];

    InitStack(100);

    for(;;) {

        fgets(buff, sizeof(buff),stdin);
        buff[strlen(buff)-1] = '\0';
        if (buff[0] == 'E' || buff[0] == 'e')
            break;

        switch(buff[0]) {
        case '?' :
            printf ("-- Stack/Command list --\n");
            printf ("  U valuse →  push(value)\n");
            printf ("  O →  pop()\n");
            printf ("  E →  End、* →  PrintAllStack、T →  Test\n\n");
            break;
        case '*' :
            PrintAllStack();
            break;
        case 'T' :
        case 't' :
            push (10); printf("push/%d\n",10);
            push (20); printf("push/%d\n",20);
            push (30); printf("push/%d\n",30);
            push (40); printf("push/%d\n",40);
            push (50); printf("push/%d\n",50);
            PrintAllStack();
            value = pop(); printf("pop/%d\n", value);
            value = pop(); printf("pop/%d\n", value);
            value = pop(); printf("pop/%d\n", value);
            PrintAllStack();
            break;
        case 'U' :
        case 'u' :
            value = atoi(&buff[1]);
            push(value);
            printf("push : %d\n", value);
            break;
        case 'O' :
        case 'o' :
            value = pop();
            printf("pop : %d\n", value);
            break;
        }
    }

    TermStack();
}
