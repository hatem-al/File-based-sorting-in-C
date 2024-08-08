#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to read integers from a file
int readIntegers(const char *filename, int **arr) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    int size = 0;
    fscanf(file, "%d", &size);
    *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &(*arr)[i]);
    }

    fclose(file);
    return size;
}

// Function to write integers to a file
void writeIntegers(const char *filename, int *arr, int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    fprintf(file, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

int main() {
    const char *inputFile = "test/test1.txt";   // Path to the input file you want in the test folder
    const char *outputFile = "test/output.txt"; // Path to the output file in the test folder

    int *arr;
    int size = readIntegers(inputFile, &arr);
    if (size == -1) {
        return 1;
    }

    bubbleSort(arr, size);
    writeIntegers(outputFile, arr, size);

    printf("Integers sorted and written to %s\n", outputFile);

    free(arr);
    return 0;
}
