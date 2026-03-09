#include <stdio.h>
#include <math.h>

// 素数判定函数：是素数返回1，否则返回0
int isPrime(int x) {
    // 小于2的数不是素数
    if (x < 2) return 0;
    // 2是最小的素数
    if (x == 2) return 1;
    // 偶数（除2外）不是素数
    if (x % 2 == 0) return 0;
    // 验证3到sqrt(x)的奇数是否为因数
    int sqrtX = (int)sqrt(x);
    for (int i = 3; i <= sqrtX; i += 2) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int m;
    // 循环读取输入，直至文件尾（EOF）
    while (scanf("%d", &m) != EOF) {
        int target = m - 2;
        // 判断target是否为素数，输出对应结果
        if (isPrime(target)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
