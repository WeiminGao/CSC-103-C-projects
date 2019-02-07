#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
using namespace std;

int main() {
	int points=1000, right=0, wrong=0, result=0, nlet=5, limitT=5000, useT,randnumb=0,ynumb=0, hpoints=1000;
	string randletter, yletter;
	static const char alph[] =
	        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	        "abcdefghijklmnopqrstuvwxyz";
	srand(time(NULL));
	while (points>0){
		for (int i=0; i<nlet;++i){
			randletter[i]=alph[rand()%(sizeof(alph)-1)];
			randnumb=randnumb+randletter[i];
		}
		cout<<"Your current points "<<points<<", just type ["<<nlet<<"] -->";
		for (int i=0; i<nlet; ++i) cout<<randletter[i];
		cout <<": ";
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		getline(cin,yletter);
		for(int i=0,j=yletter.size(); i<j; ++i) ynumb=ynumb+yletter[i];
		int j=yletter.size();
		if (j<nlet) ynumb=ynumb+(nlet-j)*32;
		chrono::steady_clock::time_point end= chrono::steady_clock::now();
		useT=chrono::duration_cast<chrono::milliseconds>(end - begin).count();
		cout<<useT<<" millisecond, you "<<(useT<=limitT? "made":"*failed*")<<" it within the interval of "<<limitT<<"..."<<endl;
		result=abs(randnumb-ynumb);
		randnumb=ynumb=0;
		if (result==0){
			if(useT<=limitT) points=points+100;
			++right;
			wrong=0;
		}
		else {
			if (useT<=limitT)  points=points-result;
			else {
				cout<<"String off set is "<<result<<" , your penalty is "<<result*2<<"..."<<endl;
				points=points-result*2;
			}
			++wrong;
			right=0;
		}
		if (right==3){
			++nlet;
			limitT=limitT-250;
			right=0;
			cout<<"One more for next challenge!!!"<<endl;
		}
		if (wrong==3 && nlet>1){
			--nlet;
			limitT=limitT+250;
			wrong=0;
			cout<<"Make next round for not going back!!!"<<endl;
		}
		if (wrong==3 && nlet<=1) {
			cout<<"Easiest!!! Can not reduce."<<endl;
			wrong=0;
		}
		if (points>hpoints) hpoints=points;
	}
	cout << "You lost...\nYour highest score is "<<hpoints<<"\nBye..."<<endl;
	return 0;
}
