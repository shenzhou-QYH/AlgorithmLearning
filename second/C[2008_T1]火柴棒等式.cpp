#include <stdio.h>

// 每个数字对应的火柴棍数量（0-9）
int sticks[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

// 计算一个整数x需要的火柴棍数量
int countSticks(int x) {
    if (x == 0) return sticks[0]; // 单独处理0的情况
    int cnt = 0;
    while (x > 0) {
        cnt += sticks[x % 10]; // 取个位数字，累加火柴数
        x /= 10; // 去掉个位
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    int total_sticks = n - 4; // 加号(2根)+等号(2根)固定消耗4根
    if (total_sticks < 0) { // 火柴数不够拼符号，直接返回0
        printf("0\n");
        return 0;
    }

    int result = 0;
    for (int A = 0; A <= 1000; A++) {
        int a_stk = countSticks(A);
        if (a_stk >= total_sticks) continue; // 剪枝：A的火柴数已超，无需枚举B
        for (int B = 0; B <= 1000; B++) {
            int b_stk = countSticks(B);
            int C = A + B;
            int c_stk = countSticks(C);
            // 检查三者火柴数总和是否等于可用数
            if (a_stk + b_stk + c_stk == total_sticks) {
                result++;
            }
        }
    }
    printf("%d\n", result);
    return 0;
}
