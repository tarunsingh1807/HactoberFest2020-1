#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 

int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 

int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 

void push(struct Stack* stack, int item) 
{ 

        stack->array[++stack->top] = item;
  
} 

int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        printf("Stack Underflow\n");
    
    return stack->array[stack->top--];
} 

int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 
void display( struct Stack* stack)
{
int i;
if(stack->top == -1)
printf("Empty Stack");
else {
for(i = stack->top;i >= 0;i--)
printf("%d ",stack->array[i]);
}

}

int main() 
{     
    long int m,l;
    int n;
    scanf("%ld",&m);
    struct Stack* stack = createStack(m); 
    while(1){
        scanf("%d",&n);
        if(n==1){
            scanf("%ld",&l);
            if (!isFull(stack)){
                
                push(stack, l);
                }
            else{
                printf("Stack Overflow\n");
            }
        }
        else if(n==2){
            if(!isEmpty(stack))
               printf("%d\n", pop(stack));
            else{
               printf("Stack Underflow\n"); 
            }    
        }
        else if(n==3){
            display(stack);
            printf("\n");
        }
        else if(n==4){
            exit(0);
        }
    }
}
