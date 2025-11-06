// Basic Algorithms for a Array-Matrix Implementation of Graph

#include <stdio.h>
#include <stdlib.h>

#include "am_graph.h"

void enqueue(int queue[], int *front, int *rear, int val) {
    if (*rear == QUEUE_MAX - 1)
        return;
    if (*front == QUEUE_EMT)
        *front = 0;
    queue[++(*rear)] = val;
}

int dequeue(int queue[], int *front, int *rear) {
    if (*front == QUEUE_EMT)
        return -1;
    int val = queue[(*front)++];
    if (*front > *rear)
        *front = *rear = QUEUE_EMT;
    return val;
}

void bfs(char v[], char e[][N], int n, char start, char key) {
    int queue[QUEUE_MAX];
    int front = QUEUE_EMT;
    int rear = QUEUE_EMT;
    int visited[N] = {0};

    int start_idx = -1;
    for (int i = 0; i < n; i++) {
        if(v[i] == start) {
            start_idx = i;
            break;
        }
    }

    if(start_idx == -1) {
        printf("There is no such start element in the graph!\n");
        return;
    }

    enqueue(queue, &front, &rear, start_idx);
    visited[start_idx] = 1;

    while (front != QUEUE_EMT) {
        int cur = dequeue(queue, &front, &rear);
        printf("%c ", v[cur]);

        if(v[cur] == key) {
            printf("Key was found\n");
            return;
        }

        for(int i = 0; i < n; i++) {
            if(e[cur][i] == 1 && visited[i] == 0) {
                enqueue(queue, &front, &rear, i);
                visited[i] = 1;
            }
        }
    }

    printf("The key was not found in the graph!\n");
    return;
}

void push(int stack[], int *top, int val) {
    if (*top == STACK_MAX - 1)
        return;
    stack[++(*top)] = val;
}

int pop(int stack[], int *top) {
    if (*top == STACK_EMT)
        return -1;
    return stack[(*top)--];
}

void dfs(char v[], int e[][N], int n, char start, char key) {
    int stack[STACK_MAX];
    int top = STACK_EMT;
    int visited[N] = {0};

    int start_idx = -1;
    for (int i = 0; i < n; i++) {
        if(v[i] == start) {
            start_idx = i;
            break;
        }
    }

    if(start_idx == -1) {
        printf("Start element is not found\n");
        return;
    }

    push(stack, &top, start_idx);
    visited[start_idx] = 1;

    while (top != STACK_EMT) {
        int cur = pop(stack, &top);
        printf("%c ", v[cur]);

        if(v[cur] == key) {
            printf("Key was found\n");
            return;
        }

        for(int i = n - 1; i >= 0; i--) {
            if(e[cur][i] == 1 && visited[i] == 0) {
                push(stack, &top, i);
                visited[i] = 1;
            }
        }
    }

    printf("The key was not found!\n");
    return;
}
