#include <bits/stdc++.h> 
int maximumProduct(vector<int> &nums, int n)
{
	// Write your code here
	 if (nums.empty()) return 0;
		
        int best = INT_MIN;
        // Running products
        int maxProd = 1;
        int minProd = 1;
        
        for (int it: nums) {
            if (it < 0) {
                // Swap max and min
                swap(maxProd, minProd);
            }
            // Reset to current value if smaller or larger than it
            // (intuitively means that we start considering a new sub-array)
            maxProd = max(maxProd*it, it);
            minProd = min(minProd*it, it);
            // Update the best
            best = max(best, maxProd);
        }
        
        return best;
}
