class Solution {
public:
     bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0, flowers = 0;
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // reset if not bloomed
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long)m * k;
        // no of flowers - (bloomday size) < m*k not possible to find m bouquets
        if (bloomDay.size() < total) return -1; 

        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while (low <= high) { // o(log(maxelement))
            int mid = low + (high - low) / 2;
            if (canMake(bloomDay, m, k, mid)) { // o(n)
                ans = mid;
                high = mid - 1; // go left you might find minimum days
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};