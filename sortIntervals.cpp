//
//  main.cpp
//  h2q4
//
//  Created by SunHanbo on 10/6/16.
//  Copyright © 2016 SunHanbo. All rights reserved.
//

//Problem 4 - Sort Intervals (10 pts)
//Write a C++ program sortIntervals to sort a set of integer intervals in a non-decreasing order by their lower bounds. The intervals with the same lower bounds are sorted by their upper bounds. The sorting algorithm should be is stable. Note that your C++ source code file must be named as sortIntervals.cpp. The input values will be 2n integers, denoted, l1, u1, l2, u2, . . . , ln, un. They represent the input intervals
//[l1,u1],[l2,u2],...,[ln,un]
//The output of the program has two lines: the first line prints the sorted intervals, The second line prints the corresponding input order, i.e.

//case1  5 6 1 5 1 2 1 2 3 5
//1 2 1 2 1 5 3 5 5 6
//3 4 2 5 1

//case2 1 2 3 4 5 6 7 8
//1 2 3 4 5 6 7 8
//1 2 3 4

//case3  5 6 1 2 1 2 1 5 3 5


//./main 'cat momentStat.1.args'
// ./momentStat `cat momentStat.1.args` < momentStat.test1.input > momentStat.test1.output

//idea: first ascend the second(upper boundary) and then ascend the first boundary !!!
//idea2: only change the order of index !



#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cmath>

using namespace std;

void mergeSort(std::vector<int>& a, std::vector<int>& b, std::vector<int>& id,int p, int r);
void merge(std::vector<int>& a, std::vector<int>& b, std::vector<int>& id, int p, int q, int r);
void printinterval(vector<int>& A, vector<int>& B, vector<int>& id);
int main(int argc, char** argv)
{
    vector<int> v;
    vector<int> vl;
    vector<int> vu;
    int tok;
    while (std::cin >> tok)
    {
        v.push_back(tok);
    }
    int n = v.size();
    
    for (int i =0; i <n; i++ )
    {
        if (i%2 == 0)
            vl.push_back(v[i]);
        else
            vu.push_back(v[i]);
    }
    
    vector<int> id;
    for (int i=0; i<n/2; i++)
        id.push_back(i);
    
    mergeSort(vl, vu, id, 0, n/2-1);
    
    printinterval(vl, vu, id);
    
    return 0;
}


void mergeSort(std::vector<int>& a, std::vector<int>& b, std::vector<int>& id, int p, int r)
{
    if ( p < r ) {
        int q = (p+r)/2;
        mergeSort(a, b, id, p, q);
        mergeSort(a, b, id, q+1, r);
        merge(a, b, id, p, q, r);
    }
}


void merge(std::vector<int>& a, std::vector<int>& b, std::vector<int>& id,int p, int q, int r)
{
    std::vector<int> aL, aR, bL, bR, idL, idR;
    for(int i=p; i <= q; ++i)
    {
        aL.push_back(a[i]);
        bL.push_back(b[i]);
        idL.push_back(id[i]);
    }

    for(int i=q+1; i <= r; ++i)
    {
        aR.push_back(a[i]);
        bR.push_back(b[i]);
        idR.push_back(id[i]);
    }

    aL.push_back(INT_MAX);
    aR.push_back(INT_MAX);
    bL.push_back(INT_MAX);
    bR.push_back(INT_MAX);
    idL.push_back(INT_MAX);
    idR.push_back(INT_MAX);

    for(int k=p, i=0, j=0; k <= r; ++k)
    {
        if ( aL[i] < aR[j] )
        {
            a[k] = aL[i];
            b[k] = bL[i];
            id[k] = idL[i];
            ++i;
        }
        else
            if ( aL[i] == aR[j] && bL[i]<=bR[j] )
            {
                a[k] = aL[i];
                b[k] = bL[i];
                id[k] = idL[i];
                ++i;
            }
            else
            {
                a[k] = aR[j];
                b[k] = bR[j];
                id[k] = idR[j];
                ++j;
                }
    }
}



void printinterval(vector<int>& A, vector<int>& B, vector<int>& id)
{
    for(int i=0; i < id.size(); ++i)
    {
        cout << A[i] << " " << B[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < id.size(); ++i)
    {
        cout<<id[i]+1<<" ";
    }
}







