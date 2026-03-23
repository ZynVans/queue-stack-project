#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX][50];
    int front, rear;
} Queue;

typedef struct {
    char data[MAX][50];
    int top;
} Stack;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

void initStack(Stack *s) {
    s->top = -1;
}

int isEmptyQueue(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, char name[]) {
    if (q->rear == MAX - 1) {
        printf("Queue penuh!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    strcpy(q->data[q->rear], name);
}

void dequeue(Queue *q, char name[]) {
    if (isEmptyQueue(q)) {
        printf("Queue kosong!\n");
        return;
    }
    strcpy(name, q->data[q->front]);
    q->front++;
    if (q->front > q->rear)
        q->front = q->rear = -1;
}

void push(Stack *s, char name[]) {
    if (s->top == MAX - 1) {
        printf("Stack penuh!\n");
        return;
    }
    s->top++;
    strcpy(s->data[s->top], name);
}

void displayQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue kosong\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s\n", q->data[i]);
    }
}

void displayStack(Stack *s) {
    if (s->top == -1) {
        printf("History kosong\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%s\n", s->data[i]);
    }
}

int main() {
    Queue q;
    Stack s;
    initQueue(&q);
    initStack(&s);

    int choice;
    char name[50];

    do {
        printf("\n1. Tambah Antrian\n");
        printf("2. Layani Pelanggan\n");
        printf("3. Lihat Antrian\n");
        printf("4. Lihat History\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Masukkan nama: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                enqueue(&q, name);
                break;

            case 2:
                dequeue(&q, name);
                if (strlen(name) > 0) {
                    printf("Melayani: %s\n", name);
                    push(&s, name);
                }
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                displayStack(&s);
                break;
        }
    } while (choice != 5);

    return 0;
}