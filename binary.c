#include <stdio.h>
#include <string.h>

int binarySearchWords(char* words[], int size, char* target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(words[mid], target);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    char* words[] = {"apple", "banana", "cherry", "grape", "orange", "peach"};
    int index = binarySearchWords(words, 6, "grape");
    if (index != -1)
        printf("Target word 'grape' found at index %d\n", index);
    else
        printf("Target word not found\n");
    return 0;
}
