#include<iostream>
#include<vector>
#define MOD 1000000007
int main(){
    int Ncoin,target; std::cin>>Ncoin>>target;
    std::vector<int> coins(Ncoin);
    for(int i=0; i<Ncoin; i++) std::cin>>coins[i];
    std::vector<int> ways(target+1,0);
    ways[0] = 1;
    for(int coin=0; coin<Ncoin; coin++){
        for(int amt=1; amt<=target; amt++){
            if(coins[coin]<=amt && ways[amt-coins[coin]] != 0)
                ways[amt] = (ways[amt]+ways[amt-coins[coin]])%MOD;
        }
    }
    std::cout<<ways[target];
}