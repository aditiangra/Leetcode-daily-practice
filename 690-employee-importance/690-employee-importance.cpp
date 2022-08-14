class Solution {
public:
    unordered_map<int, Employee*> emap;
    int getImportance(vector<Employee*> employees, int id) {
        for(auto& emp : employees){
            emap[emp->id] = emp;
        }
        return dfs(id);
    }
    int dfs(int id){
        Employee* emp = emap[id];
        int result = emp->importance;
        for(auto& s : emp->subordinates){
            result += dfs(s);
        }
        return result;
    }
};