#include<bits/stdc++.h>
using namespace std;
int a[100005];

int cx(int n, int x) {
    int l = 1, r = n;
    int ans = n + 1; 
    while (l <= r) {
        int mid = (l + r) / 2; 
        if (x<=a[mid]) {
            ans = mid; 
            r = mid - 1; 
        } else {
            l = mid + 1; 
        }
    }
    return ans;
}

int main() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    while (m--) {
        scanf("%d", &x);
        printf("%d\n", cx(n, x));
    }
    return 0;
}
