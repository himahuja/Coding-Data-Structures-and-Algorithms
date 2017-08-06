//
//  sorting-&-comparison-2.cpp
//  Basics
//
//  Created by Himanshu Ahuja on 02/08/17.
//  Copyright © 2017 Himanshu Ahuja. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h> //for rand()

// rand() generates random integer numbers

#define REP(i, a, b) for (auto i = a; i < b; i++)

using namespace::std;

class P{
public:
    P(){
        x = rand() % 100;
        y = rand() % 50;
    }
    int x, y;
    /*
     OPTION 1: Define a class function, which is automatically called during the sort
     */
    bool operator<(const P &p) const{
        if( x != p.x ) return x < p.x;
        else return y < p.y;
    }
};

/*
 OPTION 2: define a function for comparison
*/

bool Pcomp (const P &p1, const P &p2){
    if(p1.x != p2.x) return p1.x > p2.x;
    else return p1.y > p2.y;
}

int main(){
    /* Developing a comparison operator for user defined structure.
       since they dont have one like integers, characters, strings, pairs or tuples!
     */
    P p[10];
    sort(p, p + 10);
    REP(i, 0, 10){
        cout<<"{"<<p[i].x<<","<<p[i].y<<"} ";
    }
    cout<<endl;
    sort(p, p+10, Pcomp); //Pcomp overrides the member function definition
    REP(i, 0, 10){
        cout<<"{"<<p[i].x<<","<<p[i].y<<"} ";
    }
}
