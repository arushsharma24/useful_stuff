#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main(){
    ull k; cin>>k;
    cout<<0<<"\n";
    ull res;
    for(ull i = 2; i <= k; i++){
        ull j = i*i;
        res = (j*(j-1)/2) - (4*(i-1)*(i-2));
        cout<<res<<"\n";
    }
    return 0;
}