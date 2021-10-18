#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    ll n; cin>>n;
    int dc[n+1];
    memset(dc, 0, sizeof(dc));
    int a[] = {1, 2, 3, 4, 5, 6};
    dc[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int x : a){
            if(i-x >= 0){
                dc[i] += dc[i-x];
                dc[i] %= M;
            }
        }
    }
    cout << dc[n] << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}