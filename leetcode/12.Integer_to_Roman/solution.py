class Solution:
    roman = ["M", "D", "C", "L", "X", "V", "I"]
    def check_and_up_digit(self, num):
        return [(num + 1) % 5, num + 1]
    
    def handleFourNine(self, num):
        return ("IX" if num == 9 else "IV")
    
    def handleDigits(self, num):
        return self.roman[num]
    
    def sep_digits(self, num):
        thoud = num // 1000
        f_hund = (num % 1000) // 500
        hund = (num % 500) // 100
        f_ten = (num % 100) // 50
        ten = (num % 50) // 10
        five = (num % 10) // 5
        digit = (num % 5)
        return [thoud, f_hund, hund, f_ten, ten, five, digit]
    
    def intToRoman(self, num: int) -> str:
        s_num = str(num)
        #for i in range(len(s_num)):
        #    checked = self.check_and_up_digit(int(s_num[i]))
        #    conv = True if checked[0] == 0 else False
        #    if (conv):
        #        ret += self.handleFourNine(s_num[i])
        #    else:
        #        ret += self.handleDigits(s_num[i])
        compos = self.sep_digits(num)
        for idx in len(compos):
            if (idx % 2 == 0) and (compos[idx] == 4 or compos[idx] == 9):
                ret += self.handleFourNine
                ret[idx] = 0
            else:
                while compos[idx] > 0:
                    ret += self.roman[compos[idx]]
                    compos[idx] = compos[idx] - 1
            return compos

            
        #s_num = str(num)
        #ret = ""
        #for i in range(len(s_num)):
        #    checked = self.check_and_up_digit(int(s_num[i]))
        #    conv = True if checked[0] == 0 else False
        #    if (conv):
        #        ret += self.handleFourNine(s_num[i])
        #    else:
        #        ret += self.handleDigits(s_num[i])        
        #return ""
    
if __name__ == "__main__":
	obj = Solution()
	obj.intToRoman(900)