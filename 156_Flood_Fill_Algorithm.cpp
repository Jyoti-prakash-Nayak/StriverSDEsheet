#include <bits/stdc++.h>
int DR[4] = {1, 0, -1, 0};
int DC[4] = {0, -1, 0, 1};
bool isValid(int x, int y, vector<vector<int>> &image)
{
    if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size())
        return false;
    return true;
}
void dfs(int x, int y, int iniColor, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor)
{
    int n = image.size();
    int m = image[0].size();
    ans[x][y] = newColor;
    for (int k = 0; k < 4; k++)
    {
        int newx = x + DR[k];
        int newy = y + DC[k];

        if (!isValid(newx, newy, image))
            continue;
        if (image[newx][newy] == iniColor && ans[newx][newy] != newColor)
        {
            dfs(newx, newy, iniColor, ans, image, newColor);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    vector<vector<int>> ans = image;
    int iniColor = image[x][y];
    dfs(x, y, iniColor, ans, image, newColor);
    return ans;
}