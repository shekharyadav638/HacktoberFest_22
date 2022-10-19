#include <bits/stdc++.h>
using namespace std;

void solve(int row, int col, int n, int m, vector<vector<char>> &arr, vector<vector<bool>> &visited){
      if(row>=n || row<0 || col>=m || col<0 || visited[row][col] || arr[row][col]=='#')
      return;
      
      visited[row][col]=true;
      
      solve(row+1,col,n,m,arr,visited);
      solve(row,col+1,n,m,arr,visited);
      solve(row-1,col,n,m,arr,visited);
      solve(row,col-1,n,m,arr,visited);
}

int main(){
      int n,m;
      cin>>n>>m;
      
      vector<vector<char>> arr(n, vector<char> (m));
      vector<vector<bool>> visited(n, vector<bool> (m, false));
      
      for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  cin>>arr[i][j];
            }
      }
      
      int ans=0;
      for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
                  if(arr[i][j]=='.' && !visited[i][j]){
                        solve(i,j,n,m,arr,visited);
                        ans++;
                  }
            }
      }
      
      cout<<ans;
}
