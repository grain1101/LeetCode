package com.company;

public class AddTwoNumbers_2 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if( (l1 == null) || (l2 == null) ) return null;
        int carry = 0;
        ListNode prev = new ListNode(0);
        ListNode head = prev;
        while (l1 != null || l2!=null || carry!=0){
            int val1 = 0, val2 = 0;
            if (l1!=null){
                val1 = l1.val;
                l1 = l1.next;
            }
            if (l2!=null){
                val2 = l2.val;
                l2 = l2.next;
            }
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            prev.next = new ListNode(sum % 10);
            prev = prev.next;
        }
        return head.next;
    }
    public static void main(String args[]){
        ListNode l1 = new ListNode(0);
        ListNode l2 = new ListNode(0);
        int[] arr1 = {2,4,3};
        int[] arr2 = {5,6,4};
        ListNode p = l1, q = l2;
        for(int i = 0; i < arr1.length; i++){
            p.next = new ListNode(arr1[i]);
            p = p.next;
            q.next = new ListNode(arr2[i]);
            q = q.next;
        }
        AddTwoNumbers_2 s = new AddTwoNumbers_2();
        ListNode ret = s.addTwoNumbers(l1, l2);
        ret = ret.next;
        while (ret != null){
            System.out.print(ret.val);
            System.out.print(" ");
            ret = ret.next;
        }
        System.out.println(" ");
    }
}
