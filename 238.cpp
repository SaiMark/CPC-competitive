class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>left;
        vector<int>right;
        vector<int>answer;
        
        //Build up Left
        left.push_back(1);
        for(int i=0;i<nums.size()-1;i++){
            int check = left[i] * nums[i];
            left.push_back(check);
        }
        
        reverse(nums.begin(),nums.end());
        
        //Build up Right
        right.push_back(1);
        for(int i=0 ;i<nums.size()-1;i++){
            int check = right[i] * nums[i];
            right.push_back(check);
        }
        
        reverse(right.begin(),right.end());
        
        for(int i=0;i<(int)nums.size();i++){
            int rush = left[i] * right[i];
            answer.push_back(rush);
        }
        
        return answer;
    }
};