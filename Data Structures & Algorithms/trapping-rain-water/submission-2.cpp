class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left_max(n,0);
        vector<int> right_max(n,0);
        int max_left=0;
        int max_right=0;
        for(int i=1;i<n;i++){
            max_left=max(max_left,height[i-1]);
            left_max[i]=max_left;
        }
        for(int i=n-2;i>0;i--){
            max_right=max(max_right,height[i+1]);
            right_max[i]=max_right;
        }
        int water=0;
        for(int i=0;i<n;i++){
            water+=max(min(right_max[i],left_max[i])-height[i],0);
        }
        return water;
    }
};
