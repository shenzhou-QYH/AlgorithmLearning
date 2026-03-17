#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
	int num;
	struct Node * next;
};
typedef struct Node * NodePtr;

int main(){
	int n,m;
	NodePtr head,r,p,q;
	head=new Node();
	head->next=NULL;
	r=head; //初始化 
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		NodePtr tmp=new Node();
		tmp->next=NULL;
		tmp->num=i;
		r->next=tmp;
		r=tmp;
	}
	r->next=head->next; //建立循环链表 
		
	int k;
	p=head->next; //初始为第一个节点 
	for(int i=1;i<=n;i++){
		k=1;
		while(k<m-1){
			p=p->next;
			k++;
		}//找到删除元素的前一个位置 
		q=p->next;
		cout<<q->num<<" ";
		p->next=q->next; //删除元素
		p=p->next; 
	}
	
	return 0;
}











