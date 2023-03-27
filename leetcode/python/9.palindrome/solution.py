class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (x < 0):
            return (False)
        t_lst = [int(d) for d in str(x)]
        for i in range(len(t_lst)):
            if (i > (len(t_lst) // 2)):
                return (True);
            if (t_lst[i] != t_lst[-1 - i]):
                return (False)
        return (True)
        
