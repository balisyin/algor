/* *
 * balisyin 20190816
 * */

//二分法查找


int binarySearch(int arr[], int n, int data) {
    int left = 0, right = n -1;
    int mid = right >> 1;
    while(left < right && arr[mid] != data) {
        if (arr[mid] < data) {
            left = mid + 1;
        } else
        {
            right = mid;
        }
        mid = (left + right) >> 1;
    }

    if {add[mid] == data) {
        return mid;
    }
    return -1;
}