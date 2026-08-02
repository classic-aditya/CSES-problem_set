#include<iostream>
#include<vector>
#include<climits>
int main(){
    int Ncoins,money; std::cin>>Ncoins>>money;
    std::vector<int> coins(Ncoins);
    for(int i=0; i<Ncoins; i++) std::cin>>coins[i];
    std::vector<int> minCoin(money+1,INT_MAX);
    minCoin[0] = 0;
    for(int amt=1; amt<=money; amt++){
        for(int i=0; i<Ncoins; i++){
            if(coins[i]<=amt && minCoin[amt-coins[i]] !=INT_MAX)
                if(minCoin[amt] > minCoin[amt-coins[i]]+1) minCoin[amt] = minCoin[amt-coins[i]]+1;
        }
    }
    minCoin[money]==INT_MAX ? std::cout<<-1 : std::cout<<minCoin[money];
}
