/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        
        if (n == 0) return 0;
        
        map<int, int> x, y;
        map<double, int> normal;
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            if (n - i <= ans) break;
            x.clear(); y.clear(); normal.clear(); fprintf(stderr, "%d: ", i);
            int dup, temp;
            dup = temp = 0;
            for (int j = i + 1; j < n; j ++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) dup ++; else {
                    if (points[i].x == points[j].x) {
                        x[points[i].x] ++;
                        temp = max(temp, x[points[i].x]);
                    }
                    
                    if (points[i].y == points[j].y) {
                        y[points[i].y] ++;
                        temp = max(temp, y[points[i].y]);
                    }
                    
                    if (points[i].x != points[j].x && points[i].y != points[j].y) {
                        double d = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
                        normal[d] ++;
                        temp = max(temp, normal[d]);
                    }
                }
            }
            
            ans = max(ans, temp + dup + 1);
        }

        return ans;
    }
};