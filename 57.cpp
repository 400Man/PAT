#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector<int> st;
	vector<string> input;
	vector<int> ans;
	int n;
	cin >> n;
	getchar();
	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		input.push_back(s);
	}
	// cout << input.size() << endl;
	// for(int i=0;i<n;i++)
	// 	cout << input[i] << endl;
	
	for(int i=0;i<n;i++){
		string s = input[i];
		if(s[1]=='o'){
			if(st.size()!=0){
				ans.push_back(st[st.size()-1]);
				st.pop_back();
			}
			else
				ans.push_back(-1);
		}
		else if(s[1]=='e'){
			if(st.size()!=0){
				vector<int> lis = st;
				sort(lis.begin(),lis.end());
				if(lis.size()%2==0){
					ans.push_back(lis[max(0,int(lis.size()-1/2))]);
				}
				else{
					ans.push_back(lis[int(lis.size()/2)]);
				}

			}
			else
				ans.push_back(-1);
		}
		else{
			st.push_back(stoi(s.substr(s.find(' '),s.size())));
		}
	}
	for(int i=0;i<ans.size();i++){
		if(ans[i]!=-1){
			cout << ans[i] << endl;
		}
		else
			cout << "Invalid" << endl;
	}
}