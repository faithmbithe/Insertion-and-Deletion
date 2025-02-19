#include <stdio.h>

#define SIZE 100

int array[SIZE];
int n = 0;

void display() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insert(int element, int position) {
    if (n >= SIZE) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    if (position < 0 || position > n) {
        printf("Invalid position! Please enter position between 0 and %d\n", n);
        return;
    }
    for (int i = n; i > position; i--) {
        array[i] = array[i - 1];
    }
    array[position] = element;
    n++;
    printf("Element inserted successfully.\n");
}

void delete(int position) {
    if (n <= 0) {
        printf("Array is empty, cannot delete.\n");
        return;
    }
    if (position < 0 || position >= n) {
        printf("Invalid position! Please enter position between 0 and %d\n", n - 1);
        return;
    }
    for (int i = position; i < n - 1; i++) {
        array[i] = array[i + 1];
    }
    n--;
    printf("Element deleted successfully.\n");
}

int main() {
    int choice, element, position;
    while (1) {
        printf("\nOperations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert at (0 to %d): ", n);
                scanf("%d", &position);
                insert(element, position);
                break;
            case 2:
                printf("Enter the position to delete from (0 to %d): ", n - 1);
                scanf("%d", &position);
                delete(position);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}
