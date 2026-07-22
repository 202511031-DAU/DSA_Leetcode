class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Step 1: Build graph
        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);  // b → a
            indegree[a]++;
        }

        // Step 2: Push nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        // Step 3: BFS (Topological Sort)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Step 4: Check if all courses processed
        return count == numCourses;
    }
};