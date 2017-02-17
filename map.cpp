#include<map>
#include<iostream>
#include<string>

using namespace std;

int main(){
	map<string,int> m;
	m["Han Jialu"] = 344;
	m["Math"] = 88;
	m["Computer"] = 122;
	map<string,int>::iterator it = m.begin();
	for(;it!=m.end();it++)
		cout << it->first << " " << it->second << endl;
	if(m.find("English")!=m.end()){
		cout << m.find("Math")->first << " " << endl;
	}
	cout << "m's size: " << m.size() << endl;
}