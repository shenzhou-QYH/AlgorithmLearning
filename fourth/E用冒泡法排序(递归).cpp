#include <iostream>
using namespace std;

void mp(int arr[], int n) {
    if (n == 1) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    mp(arr, n - 1);
}

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    mp(arr, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
