class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(min(numRows, int(s.size())));
        if(numRows == 1){
            return s;
        }
        bool curr = false;
        int j = 0;
        for(int i=0;i<s.length();i++){
            if(j==numRows-1){
                curr = true;
            }
            if(j==0){
                curr = false;
            }
            if(curr){
                v[j]+=s[i];
                j--;
            }
            if(!curr){
                v[j]+=s[i];
                j++;
            }
        }
        
        string answer ="";
        for(string x:v) answer+=x;
        return answer;
    }
};