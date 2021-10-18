#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

int main(){
    int n; cin>>n;
    int count = 0;
    int x;
    int here;
    for(int i = 1; i <= 13; i++){
        x = pow(5, i);
        here = n/x;
        if(here == 0) break;
        count += here;
    }
    cout<<count<<endl;
}