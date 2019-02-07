#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int p1_allow=100, p2_allow=100, y_allow=100, p1_bet, p2_bet, y_bet, dice, p1_dice, p2_dice;
	char p1_choice, p2_choice, y_choice, dice_result;
	cout <<"You have "<<y_allow<<endl<<"Player 1 has "<<p1_allow<<endl<<"Player 2 has "<<p2_allow<<endl;
	while(y_allow>0 && p1_allow>0 && p2_allow>0){
		cout<<"Please guess the sum of two dices is 'o' (old) or 'e' (even): ";
		cin>>y_choice;
		if (y_choice!='o'&&y_choice!='e') {
		cout<<"Please don't enter other letter or number, enter 'o' (old) or 'e' (even) in this game."<<endl;
		cin >> y_choice;}
		cout<<"Please enter an amount you bet: $ ";
		cin >> y_bet;
		if (y_bet>y_allow) {
		cout<<"Sorry! You don't have enough bet. Please enter an amount of bet you have."<<endl;
		cin	>>y_bet;}
		srand (time(NULL));
		p1_bet=rand ()%p1_allow+1;
		if (p1_bet<y_bet) p1_bet=p1_bet/2;
		p2_bet=rand ()%p2_allow+1;
		if (p2_bet<y_bet) p2_bet=p2_bet/2;
		p1_dice=rand ()%2+1;
		p2_dice=rand ()%2+1;
		dice=rand ()%6+1+rand ()%6+1;
		dice=dice%2;
		if (p1_dice==1) p1_choice='o';
		else p1_choice='e';
		if (p2_dice==1) p2_choice='o';
		else p2_choice='e';
		if(dice==1) dice_result='o';
		else dice_result='e';
		cout<<"You bet "<<y_bet;
		if (y_choice==dice_result) {y_allow=y_allow+y_bet; cout<<" -> won :)"<<endl;}
		else {y_allow=y_allow-y_bet; cout<<" -> lost :("<<endl;}
		cout<<"Player 1 bet "<<p1_bet;
		if (p1_choice==dice_result) {p1_allow=p1_allow+p1_bet; cout<<" -> won :)"<<endl;}
		else {p1_allow=p1_allow-p1_bet; cout<<" -> lost :("<<endl;}
		cout<<"Player 2 bet "<<p2_bet;
		if (p2_choice==dice_result) {p2_allow=p2_allow+p2_bet; cout<<" -> won :)"<<endl;}
		else {p2_allow=p2_allow+p2_bet; cout<<" -> lost :("<<endl;}
		cout <<"You have "<<y_allow<<endl<<"Player 1 has "<<p1_allow<<endl<<"Player 2 has "<<p2_allow<<endl;
	}
    if (y_allow<1) cout<<"You are broke..(ToT)"<<endl;
	if (p1_allow<1) cout<<"Player 1 is broke..(ToT)"<<endl;
	if (p2_allow<1) cout<<"Player 2 is broke..(ToT)"<<endl;
	cout<<"Bye..."<<endl;
	return 0;
}
