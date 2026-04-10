class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue <pair<int,pair<int ,int>>,vector <pair<int,pair<int,int>>> , greater <pair <int,pair<int,int>>>> pq;
        int m=heights.size();
        int n=heights[0].size();
        pq.push({0,{0,0}});
        vector <vector <int>> dist(m,vector <int> (n,1e9));
        dist[0][0]={0};
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();
            if(r == m-1 && c == n-1)    return diff;
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow >=0 && ncol>=0 && nrow <m && ncol <n){
                    int neweffort=max(abs(heights[nrow][ncol] - heights[r][c]),diff);
                    if(neweffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};