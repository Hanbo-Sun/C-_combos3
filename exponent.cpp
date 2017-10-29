//
//  main.cpp
//  h3q2
//
//  Created by SunHanbo on 10/29/16.
//  Copyright © 2016 SunHanbo. All rights reserved.
//Exponentiation (10 pts)
//exponent.cpp

//given a sequence of nonnegative integers n1,n2,...,nk, computes and prints the last 4 digits of (· · · (n1)n2 )n3 · · ·)nk .
//If the last four digits are all zeros, print‘0’;
//otherwise, omit any leading zeros. Example runs of valid input arguments are

// test

//10 5
// 0

// 2 4 4
// 5536

// 2 3 4
// 4096

// 1 0 0 0
// 1

// 100 100 0
// 1

// 0 0 0
// 1 (no define)

// 100 100 100
// 0

// 1314315 31314 43453 313
// 5625



#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    vector<int> n;
    int tok;
    int flag = 0;
    while (cin >> tok)
    {
        n.push_back(int(tok));
        if (tok == 0)
            flag = 1;
    }
    int k = n.size();
    
    int* es = new int[k+1];
    
    es[0] = n[0]%10000;
    if (k>1)
    {
        for(int i=1; i < k; ++i)
        {
            if (flag ==1)
            {es[k-1]=1;break;}
            es[i] = 1;
            for (int j = 1; j<=n[i]; j++)
            {
                es[i] *= es[i-1];
                es[i] %= 10000;
            }
        }
    }
    cout<<es[k-1]<<endl;
    delete [] es;
}
