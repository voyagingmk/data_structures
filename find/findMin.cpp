#include <exception>
#include <stdio.h>

int MinInOrder(int* numbers, int index1, int index2)
{
    int result = numbers[index1];
    for(int i = index1 + 1; i <= index2; ++i)
    {
        if (result > numbers[i])
            result = numbers[i];
    }
    return result;
}


int Min(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
        throw "Invalid parameters";
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while(numbers[index1] >= numbers[index2])
    {
        if(index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;
        //如果下标为indexl、index2和indexMid指向的三个数字相等，
        //则只能顺序查找
        if(numbers[index1] == numbers[index2]
            && numbers[indexMid] == numbers[index1]) {
            return MinInOrder(numbers, index1, index2);
        }
        if(numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if(numbers[indexMid] <= numbers[index2])
            index2 = indexMid;
    }
    return numbers[indexMid];
}

int main() {
    int data[] = {4,5,6,7,8,9,1,2,3};
    int len = sizeof(data) / sizeof(int);
    int minNum = Min(data, len);
    printf("min: %d \n", minNum);
    return 0;
}