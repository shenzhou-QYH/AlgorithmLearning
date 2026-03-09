#include <iostream>
#include <cmath>
using namespace std;
//A'和B' 均不大于L

//1. A’和 B’互质，
//2. A’/ B’ ≥ A/B且
//3. A’/B’ - A/B 的值尽可能小
int gcd(int a,int b){
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}

int main(){
	int a,b,L,a1,b1;
	double minn=1e9;
	cin>>a>>b>>L;
	double f=1.0*a/b;
	for(int i=1;i<=L;i++)//A'
	for(int j=1;j<=L;j++){//B'
		double f1=1.0*i/j;
		if(gcd(i,j)){//1
			if(f1>f && f1-f<minn){//2、3 
				minn=f1-f;
				a1=i;
				b1=j;
			}
		}
	}
	cout<<a1<<" "<<b1;
	return 0;
} 















