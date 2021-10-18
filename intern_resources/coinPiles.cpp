#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int t; cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        if((a+b)%3==0){
            ll steps = (a+b)/3;
            ll x = (2*a-b);
            ll y = (2*b-a);
            //cout<<x%3<<" "<<y%3<<" "<<x<<" "<<y<<" ";
            if(x%3==0 && y%3==0 && x> -1 && y > -1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            cout<<"NO\n";
        }
    }
}