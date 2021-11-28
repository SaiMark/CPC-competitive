class Solution {
public:
    int target = 0;
    vector<int>temp;
    vector<vector<int>>vec;
    
    void dfs(vector<vector<int>>&graph, int curr=0 ){
        
        temp.push_back(curr);
        
        if(curr == target){
            vec.push_back(temp);
        }
        for(int i:graph[curr]){
            dfs(graph,i);
        }
        
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size()-1;
        dfs(graph);
        return vec;
    }
};