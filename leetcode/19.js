/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
const removeNthFromEnd = (head, n) => {
  if (!head.next) {
    return null;
  }

  const find = (current) => {
    if (!current.next) {
      return 1;
    }

    const fromEnd = find(current.next) + 1;
    if (fromEnd === n + 1) {
      if (current.next.next) {
        current.next = current.next.next;
      } else {
        current.next = null;
      }
    }

    return fromEnd;
  };

  const length = find(head);
  if (length === n) {
    return head.next;
  }

  return head;
};
