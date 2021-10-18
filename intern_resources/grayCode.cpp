#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// for every n, the first 2^(n-1) are simply with 0 appended to it
// and the next with 1 appended, just in reverse order

// take an array
// declaring this global array
// now, for each digit, the outputs are doubled, so start with n = 1, and build up to n;
// my code does this
// first for n = 1 makes an array to start with
// and for every next time it is called, it doubles the current array and appends 0 to the first half and 1 to the second half
vector<string> codes;

void solve(int n){
    // returns a vector of strings
    if(n == 1){
        codes.push_back("0");
        codes.push_back("1");
    }
    else{
        for(int i = pow(2,n-1); i < pow(2, n); i++){
            codes.push_back("1"+codes[pow(2,n)-1-i]);
        }
        // added the second half for new
        // add zeroes to the first half
        for(int i = 0; i < pow(2,n-1); i++){
            codes[i] = "0" + codes[i];
        }
    }
}

int main(){
    int n; cin>>n;
    for(int i = 1; i <=n; i++){
        solve(i);
    }
    for(int i = 0; i < pow(2, n); i++){
        cout<<codes[i]<<"\n";
    }
}