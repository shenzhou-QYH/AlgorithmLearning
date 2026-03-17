#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        int result = (int)sqrt(n);
        printf("%d\n", result);
    }
    return 0;
}
