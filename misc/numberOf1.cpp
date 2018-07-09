#include <stdio.h>

int NumberOf1(int n) {
    int count = 0;
    while(n!= 0){
        count++;
        n = n & (n - 1);
    }
    return count;
}

int main() {
    for(int i = -10; i < 10; i++) {
        printf("%d %d\n", i, NumberOf1(i));
    }
    return 0;
}