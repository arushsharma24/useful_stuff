#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    string s; cin>>s;
    int n = s.length();
    int letters[26] = {0};
    for(int i = 0; i < n; i++){
        letters[(int)(s[i] - 'A')]++;
    }
    int even = 0, odd = 0;
    for(int i = 0; i < 26; i++){
        if(letters[i] == 0) continue;
        if(letters[i]%2) odd++;
        else even++;
    }
    string res(n, 'A');
    if(n%2==0){
        // even string
        if(odd == 0){
            int index = 0;
            for(int i = 0; i < 26; i++){
                if(letters[i]==0) continue;
                for(int j = 0; j < letters[i]/2; j++){
                    res[index+j] = (char)(i+65);
                    res[n-1-(index+j)] = (char)(i+65);
                }
                index += letters[i]/2;
            }
        }
        else{
            cout<<"NO SOLUTION\n";
            return 0;
        }
    }
    else{
        // odd lengthed string
        if(odd == 1){
            int index = 0;
            for(int i = 0; i < 26; i++){
                char x = (char)(i+65);
                if(letters[i]==0) continue;
                if(letters[i]%2 == 0){
                    for(int j = 0; j < letters[i]/2; j++){
                        res[index+j] = x;
                        res[n-1-(index+j)] = x;
                    }
                    index += letters[i]/2;
                }
                else{
                    res[(n-1)/2] = x;
                    for(int j = 1; j <= letters[i]/2; j++){
                        res[(n-1)/2 + j] = x;
                        res[(n-1)/2 - j] = x;
                    }
                }
            }
        }
        else{
            cout<<"NO SOLUTION\n";
            return 0;
        }
    }
    cout<<res<<"\n";
    return 0;
}