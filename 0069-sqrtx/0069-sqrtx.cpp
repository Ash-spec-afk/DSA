class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int res;

        if(x == 0){
            return 0;
        }

        while(low <= high){
            int mid = low + (high - low)/2;

            if(1L * mid*mid <= x){
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return res;
    }
};