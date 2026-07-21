class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // Boundary check + color match check
        if (sr < 0 || sc < 0 || sr >= n || sc >= m || image[sr][sc] != oldColor)
            return;

        // Change color
        image[sr][sc] = newColor;

        // 4-directional movement
        dfs(image, sr + 1, sc, oldColor, newColor);
        dfs(image, sr - 1, sc, oldColor, newColor);
        dfs(image, sr, sc + 1, oldColor, newColor);
        dfs(image, sr, sc - 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        if (oldColor == color) return image;

        dfs(image, sr, sc, oldColor, color);
        return image;
    }
};