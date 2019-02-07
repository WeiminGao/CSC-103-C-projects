#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <ctime>
#include <math.h>
#include <string>
//----------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    double r=80.0;
    double pi;

    pi = (22./7.);

    double hour_angle =-((pi/2)-((timeinfo->tm_hour)*(pi/6)));
    double min_angle =-((pi/2)-(timeinfo->tm_min)*(pi/30));
    double sec_angle =-((pi/2)-(timeinfo->tm_sec)*(pi/30));

    double hour_x =125+(r-25)*cos(hour_angle);
    double hour_y =125+(r-25)*sin(hour_angle);

    double min_x =125+r*cos(min_angle);
    double min_y =125+r*sin(min_angle);

    double sec_x =125+r*cos(sec_angle);
    double sec_y =125+r*sin(sec_angle);

    Simple_window win(Point(100,100),500,500,"Programming Assignment #7");
    const Point x (125,125);

    Circle c1 (x,100);
    Circle c2 (x,99);
    Circle c3 (x,2);

    Line hours (x,Point(hour_x,hour_y));
    Line minutes (x,Point(min_x,min_y));
    Line seconds (x,Point(sec_x,sec_y));

    hours.set_style(Line_style(Line_style::solid,3));
    seconds.set_style(Line_style(Line_style::dash));
    seconds.set_color(Color::red);


    c1.set_color(Color::dark_red);
    c2.set_color(Color::dark_red);

    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.attach(hours);
    win.attach(minutes);
    win.attach(seconds);
//----------------------------------------------------------------------------
    Graph_lib::Rectangle rect1(Point(225,325),180,80);
    Graph_lib::Rectangle rect2(Point(227,323),176,84);

    rect1.set_color(Color::red);
    rect2.set_color(Color::red);

    string times= to_string(timeinfo->tm_hour) + ':' + to_string(timeinfo->tm_min) + ':' + to_string(timeinfo->tm_sec);
    // 'to_string' works in C++11

    Text text1(Point(237,383),times);
    text1.set_font(Font::times_bold);
    text1.set_font_size(42);

    win.attach(rect1);
    win.attach(rect2);
    win.attach(text1);

    win.wait_for_button();       // Display!
}

//unfinished, still figure out reverse-engineering.