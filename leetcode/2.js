/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
const addTwoNumbers = (l1, l2) => {
  const result = {};
  let carry = 0;

  let head = result;
  let h1 = l1;
  let h2 = l2;

  while (h1 !== null || h2 !== null) {
    const v1 = h1 ? h1.val : 0;
    const v2 = h2 ? h2.val : 0;

    head.next = {};
    head.next.val = (v1 + v2 + carry) % 10;
    head.next.next = null;
    head = head.next;

    carry = Math.floor((v1 + v2 + carry) / 10);

    h1 = h1 ? h1.next : null;
    h2 = h2 ? h2.next : null;
  }

  if (carry !== 0) {
    head.next = {};
    head.next.val = carry;
    head.next.next = null;
  }

  return result.next;
};
