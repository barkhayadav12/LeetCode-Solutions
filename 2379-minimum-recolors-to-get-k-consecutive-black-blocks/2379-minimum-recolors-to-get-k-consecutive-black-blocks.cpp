class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0;
        int j=0;
        int mini=INT_MAX;
        int cnt=0;
        while(j<blocks.size())
        {
            if(blocks[j]=='W')
            {
                cnt++;
            }
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                mini=min(mini,cnt);
                if(blocks[i]=='W')
                {
                    cnt--;
                }
                i++;
                j++;
            }
            
        }
        return mini;
    }
};