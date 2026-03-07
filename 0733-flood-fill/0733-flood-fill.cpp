class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        queue <pair<int,int>> q;
        q.push({sr,sc});
        int clr=image[sr][sc];
        image[sr][sc]=color;
        vector <vector <int>> vis(n,vector <int> (m , 0));
        vis[sr][sc]=1;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=drow[i]+r;
                int ncol=dcol[i]+c;
                if(nrow >= 0 && nrow<n && ncol>=0 && ncol < m && vis[nrow][ncol] !=1 && image[nrow][ncol] == clr){
                    q.push({nrow,ncol});
                    image[nrow][ncol]=color;
                    vis[nrow][ncol]=1;
                }
            }
        }
        return image;
    }
};