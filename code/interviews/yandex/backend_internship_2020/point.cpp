//Нужно узнать можно ли провести вертикальную прямую, чтобы все точки были симметричны

bool f(vector<pnt> &points){
    
    int n = points.size();
    
    int mid;
    for(int i = 0; i < n; ++i){
        mid += (points[i].x * 2);
    }
    if(mid % n != 0) return false;
    mid /= n;
    
    
    map<pair<int, int>, int> mp;
    for(int i = 0; i < n; ++i){
        int y = points[i].y;
        int x = points[i].x * 2;
        
        x -= mid;
        mp[{y, abs(x)}]++;
    }
    
    for(auto &[k, v] : mp){
        if(v % 2 != 0){
            return false;
        }
    }
    
    
    return true;
}
