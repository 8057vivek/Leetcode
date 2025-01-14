class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> seenA, seenB; 
        vector<int> result(n, 0); 
        int commonCount = 0;

        for (int i = 0; i < n; i++) {
            
            if (seenB.count(A[i])) commonCount++;
            if (seenA.count(B[i])) commonCount++;
            
            
            seenA.insert(A[i]);
            seenB.insert(B[i]);

            
            if (A[i] == B[i]) commonCount++;

            result[i] = commonCount; 
        }
        
        return result;
    }
};
