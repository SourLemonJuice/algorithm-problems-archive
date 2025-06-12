/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <iso646.h>
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    uint64_t digit_sum = 0;
    uint64_t carry = 0;
    struct ListNode *out_base = malloc(sizeof(struct ListNode));
    struct ListNode *out = out_base;
    *out = (struct ListNode){.val = 0, .next = NULL};
    do {
        digit_sum = carry;
        // add all digit
        if (l1 != NULL) {
            digit_sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            digit_sum += l2->val;
            l2 = l2->next;
        }

        // process carry
        if (digit_sum >= 10) {
            carry = digit_sum / 10;
            digit_sum = digit_sum % 10;
        } else {
            carry = 0;
        }

        // finishing this node
        struct ListNode *new_node = malloc(sizeof(struct ListNode));
        *new_node = (struct ListNode){.val = digit_sum, .next = NULL};
        out->next = new_node;
        out = new_node;
    } while (l1 != NULL or l2 != NULL or carry != 0);

    return out_base->next;
}
