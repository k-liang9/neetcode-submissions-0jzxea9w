class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            print(token)
            if token == '+' or token == '-' or token == '*' or token == '/':
                second = stack.pop()
                first = stack.pop()
                print(first, second)
                if token == '+':
                    stack.append(first + second)
                    print(first + second)
                elif token == '-':
                    stack.append(first - second)
                    print(first - second)
                elif token == '*':
                    stack.append(first * second)
                    print(first * second)
                else:
                    stack.append(int(first / second))
                    print(int(first / second))
            else:
                print('num')
                stack.append(int(token))
                

        return stack.pop()