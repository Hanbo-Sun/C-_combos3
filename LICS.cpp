// Longest Increasing Common Subsequence
// ref:https://comeoncodeon.wordpress.com/2010/06/01/longest-common-increasing-subsequence-lcis/
// test1 5 1 2 3 4 5 3 1 3 5
//3
// test2 5 5 4 3 2 1 3 5 3 1
//1


#include<iostream>
using namespace std;
#include<vector>

void LCIS(vector<int> A, vector<int> B)
{
    int N=A.size(),M=B.size(),i,j;
    vector<int> C(M,0);
    vector<int> prev(M,0);
    vector<int> res;
    
    for (i=0;i<N;i++)
    {
        int cur=0,last=-1;
        for (j=0;j<M;j++)
        {
            if (A[i]==B[j] && cur+1>C[j])
            {
                C[j]=cur+1;
                prev[j]=last;
            }
            if (B[j]<A[i] && cur<C[j])
            {
                cur=C[j];
                last=j;
            }
        }
    }
    
    int length=0,index=-1;
    for (i=0;i<M;i++)
        if (C[i]>length)
        {
            length=C[i];
            index=i;
        }
    cout<<length;
   // if (length>0)
   // {
        //printf("The LCIS is \n");
     //   while (index!=-1)
       // {
         //   res.push_back(B[index]);
           // index=prev[index];
       // }
       // reverse(res.begin(),res.end());
        //for (i=0;i<length;i++)
          //  printf("%d%s",res[i],i==length-1?"\n":" ");
   // }
}


int main()
{
    vector<int> A;
    vector<int> B;
    vector<int> t;
    int tok;
    while(cin>>tok)
    {
        t.push_back(tok);
    }
    int n = t[0];
    for (int i=0; i<n; i++)
    {
        A.push_back(t[i+1]);
    }
    
    int m = t[n+1];
    for (int i =n+1; i<n+m+1;i++)
    {
        B.push_back(t[i+1]);
    }
        
    LCIS(A,B);
}









