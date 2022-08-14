/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int result=0;
        for(auto it:employees)
        {
            if(it->id==id)
            {
                result=it->importance;
                if(it->subordinates.empty()==false)
                {
                    for(auto i:it->subordinates)
                    {
                        result+=getImportance(employees,i);
                    }
                }
            }
        }
        return result;
    }
};