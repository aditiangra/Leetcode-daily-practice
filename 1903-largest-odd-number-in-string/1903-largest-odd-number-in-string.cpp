class Solution {
public:
    string largestOddNumber(string n) {
         return n.substr(0, n.find_last_of("13579") + 1);
    }
};