#include<iostream>
#include<vector>
const int MOD = 1e9+7;
int findpaths(std::vector<std::vector<char>>& grid,int rowNo, int colNo,std::vector<std::vector<int>>& dp){
    int size = grid.size();
    if(rowNo == size-1 && colNo == size-1) 
    {
        if(grid[rowNo][colNo] == '*') return dp[rowNo][colNo] = 0;
        else return 1;
    }
    else if(rowNo<size-1 && colNo<size-1 && grid[rowNo+1][colNo] == '*' && grid[rowNo][colNo+1] == '*')
        return dp[rowNo][colNo] = 0;
    
    else if( dp[rowNo][colNo] != -1 ) return dp[rowNo][colNo];

    else if(rowNo == size-1 && colNo<size-1)
    {
        if(grid[rowNo][colNo+1] == '.') return dp[rowNo][colNo] = findpaths(grid,rowNo,colNo+1,dp)%MOD;
        else return dp[rowNo][colNo] = 0;
    }
    else if(rowNo<size-1 && colNo == size-1)
    {   
        if(grid[rowNo+1][colNo] == '.') return dp[rowNo][colNo] = findpaths(grid,rowNo+1,colNo,dp)%MOD;
        else return dp[rowNo][colNo] = 0;
    }
    else{
        if(grid[rowNo+1][colNo] == '.' && grid[rowNo][colNo+1] == '.')
            return dp[rowNo][colNo] = (findpaths(grid,rowNo+1,colNo,dp) + findpaths(grid,rowNo,colNo+1,dp))%MOD;
        else if(grid[rowNo+1][colNo] == '.') return dp[rowNo][colNo] = findpaths(grid,rowNo+1,colNo,dp)%MOD;
        else return dp[rowNo][colNo] = findpaths(grid,rowNo,colNo+1,dp)%MOD;
    }
}
int main(void){
    int n; 
    std::cin>>n;
    std::vector<std::vector<char>> grid(n, std::vector<char>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            std::cin>>grid[i][j];
    }
    if(grid[0][0] == '*')
    {
        std::cout<<0;
        return 0;
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(n,-1));
    int rowNo = 0 , colNo = 0;
    std::cout<<findpaths(grid,rowNo,colNo,dp);
}