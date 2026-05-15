class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &p : prerequisites) {
            int course = p[0];
            int pre = p[1];

            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;

        // Kahn's Algorithm
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            result.push_back(node);

            for (int neigh : adj[node]) {

                indegree[neigh]--;

                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // Cycle exists
        if (result.size() != numCourses)
            return {};

        return result;
    }
};