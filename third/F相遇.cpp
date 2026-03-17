#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    int dx[4] = {0, 1, 0, -1};  // 东、南、西、北
    int dy[4] = {1, 0, -1, 0};

    while (t--) {
        int n;
        scanf("%d", &n);
        int x1, y1, d1, x2, y2, d2;
        scanf("%d %d %d", &x1, &y1, &d1);
        scanf("%d %d %d", &x2, &y2, &d2);

        // 初始就相遇
        if (x1 == x2 && y1 == y2) {
            printf("%d %d\n", x1, y1);
            continue;
        }

        // 动态分配访问标记数组
        char **vis1 = (char **)malloc(n * sizeof(char *));
        char **vis2 = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++) {
            vis1[i] = (char *)calloc(n, sizeof(char));
            vis2[i] = (char *)calloc(n, sizeof(char));
        }
        vis1[x1][y1] = 1;
        vis2[x2][y2] = 1;

        int stop1 = 0, stop2 = 0;

        while (1) {
            int nx1, ny1, nd1, stop1_new;
            int nx2, ny2, nd2, stop2_new;

            // 计算小林的新状态
            if (stop1) {
                nx1 = x1; ny1 = y1; nd1 = d1; stop1_new = 1;
            } else {
                int tx = x1 + dx[d1];
                int ty = y1 + dy[d1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < n && !vis1[tx][ty]) {
                    nx1 = tx; ny1 = ty; nd1 = d1; stop1_new = 0;
                } else {
                    int nd = (d1 + 1) % 4;  // 右转
                    tx = x1 + dx[nd];
                    ty = y1 + dy[nd];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < n && !vis1[tx][ty]) {
                        nx1 = tx; ny1 = ty; nd1 = nd; stop1_new = 0;
                    } else {
                        nx1 = x1; ny1 = y1; nd1 = d1; stop1_new = 1;
                    }
                }
            }

            // 计算小华的新状态
            if (stop2) {
                nx2 = x2; ny2 = y2; nd2 = d2; stop2_new = 1;
            } else {
                int tx = x2 + dx[d2];
                int ty = y2 + dy[d2];
                if (tx >= 0 && tx < n && ty >= 0 && ty < n && !vis2[tx][ty]) {
                    nx2 = tx; ny2 = ty; nd2 = d2; stop2_new = 0;
                } else {
                    int nd = (d2 + 3) % 4;  // 左转
                    tx = x2 + dx[nd];
                    ty = y2 + dy[nd];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < n && !vis2[tx][ty]) {
                        nx2 = tx; ny2 = ty; nd2 = nd; stop2_new = 0;
                    } else {
                        nx2 = x2; ny2 = y2; nd2 = d2; stop2_new = 1;
                    }
                }
            }

            // 更新访问标记
            if (!stop1_new) vis1[nx1][ny1] = 1;
            if (!stop2_new) vis2[nx2][ny2] = 1;

            // 同时更新位置、方向和停止标志
            x1 = nx1; y1 = ny1; d1 = nd1; stop1 = stop1_new;
            x2 = nx2; y2 = ny2; d2 = nd2; stop2 = stop2_new;

            // 检查相遇
            if (x1 == x2 && y1 == y2) {
                printf("%d %d\n", x1, y1);
                break;
            }
            if (stop1 && stop2) {
                printf("-1\n");
                break;
            }
        }

        // 释放内存
        for (int i = 0; i < n; i++) {
            free(vis1[i]);
            free(vis2[i]);
        }
        free(vis1);
        free(vis2);
    }
    return 0;
}
