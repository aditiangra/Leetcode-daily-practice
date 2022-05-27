class Solution {
public:
		vector<int> NSL(vector<int> heights){ // Function to find indices of next smallest left element
        vector<int> left;
        stack<pair<int,int>> st;
        for(int i=0;i<heights.size();i++){
            if(st.empty())
                left.push_back(-1);
            else if(!st.empty() && st.top().first<heights[i])
                left.push_back(st.top().second);
            else if(!st.empty() && st.top().first>=heights[i]){
                while(!st.empty() && st.top().first>=heights[i])
                    st.pop();
                if(st.empty())
                    left.push_back(-1);
                else 
                    left.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        return left;
    }
    vector<int> NSR(vector<int> heights){  // Function to find indices of next smallest right element
        vector<int> right;
        stack<pair<int,int>> st;
        for(int i=heights.size()-1;i>=0;i--){
            if(st.empty())
                right.push_back(heights.size());
            else if(!st.empty() && st.top().first<heights[i])
                right.push_back(st.top().second);
            else if(!st.empty() && st.top().first>=heights[i]){
                while(!st.empty() && st.top().first>=heights[i])
                    st.pop();
                if(st.empty())
                    right.push_back(heights.size());
                else 
                    right.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        return right;
    }
    int MAH(vector<int>& heights) {  //Function to find maximum area of histogram
        vector<int> right;
        vector<int> left;
        
        right=NSR(heights);
        left=NSL(heights);
        
        vector<int> width;
        int mx=0;
        for(int i=0;i<left.size();i++){
            width.push_back(right[i]-left[i]-1);
        }
        
        for(int i=0;i<heights.size();i++){
            mx=max(mx,heights[i]*width[i]);
        }
        
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {  // Finally......our required Maximal Rectangle Function
        int n=matrix.size();
        if(n == 0){
            return 0;
        }
        int m=matrix[0].size();
        vector<int> v;
        for(int j=0;j<m;j++){
            v.push_back(matrix[0][j]-'0');
        }
        int mx= MAH(v);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')
                    v[j]=0;
                else
                    v[j]=v[j]+(matrix[i][j]-'0');
            }
            mx=max(mx,MAH(v));
        }
        return mx;
    }
};