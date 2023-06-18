#include <bits/stdc++.h>
 
int merge(vector<int> &arr, int left,int m,int right){
	int count=0;
	int l=left;
	int r=m+1;
	while(l<=m && r<=right){
		if((long)arr[l] > 2*(long)arr[r]){
			count +=(m-l+1);
			r++;
		}
		else{
			l++;
		}
	}

	vector<int> temp;
	int i=left;
	int j=m+1;
    while(i<=m && j<=right){
		if(arr[i]<arr[j]){
			temp.push_back(arr[i]);
			i++;
		}
		else{
			temp.push_back(arr[j]);
			j++;
		}
	}
	while(i<=m){
		temp.push_back(arr[i]);
			i++;
	}
	while(j<=right){
		temp.push_back(arr[j]);
			j++;
	}
    
	int k=0;
	for(int i=left;i<=right;i++){
       arr[i]=temp[k];
	   k++;
	}
	return count;
}
int mergeSort(vector<int> &arr, int l,int r){
	int count=0;
	if(l<r){
       int mid=(l+r)/2;
	   count +=mergeSort(arr,l,mid);
	  count += mergeSort(arr,mid+1,r);
	  count += merge(arr,l,mid,r);
	}
	return count;

}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
    
	return mergeSort(arr,0,n-1);
}