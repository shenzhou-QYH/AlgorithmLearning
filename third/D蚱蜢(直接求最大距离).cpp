#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 105

int is_vowel(char c) {
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

int main() {
    char s[MAX_LEN];
    scanf("%s", s);
    int len = strlen(s);
    
    int prev = 0; // 上一个可跳位置（初始是起点0）
    int max_dist = 0; // 记录最大相邻距离
    
    // 第一步：遍历字符串，计算到每个元音的距离
    for (int i = 0; i < len; i++) {
        if (is_vowel(s[i])) {
            int curr = i + 1; // 当前元音的位置（从1开始）
            int dist = curr - prev;
            if (dist > max_dist) max_dist = dist;
            prev = curr; // 更新上一个位置
        }
    }
    
    // 第二步：计算到终点的距离（终点是len+1）
    int end = len + 1;
    int dist_to_end = end - prev;
    if (dist_to_end > max_dist) max_dist = dist_to_end;
    
    // 输出最大距离（就是答案）
    printf("%d\n", max_dist);
    return 0;
}
