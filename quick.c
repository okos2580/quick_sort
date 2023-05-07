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
    // 파일 열기
    FILE* inputFile = fopen("data.txt", "r");
    if (inputFile == NULL) {
        printf("입력 파일을 열 수 없습니다.");
        return 1;
    }

    // 파일에서 데이터 읽기
    int size = 0;
    int capacity = 10;
    int* arr = (int*)malloc(capacity * sizeof(int));

    int num;
    while (fscanf(inputFile, "%d", &num) == 1) {
        arr[size++] = num;

        // 배열 크기 조정
        if (size >= capacity) {
            capacity *= 2;
            arr = (int*)realloc(arr, capacity * sizeof(int));
        }
    }

    // 파일 닫기
    fclose(inputFile);

    // 퀵 정렬 수행
    quickSort(arr, 0, size - 1);

    // 정렬된 결과를 파일에 저장
    FILE* outputFile = fopen("result.txt", "w");
    if (outputFile == NULL) {
        printf("결과 파일을 생성할 수 없습니다.");
        free(arr);
        return 1;
    }

    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d\n", arr[i]);
    }

    // 파일 닫기
    fclose(outputFile);

    // 동적 할당한 메모리 해제
    free(arr);

    printf("퀵 정렬이 완료되었습니다.\n");

    return 0;
}
