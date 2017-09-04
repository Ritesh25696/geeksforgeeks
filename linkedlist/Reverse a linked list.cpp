Node* reverse(Node *head)
{
  Node* prev = NULL, *next = head, *cur = head;
  while(cur != NULL){
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
  }
  head = prev;
  return head;
}
