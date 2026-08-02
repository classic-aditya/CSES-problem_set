#include<iostream>
#include<vector>
#define MOD 1000000007
int main(){
    int Ncoins,money; std::cin>>Ncoins>>money;
    std::vector<int> coins(Ncoins);
    for(int i=0; i<Ncoins; i++) std::cin>>coins[i];
    std::vector<int> ways(money+1,0);
    ways[0] = 1;
    for(int amt=1; amt<=money; amt++){
        for(int i=0; i<Ncoins; i++){
            if(coins[i]<=amt && ways[amt-coins[i]] !=0)
               ways[amt] = (ways[amt]+ways[amt-coins[i]])%MOD;
        }
    }
    std::cout<<ways[money];
}
