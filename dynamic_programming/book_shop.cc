#include<iostream>
#include<vector>
int main(){
    int n,x; std::cin>>n>>x;
    std::vector<int> prices(n);
    std::vector<int> pages(n);
    for(int i=0;i<n;i++) std::cin>>prices[i];
    for(int i=0;i<n;i++) std::cin>>pages[i];
    std::vector<std::vector<int>> dp(n+1,std::vector<int>(x+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            int notTake=dp[i-1][j];
            int take=0;
            if(prices[i-1]<=j){
                take=pages[i-1]+dp[i-1][j-prices[i-1]];
            }
            dp[i][j]=std::max(take,notTake);
        }
    }
    std::cout<<dp[n][x];
}