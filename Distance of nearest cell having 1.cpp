//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
   vector<vector<int>>nearest(vector<vector<int>>grid)
   {
       // Code here
      int n,m;
      n=grid.size();
      m=grid[0].size();
      int vis[n][m]={0};
      for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            vis[i][j]=0;
         }
      }
      vector<vector<int>>ans(n,vector<int>(m,-1));
      
      queue<pair<pair<int,int>,int>>q;

      for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            if(grid[i][j]==1){
               q.push({{i,j},0});
               vis[i][j]=1;
            }
            
         }
       
      }

      int lv;
      int dx[]={1,-1,0,0};
      int dy[]={0,0,1,-1};
      while(!q.empty()){
         int x=q.front().first.first;
         int y=q.front().first.second;
         lv=q.front().second;
         q.pop();
         ans[x][y]=lv;

         for(int i=0; i<4; i++){
            int a=x+dx[i];
            int b=y+dy[i];
            if(a>=0 and a<n and b>=0 and b<m and vis[a][b]==0 and grid[a][b]==0){
               q.push({{a,b},lv+1});
               vis[a][b]=1;
            }
         }
      }

      return ans;
   }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int n, m;
      cin >> n >> m;
      vector<vector<int>>grid(n, vector<int>(m, -1));
      for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++){
            cin >> grid[i][j];
         }
      }
      Solution obj;
      vector<vector<int>> ans = obj.nearest(grid);
      for(auto i: ans){
         for(auto j: i){
            cout << j << " ";
         }
         cout << "\n";
      }
   }
   return 0;
}
// } Driver Code Ends
