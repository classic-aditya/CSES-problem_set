#include<iostream>
#include<vector>
int main(){
    long long sum = 0;
    int n,i=0; std::cin>>n;
    std::vector<int> arr(n-1);
    for(i=0; i<n-1; i++) 
    {
        std::cin>>arr[i];
        sum += arr[i];
        sum -= i+1;
    }
    std::cout<<n-sum;
}