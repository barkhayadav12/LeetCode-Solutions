class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int>s;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(s.empty())
            {
                ans.push_back(-1);
            }
            else if(s.size()>0 && s.top()>nums2[i])
            {
                ans.push_back(s.top());
            }
            else if(s.size()>0 && s.top()<=nums2[i])
            {
                while(s.size()>0 && s.top()<=nums2[i])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(s.top());
                }
            }
            s.push(nums2[i]);
        }
        reverse(ans.begin(),ans.end());
        vector<int>ind;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    ind.push_back(ans[j]);
                }
            }
        }
        return ind;
    }
};