#include <stdio.h>
#include <string.h>

// 模拟切断过程：输入n和m，返回最后一个被切断的城市编号
int simulate(int n, int m) {
    int cut[155] = {0}; // 0=未切断，1=已切断
    int last_cut = 0;   // 记录上一个被切断的城市编号
    int cut_count = 0;  // 已切断的城市数量

    // 第一步：先切断1号（题目固定规则）
    cut[1] = 1;
    cut_count = 1;
    last_cut = 1;
    // 如果n=1（特殊情况），直接返回1（但题目里杭州是2，n>=2）
    if (n == 1) return 1;

    // 循环切断，直到只剩最后一个城市
    while (cut_count < n) {
        int step = 0;    // 数的步数（只数未切断的）
        int current = last_cut; // 从上一个被切断的下一个开始数

        // 数m个未被切断的城市
        while (step < m) {
            // 下一个城市（绕圈：current+1超过n则回到1）
            current = (current % n) + 1;
            // 只数未切断的
            if (cut[current] == 0) {
                step++;
            }
        }

        // 切断找到的这个城市
        cut[current] = 1;
        cut_count++;
        last_cut = current;

        // 记录最后一个被切断的
        if (cut_count == n) {
            return current;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    // 从m=1开始试，找最小的符合条件的m
    for (int m = 1; ; m++) {
        if (simulate(n, m) == 2) {
            printf("%d\n", m);
            break;
        }
    }
    return 0;
}
