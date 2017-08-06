//
//  binary-search.cpp
//  Basics
//
//  Created by Himanshu Ahuja on 07/08/17.
//  Copyright © 2017 Himanshu Ahuja. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>


using namespace::std;

void vanilla(int *arr, int N, int x){
    int flag = 0;
    int low = 0, high = N - 1;
    int mid = -1;
    
    while(low <= high){
        mid = low + (high - low)/2;
        if (arr[mid] == x){
            flag = 1;
            break; // returns on the first occurence of the element
        }
        if(arr[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
    
    if (flag) cout<<x<<" is found at place "<< mid<<endl;
    else cout<<"Element not found"<<endl;
}


void first(int *arr, int N, int x){
    int flag = 0;
    int low = 0, high = N - 1;
    int mid = -1;
    
    while(low <= high){
        mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid-1]) && arr[mid] == x){
            flag = 1;
            break;
        }
        else if(x > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    
    if (flag) cout<<x<<"'s first occurence is found at place "<< mid<<endl;
    else cout<<"Element not found"<<endl;
}


void last(int *arr, int N, int x){
    int flag = 0;
    int low = 0, high = N - 1;
    int mid = -1;
    
    while(low <= high){
        mid = low + (high - low) / 2;
        if ((mid == N-1 || x < arr[mid+1]) && arr[mid] == x){
            flag = 1;
            break;
        }
        else if(x < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    
    if (flag) cout<<x<<"'s last occurence is found at place "<< mid<<endl;
    else cout<<"Element not found"<<endl;
}

int main(){
    int arr[] = {2, 4, 10, 11, 34, 90, 90, 90, 90, 91, 101, 108};
    int N = 12;

    int x = 90; // item to search

    ///////////////// BINARY SEARCH ///////////////////
    
    ///////////////////////////////////////////////////
    
    // Once the element is found, move
    // 1. forward (for the last occurence)
    // 2. backward (for the first occurence)
    // if such an algorithm is developed, it
    // will take n/2 time O(n) time complexity
    
    // This method will be no good as it shares
    // the same time complexity as the linear search
    
    // We will find the first and the last occurence
    // using only alteration in binary search.
    
    // NOTE : //
    // See the ordering of the loop conditions in the
    // methods : first & last
    
    ////////////////////////////////////////////////////
    
    vanilla(arr, N, x);
    first  (arr, N, x);
    last   (arr, N, x);
}




