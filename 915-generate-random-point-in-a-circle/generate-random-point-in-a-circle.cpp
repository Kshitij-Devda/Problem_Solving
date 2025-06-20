class Solution {
public:
    double x,y,r;

    uint64_t state;

    uint64_t xorshift() {
        auto x = state;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        return state = x;
    }


    double randf() {
        return ((double)xorshift() / (double)std::numeric_limits<uint64_t>::max()) * 2.0 - 1.0;
    }

    Solution(double radius, double x_center, double y_center) 
        : r{radius}, x{x_center}, y{y_center}
    {
        state = (uintptr_t)this;
    }
    
    vector<double> randPoint() {
        double rx, ry;
        auto rr = r*r;
        do {
            rx = randf() * r, ry = randf() * r;
        } while(rx*rx+ry*ry>rr);
        return {x+rx,y+ry};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */