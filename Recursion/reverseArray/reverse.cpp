void help(vector<int> &arr,int l,int r){
  //base condition  
  if(l>=r) return;
  //my task
    swap(arr[l],arr[r]);
  // function task
    return help(arr,l+1,r-1);
}
void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
    return help(arr,m+1,arr.size()-1);
}
