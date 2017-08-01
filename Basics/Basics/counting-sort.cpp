//
//  counting-sort.cpp
//  Basics
//
//  Created by Himanshu Ahuja on 01/08/17.
//  Copyright © 2017 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <vector>
#define RANGE 8

using namespace::std;

int main(){
    int arr[] = {4, 2, 5, 3, 5, 8, 3};
    int output[sizeof(arr)/sizeof(arr[0])];
    /*
     Important is, always use the prefix increment form for iterators whose definitions you don't know. 
     That will ensure your code runs as generic as possible.
     
     https://stackoverflow.com/questions/409348/iteration-over-stdvector-unsigned-vs-signed-index-variable
     */
    
    int count[RANGE + 1];
    memset(count, 0, sizeof(count));
    
    for (int i = 0; arr[i]; i++){
        ++count[arr[i]];
    }
    //Making the count array store the actual end index of that number
    for (int i = 1; i <= RANGE; i++){
        count[i] += count[i-1];
    }
    
    for (int i = 0; arr[i]; i++){
        // count[arr[i]] will always make you land on a non-negative index
        output[count[arr[i]] - 1] = arr[i];
        -- count[arr[i]];
    }
    
    for(int i = 0; output[i]; i++){
        cout<<output[i]<<" ";
    }
}

