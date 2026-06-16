#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(m*n*(m+n)),O(1)
void setzeroes(vector<vector<int>> & matrix){
    //row
    int m = matrix.size();
    //column
    int n = matrix[0].size();
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            if(matrix[i][j]==0){
                //column
                for(int col = 0;col<n;col++){
                    if(matrix[i][col]!= 0){
                        matrix[i][col] = -1;
                    }
                }
                //row
                for(int row = 0;row<n;row++){
                    if(matrix[row][j]!=0){
                        matrix[row][j]=-1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }

}
//O(m*n),O(m+n)
void setzeroes1(vector<vector<int>> & matrix){
    //row
    int m = matrix.size();
    //column
    int n = matrix[0].size();
    vector<int> row(m,0);
    vector<int> col(n,0);
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i]==1 || col[j]==1)
                    matrix[i][j] = 0;
            }
        }

}
//O(m*n),O(1)
void setzeroes2(vector<vector<int>> & matrix){
    int m = matrix.size();
    int n = matrix[0].size();
     bool firstRowZero = false;
     bool firstColZero = false;
     for(int j =0;j<n;j++){
        if(matrix[0][j]==0){
            firstRowZero =true;
            break;
        }
     }
     for(int i =0;i<m;i++){
        if(matrix[i][0]==0){
            firstColZero = true;
            break;
        }
     }
     for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
     for(int i =1;i<m;i++){
        for(int j =1;j<n;j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j] = 0;
            }
        }
     }
     if(firstRowZero){
        for(int j =0;j<n;j++){
            matrix[0][j] = 0;
        }
     }
     if(firstColZero){
        for(int i =0;i<m;i++){
            matrix[i][0] = 0;
        }
     }
}

int main(){
    vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
    setzeroes2(m);
    for (auto row : m) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}