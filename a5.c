#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int *create(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    return arr;
}

void push(int arr[], int *top, int n, int value) {
    if ((*top) == n - 1) {
        printf("stack is full\n");
        return;
    } else {
        (*top)++;
        arr[(*top)] = value;
    }
}

int pop(int arr[], int *top) {
    if ((*top) == -1) {
        printf("stack is empty\n");
        return -1; 
    } else {
        int x = arr[(*top)];
        (*top)--;
        return x;
    }
}

bool isempty(int top) {
    return top == -1;
}

void print(int arr[], int top) {
    if (isempty(top)) {
        printf("stack is empty\n");
    } else {
        for (int i = 0; i <=top; i++) {
            printf("%d  ", arr[i]);
        }
        printf("\n");
    }
}

int size(int top) {
    return top + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int *st = create(n);
    int top = -1;

    for (int i = 0; i < 4; i++) {
        int x;
        printf("Enter your choice (1: Push, 2: Pop, 3: Size, 4: Exit): ");
        scanf("%d", &x);
        switch (x) {
            case 1: {
                int y;
                printf("Enter value to push: ");
                scanf("%d", &y);
                push(st, &top, n, y);
                print(st, top);
                break;
            }
            case 2: {
                int z = pop(st, &top);
                if (z != -1) {
                    printf("Popped: %d\n", z);
                }
                print(st, top);
                break;
            }
            case 3: {
                int a = size(top);
                printf("Size: %d\n", a);
                break;
            }
            case 4:
                printf("Exiting...\n");
                i = 4;
                break;
        }
    }

    return 0;
}
