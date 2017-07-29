//
//  main.cpp
//  Basics
//
//  Created by Himanshu Ahuja on 29/07/17.
//  Copyright © 2017 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <utility>

using namespace std;

int main(int argc, const char * argv[]) {
    
//     Preparing the input
//    int len, *arr;
//    cin>>len;
//    arr = new int[len];
//    for(int i = 0; i < len; i++){
//        cin>>arr[i];
//    }
    
    int arr[] = {-1, 2, 4, -3, 5, 2, -5, 2, 10, 3, -2, 4, 7, -9, 4, -3, 8,
                 -2, 8, -4, 6, 3, 7, 8, 9, -10, 11, 4, -2, 2};
    int len = sizeof(arr)/sizeof(int);
    
    
    int best = 0;
    clock_t begin = clock();
    //O(n3) implementation
    for (int a = 0; a < len; a++){
        for(int b = a; b < len; b++){
            int sum = 0;
            for(int k = a; k <=b; k++){
                sum+=arr[k];
            }
            best = max(best, sum);
        }
    }
    clock_t end = clock();
    cout<<"In O(n3): "<<double(end - begin) / CLOCKS_PER_SEC<<": "<<best<<"\n";
    
    best = 0;
    begin = clock();
    //O(n2) implementation
    for (int a = 0; a < len; a++){
        int sum = 0;
        for (int b = a; b < len; b++){
            sum += arr[b];
            best = max(best, sum);
        }
    }
    end = clock();
    cout<<"In O(n2): "<<double(end - begin) / CLOCKS_PER_SEC<<": "<<best<<"\n";
    
    best = 0;
    int sum = 0;
    begin = clock();
    //O(n) implementation
    for (int k = 0; k < len; k++){
        sum = max(arr[k], sum + arr[k]);
        best = max(sum, best);
    }
    end = clock();
    cout<<"In O(n): "<<double(end - begin) / CLOCKS_PER_SEC<<": "<<best<<"\n";
    
}
