#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int n; cin>>n;
    bool trap[n][n];
    memset(trap, 0, sizeof(trap));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; cin>>c;
            if(c == '*') trap[i][j] = 1;
        }
    }
    if(trap[0][0]){
        cout << "0\n";
        return;
    }
    int grid[n+1][n+1];
    memset(grid, 0, sizeof(grid));
    grid[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if( !(((i == 1) && (j == 1)) || trap[i-1][j-1])){
                grid[i][j] += grid[i-1][j];
                grid[i][j] %= M;
                grid[i][j] += grid[i][j-1];
                grid[i][j] %= M;
            }
            // cout << grid[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << grid[n][n] << "\n";

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