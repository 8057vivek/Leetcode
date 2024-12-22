class Solution {
public:
    int calPoints(vector<string>& operations) {
        int totalSum=0;
        vector<int> result;
        

        for(string& str : operations){
            if(str=="+"){
                int sum = result[result.size()-1]+result[result.size()-2];
                result.push_back(sum);
            }
            else if(str=="D"){
                result.push_back(2*result[result.size()-1]);
            }
            else if(str=="C"){
                result.pop_back();
            }else{
                result.push_back(stoi(str));
            }
        }

        int total=0;
        for(int& a:result){
            total+=a;
        }
        return total;
    }
};