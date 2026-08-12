class Solution {
public:
    int findlast(vector<int>& nums, int target, int left, int right){
        int last = -1;
        while(left <= right){
            int mid = (left  + right)/2;
            if(nums[mid] == target){
            last = mid;
            left = mid + 1;
            }

            if(nums[mid] < target){
                left = mid + 1;
            }

            else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        return last;
    }

    int findfirst(vector<int> &nums, int target, int left, int right){
        int first = -1;

        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                first = mid;
                right = mid -1;
            }

            if(nums[mid] > target){
                right = mid -1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
        }
        return first;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = findfirst(nums, target, 0, n-1);
        int last = findlast(nums, target, 0, n-1);
        vector<int>res = {first, last};
        return res;
    }
};