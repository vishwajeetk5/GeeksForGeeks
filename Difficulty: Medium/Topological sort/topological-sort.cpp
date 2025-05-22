class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> in(V,0);
       vector<int> adj[V];
       vector<int> res;
       
      for(int i=0;i<edges.size();i++){
          in[edges[i][1]]++;
          adj[edges[i][0]].push_back(edges[i][1]);
      }
      
      queue<int> que;
      for(int i=0;i<V;i++){
          if(in[i]==0) que.push(i);
      }
      
      while(!que.empty()){
          int node = que.front();
          que.pop();
          res.push_back(node);
          
          for(auto it : adj[node]){
              in[it]--;
              if(in[it]==0) que.push(it);
          }
      }
      
      for(int i=0;i<V;i++){
          if(in[i]>0)res.push_back(i);
      }
      
      return res;
    }
};