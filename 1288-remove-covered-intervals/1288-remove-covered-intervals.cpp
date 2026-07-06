class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
    
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int count = 0;
        int currentEnd = -1; 

        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

        
            if (end > currentEnd) {
                count++;       
                currentEnd = end; 
            }
        }

        return count;
    }
};
