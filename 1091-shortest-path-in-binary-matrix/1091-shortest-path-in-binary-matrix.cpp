class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(); 
        if(n==1){
            return grid[0][0] == 0? 1:-1;
        }
        if(grid[0][0] == 1) return -1;
        queue <pair<int,pair<int,int>>> q;
        int destr=n-1;
        int destc=n-1;
        q.push({1,{0,0}});
        vector <vector <int>> dist(n,vector <int>(n,1e9));
        int dr[]={0,1,0,-1,-1,-1,+1,+1};
        int dc[]={1,0,-1,0,-1,+1,-1,+1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0;i<8;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow >=0 && nrow <n && ncol >=0 && ncol <n && grid[nrow][ncol] == 0 && dis+1 < dist[nrow][ncol]) 
                {
                    dist[nrow][ncol]=1+dis;
                    if(nrow == destr && ncol == destc)  return dis+1;
                    q.push({1+dis,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};