class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        for (int card : hand) {
            int start = card;
            while (count[start-1] > 0) {
                start--;
            }
            while (start <= card) {
                while (count[start] > 0) {
                    for (int i = start; i < start + groupSize; i++) {
                        if (count[i] == 0) {
                            return false;
                        }
                        count[i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};
