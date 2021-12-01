class Solution {
public:
    unordered_set<string>visited;
    unordered_map<string,vector<string>>adjacent;
    
    void DFS(vector<string>&MergeAccount, string &email){
        visited.insert(email);
        MergeAccount.push_back(email);
        
        for(string& acc: adjacent[email]){
            if(visited.find(acc) == visited.end()){
                DFS(MergeAccount,acc);
            }
        } 
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int accountlengthSize = accounts.size();
        vector<vector<string>> solve;
        
        //Create Ajacency List
        for(vector<string>&acc :accounts){
            int accountSize = acc.size();
            
            string firstemail = acc[1];
            for(int j=2;j<accountSize;j++){
                string email = acc[j];
                adjacent[firstemail].push_back(email);
                adjacent[email].push_back(firstemail);
            }
        }
        
        for(vector<string>&acc : accounts){
            string name = acc[0];
            string firstemail = acc[1];
            
            if(visited.find(firstemail) == visited.end()){
                vector<string>MergeAccount;
                
                MergeAccount.push_back(name);
                DFS(MergeAccount,firstemail);
                
                sort(MergeAccount.begin()+1,MergeAccount.end());
                solve.push_back(MergeAccount);
            }
        }
        
        return solve;
    }
};