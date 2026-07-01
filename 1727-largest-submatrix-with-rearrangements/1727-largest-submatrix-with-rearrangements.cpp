//  simplified revised
int freq[100000];
class Solution {
public:  
    static int largestSubmatrix(vector<vector<int>>& matrix) {
        const int m=matrix.size(), n=matrix[0].size();
        int area=count(matrix[0].begin(), matrix[0].end(), 1);
        if (m==1) return area;
        if (n==1){
            for(int i=1; i<m; i++){
                int& x=matrix[i][0];
                x+=-x & matrix[i-1][0];
                area=max(area, x);
            }
            return area;
        }
        int maxH=0;
        for(int i=1; i<m; i++){
            for(int j=0;  j<n; j++){
                int& x=matrix[i][j];
                x+= -x & matrix[i-1][j];
                maxH=max(maxH, x);// find max height for this row
            }
            memset(freq, 0, sizeof(int)*(maxH+1));
            for(int x: matrix[i]){
                freq[x]++;
            }
            int acc=0;
            for(int x=maxH; acc<n; x--){
                if (freq[x]>0){
                    acc+=freq[x];
                    area=max(area, acc*x);
                }
            }  
        }
        return area;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();