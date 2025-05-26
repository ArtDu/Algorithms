// Нужно узнать можно ли провести вертикальную прямую, чтобы все точки были симметричны
// https://www.lintcode.com/problem/908/

class Solution {
public:
    /**
     * @param points: n points on a 2D plane
     * @return: if there is such a line parallel to y-axis that reflect the given points
     */
    bool isReflected(vector<vector<int>> &points) {
        if (points.size() < 1) {
            return true;
        } 

        int min_x = INT_MAX;
        int max_x = INT_MIN;

        map<pair<int, int>, int> mp;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            min_x = min(min_x, x);
            max_x = max(max_x, x);
            mp[{x, y}]++;
        }
        int candidate = max_x + min_x;
        
        for (auto& [k, v] : mp) {
            int reflected_x = candidate - k.first;
            int y = k.second;

            if (mp[{reflected_x, y}] != v) {
                return false;
            }
        }

        return true;
    }
};
