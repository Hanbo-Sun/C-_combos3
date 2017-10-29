//
//  main.cpp
//  hw3q1
//
//  Created by SunHanbo on 10/29/16.
//  Copyright © 2016 SunHanbo. All rights reserved.
// detectSquare.cpp

//  given coordinates of N points in the 2-D X-Y plane (read from cin),
// detects whether there are four points (among the N points provided)
// which form the four corners of a square with all edges parallel to the X or Y coordinate axes, and prints “Yes” or “No” correspondingly. The input contains 2N integers, with each pair of adjacent numbers representing the X and Y coordinates of a point.

// ref: <<Finding squares and rectangles in sets of points>>

//test
// 1 2 1 3 2 2 2 3 Yes
// 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8  No
// 1 1 1 1 1 1 1 1 no
//-1 -1 -2 -1 -1 -2 -2 -2 yes

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std; // to avoid typing std:: repetitively

int main() {
    map<int, set<int> > sx;
    map<int, set<int> > sy;
    
    //read from cin
    vector<int> ini;
    int to;
    while (cin >> to)
        ini.push_back(to);
    int n = ini.size()/2;
    int sqn = sqrt(n); // ref <<Finding squares and rectangles in sets of points>> every subsets less than sqrt(n)
    // partition points set to collection subsets sx and collection subsets sy
    for (int i = 0; i<n; ++i)
    {
        if (sx[ini[2*i]].size()< sqn)
        {
            //cout<<ini[2*i+1]<<endl;
            sx[ini[2*i]].insert(ini[2*i+1]); //subset with same x-coordinate
        }
        else
            sy[ini[2*i+1]].insert(ini[2*i]); //store remain elements in sy (with same y-coordinate)
    }
    
    //search every pair in every subset of sx
    for (map<int,set<int> >::iterator i=sx.begin(); i!=sx.end(); ++i)
    {
        if ( i->second.size() > 1 ) // have pair
        {
            for (set<int>::iterator it = i->second.begin(); it!=i->second.end(); ++it)
            {
                set<int>::iterator itt = it;
                
                for ( ++itt; itt!=i->second.end(); ++itt)
                {
                    int ab=(int)abs(float(*it - *itt)); //in some environment, ambiguous of abs(float) or (double)
                    // wether correspoding two points exist(two possible positions of the two points)
                    // and each of them can exist in sx or sy.
                    if(((sx[i->first+ab].find(*it)!=sx[i->first+ab].end() || sy[*it].find(i->first+ab)!=sy[*it].end()) & (sx[i->first+ab].find(*itt)!=sx[i->first+ab].end() || sy[*itt].find(i->first+ab)!=sy[*itt].end())) || ((sx[i->first-ab].find(*it)!=sx[i->first-ab].end() || sy[*it].find(i->first-ab)!=sy[*it].end()) & (sx[i->first-ab].find(*itt)!=sx[i->first-ab].end() || sy[*itt].find(i->first-ab)!=sy[*itt].end()))  )
                    {
                        cout<<"Yes"<<endl;
                        exit(0);
                        
                    }
                    
                }
            }
        }
    }
    
    //search every pair in every subset of sy
    for (map<int,set<int> >::iterator i=sy.begin(); i!=sy.end(); ++i)
    {
        if ( i->second.size() > 1 )
        {
            for (set<int>::iterator it = i->second.begin(); it!=i->second.end(); ++it)
            {
                set<int>::iterator itt = it;
                
                for (++itt; itt!=i->second.end(); ++itt)
                {
                    int ab=(int)abs(float(*it - *itt));
                    
                    if(((sy[i->first+ab].find(*it)!=sy[i->first+ab].end() || sx[*it].find(i->first+ab)!=sx[*it].end()) & (sy[i->first+ab].find(*itt)!=sy[i->first+ab].end() || sx[*itt].find(i->first+ab)!=sx[*itt].end())) || ((sy[i->first-ab].find(*it)!=sy[i->first-ab].end() || sx[*it].find(i->first-ab)!=sx[*it].end()) & (sy[i->first-ab].find(*itt)!=sy[i->first-ab].end() || sx[*itt].find(i->first-ab)!=sx[*itt].end()))  )
                    {
                        cout<<"Yes"<<endl;
                        exit(0);
                        
                    }
                    
                }
            }
        }
    }
    
    cout<<"No"<<endl;
    return 0;
}
