#include <exception>
#include <stdio.h>

inline void Swap(int *a, int *b) {
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
    int index = RandomInt(start, end);
    Swap(&data[index], &data[end]);
    int small = start - 1;
    for(index = start; index < end; ++index) {
        if(data[index] < data[end]) {
            ++small;
            if(small != index) {
                Swap(&data[index], &data[small]);
            }
        }
    }
    ++small;
    Swap(&data[small], &data[end]);
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

int main() {
    int data[] = {2,4,5,1,6,3,7,9,8,0};
    int len = sizeof(data) / sizeof(int);
    QuickSort(data, len, 0, len - 1);
    for(int i = 0; i < len; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}