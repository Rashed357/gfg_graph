//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int x,int y, vector<pair<int,int>>& list, vector<vector<int>>& vis, vector<vector<int>>& grid, int bx,int by,int n,int m){
     vis[x][y]=1;
     list.push_back({x-bx,y-by});
     
     int dx[]={1,-1,0,0};
     int dy[]={0,0,1,-1};
     for(int i=0; i<4; i++){
         int nx=x+dx[i];
         int ny=y+dy[i];
         if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]==1 and vis[nx][ny]==0){
             dfs(nx,ny,list,vis,grid,bx,by,n,m);
         }
     }
  }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 and grid[i][j]==1){
                    vector<pair<int,int>>list;
                    dfs(i,j,list,vis,grid,i,j,n,m);
                    st.insert(list);
                }
            }
        }
        
        return st.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
