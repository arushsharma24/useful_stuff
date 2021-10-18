#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define ull unsigned long long
#define ll long long
#define M1 1000000007


ll myPowM(ll x, ll y, ll m){
    // we will basically use the fact that all numbers can be represented in binary, and keep moving this way for decreased time complexity
    ll res = 1;
    // ll r = 1;
    if(x%m == 0) return 0;
    x %= m;
    while(y > 0){
        // if y is odd, that is, the last bit of the current y is 1, then we will be counting it, otherwise, we do not multiply this power of x with res
        if(y & 1){
            res *= x;
            res %= m;
        }
        // now, we will divide y / 2, which is what right shifting does, it basically removes the last bit
        // so this is what will eventually limit our while loop, when we run out of bits to remove, when we remove the last bit
        // y will be 0, and loop stops executing 
        // therefore the complexity of this method is also log(y)
        y = y>>1;
        // now, regardless of whether or not we added our x yet, we square x again
        x *= x;
        // obvious modulo
        x %= m;
    } 
    return res;
}

ll myMod(ll x, ll m){
    if(x<m){
        return x;
    }
    while (x >= m){
        x -= m;   
    }
    
    return x;
}

ll myNewPowM(ll x, ll y, ll m){
    // we will basically use the fact that all numbers can be represented in binary, and keep moving this way for decreased time complexity
    ll res = 1;
    ll r = 1;
    if(x%m == 0) return 0;
    //x %= m;
    x = myMod(x, m);
    while(y > 0){
        // if y is odd, that is, the last bit of the current y is 1, then we will be counting it, otherwise, we do not multiply this power of x with res
        if(y & 1){
            res *= x;
            res = myMod(res, m);
        }
        // now, we will divide y / 2, which is what right shifting does, it basically removes the last bit
        // so this is what will eventually limit our while loop, when we run out of bits to remove, when we remove the last bit
        // y will be 0, and loop stops executing 
        // therefore the complexity of this method is also log(y)
        y = y>>1;
        // now, regardless of whether or not we added our x yet, we square x again
        x *= x;
        // obvious modulo
        x = myMod(x , m);
    } 
    return res;
}

int main(){
    /*
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    ull n; cin>>n;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);    
    cout<<"Time taken for cin is: "<<duration.count()<<"us\n";

    start = high_resolution_clock::now();
    ull num = myPowM(2, n, M1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);    
    cout<<"Time taken for myPowM is: "<<duration.count()<<"us\n";

    start = high_resolution_clock::now();
    ull num2 = myNewPowM(2, n, M1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);    
    cout<<"Time taken for myNewPowM is: "<<duration.count()<<"us\n";

    cout<<num<<"\n";
    cout<<num2<<"\n";
    */
    int x, n, d; cin>>x>>n>>d;
    cout<<myPowM(x, n, d)<<endl;
}