//
//  main.cpp
//  qqq3
//
//  Created by SunHanbo on 9/22/16.
//  Copyright © 2016 SunHanbo. All rights reserved.
//

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

int main(int argc, char* argv[]){
    
    const int e = 8;
    const int s = 23;
    const int flexp=127;
    const int flo=32;
    
    float x = atof(argv[1]); //can't use double. IEEE is standard.
    double x_rel=atof(argv[1]); //to compare with binary expression.
    
    int y[32]={0};
    
    if (x<0)
        y[0]=1;
    
    
    // what about 0: 0 is extreme value the right present is all 0 (represent=e-127)
    
    unsigned short ex=0;
    
    for (int i=128; i>=-127; i--)  //or log get interger part
    {
        if (abs(x)/pow(2,i) >= 1)
        {
            ex=i+flexp;
            break;
        }
    }
    
    for (int i = e-1; i >=0; i--)
    {
        if((unsigned short)ex & (1 << i))
            y[7-i+1]=1;
    }

    float res=(abs(x)-pow(2,ex-flexp))/pow(2,ex-flexp);
    
    int flag=0;
    for (int i=0;i<s;i++)
    {
        if (res==0)
        {
          //cout<<"break"<<endl;
            //flag=1;
            break;
        }
        res=res*2;
        if (res>=1)
        {
            res=res-1;
            y[i+9]=1;
        }
            
    }
    
    //represent
    double x_rep=1;   // "double" and "float" are both fine. Because there is no error.
    
    for (int i=0;i<s;i++)
    {
        if (y[i+9]==1)
        x_rep=x_rep+pow(2,(-i-1));
    }
    x_rep=x_rep*pow(2,(ex-flexp));
    
    if (y[0]==1)
        x_rep=x_rep*(-1);

    for (int i=0;i<flo;i++)
        cout<<y[i];
    cout<<endl;
    
    //cout<<x_rep-x_rel<<endl;
    if (x_rep-x_rel==0)
        flag=1;
    cout<<flag<<endl;
    
    return 0;
}
