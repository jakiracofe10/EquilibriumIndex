#include <iostream>

using namespace std;

//Time: O(n2)

int findEquilibriumIndex(int* arr, int n) {
    if (n%2 != 1) { //array must be odd to have eq. index
        return -1;
    }
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
    int n=9;
    int arr[n] = {-7,1,5,2,-4,3,0,3,-5};
    int result = findEquilibriumIndex(arr,n);
    cout << result;
    return 0;
}