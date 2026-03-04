#include <stdio.h>
#include <limits.h>  // 用于INT_MAX
 
// 定义结构体存储旅行券信息
typedef struct {
    int l;          // 出发日
    int r;          // 返回日
    int cost;       // 费用
    int duration;   // 持续时间
} Ticket;
 
int main() {
    int n, x;
    // 读取旅行券数量n和假期天数x
    scanf("%d %d", &n, &x);
     
    Ticket tickets[n];  // 存储所有旅行券
    // 读取每张旅行券的信息并计算持续时间
    for (int i = 0; i < n; i++) {
        int l, r, cost;
        scanf("%d %d %d", &l, &r, &cost);
        tickets[i].l = l;
        tickets[i].r = r;
        tickets[i].cost = cost;
        tickets[i].duration = r - l + 1;  // 计算持续时间
    }
     
    int min_total_cost = INT_MAX;  // 初始化最小花费为整型最大值
     
    // 遍历所有两两组合
    for (int i = 0; i < n; i++) {
        int d1 = tickets[i].duration;
        int target_d = x - d1;  // 另一张券需要的持续时间
         
        for (int j = 0; j < n; j++) {
            if (i == j) {  // 跳过同一张券
                continue;
            }
            int d2 = tickets[j].duration;
            // 检查持续时间匹配且券不相交
            if (d2 == target_d && (tickets[i].r < tickets[j].l || tickets[j].r < tickets[i].l)) {
                int total = tickets[i].cost + tickets[j].cost;
                // 更新最小花费
                if (total < min_total_cost) {
                    min_total_cost = total;
                }
            }
        }
    }
     
    // 输出结果：无符合条件的组合则输出-1
    if (min_total_cost == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", min_total_cost);
    }
     
    return 0;
}
