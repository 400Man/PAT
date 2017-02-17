#include <algorithm>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	string str,word;
	getline(cin,str);
	str += ' ';
	int len = str.size();
	int in_word = 0;
	map<string,int> mp;

	for(int i=0;i<len;i++){
		if(isalnum(str[i])){
			if(in_word==0){
				word.clear();
				word += tolower(str[i]);
				in_word = 1;
			}
			else{
				word += tolower(str[i]);
			}
		}
		else{
			if(in_word==1){
				mp[word]++;
				in_word=0;
			}
		}
	}

	string ans;
	int MAX;
	map<string,int>::iterator it=mp.begin();
	for(;it!=mp.end();it++){
		if(it->second>MAX){
			MAX = it->second;
			ans = it->first;
		}
		if(it->second==MAX){
			if(it->first<ans){
				MAX = it->second;
				ans = it->first;
			}
		}
		
	}
	cout << ans << " "<< MAX << endl;


}