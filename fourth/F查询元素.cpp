#include<bits/stdc++.h>//输入输出头文件
using namespace std;
int a[100005];

int erfen(int l,int r, int x){
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(x==a[mid])return 1;
        else if(x<a[mid])
            r=mid-1;
        else
            l=mid+1;
    }
    return 0;
}

int main(){
    int n,m,x;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    while(m--){
        scanf("%d",&x);

        if(erfen(1,n,x))
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
