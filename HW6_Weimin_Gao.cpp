#include "Simple_window.h"  
#include "Graph.h"          
#include <iostream>
#include <ctime>


int main()
{
    using namespace Graph_lib;  

    int length;
    while(true){
        cin >> length;
        while (true){
        	if (length >= 500) cout << "Wrong input! The line length should less than 500." << endl;
        	else break;
        	cin >> length;
        }
        if (length <= 0) break;

        Simple_window win(Point(100,100),500,500,"Square");
        int x1, x2, x3, y1, y2, y3;
        srand(time(NULL));
        x1=rand()%(500-length);
        y1=rand()%(500-length);
        Graph_lib::Rectangle rect01(Point(x1,y1),length,length);
        x2=rand()%(500-length);
        y2=rand()%(500-length);
        Graph_lib::Rectangle rect02(Point(x2,y2),length,length);
        x3=rand()%(500-length);
        y3=rand()%(500-length);
        Graph_lib::Rectangle rect03(Point(x3,y3),length,length);

        rect01.set_fill_color(Color::dark_red);
        rect02.set_fill_color(Color::dark_red);
        rect03.set_fill_color(Color::dark_red);

        win.attach(rect01);
        win.attach(rect02);
        win.attach(rect03);

        int overx=1, overy=1, overwidth=1, overlength=1;
        if((x1<=x2&&x2<=x1+length) && (y1<=y2&&y2<=y1+length)){
                 overx=x2;
                 overy=y2;
                 overwidth=x1+length-x2;
                 overlength=y1+length-y2;
        }
        if((x2<=x1&&x1<=x2+length) && (y2<=y1&&y1<=y2+length)){
                 overx=x1;
                 overy=y1;
                 overwidth=x2+length-x1;
                 overlength=y2+length-y1;
         }
        if(x1>x2 && y1<y2 && y2<y1+length){ //for special case.
        	overx=x1;
        	overy=y2;
        	overwidth=length-(x1-x2);
        	overlength=length-(y2-y1);
        }
        if (x2>x1 && y2<y1 && y1<y2+length){//for special case.
           overx=x2;
           overy=y1;
           overwidth=length-(x2-x1);
           overlength=length-(y1-y2);
         }
         Graph_lib::Rectangle over01(Point(overx,overy),overwidth,overlength);
         over01.set_fill_color(Color::white);
         over01.set_color(Color::invisible);
         win.attach(over01);


         if((x3<=x2&&x2<=x3+length) && (y3<=y2&&y2<=y3+length)){
                 overx=x2;
                 overy=y2;
                 overwidth=x3+length-x2;
                 overlength=y3+length-y2;
          }
          if((x2<=x3&&x3<=x2+length) && (y2<=y3&&y3<=y2+length)){
                 overx=x3;
                 overy=y3;
                 overwidth=x2+length-x3;
                 overlength=y2+length-y3;
          }
          if(x3>x2 && y3<y2 && y2<y3+length){ //for special case.
          	overx=x3;
          	overy=y2;
          	overwidth=length-(x3-x2);
          	overlength=length-(y2-y3);
          }
          if(x2>x3 && y2<y3 && y3<y2+length){ //for special case.
          	overx=x2;
          	overy=y3;
          	overwidth=length-(x2-x3);
          	overlength=length-(y3-y2);
          }
          Graph_lib::Rectangle over02(Point(overx,overy),overwidth,overlength);
          over02.set_fill_color(Color::white);
          over02.set_color(Color::invisible);
          win.attach(over02);


          if((x3<=x1&&x1<=x3+length) && (y3<=y1&&y1<=y3+length)){
                  overx=x1;
                  overy=y1;
                  overwidth=x3+length-x1;
                  overlength=y3+length-y1;
           }
           if((x1<=x3&&x3<=x1+length) && (y1<=y3&&y3<=y1+length)){
                  overx=x3;
                  overy=y3;
                  overwidth=x1+length-x3;
                  overlength=y1+length-y3;
           }
           if(x3>x1 && y3<y1 && y1<y3+length){ //for special case.
           	overx=x3;
           	overy=y1;
           	overwidth=length-(x3-x1);
           	overlength=length-(y1-y3);
           }
           if(x1>x3 && y1<y3 && y3<y1+length){ //for special case.
            	overx=x1;
            	overy=y3;
            	overwidth=length-(x1-x3);
            	overlength=length-(y3-y1);
           }
           Graph_lib::Rectangle over03(Point(overx,overy),overwidth,overlength);
           over03.set_fill_color(Color::white);
           over03.set_color(Color::invisible);
           win.attach(over03);

        win.wait_for_button();       // Display!
    }
    return 0;
}
