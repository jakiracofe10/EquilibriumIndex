#include <iostream>

using namespace std;

//Time: O(n2)
//Time2: O(n)

int findEquilibriumIndex2(int* arr, int n) {
    int sum = 0;
    int leftSum = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
    }
    for (int i=0; i<n; i++) {
        sum -= arr[i];
        if (i!=0 && i!=n-1 && sum == leftSum) {
            return i;
        }
        leftSum += arr[i];
    }
    return -1;
}

int findEquilibriumIndex(int* arr, int n) {
    for (int i=1; i<n-1; i++) {
        int sumLeft = 0;
        int sumRight = 0;
        for (int j = 0; j < i; j++) {
            sumLeft += arr[j];
        }
        for (int j = i + 1; j < n; j++) {
            sumRight += arr[j];
        }
        if (sumLeft == sumRight) {
            return i;
        }
    }
    return -1;
}

//Prints equilibrium index where sum of elements left of
//index = sum of elements right of index. -1 if no equilibrium index found
int main() {
    int arr[] = {-7,1,5,4,-4,3,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = findEquilibriumIndex2(arr,n);
    cout << result;
    return 0;
}