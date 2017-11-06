#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>

using namespace std;
int main(){
	string s ="f 89";


	cout << to_string(stoi(s.substr(s.find(' '),s.size()))) <<endl;
}

