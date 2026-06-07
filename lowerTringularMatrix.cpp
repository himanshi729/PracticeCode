#include<iostream>
using namespace std;

class LowerTriangular{
    private:
        int *a; 
        int n;
    public:
        LowerTriangular()
        {
            n = 2;
            a = new int[2];
        }
        LowerTriangular(int n){
            this-> n = n; 
            a = new int[n];
        }

        void SetRowMajor(int i, int j, int x);
        void SetColMajor(int i, int j, int x);
        int GetRowMajor(int i, int j);
        int GetColMajor(int i, int j);
        void Display(bool row = true);

};
void LowerTriangular :: SetRowMajor(int i, int j, int x){
    if(i>=j){
    int index = (i*(i-1)/2) + j-1;
    a[index] = x;
    }
}

void LowerTriangular :: SetColMajor(int i, int j, int x){
    if(i>=j){
    int index = (n*(j-1) - (((j-2)*(j-1))/2)) + (i-j);
    a[index] = x;
    }
}

int LowerTriangular :: GetColMajor(int i, int j){
    if(i>=j){
        int index = (n*(j-1) - (((j-2)*(j-1))/2)) + (i-j);
        return a[index]; 
    }
    else{
        return 0;
    }
}

int LowerTriangular :: GetRowMajor(int i, int j){
    if(i>=j){
        int index = (i*(i-1)/2) + j-1;
        return a[index];
    }
    else{
        return 0;
    }
}

void LowerTriangular :: Display(bool row){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i>=j){
                if(row){
                cout<<GetRowMajor(i, j);
            }
            else{
                cout<<GetColMajor(i, j);
            }
        }
            cout<<"0 ";
        }
        cout<<endl;
    }
}

int main(){
    LowerTriangular rm(4);
    rm.SetRowMajor(1, 1, 1);
    rm.SetRowMajor(2, 1, 2);
    rm.SetRowMajor(2, 2, 3);
    rm.SetRowMajor(3, 1, 4);
    rm.SetRowMajor(3, 2, 5);
    rm.SetRowMajor(3, 3, 6);
    rm.SetRowMajor(4, 1, 7);
    rm.SetRowMajor(4, 2, 8);
    rm.SetRowMajor(4, 3, 9);
    rm.SetRowMajor(4, 4, 10);

    rm.Display();
    cout<<endl;

    LowerTriangular cm(4);
    rm.SetColMajor(1, 1, 1);
    rm.SetColMajor(2, 1, 2);
    rm.SetColMajor(2, 2, 3);
    rm.SetColMajor(3, 1, 4);
    rm.SetColMajor(3, 2, 5);
    rm.SetColMajor(3, 3, 6);
    rm.SetColMajor(4, 1, 7);
    rm.SetColMajor(4, 2, 8);
    rm.SetColMajor(4, 3, 9);
    rm.SetColMajor(4, 4, 10);

    rm.Display();

    return 0;


}

