#include <exception>
#include <stdio.h>

void PrintArray(int data[], int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

inline void Swap(int *a, int *b) {
    printf("%d <=> %d\n", *a, *b);
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int RandomInt(int lmin, int lmax) {
   return lmin + random() % (lmax - lmin);
}


int Partition(int data[], int len, int start, int end) {
    if (data == nullptr || len <= 0 || start < 0|| end >= len ){
        throw "Invalid Parameters";
    }
    printf("=== Partition begin: %d %d %d ===\n", len, start, end);
    int index = RandomInt(start, end);
    printf("index %d \n", index);
    Swap(&data[index], &data[end]);
    PrintArray(data, len);
    int small = start - 1;
    for(index = start; index < end; ++index) {
        if(data[index] < data[end]) {
            ++small;
            if(small != index) {
                Swap(&data[index], &data[small]);
                PrintArray(data, len);
            }
        }
    }
    ++small;
    Swap(&data[small], &data[end]);
    PrintArray(data, len);
    return small;
}

void QuickSort(int data[], int len, int start, int end) {
    if(start == end) {
        return;
    }
    int index = Partition(data, len, start, end);
    if(index > start) {
        QuickSort(data, len, start, index - 1);
    }
    if(index < end) {
        QuickSort(data, len, index + 1, end);
    }
}

void QuickSort(int data[], int len) {
    QuickSort(data, len, 0, len - 1);
}

int main() {
    int data[] = {2,4,5,1,6,3,7,9,8,0};
    int len = sizeof(data) / sizeof(int);
    PrintArray(data, len);
    QuickSort(data, len);
    PrintArray(data, len);
    return 0;
}