#include<iostream>
void weirdAlgo(long long n){
    if(n==1) return;
    else if(n%2==0){
        std::cout<<n/2<<" ";
        weirdAlgo(n/2);
    }
    else{
        std::cout<<n*3+1<<" ";
        weirdAlgo(n*3+1);
    }
}
int main(){
    long long n; std::cin>>n;
    std::cout<<n<<" ";
    weirdAlgo(n);
}