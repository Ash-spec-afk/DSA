class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> res;

        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin()+k);

        for(int i=k; i<nums.size(); i++){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res[k-1];
    }
};