class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        int n = recipes.size();
        vector<string> result;
        vector<bool> cooked(n,false);
        unordered_set<string> supply(supplies.begin(),supplies.end());



        int count = n;

        while(count--){
            for(int i=0;i<n;i++){
                if(cooked[i]){
                    continue;
                }

                bool banega = true;
                for(int j=0;j<ingredients[i].size();j++){
                    if(supply.find(ingredients[i][j])==supply.end()){
                        banega = false;
                        break;
                    }
                }
                if(banega){
                    supply.insert(recipes[i]);
                    cooked[i]=true;
                    result.push_back(recipes[i]);

                }
            }
        }

        return result;
    }
};