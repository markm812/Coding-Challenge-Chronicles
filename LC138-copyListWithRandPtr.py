from typing import Optional


class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        if not head:
            return None

        curr = head
        binding_map = {}
        while curr:
            new_node = Node(curr.val)
            binding_map[curr] = new_node
            curr = curr.next

        curr = head
        while curr:
            if curr.next:
                binding_map[curr].next = binding_map[curr.next]
            if curr.random:
                binding_map[curr].random = binding_map[curr.random]
            curr = curr.next

        return binding_map[head]
