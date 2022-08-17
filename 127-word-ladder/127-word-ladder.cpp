class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //finding endWord in the list//
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())return 0;
        //inserting everything in a set//
        set<string>s;
        for(int i=0;i<wordList.size();i++)
        {
            s.insert(wordList[i]);
        }
        //starting bfs//
        queue<string>q;
        q.push(beginWord);
        int cnt=0;
        while(q.empty()==false)
        {
            cnt++;
            int size=q.size();
            while(size--)
            {
                string curr=q.front();
                q.pop();
                for(int j=0;j<curr.size();j++)
                {
                    string temp=curr;
                    for(char c='a';c<='z';c++)
                    {
                        temp[j]=c;
                        if(temp==curr)continue;
                        if(temp==endWord)return cnt+1;
                        if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
        
            }
};