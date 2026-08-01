#include<iostream>
#include<vector>
#define MOD 1000000007
int main(){
    int n; std::cin>>n;
    std::vector<long long> dp(n+1,0);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            if(i-j>=0){
                dp[i] = (dp[i]+dp[i-j])%MOD;
            }
        }
    }
    std::cout<<dp[n];
}