#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int num,n,len;
	cin >> len >> n;
	int vi[len];
	for(int i=0;i<len;i++){
		cin >> num;
		vi[i]=num;
	}
	
	sort(vi,vi+len);
	
	for(int i=0,j=len-1;i!=j;){
		num=vi[i]+vi[j];
		// cout << num << endl;
		if(num==n){
			cout << vi[i] << " " << vi[j] << endl;
			return 0;
		}
		else if(num>n)
			j--;
		else
			i++;
	}
	cout << "No Solution" << endl;
	return 0;
}