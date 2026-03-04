#include <bits/stdc++.h>
using namespace std;

struct bao_wu {
    int w, v;   // 重量w，价值v
    double p;   // 性价比 p = v / w
} bw[10001];

// 根据性价比从大到小排序
int cmp(bao_wu a, bao_wu b) {
    return a.p > b.p;
}

int main() {
    int n, c;
    double sum = 0;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> bw[i].w >> bw[i].v;
        // 计算性价比
        bw[i].p = (double)bw[i].v / bw[i].w;
    }

    // 按性价比从高到低排序
    sort(bw, bw + n, cmp);

    for (int i = 0; i < n; i++) {
        if (bw[i].w <= c) {
            // 能整个装入
            sum += bw[i].v;
            c -= bw[i].w;
        } else {
            // 不能整个装入，分割物品
            sum += bw[i].p * c;
            c = 0;
        }
        if (c == 0) break; // 背包已满，提前退出
    }

    printf("%.1lf\n", sum); // 按题目要求保留一位小数
    return 0;
}
