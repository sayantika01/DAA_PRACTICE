#include<bits/stdc++.h>
using namespace std;
    void matDisp(int n, int** S ,int i, int j){
        if(i==j)
            cout<<"A"<<i;
        else{
            cout<<"(";
            matDisp(n,S,i,S[i][j]);
            matDisp(n,S,S[i][j]+1,j);
            cout<<")";
        }
    }
    void mat_mul(int p[],int n){
        int i=0,j=0;
        int** S=new int*[n];
        int** M=new int*[n];
        for(int i=0;i<n;i++){
            S[i]=new int[n];
            M[i]=new int[n];
        }

        for(int i=0;i<n;i++){
            M[i][i]=0;
        }

        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                M[i][j]=INT_MAX;
                for(int k=i;k<j;k++){
                    int c=M[i][k]+M[k+1][j]+ p[i-1]*p[k]*p[j];
                    if(c<M[i][j]){
                        M[i][j]=c;;
                        S[i][j]=k;
                    }
                }
            }
        }
        cout<<"Table for M: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j<i)
                    cout<<"\t";
                else cout<<M[i][j]<<" \t";
            }
            cout<<endl;
        }
        cout<<"Table for S: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j<i)
                    cout<<" ";
                else cout<<S[i][j]<<" ";
            }
            cout<<endl;
        }
        matDisp(n,S,0,n-1);
    }
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int p[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    mat_mul(p,n);
    return 0;
}