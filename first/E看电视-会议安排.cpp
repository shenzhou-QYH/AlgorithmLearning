#include <iostream>
#include <algorithm>
using namespace std;

struct meeting {
    int s, e; // 开始时间s，结束时间e
} meet[101];

int cmp(meeting a, meeting b) {
    return a.e < b.e; // 按结束时间从小到大排序
}

int main() {
    int last, n;
    int sum;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            cin >> meet[i].s >> meet[i].e;
        }
        sort(meet, meet + n, cmp); // 按结束时间排序
        sum = 1; // 选择第一个节目
        last = meet[0].e; // 记录第一个节目的结束时间
        for (int j = 1; j < n; j++) { // 扫描剩下的节目
            if (meet[j].s >= last) { // 当前节目开始时间不早于上一个结束时间
                sum++;
                last = meet[j].e; // 更新为当前节目的结束时间
            }
        }
        cout << sum << endl;
    }
    return 0;
}
