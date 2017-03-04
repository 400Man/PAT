
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 50;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

int pre[maxn],in[maxn], post[maxn];
int n;

node* in_post_create(int postL,int postR,int inL,int inR){
	if(postL>postR)
		return NULL;
	node* root = new node;
	root->data = post[postR];
	
	int k;
	for(k=inL;k<=inR;k++)
		if(in[k]==post[postR])
			break;

	int numLeft = k-inL;
	root->lchild=in_post_create(postL,postL+numLeft-1,inL,k-1);
	root->rchild=in_post_create(postL+numLeft,postR-1,k+1,inR);
	return root;
}

int num = 0;
void BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		if(num!=n-1)
			printf("%d ", now->data);
		else
			printf("%d\n", now->data);

		if(now->lchild!=NULL)
			q.push(now->lchild);
		if(now->rchild!=NULL)
			q.push(now->rchild);
		num++;
	}
}

void reverse(node* root){
	if(root != NULL){
		reverse(root->lchild);
		reverse(root->rchild);
		swap(root->lchild,root->rchild);
	}
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> post[i];
	for(int i=0;i<n;i++)
		cin >> in[i];
	node* root = in_post_create(0,n-1,0,n-1);
	BFS(root);
	reverse(root);
	num = 0;
	BFS(root);
}





