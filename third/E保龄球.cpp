#include <bits/stdc++.h>
using namespace std;
const int SIZE=15;
string s[SIZE];
int hit[SIZE][2];
int score[SIZE];

int main(){
	int n,i=1;
	while(cin>>s[i])i++;
	i--;
	n=i;
	
	for(int i=1;i<=n;i++){
		if(s[i][0]=='/') //第一次打完 
			hit[i][0]=10;
		else if(s[i][1]=='/'){
			hit[i][0]=s[i][0]-'0'; //第二次打完 
			hit[i][1]=10-hit[i][0];
		}
		else{ //第三次打完 
			hit[i][0]=s[i][0]-'0';
			hit[i][1]=s[i][1]-'0';
		}
	}
	
	int ans=0;
	for(i=1;i<=10;i++){
		if(s[i][0]=='/'){
			int tt;
			if(s[i+1].size()<2)tt=hit[i+2][0];
			else tt=hit[i+1][1];
			score[i]=10+hit[i+1][0]+tt;
		}
		else if(s[i][1]=='/')
			score[i]=10+hit[i+1][0];
		else
			score[i]=hit[i][0]+hit[i][1];
		ans+=score[i];
	} 
	cout<<ans;
	
	
	
	return 0;
}
