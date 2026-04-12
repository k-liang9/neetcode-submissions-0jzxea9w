class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;

            int intermediate = a_bit ^ b_bit ^ c;
            c = (a_bit*b_bit) | (b_bit*c) | (c*a_bit);

            res |= (intermediate << i);
        }

        return res;
    }
};