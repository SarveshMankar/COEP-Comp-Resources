#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node * next;
}
Node;

typedef struct Queue {
    struct Node * f;
    struct Node * r;
    int count;
    int size;
}
Queue;

Queue Q;

int enqueue(int data) {
    int e = INT_MIN;

    if (Q.count + 1 == Q.size) {
        return e;
    }

    Node * temp = Q.r;
    Node * qnode = (Node * ) malloc(sizeof(Node));
    qnode -> data = data;

    if (Q.count == 0) {
        Q.f = qnode;
        Q.r = qnode;
    } else {
        temp -> next = qnode;
    }

    Q.r = qnode;
    Q.count++;

    return 0;
}

int isEmpty() {
    return Q.count == 0;
}

int isFull() {
    return Q.size == Q.count;
}

int dequeue() {
    int e = INT_MIN;

    if (Q.count == 0) {
        return e;
    }

    int ret = Q.f -> data;
    Node * temp = Q.f;
    Q.f = Q.f -> next;
    free(temp);

    Q.count--;

    return ret;
}

int peekFront() {
    if (Q.count == 0) {
        return -1;
    }

    return Q.f -> data;
}

int peekRear() {
    if (Q.count == 0) {
        return -1;
    }
	
    return Q.r -> data;
}



int main() {
    Q.count = 0;

    printf("Enter Queue Size: ");
    scanf("%d", & Q.size);

    int choice;
	int flag=1;

    while (flag) {

        printf("\n1. Enqueue an Element to Queue\n2. Dequeue an Element\n3. Peek at front \n4. Peek at rear \n5. Exit\n");
        scanf("%d", & choice);

        switch (choice) {
        case 1:
            printf("Enter Element to enqueue: ");
            scanf("%d", & choice);
            enqueue(choice);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("\n%d\n", peekFront());
            break;
        case 4:
            printf("\n%d\n", peekRear());
            break;
		case 5:
			printf("Exiting!");
			flag=0;
			break;
        default:
            printf("Invalid Input! Select from 1-5: \n");
            break;
        }
    }
}