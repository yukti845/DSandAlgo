class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        r=None
        c=head
        while(c):
            next=c.next
            c.next=r
            r=c
            c=next
        return r
