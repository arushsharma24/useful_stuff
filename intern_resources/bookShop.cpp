#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int n, x; cin>>n>>x;
    vector<pair<int, int>> vpi(n);
    for(int i = 0; i < n; i++) cin>>vpi[i].first;
    for(int i = 0; i < n; i++) cin>>vpi[i].second;
    sort(vpi.begin(), vpi.end());
    int pages[n+1][x+1];
    memset(pages, 0, sizeof(pages));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            pages[i][j] = max(pages[i-1][j], pages[i][j-1]);
            if(j >= vpi[i-1].first){
                pages[i][j] = max(pages[i][j], vpi[i-1].second + pages[i-1][j - vpi[i-1].first]);
            }
            // cout << pages[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << pages[n][x] << "\n";
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