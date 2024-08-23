#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Object{
    int p;
    int w;
    double ratio;
};

bool compare(Object a,Object b){
    return a.ratio > b.ratio;
}

int main(){
    //number of objects
    cout<<"enter no of objects:"<<endl;
    int n;
    cin>>n;
    //max capacity it can hold
    cout<<"enter the capacity"<<endl; 
    int c;
    cin>>c;
    vector<Object>objs(n);
    cout<<"enter objects data"<<endl;
    for(int i=0;i<n;i++){
        cin>>objs[i].p;
        cin>>objs[i].w;
        objs[i].ratio=objs[i].p/objs[i].w;
    }
    sort(objs.begin(),objs.end(),compare);
    int res=0;
    for(auto obj:objs){
        if(obj.w<=c){
            c-=obj.w;
            res+=obj.p;
        }

        else{
            res+=obj.ratio*(c);
        }
    }
    cout<<res;
}
