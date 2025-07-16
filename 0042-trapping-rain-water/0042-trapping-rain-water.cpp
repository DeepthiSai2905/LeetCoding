class Solution {
public:
    int trap(vector<int>& height) {
        // optimal -> trap possible - left taller right taller
        int totalArea=0;
        int n=height.size();
        int i=0,j=n-1;
        int rightMax,leftMax;
        while(i<=j){// always stop/endup at tallest building
            if(height[i]<=height[j]){ // right more - check leftmax
                if(leftMax>height[i]) {
                    totalArea += leftMax-height[i];
                }else{
                    leftMax = height[i];
                }
                i++;
            }else{
                if(rightMax>height[j]){
                    totalArea += rightMax-height[j];
                }else{
                    rightMax = height[j];
                }
                j--;
            }
        }
        return totalArea;
    }
};