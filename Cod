#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó na lista encadeada
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar um novo nó no final da lista
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Função para exibir a lista
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Bubble Sort para lista encadeada
void bubbleSort(struct Node** head) {
    if (*head == NULL) return;
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = *head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Insertion Sort para lista encadeada
void insertionSort(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    struct Node* sorted = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        struct Node* next = current->next;
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}

// Merge Sort para lista encadeada
struct Node* split(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node* mid = slow->next;
    slow->next = NULL;
    return mid;
}

struct Node* merge(struct Node* left, struct Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;

    struct Node* mid = split(head);
    struct Node* left = mergeSort(head);
    struct Node* right = mergeSort(mid);

    return merge(left, right);
}

// Quick Sort para lista encadeada
struct Node* getTail(struct Node* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

struct Node* partition(struct Node* head, struct Node* end, struct Node** newHead, struct Node** newEnd) {
    struct Node* pivot = end;
    struct Node* prev = NULL, *curr = head, *tail = pivot;

    while (curr != pivot) {
        struct Node* next = curr->next;
        if (curr->data < pivot->data) {
            if (*newHead == NULL) *newHead = curr;
            prev = curr;
        } else {
            if (prev) prev->next = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
        }
        curr = next;
    }

    if (*newHead == NULL) *newHead = pivot;
    *newEnd = tail;

    return pivot;
}

struct Node* quickSortRecur(struct Node* head, struct Node* end) {
    if (!head || head == end) return head;

    struct Node* newHead = NULL, *newEnd = NULL;
    struct Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        struct Node* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = NULL;

        newHead = quickSortRecur(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(struct Node** head) {
    *head = quickSortRecur(*head, getTail(*head));
}

// Função principal para testar os algoritmos
int main() {
    struct Node* head = NULL;

    // Adicionando elementos à lista
    append(&head, 4);
    append(&head, 2);
    append(&head, 5);
    append(&head, 3);
    append(&head, 1);

    printf("Lista original:\n");
    display(head);

    // Descomente o algoritmo que deseja testar

    // Bubble Sort
    // bubbleSort(&head);
    // printf("Lista após Bubble Sort:\n");

    // Insertion Sort
    // insertionSort(&head);
    // printf("Lista após Insertion Sort:\n");

    // Merge Sort
    // head = mergeSort(head);
    // printf("Lista após Merge Sort:\n");

    // Quick Sort
    quickSort(&head);
    printf("Lista após Quick Sort:\n");

    display(head);

    return 0;

}
