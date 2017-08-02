//
//  sorting-&-comparison.cpp
//  Basics
//
//  Created by Himanshu Ahuja on 02/08/17.
//  Copyright © 2017 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>

#define REP(i, a, b) for (auto i = a; i < b; i++)

using namespace::std;

int main(){
    vector< pair<int, int> > v2;
    v2.push_back({1, 5});
    v2.push_back({2,3});
    v2.push_back({1,2});
    sort(v2.begin(), v2.end());
    
    REP(i, v2.begin(), v2.end()){
        cout<<"{"<<i->first<<","<<i->second<<"} ";
    }
    cout<<endl;
    
    /*
     
     Pair has a built-in defined comparison mechanism:
     sort the elements according to their first element.
     if first values of the pairs are equal, compare the 
     second values of the pair.
     
     Similarly in a tuple, first --> second --> third ...
     */
    
    vector< tuple <int, int, int> > v3;
    v3.push_back({2, 1, 4});
    v3.push_back({1, 5, 3});
    v3.push_back({2, 1, 3});
    sort(v3.begin(), v3.end());
    REP(i, v3.begin(), v3.end()){
        cout<<"{"<<get<0>(*i)<<","<<get<1>(*i)<<","<<get<2>(*i)<<"} ";
    }
}
