//二分查找
int binarySearch(int arr[], int len, int key)
{
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right) {
        mid = left+(right-left) / 2;
        if (key < arr[mid]) {//key在左边
            right = mid - 1;
        } else if (arr[mid] < key) {//key在右边
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

//二分查找: 递归实现  
int binarySearch(int a[],int low,int high,int key)  
{  
    int mid=low+(high-low)/2;  
  
    if(low>high)  
        return -1;  
    else{  
        if(a[mid]==key)  
            return mid;  
        else if(a[mid]>key)  
            return binarySearch(a,low,mid-1,key);  
        else  
            return binarySearch(a,mid+1,high,key);  
      
    }  
  
} 

//查找最后一次出现
 int binarySearch2(int arr[], int len, int key)
 {
	 int left = 0;
	 int right = len - 1;
	 int mid;

	 while (left < right) {
		 mid = left+(right - left) / 2+1;
		 if (key < arr[mid]) {//key在左边
			 right = mid - 1;
		 }
		 else  {//key在右边
			 left = mid ;
		 }
	 }
	 return arr[left] == key ? left:-1;
 }
 //查找第一次出现
  int binarySearch2(int arr[], int len, int key)
 {
	 int left = 0;
	 int right = len - 1;
	 int mid;

	 while (left < right) {
		 mid = left+(right - left) / 2;
		if (arr[mid] < key) {//key在右边
            left = mid + 1;
        } else {
           right=mid;
        }
	 }
	  return arr[right] == key ? right:-1;
 }