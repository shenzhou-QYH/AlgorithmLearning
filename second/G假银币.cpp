#include <stdio.h>
#include <string.h>

// 存储单次称重的信息
typedef struct {
    char left[16];   // 天平左边的硬币
    char right[16];  // 天平右边的硬币
    char result[8];  // 结果：up/down/even
} Weigh;

// 检查字符c是否在字符串s中
int isIn(char c, const char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return 1;
        }
    }
    return 0;
}

// 验证假设：coin是假币，is_light=1表示轻，0表示重
int check(char coin, int is_light, const Weigh* weighs) {
    for (int i = 0; i < 3; i++) {
        int left_has = isIn(coin, weighs[i].left);
        int right_has = isIn(coin, weighs[i].right);
        
        if (strcmp(weighs[i].result, "even") == 0) {
            // 平衡则假币不能在两边
            if (left_has || right_has) {
                return 0;
            }
        } else if (strcmp(weighs[i].result, "up") == 0) {
            // 右边up（右边轻）：假币在左则必须重，在右则必须轻
            if (left_has && is_light) {
                return 0;
            }
            if (right_has && !is_light) {
                return 0;
            }
        } else if (strcmp(weighs[i].result, "down") == 0) {
            // 右边down（右边重）：假币在左则必须轻，在右则必须重
            if (left_has && !is_light) {
                return 0;
            }
            if (right_has && is_light) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    // 处理多组测试用例
    while (n--) {
        Weigh weighs[3];
        // 读取3次称重数据
        for (int i = 0; i < 3; i++) {
            scanf("%s %s %s", weighs[i].left, weighs[i].right, weighs[i].result);
        }
        
        // 枚举A-L所有硬币，验证轻重两种可能
        for (char c = 'A'; c <= 'L'; c++) {
            // 先验证是否是轻的假币
            if (check(c, 1, weighs)) {
                printf("%c is the counterfeit coin and it is light.\n", c);
                break;
            }
            // 再验证是否是重的假币
            if (check(c, 0, weighs)) {
                printf("%c is the counterfeit coin and it is heavy.\n", c);
                break;
            }
        }
    }
    return 0;
}
