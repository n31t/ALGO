#include <iostream>
#include <climits>
#include <cmath>

using namespace std;
void printArray(string arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
void arrayInput(string arr[],string arr2[], int n)
{
    string s1;
    string s2;
    for(int i = 0 ; i < n;i++){
        cin >> s1;
        cin >> s2;
        int k = 0;
        for(int j = 0; j < n;j++){
            if(s1==arr2[j]){
                arr[j]=s2;
                k = 1;
                break;
                
            }
        }
        if(k==0){
            arr[i] = s1;
            arr2[i] = s2;
        }
    }
}
    

int main(){
    int n;
    cin >> n;
    string a[n];
    string b[n];
    arrayInput(a,b,n);
    printArray(a,n);
    printArray(b,n);
    return 0;
}