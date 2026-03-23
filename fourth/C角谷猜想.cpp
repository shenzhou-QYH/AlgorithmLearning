#include <iostream>
using namespace std;
int main(){
	int n,temp;
	cin>>n;
	while(n!=1){
		if(n%2!=0){
			temp=n;
			n=n*3+1;
			cout<<temp<<"*3+1="<<n<<"\n";
		}else{
			temp=n;
			n=n/2;
			cout<<temp<<"/2="<<n<<"\n";
		}
	
	}
	cout<<"End";
	return 0;
}
