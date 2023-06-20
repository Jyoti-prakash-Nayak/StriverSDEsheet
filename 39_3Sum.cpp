#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>> res;

	for(int i=0; i<n-2; i++){

        int left = i + 1;

        int right= n - 1;

        while(left < right){

            int sum = arr[i]+arr[left]+arr[right];

            if(sum==K){

                res.push_back({arr[i],arr[left],arr[right]});

                left++;

                right--;

                while(left < right && arr[left] == arr[left-1]) {
                    left++;
                }

                while(left < right && arr[right] == arr[right+1]) {
                    right--;
                }

            }

            else if(sum < K){
                left++;
            }

            else{
                right--;
            }

        }

        while( i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
        }

    }

    return res;
}