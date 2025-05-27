class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>m(n,vector<int>(n,0));
        int top=0,bot=n-1,left=0,right=n-1,dir=0;
        int value=1;
        while(top<=bot && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++) {
                    m[top][i]=value;
                    value++;
                }
                top++;
            }
            else if(dir==1){
                for(int i=top;i<=bot;i++){
                     m[i][right]=value;
                     value++;
                }
                right--;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--) {
                    m[bot][i]=value;
                    value++;
                }
                bot--;
            }
            else if(dir==3){
                for(int i=bot;i>=top;i--){
                    m[i][left]=value;
                    value++;
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return m;
    }
};