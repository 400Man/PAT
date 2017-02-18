#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){ 
	int n,k,num;
	scanf("%d",&n);
	vector<set<int> > vt;
	

	for(int i=0;i<n;i++){
		scanf("%d",&k);
		set<int> st;
		for(int j=0;j<k;j++){
			scanf("%d",&num);
			st.insert(num);
		}
		vt.push_back(st);
	}

	int a,b;
	set<int>::iterator it;
	scanf("%d",&n);
	vector<float> v;
	for(int i=0;i<n;i++){
		
		scanf("%d %d",&a,&b);
		float a_size=vt[a-1].size(),b_size=vt[b-1].size();
		set<int> st;
		for(it=vt[a-1].begin();it!=vt[a-1].end();it++)
			st.insert(*it);
		for(it=vt[b-1].begin();it!=vt[b-1].end();it++)
			st.insert(*it);
		float c_size = float(st.size());
		v.push_back((a_size+b_size-c_size)/c_size);
	}
	for(int i=0;i<v.size();i++){
		printf("%.1f%%\n", v[i]*100);
	}

}