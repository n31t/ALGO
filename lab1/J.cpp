#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <string>
using namespace std;
int main(){
    deque<int> dq;
    char a;
    int number;
    while(a!='!'){
        cin >> a;
        if(a == '+'){
            cin >> number;
            dq.push_front(number);
        }
        else if(a == '-'){
            cin >> number;
            dq.push_back(number);
        }
        else if(a == '*'){
            int sum;
            if(dq.size()==0){
                cout << "error" << endl;
            }
            else if(dq.size()==1){
                cout << (dq.front() + dq.back()) << endl;
                dq.pop_front();
            }
            else{
                cout << (dq.front() + dq.back()) << endl;
                dq.pop_front();
                dq.pop_back();
            }
        }
    }

    
}

// + 1
// - 9
// + 2
// *
// + 2
// - 6
// + 3
// - 9
// *
// *
// *
// *
// !