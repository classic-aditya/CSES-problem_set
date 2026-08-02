#include<iostream>
#include<string>
int main(){
    std::string str; std::cin>>str;
    int len = 0, maxlen = 0;
    if(str.empty()) { std::cout<<0; return 0; }
    for(int i=1; i<str.length(); i++){
        if(str[i] == str[i-1]) len++; 
        if(len>maxlen) maxlen = len;
        if(str[i] != str[i-1]){
            len = 0;
        }
    }
    std::cout<<maxlen+1;
}