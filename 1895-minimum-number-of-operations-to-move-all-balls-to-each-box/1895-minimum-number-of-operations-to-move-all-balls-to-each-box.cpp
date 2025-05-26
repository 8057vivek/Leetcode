class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n,0);

        // for(int i=0;i<n;i++){
        //     int stepsToAdd = 0;
        //     for(int j=0;j<n;j++){
        //         if(boxes[j]=='1'){
        //             stepsToAdd += abs(i-j);
        //         }
        //     }
        //     result[i] = stepsToAdd;
        // }

        int balls = 0;
        int stepsToAdd = 0;
        for(int i=0;i<n;i++){
            result[i] += stepsToAdd;
            balls += boxes[i]-'0';
            stepsToAdd += balls;
        }
        
        balls = 0;
        stepsToAdd = 0;
        for(int i=n-1;i>=0;i--){
            result[i] += stepsToAdd;
            balls += boxes[i]-'0';
            stepsToAdd += balls;
        }

        return result;

    }
};