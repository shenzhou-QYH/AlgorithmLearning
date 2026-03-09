#include <stdio.h>

// 计算最少切换次数
int minSwitch(int n, int states[]) {
    int count1 = 0; // 目标模式：1 0 1 0...（偶数索引为1，奇数索引为0）
    int count2 = 0; // 目标模式：0 1 0 1...（偶数索引为0，奇数索引为1）
    
    for (int i = 0; i < n; ++i) {
        // 检查是否符合模式1
        int expected1 = (i % 2 == 0) ? 1 : 0;
        if (states[i] != expected1) {
            count1++;
        }
        
        // 检查是否符合模式2
        int expected2 = (i % 2 == 0) ? 0 : 1;
        if (states[i] != expected2) {
            count2++;
        }
    }
    
    // 返回两个计数中的较小值（C语言没有全局min函数，手动判断）
    return count1 < count2 ? count1 : count2;
}

int main() {
    int n;
    // 循环读取输入：第一个数是灯的数量n，后续是n个0/1状态
    while (scanf("%d", &n) == 1) {
        int states[1000]; // 定义数组存储灯的状态（假设n不超过1000，可按需调整）
        // 读取n个状态值
        for (int i = 0; i < n; ++i) {
            scanf("%d", &states[i]);
        }
        // 计算并输出结果
        printf("%d\n", minSwitch(n, states));
    }
    
    return 0;
}
