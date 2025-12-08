#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
char stack[MAX], infix[MAX], postfix[MAX];
int top = -1;
void push(char c){
    if(top == MAX-1) printf("Stack overflow");
    top++;
    stack[top] = c;
}
char pop(){
    if(top == -1) printf("Stack underflow");
    char c = stack[top];
    top = top-1;
    return c;
}
int isEmpty(){
    if(top == -1) return 1;
    else return 0;
}
int space(char c){
    if(c == ' '|| c == '\t') return 1;
    else return 0;
}
int precedence(char symbol){
    switch(symbol){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '-':
        case '+':
            return 1;
        default:
            return 0;
    }
}
void print(){
    int i = 0;
    printf("Postfix expression : ");
    while(postfix[i]){
        printf("%c ",postfix[i++]);
    }
    printf("\n");
}
void inToPost(){
    int i = 0,j=0;
    char symbol , next;
    for(int i = 0;i<strlen(infix);i++){
        symbol = infix[i];
        if(!space(symbol)){
            switch(symbol){
                case '(':
                    push(symbol);
                    break;
                
                case ')':
                    while(next = pop() != '(')
                        postfix[j++] = next;
                    break;

                case '*':
                case '/':
                case '-':
                case '+':
                    while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                        postfix[j++] = pop();
                    push(symbol);
                    break;
                default:
                    postfix[j++] = symbol;
                    
            }
        }
    }
    while(!isEmpty())
        postfix[j++] = pop();
    postfix[j] = 0;
}
int main(){
    printf("Enter infix expression : ");
    gets(infix);

    inToPost();
    print();
    return 0;
}