class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        return self.build_strs('', n, 0)

    def build_strs(self, cur_str : str, num_avail_open, num_need_close):
        if num_avail_open == 0:
            if num_need_close == 0:
                return [cur_str]
            else:
                cur_str += ')'
                return self.build_strs(cur_str, num_avail_open, num_need_close-1)

        if num_need_close == 0:
            cur_str += '('
            return self.build_strs(cur_str, num_avail_open-1, num_need_close+1)

        strs = []
        strs.extend(self.build_strs(cur_str + '(', num_avail_open-1, num_need_close+1))
        strs.extend(self.build_strs(cur_str + ')', num_avail_open, num_need_close-1))
        return strs