#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int knapsack(int p[],int w[],int n,int capacity)
{
   
    int arr[n+1][capacity+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            if(i==0||j==0)
            {
                arr[i][j]=0;
            }
            else{
                if(w[i]>j){
                    arr[i][j]=arr[i-1][j];
                }
                else
                arr[i][j]=max(p[i]+arr[i-1][j-w[i]],arr[i-1][j]);
            }
        }
    }
    return arr[n][capacity];
}

int main()
{
    int n;
    cin>>n;
    int p[n],w[n];
    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>w[i];
    }
    int capacity;
    cin>>capacity;
    int res=knapsack(p,w,n,capacity);
    cout<<res;
}