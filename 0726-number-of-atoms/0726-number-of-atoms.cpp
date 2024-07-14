class Solution {
public:
    string countOfAtoms(string formula) {
        int n=formula.length();
        //formula,count
        stack<unordered_map<string,int>>stk;
        //pushing an empty unordered map 
        stk.push(unordered_map<string,int>());
        int i=0;
        while(i<n)
        {
            //opening bracket, ek empty map push krni thi
            if(formula[i]=='(')
            {
                stk.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i]==')')
            {
                //closing bracket hui toh jo top pe hai usko pop krni hai and check krni hai ki closing bracket ke baad koi number hai kya, agar hai toh usse multiply kr deni hai jo top pe elements present hai unke frequency ke saath
                unordered_map<string,int>mpp=stk.top();
                stk.pop();
                i++;
                string mult;
                while(i<n && isdigit(formula[i]))
                {
                    mult+=(formula[i]);
                    i++;
                }
                //if koi number thi closing bracket ke baad
                if(!mult.empty())
                {
                    int multiplier=stoi(mult);
                    for(auto &it:mpp)
                    {
                        string elt=it.first;
                        int num=it.second;
                        mpp[elt]=num*multiplier;
                    }
                }
                //ab merge krni jo stack ke top pe hai uske saath
                for(auto it:mpp)
                {
                    string elt=it.first;
                    int num=it.second;
                    stk.top()[elt]+=num;
                }
            }
            else{ //koi string hui toh
                string currElement;
                currElement+=formula[i];
                i++;
                //if agar element mein lower case bhi present hui toh
                while(i<n && islower(formula[i]))
                {
                    currElement+=formula[i];
                    i++;
                }
                //agar uske baad koi number hui toh
                string currCount;
                while(i<n && isdigit(formula[i]))
                {
                    currCount+=formula[i];
                    i++;
                }
                int count=currCount.empty()?1:stoi(currCount);
                stk.top()[currElement]+=count;
            }
        }
        map<string,int>mpp(begin(stk.top()),end(stk.top()));
        string res;
        for(auto it:mpp)
        {
            res+=it.first;
            if(it.second>1)
            {
                res+=to_string(it.second);
            }
        }
        return res;
    }
};