#include<stdio.h>
#define MAX 100
typedef struct{
    char items[MAX];
    int top;
}Stack;
void init(Stack *s){
    s->top = -1;
}
int isEmpty(Stack *s){
    return s->top == -1;
}
void push(Stack *s,char c){
    s->items[++(s->top)] = c;
}
char pop(Stack *s){
    return s->items[(s->top)--];
}
void conversion(int num,int base){
    Stack s;
    char digits[] = "0123456789ABCDEF";
    init(&s);
    if(num  == 0) printf("0");
    while(num > 0){
        push(&s,digits[num%base]);
        num /= base;
    }
    while(!isEmpty(&s)){
        printf("%c",pop(&s));
    }
}
int main(){
    int n;
    printf("\nEnter Decimal number : ");
    scanf("%d",&n);
    printf("\nBinary conversion is : ");
    conversion(n,2);
    printf("\nOctal conversion is : ");
    conversion(n,8);
    printf("\nHexadecimal conversion is : ");
    conversion(n,16);
    return 0;
}