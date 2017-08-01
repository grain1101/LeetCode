// 305 Number of Islands II 
class UnionFind{
private:
    vector<int> p;
    int cnt;
public:
    UnionFind(int n){
        p.assign(n, -1);
        cnt = n;
    }
    bool Union(int x, int y){
        int rx = Find(x), ry = Find(y);
        if (rx == ry) return false;
        cnt--;
        if (p[rx] < p[ry]) p[rx] += p[ry], p[ry] = rx;
        else p[ry] += p[rx], p[rx] = ry;
        return true;
    }
    int Find(int x){
        return p[x] < 0 ? x : (p[x] = Find(p[x]));
    }
    int getCnt(){
        // negative number is root;
        return cnt;
    }
};

class PondsAndIslands {
public:
    int getIslands(int m, int n, vector<PII> positions) {
        UnionFind uf(m * n);
        int ret = 0;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(auto p : positions) {
            if (grid[p.first][p.second] == 1) continue;
            grid[p.first][p.second] = 1;
            int idx = p.first * n + p.second;
            set<int> roots;
            for(int i = 0; i < 4; i++) {
                if (checkBoundary(p.first + d[i][0], p.second + d[i][1], m, n) && grid[p.first + d[i][0]][p.second + d[i][1]] == 1) {
                    int tmp = (p.first + d[i][0]) * n + p.second + d[i][1];
                    int r = uf.Find(tmp);
                    roots.insert(r);
                }
            }
            ret++;
            for(auto r : roots) {
                uf.Union(idx, r);
                ret--;
            }
            cout << ret << endl;
        }
        return ret;
    }
private:
    vector<vector<int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
    bool checkBoundary(int i, int j, int m, int n) {
        return (i >=0 && i < m && j >=0 && j < n);
    }
};