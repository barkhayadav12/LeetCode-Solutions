class Solution {
public:
    int findComplement(int num) {
        int numberBits=(int)(log2(num))+1;
        for(int i=0;i<numberBits;i++)
        {
            num=num^(1<<i);
        }
        return num;
    }
};