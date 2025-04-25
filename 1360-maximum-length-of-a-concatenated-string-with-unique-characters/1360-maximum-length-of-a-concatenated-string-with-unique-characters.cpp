class Solution {
public:
    bool hasDuplicate(string& s1, string& s2){
        int arr[26] = {0};
        for(char& c : s1){
            if(arr[c-'a']>0){
                return true;
            }
            arr[c-'a']++;
        }
        for(char& c : s2){
            if(arr[c-'a']>0){
                return true;
            }
        }
        return false;
    }
    int recursion(vector<string>& arr, int index, int n,string temp){
        if(index>=n){
            return temp.length();
        }
        int include = 0;
        int exclude = 0;
        if(hasDuplicate(arr[index], temp)){
            exclude = recursion(arr, index+1, n, temp);
        }
        else{
            exclude = recursion(arr, index+1, n, temp);
            include = recursion(arr, index+1, n, temp+arr[index]);
        }
        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";

        return recursion(arr, 0, n, temp);

    }
};