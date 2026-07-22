class Solution {
    class cmp {
public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if(a.first == b.first)
            return a.second < b.second;   // larger value has higher priority
        return a.first < b.first;         // larger distance has higher priority
    }
};
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for(int i=0; i<arr.size(); i++){
            //if(arr[i] == x){
                //continue;
           // }
            int diff = abs(arr[i] - x);

            pq.push({diff, arr[i]});

            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        //reverse(res.begin(), res.end());
        sort(res.begin(), res.end());
        return res;
    }
};