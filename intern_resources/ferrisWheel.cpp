#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, x; cin>>n>>x;
    vector<int>w(n);
    for(int i = 0; i < n; i++){
        cin>>w[i];
    }
    //cout<<"ok1\n";
    ll min = n;
    sort(w.begin(), w.end());
    ll end = n-1;
    ll start = 0;
    while(start < end){
        //cout<<"min is : "<<min<<"\n";
        if(w[end] == x){
            end--;
            //cout<<"full: "<<end<<"\n";
        }
        else{ // w[end] < x
            //cout<<"start: "<<start<<" ";
            //cout<<"end: "<<end<<" ";
            //cout<<"\n";
            ll diff = x - w[end];
            //while(diff>0){
                if(w[start]<=diff){
                    //diff -= w[start];
                    start++;
                    min--;
                    //cout<<"inHere: "<<"diff: "<<diff<<" "<<"w: "<<w[start]<<" "<<start<<"\n";
                }
                //else{
                    //cout<<"ending: "<<end<<"\n";
                //    break;
                //}
            //}
            end--;
        }
    }
    cout<<min<<"\n";
}
//4 10
//7 2 3 9
