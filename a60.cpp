#include<string>
#include<iostream>

using namespace std;

int all_zero(string str){
	int dot_loc = str.find('.');
	if(dot_loc!=-1)
		str.erase(str.begin()+dot_loc);
	for(int i=0;i<str.size();i++)
		if(str[i]!='0' && str[i]!='.')
			return 0;
	return 1;
}

string Sci_Notification(int num,string str){
	string str1 = "0.";
	string str2 = "*10^";
	string zeros;
	int power = 0;

	if(all_zero(str)){
		for(int i=0;i < num;i++)
			zeros += '0';
		return str1 + zeros + str2 + "0"; 
	}

	while((str[0]=='0') && (str[1]!='.') && str.size()>1)
		str.erase(str.begin());

	if(str.find('.')==-1){
		str+=".";
	}
	int pos = str.find('.');


	for(int i=0;i < 100;i++)
		zeros += '0';
	str += zeros;

	if(str[0]=='0'&&str[1]=='.'){
		int i = 1;
		while(str[i+pos]=='0')
			i++;
		power = (i-1)*-1;
		str1 += str.substr(i+pos,num);

	}
	else{
		power = pos;
		str.erase(str.begin()+str.find('.'));
		str1 += str.substr(0,num);
	}
	string str3 = to_string(power);
	return str1 + str2 + str3;
}

int main(){
	string a,b;
	int num;
	cin >> num >> a >> b;
	string str1 = Sci_Notification(num,a);
	string str2 = Sci_Notification(num,b);
	if(str1==str2)
		cout << "YES" << " " << str1 << endl;
	else
		cout << "NO" << " " << str1 << " " << str2 << endl;

}