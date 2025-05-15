class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {

        sort(clips.begin(), clips.end(), [] (vector<int>& A, vector<int>& B){
            if(A[0]==B[0]){
                return A[0]>B[0];
            }
            return A[0]<B[0];
        });

        int count = 0;
        int end = 0;
        int farthest = 0;
        int i = 0;
        int n = clips.size();

        while (end < time) {
            while (i < n && clips[i][0] <= end) {
                farthest = max(farthest, clips[i][1]);
                i++;
            }

            if (farthest == end) return -1;

            end = farthest;
            count++;
        }

        return count;

    }
};