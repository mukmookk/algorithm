from collections import deque

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # reverse
        reverse = head
        r_deque = deque()
        while reverse:
            r_deque.appendleft(reverse.val)
            reverse = reverse.next

        r_len = len(r_deque)
        for i in range(r_len):
            if i < r_len / 2:
                head.val = r_deque[-1-i]
                head = head.next
            else:
                break
            
            if i < r_len // 2:
                head.val = r_deque[i]
                head = head.next