#include <iostream>
#include <climits>
using namespace std;

struct node{
    int val;
    node * prev;
    node * next;
    node(int val){
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
        void pop_back(){
            if(tail!=NULL){
                tail = tail->prev;
                tail->next = NULL;
            }
        }
        void pop_front(){
            if(head!=NULL){
                head = head->next;
                head->prev = NULL;
            }
        }
        void push_front(int x){
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

        void nearest(int a){
        int min = INT_MAX;
        int index = 0;
        int i=0;
        node * temp = head;
        while(temp != NULL){
            if(abs((temp->val)-a)<min){
            min = abs((temp->val)-a);
            index = i;
            }
            ++i;
            temp = temp->next;
            
        }
        cout<<index;
        
        }   

        void push_back(int x){
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
    private:
        node * head;
        node * tail;
        void print(node * cur){
            if(cur!=NULL){
                cout << cur->val << " ";
                print(cur->next);
            }
        }
        void r_print(node * cur){
            if(cur != NULL){
                cout << cur->val << " ";
                r_print(cur->prev);
            }
        }
};

int main(){

    dll dl;
    int n;
    cin >> n;
    for(int j=0;j<n;j++){
        int b;
        cin>>b;
        dl.push_back(b);
    }
    int x;
    cin >> x;
    dl.nearest(x);
    cout << endl;
   return 0;
}