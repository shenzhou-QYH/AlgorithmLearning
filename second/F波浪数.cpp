#include<bits/stdc++.h>
using namespace std;
int x,y,a,b,k;
const int maxn = 1e7 + 10;
int c[maxn];//记录每个波浪数出现的次数
int Len(int a,int k){
    int x=0;//转化为K进制的长度
    while(a){
        a/=k;
        ++x;
    }
    return x;
}
int make(int a,int b,int len,int k){
    int x=0;//生成波浪数，如535353
    for (int i=1;i<=len;++i){
        if (i%2==1) x=x*k+a;//奇数的时候 i&1==1
        else x=x*k+b;//偶数位
    }
    return x;
}

//预处理,生成K进制下所有波浪数
void dodo(int k){
    int l=Len(a,k),r=Len(b,k);
    ////取得改进进制下的任意两个数，生成波浪数
    for (int i=1;i<k;++i)//第一个数不能为0，从1开始
      for (int j=0;j<k;++j){//第二个可为0
          if (i==j) continue;//i==j不是波浪数
          for (int len=1;len<=r;++len){
              int num=make(i,j,len,k);//生成波浪数
              if (num>=a&&num<=b) ++c[num];
              //生成的波浪数在范围之内+1
          }
      }
}
int main(){
    //10 11 190000 960000 2
    //x,y表示进制的范围;a,b表示指定的范围;k表示要找的波浪数的重数。
    scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
    for (int i=x;i<=y;++i) dodo(i);//处理i进制的
    for (int i=a;i<=b;++i)//如果波浪数出现的次数==k
      if (c[i]==k) printf("%d\n",i);
    return 0;
}
