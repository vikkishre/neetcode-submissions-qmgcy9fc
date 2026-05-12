class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // build graph
        for (auto &p : prerequisites) {
            int course = p[0];
            int pre = p[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // push all nodes with 0 indegree
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // if we processed all courses → no cycle
        return count == numCourses;
    }
};