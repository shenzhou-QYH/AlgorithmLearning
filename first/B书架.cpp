#include <stdio.h>
#include <stdlib.h>

// 用于qsort的比较函数，实现降序排序
int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int N, B;
    if (scanf("%d %d", &N, &B) != 2) return 1;

    int *H = (int *)malloc(N * sizeof(int));
    if (H == NULL) return 1;

    for (int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
    }

    // 将奶牛身高按从高到低排序
    qsort(H, N, sizeof(int), cmp);

    int sum = 0;
    int count = 0;

    // 从最高的奶牛开始累加
    for (int i = 0; i < N; i++) {
        sum += H[i];
        count++;
        if (sum >= B) {
            break;
        }
    }

    printf("%d\n", count);
    free(H);
    return 0;
}
