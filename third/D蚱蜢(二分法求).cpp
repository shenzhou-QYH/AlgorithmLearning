#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 105
#define MAX_VOWELS 105 // 最多100个字符，元音最多100个，加上起点终点共102个

// 判断字符是否为元音（大小写都算）
int is_vowel(char c) {
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

// 验证：是否可以用最大跳跃距离max_jump完成全程
int check(int max_jump, int vowels[], int cnt) {
    int current = 0; // 当前位置
    for (int i = 1; i < cnt; i++) {
        if (vowels[i] - current > max_jump) {
            return 0; // 跳不过去，不可行
        }
        current = vowels[i]; // 跳到下一个元音位置
    }
    return 1; // 全程都能跳过去
}

int main() {
    char s[MAX_LEN];
    scanf("%s", s);
    int len = strlen(s);
    
    int vowels[MAX_VOWELS];
    int cnt = 0;
    vowels[cnt++] = 0; // 起点：0
    
    // 收集所有元音的位置（从1开始）
    for (int i = 0; i < len; i++) {
        if (is_vowel(s[i])) {
            vowels[cnt++] = i + 1;
        }
    }
    vowels[cnt++] = len + 1; // 终点：len+1（纸带结尾后一个位置）
    
    // 二分查找最小的最大跳跃距离
    int left = 1, right = len + 1;
    int ans = len + 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid, vowels, cnt)) {
            ans = mid;
            right = mid - 1; // 尝试更小的跳跃距离
        } else {
            left = mid + 1; // 需要更大的跳跃距离
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
