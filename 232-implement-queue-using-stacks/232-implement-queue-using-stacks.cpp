class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>s1;
    stack<int>s2;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        if(s1.empty()) s1.push(x);
        
        else{
            
            while(!s1.empty()){
                int a=s1.top();
                s1.pop();
                s2.push(a);
            }
            
            s1.push(x);
            
            while(!s2.empty()){
                int a=s2.top();
                s2.pop();
                s1.push(a);
            }
        }
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        int a=s1.top();
        s1.pop();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        
        return s1.empty();
    }
};