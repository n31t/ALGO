#include <iostream>
#include <climits>
using namespace std;

struct node{
    string val;
    node * prev;
    node * next;
    node(string val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
struct dll{
    public:
        dll(){
            head = NULL;
            tail = NULL;
        }
        int size(){
            node *node = head;
            int iter=0;
            while(node != NULL ){
                node = node->next;
                iter++;
        }
        return iter;
        }
        void pop_back(){
                if(tail != NULL){
                    if (tail == head) {
                        delete tail;
                        tail = NULL;
                        head = NULL;
                    } else {
                        tail = tail->prev;
                        tail->next = NULL;
                    }
                }
            }

        void pop_front(){
            if(head != NULL){
                if (head == tail) {
                    delete head;
                    head = NULL;
                    tail = NULL;
                } else {
                    head = head->next;
                    head->prev = NULL;
                }
            }
        }
        void push_front(string x){
            node * temp = new node(x);
             if(head == NULL){
                head = temp;
                tail = temp;
            }else{
                head->prev = temp;
                temp->next = head;
                head = temp;
            }
        }
        void insert(string x, int pos){
            node * temp = new node(x);
            node * cur = head;
            if(head==NULL){
                head = temp;
                tail = temp;
            }
            else if(pos ==0){
                push_front(x);
            }
            else if(pos == size()){
                push_back(x);
            }
            else
            {for(int i = 0; i < pos;i++){
                cur = cur->next;
            }
             temp->prev = cur->prev;
             temp->next = cur;
             cur->prev->next = temp;
             cur->prev = temp;
            }

        }

        void push_back(string x){
            node * temp = new node(x);
            if(head == NULL){
                head = temp;
                tail = temp;
            }else{
                tail->next = temp;  
                temp->prev = tail;
                tail = temp;  
            }
        }
        void print(){
            print(head);
        }
        void r_print(){
            r_print(tail);
        }
        void push_front_nodup(string x){
            node * temp = new node(x);
             if(head == NULL){
                head = temp;
                tail = temp;
            }else if(temp->val != head->val){
                head->prev = temp;
                temp->next = head;
                head = temp;
            }
        }
        node* cyclicShift(int k) {
            node* cur = head; 
            while(cur->next != NULL) {
                cur = cur->next;
            }
            for(int i = 0; i < k; i++) {
                cur->next = head;
                head = head->next;
                cur = cur->next;
                cur->next = NULL;
            }
            return head;
        }


    private:
        node * head;
        node * tail;
        void print(node * cur){
            if(cur!=NULL){
                cout << cur->val << " ";
                print(cur->next);
            }
        }
        void _print(node * cur){
            if(cur!=NULL){
                cout << cur->val << " " << endl;
                _print(cur->next);
            }
        }
        void r_print(node * cur){
            if(cur != NULL){
                cout << cur->val << " ";
                r_print(cur->prev);
            }
        }
}
;

int main(){

    dll dl;
    int n;
    
    cin >> n;
    for(int j=0;j<n;j++){
        string b;
        cin>>b;
        dl.push_back(b);
    }
    int x;
    string word;
    cin >> word;
    cin >> x;
    // dl.print();
    dl.insert(word,x);
    dl.print();
   return 0;
}