#include <iostream>
#include <string>
#include <vector>
using namespace std;

void frame (int w){
	cout<<"|";
	for (int i=0; i<w; ++i) cout<<"-";
	cout<<"|"<<endl;
}
int main() {
string line, w;
cout<<"Enter text, empty return will quit the input:"<<endl;
getline(cin,line);
if(line==" "){
	cout<<"Don't leave blank, please enter again"<<endl;
    getline(cin,line);
}
while(true){
    vector<string>word;
    vector<int>space;
    int width, remain=0;
	cout<<"Enter the width of text: ";
	cin>>width;
	if(width==0) break;
	frame(width);
	for(int i=0,lenline=line.size(); i<lenline; ++i) if(line[i]==' ') space.push_back(i);

	w=line.substr(0,space[0]);
	word.push_back(w);
	int lenspace=space.size();
	for(int i=0; i<lenspace; ++i){
		 w=line.substr(space[i]+1, space[i+1]-space[i]-1);
		 word.push_back(w);
	}
	
	int i=0, lenword=word.size(), availword=0, availsize=0, firstword=0, check=0;
	for (int j=0; j<lenword; j++){
	    w=word[j];
	    check=w.size();
	    if (check>width) {
	        cout<<"Your width smaller than your word. Please Enter a width which larger than your word."<<endl;
	        i=lenword+1;
	        lenword=0;
	    }
        }
    while (i<=lenword){
          if (i==firstword){
              w=word[i];
	          availsize=availsize+w.size();
          }      
          else {
	        w=word[i];
	        availsize=availsize+w.size()+1;
	        ++availword;
	      }
	      if (availword==0&&i+1==lenword){
	          remain=width-availsize;
	          cout<<"|"<<word[firstword];
              for(int whitespace=0; whitespace<remain; ++whitespace) cout<<" ";
	          cout<<"|"<<endl;
	      }
          if ((availsize>width||i+1==lenword)&&availword>0){
	        remain=width-(availsize-w.size()-1);
	        cout<<"|"<<word[firstword];
            for(int j=i-(availword-1); j<i; ++j){
                if (j==i-1) for(int whitespace=0; whitespace<remain; ++whitespace) cout<<" ";
                cout<<" "<<word[j]; 
            }
            if (availword-1==0) for(int whitespace=0; whitespace<remain; ++whitespace) cout<<" ";
	        cout<<"|"<<endl;
	        --i;
	        availword=availsize=0;
	        firstword=i+1;
	      }
	      ++i;
    }    
    frame(width);
}

	return 0;
}