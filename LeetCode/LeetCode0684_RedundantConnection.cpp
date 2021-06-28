// LeetCode0684.cpp
// https://leetcode.com/problems/redundant-connection/
class Solution {
    vector<int> parent;

    int Find(int target) {
        return (target == parent[target] ? target : Find(parent[target]));
    }

    void Union(int a, int b) {
        if (a < b)
            parent[b] = a;
        else
            parent[a] = b;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i = 0; i < n + 1; i++)
            parent.push_back(i);

        for (vector<int>& edge : edges) {
            int aRoot = Find(edge[0]);
            int bRoot = Find(edge[1]);

            if (aRoot == bRoot)
                return edge;
            else
                Union(aRoot, bRoot);
        }

        return vector<int> (2);
    }
};