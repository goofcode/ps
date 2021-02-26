/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

const printList = (head) => {
  let current = head;
  while (current) {
    process.stdout.write(`${current.val} `);
    current = current.next;
  }
  console.log();
};

const swapPairs = (head) => {
  let current = head;
  let prev = null;
  while (current && current.next) {
    const { next } = current;
    const nextNext = next.next;

    if (!prev) {
      head = next;
    } else {
      prev.next = next;
    }

    next.next = current;
    current.next = nextNext;

    prev = current;
    current = current.next;
  }

  return head;
};

swapPairs({ val: 1, next: { val: 2, next: { val: 3, next: { val: 4, next: null } } } });
