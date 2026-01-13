#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* ---------- Print Linked List ---------- */
void print_ll(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------- Create Linked List ---------- */
struct Node *create_ll(int size) {
    struct Node *head = NULL, *temp = NULL, *new_node = NULL;

    for (int i = 0; i < size; i++) {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            temp = new_node;
        } else {
            temp->next = new_node;
            temp = new_node;
        }
    }
    return head;
}

/* ---------- Insert at Beginning ---------- */
struct Node *insert_beginning(struct Node *head, int *size) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);

    new_node->next = head;
    head = new_node;
    (*size)++;
    return head;
}

/* ---------- Insert at End ---------- */
struct Node *insert_end(struct Node *head, int *size) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
    (*size)++;
    return head;
}

/* ---------- Insert at Position ---------- */
struct Node *insert_at_position(struct Node *head, int *size) {
    int pos;
    printf("Enter position (1 to %d): ", *size + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > *size + 1) {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1)
        return insert_beginning(head, size);

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);

    struct Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    new_node->next = temp->next;
    temp->next = new_node;
    (*size)++;
    return head;
}

/* ---------- Insert Before a Number ---------- */
struct Node *insert_before_number(struct Node *head, int *size) {
    int num;
    printf("Enter number before which to insert: ");
    scanf("%d", &num);

    if (head == NULL) {
        printf("List empty\n");
        return head;
    }

    if (head->data == num)
        return insert_beginning(head, size);

    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != num)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Number not found\n");
        return head;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);

    new_node->next = temp->next;
    temp->next = new_node;
    (*size)++;
    return head;
}

/* ---------- Insert After a Number ---------- */
struct Node *insert_after_number(struct Node *head, int *size) {
    int num;
    printf("Enter number after which to insert: ");
    scanf("%d", &num);

    struct Node *temp = head;
    while (temp != NULL && temp->data != num)
        temp = temp->next;

    if (temp == NULL) {
        printf("Number not found\n");
        return head;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);

    new_node->next = temp->next;
    temp->next = new_node;
    (*size)++;
    return head;
}

/* ---------- MAIN ---------- */
int main() {
    int size, choice;
    struct Node *head = NULL;

    printf("Enter initial size: ");
    scanf("%d", &size);

    head = create_ll(size);

    while (1) {
        printf("\n1.Insert Beginning\n2.Insert End\n3.Insert at Position\n");
        printf("4.Insert Before Number\n5.Insert After Number\n6.Print\n0.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head = insert_beginning(head, &size); break;
            case 2: head = insert_end(head, &size); break;
            case 3: head = insert_at_position(head, &size); break;
            case 4: head = insert_before_number(head, &size); break;
            case 5: head = insert_after_number(head, &size); break;
            case 6: print_ll(head); break;
            case 0: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
