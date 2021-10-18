#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void towerOfHanoi(int n, int x, int y){
    // n number of disks from x to y
    if(n == 1){
        cout<<x<<" "<<y<<"\n";
    }
    else{
        int z;
        if(x+y==3) z = 3;
        else if(x+y == 4) z = 2;
        else z = 1;
        // now z is set
        towerOfHanoi(n-1, x, z);    // f(n-1) steps
        towerOfHanoi(1, x, y);      // 1 step
        towerOfHanoi(n-1, z, y);    // f(n-1) steps
    }
    return;
}

int main(){
    int n; cin>>n;
    // for this solution that i have written
    // we can form a recurrence relation of f(n) = 2*f(n-1) + 1;
    // which we can calculate using dp
    vector<int>dp;
    // dp[i][0] will have value and dp[i][1] will have sum till that value
    dp.push_back(0);
    dp.push_back(1);
    for(int i = 2; i <=n; i++){
        dp.push_back(2*dp[i-1]+1);
    }
    cout<<dp[n]<<"\n";
    towerOfHanoi(n, 1, 3);
}