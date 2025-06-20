class Solution {
public:
    int maxDistance(string s, int k) {
        int north = 0, south = 0;
        int east = 0, west = 0;
        int maxDist = 0;

        for (char move : s) {

            if (move == 'N') north++;
            else if (move == 'S') south++;
            else if (move == 'E') east++;
            else if (move == 'W') west++;

            
            int changeNS = min({north, south, k});

            int changeEW = min({east, west, k - changeNS});


            int vertical = abs(north - south) + 2 * changeNS;
            int horizontal = abs(east - west) + 2 * changeEW;

            int total = vertical + horizontal;
            
            maxDist = max(maxDist, total);
        }

        return maxDist;
    }
};
