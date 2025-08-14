// C program to create a stack with given capacity
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top, cap;
    int *a;
};

struct Stack* createStack(int cap) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->a = (int*)malloc(cap * sizeof(int));
    return stack;
}

void deleteStack(struct Stack* stack) {
    free(stack->a);
    free(stack);
}

int isFull(struct Stack* stack) {
    return stack->top >= stack->cap - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top < 0;
}

int push(struct Stack* stack, int x) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return 0;
    }
    stack->a[++stack->top] = x;
    return 1;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack->a[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is Empty\n");
        return 0;
    }
    return stack->a[stack->top];
}

int main() {
    struct Stack* s = createStack(5);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printf("%d popped from stack\n", pop(s));

    printf("Top element is: %d\n", peek(s));

    printf("Elements present in stack: ");
    while (!isEmpty(s)) {
        printf("%d ", peek(s));
        pop(s);
    }

    deleteStack(s);
    return 0;
}
