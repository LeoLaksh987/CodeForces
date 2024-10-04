#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void primeFactors(int n, vector<int> &ans){ 
 
    for (int i = 3; i <= sqrt(n); i += 2){ 
        while (n % i == 0){ 
            // cout << i << " "; 
            ans.push_back(i);
            n = n/i; 
        } 
    } 
 
    if (n > 2){
        // cout << n << " "; 
        ans.push_back(n);
    }
} 

void solve(vector<bool> &is_prime){
    
    int n;
    cin>>n;

    vector<int> ans;

    if(n % 2 == 0 && n % 5 != 0){
        cout<<"NO"<<'\n';
        return;
    }


    // Number is already in the form of 0 or 1
    bool flag = false;

    int temp = n;
    while(temp != 0){
        int lastDigit = temp%10;

        if(lastDigit > 1){
            // cout<<"Hello"<<'\n';
            flag = true;
            break;
        }

        temp /= 10;
    }

    // cout<<flag<<'\n';
    // cout<<is_prime[n]<<'\n';

    if(flag == false){
        cout<<"YES"<<'\n';
        return;
    }

    if(flag == true && is_prime[n] == true){
        cout<<"NO"<<'\n';
        return;
    }

    primeFactors(n, ans);

    int sz = ans.size();

    // for(int i=0;i<sz;i++){
    //     cout<<ans[i]<<'\n';
    // }

    bool f = false;
    for(int i=0;i<sz;i++){
        bool flg = false;
        int tp = ans[i];
        while(tp != 0){
            int lDigit = tp%10;
    
            if(lDigit > 1){
                // f = true;
                flg = true;
                // cout<<"NO"<<'\n';
                // return;
                break;
            }
    
            tp /= 10;
        }

        // if(f == true){
        //     cout<<"NO"<<'\n';
        //     return;
        // }

        if(flg == false){
            primeFactors(n/tp, ans);
        }
    }

    cout<<"YES"<<'\n';
    return;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    cin>>t;

    int n = 1e5 + 10;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    
    while(t--){
        solve(is_prime);
    }
    
    return 0;
}