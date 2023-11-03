#include <stdio.h>
#include <stdlib.h>

// Ba�l� liste d���m� i�in yap�y� tan�mlay�n
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

    // D���mler i�in ayr�lan belle�i bo�altmay� unutmay�n.
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

