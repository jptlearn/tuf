#include <iostream>
#include <vector>
using namespace std;

class Node {
  public:
    int data;
    Node *back;
    Node *next;

  public:
  Node(int data1, Node*back1, Node*next1) {
    data = data1;
    back = back1;
    next = next1;
  }

  public:
  Node(int data1) {
    data = data1;
    back = nullptr;
    next = nullptr;
  }
};

Node* convertArr2DLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], prev, nullptr);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

Node* deleteHead(Node *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }
  Node *prev = head;
  head = head->next;
  head->back = nullptr;
  prev->next = nullptr;

  delete prev;
  return head;
}

Node* deleteTail(Node *head) {
  if(head == NULL || head->next == NULL) {
    return NULL;
  }
  Node *tail = head;
  while(tail->next != NULL) {
    tail = tail->next;
  }
  Node *newTail = tail->back;
  newTail->next = nullptr;
  tail->back = nullptr;

  delete tail;
  return head;
}

Node * insertBeforeHead(Node* head, int val) {
  Node *newHead = new Node(val, nullptr, head);
  head->back = newHead;
  return newHead;
}

Node * insertBeforeTail(Node *head,int val) {
  Node *temp = head;
  while(temp != NULL) {
    temp = temp->next;
  }
  Node *prev = temp->back;
  Node *beforeTail = new Node(val, prev, temp);
  prev->next = beforeTail;
  temp->back = beforeTail;
}

Node* insertBeforeKthElement(Node* head, int k, int val) {
  if (k == 1) {
    return insertBeforeHead(head, val);
  }

  Node *temp = head;
  int cnt = 0;
  while(temp->next != NULL) {
    cnt++;
    if (cnt == k) {
      break;
    }
    temp = temp->next;
  }
  Node *prev = temp->back;
  Node *newNode = new Node(val, prev, temp);
  prev->next = newNode;
  temp->back = newNode;

  return head;
}

void insertBeforeNode(Node* node, int val){
  Node *prev = node->back;
  Node *newNode = new Node(val, prev, node);
  prev->next = newNode;
  node->back = newNode;
}

int
main()
{
  vector<int> arr = {3, 5, 8, 9};
  Node *head = convertArr2DLL(arr);
  head = deleteHead(head);
  cout << head->data << endl;

  return 0;
}