int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int,vector<int>,greater<int>> p;
        
        for(int j=0;j<=r;j++){
            p.push(arr[j]);
        }
        
        int ans,i=1;
        
        while(!p.empty()){
            if(i==k){
                ans=p.top();
                break;
            }
            i++;
            p.pop();
        }
        return ans;
    }