#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

struct Cardnumber{
    int digit;
    char JQKA;
};
struct Card {
    char suit;
    Cardnumber number;
};

vector <Card> form (){
    vector<Card>deck;
    vector<Cardnumber>number;
    Cardnumber cn;
    cn.JQKA='A';
    number.push_back(cn);
    for (int i=2; i<=10; ++i){
        cn.digit=i;
        number.push_back(cn);
    }
    cn.JQKA='J';
    number.push_back(cn);
    cn.JQKA='Q';
    number.push_back(cn);
    cn.JQKA='K';
    number.push_back(cn);
    Card c;
    for (int i=0; i<13; ++i){
        c.suit='C';
        c.number=number[i];
        deck.push_back(c);
    }
    for (int i=0; i<13; ++i){
        c.suit='D';
        c.number=number[i];
        deck.push_back(c);
    }
        for (int i=0; i<13; ++i){
        c.suit='H';
        c.number=number[i];
        deck.push_back(c);
    }
        for (int i=0; i<13; ++i){
        c.suit='S';
        c.number=number[i];
        deck.push_back(c);
    }
    return deck;
}

vector <int> random(const int t){
    vector <int> total;
    srand(time(NULL));
    int n;
    vector <int> deal;
    for (int i=0; i<t; ++i) total.push_back(i);
    for (int i=0; i<35; ++i){
    n=rand()%(total.size()-1);
    deal.push_back(total[n]);
    total.erase(total.begin()+n);
    }
    return deal;
}

vector <Card> take(const vector<Card>d, const vector<int>p, const int n){
    vector<Card>card;
    int c_number;
    for (int i=n; i<n+7; ++i){
        c_number=p[i];
        card.push_back(d[c_number]);
    }    
    return card;
}

void version(const vector<Card>P, const vector<int>p, const int num){
     int print;
     char c;
     for (int i=0; i<7;++i){
       c='a'+i;
       cout<<"("<<c<<") ";
       cout<<P[i].suit;
       print=p[num+i]%13;
       if (print==0||print==10||print==11||print==12) cout<<P[i].number.JQKA<<"   ";
       else cout<<P[i].number.digit<<"   ";
     }
     cout<<endl;
}

int Random(){return rand()%7;}
     
Card Pass(const vector<Card>P, const vector<int>p, const int n, int& p_n, const int r){
     Card p_c;
     p_n=p[n+r];
     p_c=P[r];
     return p_c;
} 
      
vector <int> Orderpick(vector<int>p, const int n, const int r, const int p_n){
    p[n+r]=p_n;
    return p;
}    

vector <Card> Ordercard(vector<Card>P, const int r, const Card p_c){
    P[r]=p_c;
    return P;
}    
void Hint(const int num1, const int num2, const Card card, const int renum) {
    cout<<"Hint: player "<<num1<<" passed "<<card.suit;
    int print=renum%13;
       if (print==0||print==10||print==11||print==12) cout<<card.number.JQKA;
       else cout<<card.number.digit;
    cout<<" to player "<<num2<<endl;
    }
    
int check (vector<int>p){
    int n,max,C=0,D=0,H=0,S=0;
    for (int i=0; i<7; ++i){
       n=p[i];
       if (n>=0&&n<13) C++;
       if (n>=13&&n<26) D++;
       if (n>=26&&n<39) H++;
       if (n>=39&&n<52) S++;
    }
    max=C;
    if (max>D) max=D;
    if (max>H) max=H;
    if (max>S) max=S;
    return max;
}

int main (){
   vector <Card> deck;
   deck=form();
   vector <int> pick;
   pick=random(51);
   vector <Card> Player0, Player1, Player2, Player3, Player4;
   Player0=take(deck,pick,0);
   Player1=take(deck,pick,7);
   Player2=take(deck,pick,14);
   Player3=take(deck,pick,21);
   Player4=take(deck,pick,28);
   char replace;
   int r;
   while (true){
       version(Player0,pick,0);
       cout<<"Which one to replace? ";
       cin>>replace;
       while (true){
            if (replace>='a'&&replace<='g') break;   
            else if (replace=='?') {
                     cout<<"Player 1   ";
                     version(Player1,pick,7);
                     cout<<"\nPlayer 2   ";
                     version(Player2,pick,14);
                     cout<<"\nPlayer 3   ";
                     version(Player3,pick,21);
                     cout<<"\nPlayer 4   ";
                     version(Player4,pick,28);
                     cout<<endl<<"Which one to replace? ";
                }
                else cout<<"Wrong input! Which one to replace? "; 
            cin>>replace;
       }
       r=replace-'a';
       int pass_n0, pass_n1, pass_n2, pass_n3, pass_n4, rp1, rp2, rp3, rp4;
       Card pass_c0, pass_c1, pass_c2, pass_c3, pass_c4;
       pass_n0=pick[r];
       pass_c0=Player0[r];
       srand(time(NULL));
       rp1=Random();
       rp2=Random();
       rp3=Random();
       rp4=Random();
       pass_c1=Pass(Player1,pick,7,pass_n1,rp1);
       pass_c2=Pass(Player2,pick,14,pass_n2,rp2);
       pass_c3=Pass(Player3,pick,21,pass_n3,rp3);
       pass_c4=Pass(Player4,pick,28,pass_n4,rp4);
       pick=Orderpick(pick,0,r,pass_n4);
       pick=Orderpick(pick,7,rp1,pass_n0);
       pick=Orderpick(pick,14,rp2,pass_n1);
       pick=Orderpick(pick,21,rp3,pass_n2);
       pick=Orderpick(pick,28,rp4,pass_n3);
       Player0=Ordercard(Player0,r,pass_c4);
       Player1=Ordercard(Player1,rp1,pass_c0);
       Player2=Ordercard(Player2,rp2,pass_c1);
       Player3=Ordercard(Player3,rp3,pass_c2);
       Player4=Ordercard(Player4,rp4,pass_c3);
       Hint(0,1,pass_c0,r);
       Hint(1,2,pass_c1,rp1);
       Hint(2,3,pass_c2,rp2);
       Hint(3,4,pass_c3,rp3);
       Hint(4,0,pass_c4,rp4);
       int p0max,p1max,p2max,p3max,p4max;
       p0max=check(pick);
       p1max=check(pick);
       p2max=check(pick);
       p3max=check(pick);
       p4max=check(pick);
       if(p0max==7) cout<<"My Ship Sails! --- Player 0 Won..."<<endl;
       if(p1max==7) cout<<"My Ship Sails! --- Player 1 Won..."<<endl;
       if(p2max==7) cout<<"My Ship Sails! --- Player 2 Won..."<<endl;
       if(p3max==7) cout<<"My Ship Sails! --- Player 3 Won..."<<endl;
       if(p4max==7) cout<<"My Ship Sails! --- Player 4 Won..."<<endl;
       if(p0max==7||p1max==7||p2max==7||p3max==7||p4max==7) break;
   }   
   cout<<"\nPlayer 0   ";
   version(Player0,pick,0);
   cout<<"\nPlayer 1   ";
   version(Player1,pick,7);
   cout<<"\nPlayer 2   ";
   version(Player2,pick,14);
   cout<<"\nPlayer 3   ";
   version(Player3,pick,21);
   cout<<"\nPlayer 4   ";
   version(Player4,pick,28);
   return 0;
}