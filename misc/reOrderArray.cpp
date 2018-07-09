#include <vector>

using namespace std;

void reOrderArray(vector<int> &array) {
    vector<int> result;
    int num=array.size();
    for(int i=0;i<num;i++)
        {
        if((array[i]&1)==1)
            result.push_back(array[i]);
    }
    for(int i=0;i<num;i++)
        {
        if((array[i]&1)==0)
            result.push_back(array[i]);
    }
    array=result;
}

int main() {
    vector<int> arr = {1,2,3,4};
    reOrderArray(arr);
    for( auto i : arr )
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}