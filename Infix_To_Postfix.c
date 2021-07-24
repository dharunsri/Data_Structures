#include<stdio.h>
#define max 50

char stack[max];
int top;
char infix[50],postfix[50];

void push(char a)
{
    if(!full()){
        top++;
        stack[top] = a;
    }
    else{
        printf("Stack overflow");
    }
}

char pop()
{
    char t;
    if(!emp()){
        t = stack[top];
        top--;
        return t;
    }
    else
        return 0;
}

int full()
{
    if(top == max-1){
        return 1;
    }
    else
        return 0;
}

int emp()
{
    if(top==-1){
        return 1;
    }
    else
        return 0;
}

int Operator(char a)
{
    if(a=='+'||a=='-'||a=='*'||a=='/'||a=='%'||a=='^'||a=='$'){
        return 1;
    }
    else
        return 0;
}

int Operand(char a)
{
    if(a>='a'&&a<='z'||a>='A'&&a<='Z'||a>='0'&&a<='9')
        return 1;
    else
        return 0;
}

int paranthesis(char a)
{
    if(a=='(')
        return 1;
    else
        return 0;
}

int weight(char a)
{
    int p;
    switch(a)
    {
    case'-':
    case'+':
        p=1;
        break;
    case'*':
    case'/':
    case'%':
        p=2;
        break;
    case'^':
    case'$':
        p=3;
        break;
    }
    return p;
}

int HighPrecedence(char a,char b)
{
    int w1,w2;
    w1 = weight(a);
    w2 = weight(b);
    if(w1==w2){
    if(associativity(a))
        return 1;
    else
        return 0;
    }
    return(w1>w2?1:0);
}

void associativity(char a)
{
    if(a=='$'||a=='^')
        return 0;
    else
        return 1;
}

void evaluate()
{
    int i,j;
    i=j=0;
    char temp;
    for(i=0;infix[i]!='\0';i++){
        temp = infix[i];
        if(Operand(temp)){
            postfix[j]=temp;
            j++;
        }
        else if(Operator(infix[i])){
            while((!emp())&&(!paranthesis(temp))&&(HighPrecedence(stack[top],temp))){
                temp = pop();
                postfix[j]=temp;
                j++;
            }
            push(infix[i]);
        }
        else if(paranthesis(temp))
            push(infix[i]);
        else if(temp == ')'){
            temp = pop();
            while(!paranthesis(temp)){
                postfix[j] = temp;
                j++;
                temp = pop();
            }
            pop();
        }
    }
    while(!emp()){
        temp = pop();
        postfix[j] = temp;
        j++;
    }
}

int main()
{
    top = -1;
    printf("Enter an expression: ");
    scanf("%s",infix);
    evaluate();
    printf("\n the inf expression: %s",infix);
    printf("\n the postfix expression: %s", postfix);
    return 0;
}
