#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // ���� ����
    FILE* inputFile = fopen("data.txt", "r");
    if (inputFile == NULL) {
        printf("�Է� ������ �� �� �����ϴ�.");
        return 1;
    }

    // ���Ͽ��� ������ �б�
    int size = 0;
    int capacity = 10;
    int* arr = (int*)malloc(capacity * sizeof(int));

    int num;
    while (fscanf(inputFile, "%d", &num) == 1) {
        arr[size++] = num;

        // �迭 ũ�� ����
        if (size >= capacity) {
            capacity *= 2;
            arr = (int*)realloc(arr, capacity * sizeof(int));
        }
    }

    // ���� �ݱ�
    fclose(inputFile);

    // �� ���� ����
    quickSort(arr, 0, size - 1);

    // ���ĵ� ����� ���Ͽ� ����
    FILE* outputFile = fopen("result.txt", "w");
    if (outputFile == NULL) {
        printf("��� ������ ������ �� �����ϴ�.");
        free(arr);
        return 1;
    }

    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d\n", arr[i]);
    }

    // ���� �ݱ�
    fclose(outputFile);

    // ���� �Ҵ��� �޸� ����
    free(arr);

    printf("�� ������ �Ϸ�Ǿ����ϴ�.\n");

    return 0;
}
