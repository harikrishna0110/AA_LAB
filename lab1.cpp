#include <bits/stdc++.h>
using namespace std;

int comparisons;
int swaps;


int partition(int a[],int p, int r){
    int pivot = a[r];
    int i = p-1;
    
for(int j=p;j<r;j++){
    comparisons++;
    if(a[j] <= pivot){
   	 i++;
   	 swaps++;
   	 swap(a[i],a[j]);
    }
}


swap(a[i+1],a[r]);
    swaps++;
    return i+1;
}



int randomized_partition(int a[], int p, int r){
    srand(time(0));
    
    int random_index = p+ rand() %(r-p +1);
    swap(a[random_index],a[r]);
    
    return partition(a,p,r);

}




void RQ(int a[],int p,int r){
    if(p <= r){
    int q = randomized_partition(a,p,r);
    RQ(a,p,q-1);
    RQ(a,q+1,r);
    }
}

int main() {
    
    int n;
    
    cin>>n;
    
    int a[n+1];
    for(int i=n;i>=1;i--){
      a[i]=i;
    }
    
    RQ(a,1,n);
    for(int i=n;i>=1;i--)cout<<a[i]<<" ";
    cout<<endl;
   	 cout<< "No of comparisons :"<<comparisons<<"\n";
    cout<<"No of swaps :"<<swaps;
    // your code goes here
    return 0;
}
