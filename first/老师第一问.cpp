#include <stdio.h>

// 计算一个数的二进制表示中1的个数
int count_ones(int x) {
    int cnt = 0;
    while (x > 0) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int target = count_ones(n);
        int m = n + 1;
        while (1) {
            if (count_ones(m) == target) {
                printf("%d\n", m);
                break;
            }
            m++;
        }
    }
    return 0;
}
