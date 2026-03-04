#include <stdio.h>
#include <stdlib.h>

// 用于qsort的比较函数，实现升序排序
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int m;
    // 读取测试数据组数
    scanf("%d", &m);

    while (m--) {
        int c, n;
        // 读取每组数据的载重c和古董数量n
        scanf("%d %d", &c, &n);

        int w[10000]; // 存储每件古董的重量
        for (int i = 0; i < n; i++) {
            scanf("%d", &w[i]);
        }

        // 将古董按重量从小到大排序
        qsort(w, n, sizeof(int), cmp);

        int total_weight = 0;
        int count = 0;

        // 从最轻的开始装，直到超重为止
        for (int i = 0; i < n; i++) {
            if (total_weight + w[i] <= c) {
                total_weight += w[i];
                count++;
            } else {
                break;
            }
        }

        // 输出该组数据的结果
        printf("%d\n", count);
    }
    return 0;
}
