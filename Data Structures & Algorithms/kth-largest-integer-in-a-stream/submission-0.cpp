class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        if(minHeap.size() < k){
            minHeap.push(val);
        }
        else if(minHeap.top() < val){
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }
};
