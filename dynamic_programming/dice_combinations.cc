#include<iostream>
#include<vector>
#define MOD 1000000007
int main(){
    int target; std::cin>>target;
    std::vector<long long> ways(target+1,0);
    ways[0] = 1;
    for(int currSum=1; currSum<=target; currSum++){
        for(int diceVal=1; diceVal<=6; diceVal++){
            if(currSum-diceVal>=0){
                ways[currSum] = (ways[currSum]+ways[currSum-diceVal])%MOD;
            }
        }
    }
    std::cout<<ways[target];
}