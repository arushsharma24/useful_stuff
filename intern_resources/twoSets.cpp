#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main(){
    ull n; cin>>n; 
    if((n+1)%4==0){
        cout<<"YES\n";
        int i = 1;
        cout<<(n+1)/2<<"\n";
        while(i<n){
            cout<<i<<" ";
            if(i%2==0)
                i+=3;
            else
                i++;
        }
        cout<<"\n";
        i = 3;
        cout<<(n+1)/2-1<<"\n";
        while(i<=n){
            cout<<i<<" ";
            if(i%2==0)
                i+=3;
            else
                i++;
        }
        cout<<"\n";
    }
    else if(n%4==0){
        cout<<"YES\n";
        cout<<n/2<<"\n";
        int i = 1;
        while(i<=n){
            cout<<i<<" ";
            if(i%2)
                i+=3;
            else
                i++;
        }
        cout<<"\n"<<n/2<<"\n";
        i = 2;
        while(i<n){
            cout<<i<<" ";
            if(i%2==0)
                i++;
            else
                i+=3;
        }
        cout<<"\n";
    }
    else cout<<"NO\n";
}