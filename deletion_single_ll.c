#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* ---------- Print ---------- */
void print_ll(struct Node *head) {
    if (!head) {
        printf("List empty\n");
        return;
    }
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* ---------- Create ---------- */
struct Node *create_ll(int size) {
    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < size; i++) {
        struct Node *new_node = malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;

        if (!head)
            head = tail = new_node;
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

/* ---------- Delete Beginning ---------- */
struct Node *delete_beginning(struct Node *head, int *size) {
    if (!head) {
        printf("List empty\n");
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    (*size)--;
    return head;
}

/* ---------- Delete End ---------- */
struct Node *delete_end(struct Node *head, int *size) {
    if (!head) {
        printf("List empty\n");
        return head;
    }
    if (!head->next) {
        free(head);
        (*size)--;
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next->next)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    (*size)--;
    return head;
}

/* ---------- Delete At Position ---------- */
struct Node *delete_at_position(struct Node *head, int *size) {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *size) {
        printf("Invalid position\n");
        return head;
    }
    if (pos == 1)
        return delete_beginning(head, size);

    struct Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
    (*size)--;
    return head;
}

/* ---------- Delete Before Number ---------- */
struct Node *delete_before_number(struct Node *head, int *size) {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    if (!head || !head->next) {
        printf("Not possible\n");
        return head;
    }
    if (head->next->data == num)
        return delete_beginning(head, size);

    struct Node *prev = head, *curr = head->next;
    while (curr->next && curr->next->data != num) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr->next) {
        printf("Number not found\n");
        return head;
    }
    prev->next = curr->next;
    free(curr);
    (*size)--;
    return head;
}

/* ---------- Delete After Number ---------- */
struct Node *delete_after_number(struct Node *head, int *size) {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    struct Node *temp = head;
    while (temp && temp->data != num)
        temp = temp->next;

    if (!temp || !temp->next) {
        printf("Deletion not possible\n");
        return head;
    }
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
    (*size)--;
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
        printf("\n1.Delete Beginning\n2.Delete End\n3.Delete Position\n");
        printf("4.Delete Before Number\n5.Delete After Number\n6.Print\n0.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head = delete_beginning(head, &size); break;
            case 2: head = delete_end(head, &size); break;
            case 3: head = delete_at_position(head, &size); break;
            case 4: head = delete_before_number(head, &size); break;
            case 5: head = delete_after_number(head, &size); break;
            case 6: print_ll(head); break;
            case 0: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
