class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>stud;
        for(int i=0;i<students.size();i++)
        {
            stud.push(students[i]);
        }
        int rotation=0,i=0;
        while(!stud.empty() && rotation<stud.size())
        {
            if(stud.front()==sandwiches[i])
            {
                i++;
                stud.pop();
                rotation=0;
            }
            else{
                int choice=stud.front();
                stud.pop();
                stud.push(choice);
                rotation++;
            }
        }
        return stud.size();
        
    }
};