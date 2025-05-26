class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n,0);

        for(int i=0;i<n;i++){
            int stepsToAdd = 0;
            for(int j=0;j<n;j++){
                if(boxes[j]=='1'){
                    stepsToAdd += abs(i-j);
                }
            }
            result[i] = stepsToAdd;
        }

        return result;

    }
};