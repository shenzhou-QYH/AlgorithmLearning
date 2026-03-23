#include <iostream>
using namespace std;
int main() {
    int num, min;
    cin >> num;
    min = num;
    for (int i = 1; i < 10; i++) {
        cin >> num;
        if (num < min) {
            min = num;
        }
    }
    cout << min << endl;

    return 0;
}
