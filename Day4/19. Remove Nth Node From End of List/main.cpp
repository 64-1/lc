#include <iostream>
#include <vector>


 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* addHead(ListNode* head, int val)
{
    ListNode* aNewNode = new ListNode(val);
    aNewNode->next = head;
    return aNewNode;
}

void print(ListNode* head)
{
    ListNode* current = head;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        n= n+1;
        while(n-- && fast!=nullptr)
        {
            fast = fast->next;
            
        }
        while(fast!=nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
        
    }
};

int main ()
{
    std::vector<int> realInput = { 5,4,3,2,1 };
    ListNode* input = nullptr;
    for (const auto& val : realInput)
    {
        input = addHead(input, val);
    }
    print(input);
    input = Solution().removeNthFromEnd(input, 2);
    print(input);
}