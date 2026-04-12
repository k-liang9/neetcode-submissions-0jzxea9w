// iterate over every triplet
// if a triplet:
//  1: contains an element of the target triplet, and
//  2: have the other 2 elements less than or equal to the target triplet
// then set the corresponding flag for the element in the triplet to true
// check that every flag for the triplet is set to true

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> flags(3, false);
        for (auto& triplet : triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                if (triplet[0] == target[0]) {
                    flags[0] = true;
                }
                if (triplet[1] == target[1]) {
                    flags[1] = true;
                }
                if (triplet[2] == target[2]) {
                    flags[2] = true;
                }
            }
        }
        for (bool flag : flags) {
            if (!flag) {
                return false;
            }
        }
        return true;
    }
};
