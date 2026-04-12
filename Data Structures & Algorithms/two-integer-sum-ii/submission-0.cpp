class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indices(2);
        int left_ptr = 0;
        int right_ptr = numbers.size()-1;
        while (left_ptr < right_ptr) {
            int sum = numbers[left_ptr] + numbers[right_ptr];
            if (sum > target) {
                right_ptr--;
            } else if (sum < target) {
                left_ptr++;
            } else {
                indices[0] = left_ptr+1;
                indices[1] = right_ptr+1;
                break;
            }
        }
        return indices;
    }
};
