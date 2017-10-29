//
//  main.cpp
//  h2q2
//
//  Created by SunHanbo on 10/6/16.
//  Copyright © 2016 SunHanbo. All rights reserved.
//Problem 2 - Minimum Sub-Sum (10 pts)
//Write a C++ program minSubSum.cpp which, given a sequence of integers (from cin), computes and prints the minimum sum of a contiguous subsequence. Empty subsequence (with a sum of 0) is also allowed. Example runs of valid input arguments are
//case1 ./minSubSum -1 1 -1 1
//-1
//case2 ./minSubSum -1 -2 -1 2 -1
//-4

// ./main 'cat minSubSum.5.args' < minSubSum.test5.input > minSubSum.test5.output
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


int minSubArraySum(vector<int>& a, int size)
{
    int min_so_far = 0, min_ending_here = 0;
    
    for (int i = 0; i < size; i++)
    {
        min_ending_here = min_ending_here + a[i];
        if (min_ending_here > 0)
            min_ending_here = 0;
        if (min_so_far > min_ending_here)
            min_so_far = min_ending_here;
    }
    //cout<<"min_so_far="<<min_so_far<<endl;
    //cout<<"min_ending_here"<<min_ending_here<<endl;
    return min_so_far;
}

int main()
{
    vector<int> v;
    int tok;
    while (std::cin >> tok)
    {
        v.push_back(tok);
    }
    int n = v.size();
    //cout<<"length="<<n<<endl;
    int min = minSubArraySum(v, n);
    cout<<min<<endl;
    
    return 0;
}
