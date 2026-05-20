#include<iostream>
using namespace std;

class Solution{
    public:
        int totalNumbers(vector<int>& digits){
            vector<int> freq(10,0);

            for(int d : digits){
                freq [d]++;
            }

            int count =0;

            for(int num =100; num<999; num+=2){
                int a = num /100;
                int b = (num/10) % 10;
                int c = num% 10;

                vector<int> temp = freq;
                if(temp[a] == 0)
                continue;
                temp[a]--;

                if(temp[b] == 0)
                continue;
                temp[b]--;

                if(temp[c] == 0)
                continue;
                temp[c]--;

                count++;
            }
            return count;
        }
};

int main(){
    Solution s;
     int n;

    cout << "Enter number of digits: ";
    cin >> n;

    vector<int> digits(n);

    cout << "Enter digits: ";

    for(int i = 0; i < n; i++){
        cin >> digits[i];
    }

    int result = s.totalNumbers(digits);

    cout << "Total distinct 3-digit even numbers: "
         << result << endl;

    return 0;

}