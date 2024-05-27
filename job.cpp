#include<bits/stdc++.h>
using namespace std;
struct Job{
    char id;
    int dead;
    int profit;
};
bool comparision(Job a, Job b){
    return (a.profit > b.profit);
}
void JobSeq(Job arr[], int n){
    sort(arr,arr+n,comparision);
    bool slot[n];
    char result[n];
    for(int i=0;i<n;i++){
        slot[i]={false};
        result[i]= '\0';
    }
    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].dead);j>=0;j--){
            if(!slot[i]){
                slot[i]=true;
                result[i]=arr[i].id;
            }
        }
    }
    cout<<"Following resultant: "<<endl;
    for(int i=0;i<n;i++){
        if(slot[i]){
            cout<<result[i]<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the number of jobs: ";
    cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++){
        cout<<"JOB "<<i+1<<": "<<endl;
        cout<<"ID: "<<endl;
        cin>>arr[i].id;
        cout<<"Deadline: "<<endl;
        cin>>arr[i].dead;
        cout<<"Profit: "<<endl;
        cin>>arr[i].profit;
    }
    cout<<endl;
    JobSeq(arr,n);
    
    return 0;
}