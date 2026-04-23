#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int jumpSearch(int arr[], int x, int n) {
    int step = sqrt(n);
    int prev = 0;
    
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n)) return -1;
    }

    if (arr[prev] == x) return prev;

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 60;
    int result = jumpSearch(arr, x, n);
    if (result == -1) cout << "Element not found";
    else cout << "Element found at index: " << result;
    return 0;
}
