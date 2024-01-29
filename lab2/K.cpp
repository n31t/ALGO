#include <iostream>
#include <map>

using namespace std;

struct Node {
    char data;
    Node *next;
    
    Node(char x) : data(x), next(nullptr) {}
};

int main() {
    int n;
    cin >> n;

    while (n--) {
        Node *head = nullptr;
        Node *tail = nullptr;
        map<char, int> mash;

        int k;
        cin >> k;

        for (int i = 0; i < k; i++) {
            char a;
            cin >> a;

            if (mash[a] == 0) {
                // Create a new node only if the character is not a duplicate
                Node *newNode = new Node(a);
                mash[a]++;

                if (head == nullptr) {
                    // If head is null, initialize it
                    head = newNode;
                    tail = newNode;
                } else {
                    // Append the new node to the end of the linked list
                    tail->next = newNode;
                    tail = newNode;
                }
            } else {
                // Skip duplicates by incrementing the count in the map
                mash[a]++;
            }

            while (mash[head->data] > 1) {
                // Remove duplicates from the beginning of the linked list
                Node *tmp = head;
                head = head->next;
                delete tmp;
            }

            if (head != nullptr) {
                cout << head->data << " ";
            } else {
                cout << -1 << " ";
            }
        }
        cout << "\n";

        // Clean up memory by deleting the remaining nodes
        while (head != nullptr) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    return 0;
}
