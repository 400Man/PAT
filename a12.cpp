#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct Student{
	string name;
	int score[2][4];
};

int k;
bool cmp(Student s1,Student s2){
	return s1.score[0][k] > s2.score[0][k];
}

bool cmp1(int a,int b){
	Student stu;
	stu.a
}

int main(){
	int n,m;
	cin >> n >> m;
	struct Student stu[100];
	for(int i =0;i<n;i++){
		cin >> stu[i].name >> stu[i].score[0][1] >> stu[i].score[0][2] >> stu[i].score[0][3];
		stu[i].score[0][0] = (stu[i].score[0][1]+stu[i].score[0][1]+stu[i].score[0][1])/3;
	}

	for(k=0;k<4;k++){
		sort(stu,stu+n,cmp);
		int last_score = -1;
		for(int i=0;i<n;i++){
			if(stu[i].score[0][k]==last_score)
				stu[i].score[1][k] = stu[i-1].score[1][k];
			else
				stu[i].score[1][k]=i+1;
			last_score = stu[i].score[0][k];
		}
	}







	for(int i = 0;i<n;i++)
		cout << stu[i].score[0][1] << " " << stu[i].score[1][1] << " " << stu[i].score[0][2] << " " << stu[i].score[1][2] << " " << stu[i].score[0][3] << " " << stu[i].score[1][3] << endl;

}