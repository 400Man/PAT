#include<set>
#include<iostream>
#include<map>

using namespace std;

int main(){
	int N,K;
	map<int,set<string> > mp;
	cin >> N >> K;
	for(int i=0;i<N;i++){
		int n;
		string name;
		cin >> name >> n;
		for(int j=0;j<n;j++){
			int num;
			cin >> num;
			mp[num].insert(name);
		}
	}

	for(map<int,set<string> >::iterator it=mp.begin();it!=mp.end();it++){
		cout << it->first << " " << it->second.size() << endl;
		for(set<string>::iterator s_it=it->second.begin();s_it!=it->second.end();s_it++){
			cout << *s_it << endl;
		}
	}
}