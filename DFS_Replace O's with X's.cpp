//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<char>>& mat, int n, int m ){
      vis[x][y]=1;
      int dx[]={1,-1,0,0};
      int dy[]={0,0,1,-1};

      for(int i=0; i<4; i++){
         int a=x+dx[i];
         int b=y+dy[i];

         if(a>=0 and a<n and b>=0 and b<m and vis[a][b]==0 and mat[a][b]=='O'){
            dfs(a,b,vis,mat,n,m);
         }
      }
   }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
      vector<vector<int>>vis(n,vector<int>(m,0));
      vector<vector<char>> ans(n,vector<char>(m,'.'));

      for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            if((i==0 or j==0 or i==n-1 or j==m-1) and vis[i][j]==0 and mat[i][j]=='O'){
               dfs(i,j,vis,mat,n,m);
            }
         }
      }

      for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            if(mat[i][j]=='O' and vis[i][j]==0){
               ans[i][j]='X';
               continue;
            }
            ans[i][j]=mat[i][j];
         }
      }

      return ans;
    }


    };

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
