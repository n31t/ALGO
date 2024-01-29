# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, Node *head) {
    if (head == nullptr) {
        // Empty linked list, return 0
        return 0;
    }

    int maxEndingHere = head->val;
    int maxSoFar = head->val;

    Node *current = head->next;

    while (current != nullptr) {
        // Calculate the maximum sum ending at the current node
        maxEndingHere = max(current->val, maxEndingHere + current->val);

        // Update the maximum sum seen so far
        maxSoFar = max(maxSoFar, maxEndingHere);

        // Move to the next node
        current = current->next;
    }

    return maxSoFar;
}


int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
