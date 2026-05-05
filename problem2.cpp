#include <iostream>
using namespace std;
long long binarysearch(long long arr[], long long begin, long long end, long long size, long long peakindex, long long target)
{   // use % to handle searching in a shifted circular array that can have duplicates.
 if (begin > end)
    {
        return -1;
    }
    // if the fisrt and last sorted elements are the same, then all elements are the same.
    if (arr[peakindex] == arr[(peakindex+1) % size]) 
    {
        if (arr[peakindex] == target)
        {
            return peakindex;
        }
        return -1;
    }
    long long mid = (begin + end) / 2;
    if (arr[(mid + peakindex+1) % size] == target)
    {
        return (mid + peakindex+1) % size;
    }
    else if ( arr[(begin + peakindex + 1) % size]==arr[(end + peakindex+1) % size]){
        begin++;
        end--;
        return binarysearch(arr, begin, end, size, peakindex, target);
    }
    else if (arr[(mid + peakindex+1) % size] > target)
    {
        return binarysearch(arr, begin, mid-1, size, peakindex, target);
    }
    else
    {
        return binarysearch(arr, mid + 1, end, size, peakindex, target);
    }
}

int main()
{
    long long size, peak = -2147483648, peakindex, target;
    cin >> size;
    long long circular_array[size];
    for (long long i = 0; i < size; i++)
    {
        cin >> circular_array[i];
        if (circular_array[i] >= peak)
        {
            peak = circular_array[i];
            peakindex = i;
        }
    }
   
    cin >> target;
    for (long long i = 1; i <= size; i++)
    {
        cout << circular_array[(peakindex + i) % size] << " ";
        
    }
    cout << endl;
    long long result = binarysearch(circular_array, 0, size - 1, size, peakindex, target);
    if (result ==-1 ){
        cout << "value not found ya basha" << endl;
    }
    else{
        cout << "index of value to search: " << result << endl;
        cout << "value at index: " << circular_array[result] << endl;
    }
    return 0;
}