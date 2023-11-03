#include <stdio.h>
#include <stdlib.h>

// Baðlý liste düðümü için yapýyý tanýmlayýn
struct node {
    int data;
    struct node *next;
};

void listele(struct node *head) {
    int i = 1;
    while (head != NULL) {
        printf("%d. Dugumunun Adresi = %p \n", i, (void*)head);
        printf("%d. Dugumunun verisi = %d \n", i, head->data);
        printf("%d. Dugumunun Bagli Oldugu Dugumunun Adresi = %p\n\n", i, (void*)(head->next));
        head = head->next;
        i++;
    }
}

int main() {
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data = 6;
    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->data = 7;
    head->next->next->next = NULL;
    listele(head);
    printf("Data Structure!\n");

    // Düðümler için ayrýlan belleði boþaltmayý unutmayýn.
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

