#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_arr_data(std::vector<int>& arr, int start, int end) {
    cout << "start: " << start << " end: " << end << endl;
    int len = abs(end - start) + 1;
    for(auto it = arr.begin() + start; it != arr.begin() + start + len; ++it) {
        cout << *it << ",";
    }
    cout << endl;
}

void merge(std::vector<int>& arr, int start, int end) {
    int len = abs(start - end);
    std::sort(arr.begin() + start, arr.begin() + start + len);
}

void merge_sort(std::vector<int>& arr, int start, int end) {
    // check if the array is not a unit array, then dont divide anymore
    print_arr_data(arr, start, end);

    if (start < end) {
        int mid = (start + end)/2;
        //mid = start + (end-1) / 2
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, end);
    }
}

int main() {
    std::vector<int> data = {4,1,2,3,7,8,5,6,9};
    merge_sort(data, 0, data.size()-1);

    cout << "*******" << endl;
    for (int i : data) {
        cout << i << endl;
    }
    cout << "*******";

    return 0;
}
