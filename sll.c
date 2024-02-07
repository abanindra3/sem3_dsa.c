#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtHead(struct Node** head, int d) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = d;
    temp->next = *head;
    *head = temp;
}

void insertAtTail(struct Node** tail, int d) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = d;
    temp->next = NULL;
    (*tail)->next = temp;
    *tail = temp;
}


void print(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void insertAtPosition(struct Node** tail, struct Node** head, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    struct Node* temp = *head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    struct Node* nodeToInsert = (struct Node*)malloc(sizeof(struct Node));
    nodeToInsert->data = d;

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, struct Node** head) {
    if (position == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        free(temp);
    } else {
        struct Node* curr = *head;
        struct Node* prev = NULL;

        int cnt = 1;
        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Node\n");
        printf("5. Print List\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at head: ");
                scanf("%d", &data);
                insertAtHead(&head, data);
                break;

            case 2:
                printf("Enter data to insert at tail: ");
                scanf("%d", &data);
                if (tail == NULL) {
                    insertAtHead(&head, data);
                    tail = head;
                } else {
                    insertAtTail(&tail, data);
                }
                break;

            case 3:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtPosition(&tail, &head, position, data);
                break;

            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(position, &head);
                break;

            case 5:
                print(head);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}