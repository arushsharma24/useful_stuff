#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int num; cin>>num;
    int steps[num+1];
    for(int i = 0; i <= num; i++) steps[i] = M;
    steps[0] = 0;
    for(int i = 1; i <= 9; i++) steps[i] = 1;
    for(int i = 10; i <= num; i++){
        // consider each digit of each number
        // assign it minimum value
        int n = i;
        while(n){
            int d = n%10;
            steps[i] = min(steps[i], 1 + steps[i - d]);
            n/=10;
        }
        // cout << i << ": " << steps[i] << "\n";
    }
    cout << steps[num] << "\n";
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