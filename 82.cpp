/*
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

思路 1：遍历
这道题的题意是需要保留所有不同数字，而重复出现的所有数字都要删除。因为给定的链表是升序排列的，所以我们要删除的重复元素在链表中的位置是连续的。所以我们可以对链表进行一次遍历，然后将连续的重复元素从链表中删除即可。具体步骤如下：

先使用哑节点 dummy_head 构造一个指向 head 的指针，使得可以防止从 head 开始就是重复元素。
然后使用指针 cur 表示链表中当前元素，从 head 开始遍历。
当指针 cur 的下一个元素和下下一个元素存在时：
如果下一个元素值和下下一个元素值相同，则我们使用指针 temp 保存下一个元素，并使用 temp 向后遍历，跳过所有重复元素，然后令 cur 的下一个元素指向 temp 的下一个元素，继续向后遍历。
如果下一个元素值和下下一个元素值不同，则令 cur 向右移动一位，继续向后遍历。
当指针 cur 的下一个元素或者下下一个元素不存在时，说明已经遍历完，则返回哑节点 dummy_head 的下一个节点作为头节点。
#思路 1：代码
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* dummy_head = new ListNode(); 
        dummy_head->next = head;
        cur = dummy_head;
        while (cur && cur->next)
        {
            ListNode* tmp = cur->next;
        }
        

    }
};