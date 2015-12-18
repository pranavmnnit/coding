#include <iostream>
using namespace std;

pair<int, int>
range(int arr[], int size, int num) {
    int beg=0, end=size-1;
    int mid=0;

    while (beg <= end) {
	mid = (beg+end)/2;
	if (arr[mid] < num) {
	    beg = mid+1;
	} else if (arr[mid] > num) {
	    end = mid-1;
	} else {
	    //found
	    cout << "found at " << mid << endl;
	    break;
	}
    }
    if (beg > end) {
	return make_pair(-1, -1);
    }
    beg = end = mid;

    while (beg<size && arr[beg] == num) --beg;
    while (end<size && arr[end] == num) ++end;

    return make_pair(beg+1, end-1);
}

int main()
{
    int arr[] = {1, 2, 5, 7, 9, 9, 9, 9, 10, 12, 15};
    int n;
    cin>>n;

    pair<int, int> ans = range(arr,sizeof(arr)/sizeof(arr[0]), n);

    cout << "start=" << ans.first << "  " << "end=" << ans.second << endl;

    return 0;
}


