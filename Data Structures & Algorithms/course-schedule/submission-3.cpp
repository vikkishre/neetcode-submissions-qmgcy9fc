class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses,0);
        int count=0;
        for(auto &p:prerequisites)
        {
            int pre=p[1];
            int curr=p[0];
            adj[pre].push_back(curr);
            in[curr]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int pop=q.front();
            q.pop();
            count++;
            for(int n:adj[pop])
            {
                in[n]--;
                if (in[n] == 0)
                    q.push(n);
            }   
            
        }
        return count == numCourses;
    }
    
};
