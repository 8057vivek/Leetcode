class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();

        vector<vector<int>> result;
        int i = 0;
        int j = 0;
        
        while(i<n && j<m){
            int firstEle = max(firstList[i][0],secondList[j][0]);
            int secondEle = min(firstList[i][1],secondList[j][1]);
            if(firstEle<=secondEle){
                result.push_back({firstEle, secondEle});
            }

            if(firstList[i][1]<secondList[j][1]){
                i++;
            }else{
                j++;
            }
            
        }
        return result;
    }
};