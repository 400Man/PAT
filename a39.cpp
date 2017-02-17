#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(){
	// std::ios_base::sync_with_stdio(false);
	map<string,set<int> > mp;
	int N,K;
	int index,num;
	string input;
	cin >> N >> K;
	int test = 100;
	K = min(test,K);
	for(int i = 0;i<K;i++){
		cin >> index >> num;
		for(int j =0;j<num;j++){
			cin >> input;
			mp[input].insert(index);
		}
	}

	for(int i=0;i<N;i++){
		cin >> input;
		int size = mp[input].size();
		cout << input << " " << size;
		for(set<int>::iterator it = mp[input].begin();it!=mp[input].end();it++){
			cout << " " << *it;
		}
		cout << endl;
	}

}