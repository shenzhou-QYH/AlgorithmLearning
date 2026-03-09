#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    // 枚举a的取值，a至少为1，且a <= b <= c，故a最多为n/3
    for (int a = 1; a <= n / 3; ++a) {
        // b的下限：max(a, (n-2a)/2 + 1)，保证a<=b且a+b>c
        int lower_b = max(a, (n - 2 * a) / 2 + 1);
        // b的上限：(n - a)/2，保证b <= c
        int upper_b = (n - a) / 2;
        if (lower_b <= upper_b) {
            count += upper_b - lower_b + 1;
        }
    }
    cout << count << endl;
    return 0;
}
