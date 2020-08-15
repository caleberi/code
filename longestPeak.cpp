#include <bits/stdc++.h>
using namespace std;
using namespace std;
int longestPeak(vector<int> array) {
    int longestPeakLength = 0;
    int i=1;
    while(i<int( array.size()-1)) {
        bool isPeak = array[i-1]<array[i]&&array[i]>array[i+1];
        if (!isPeak) {
            i+=1;
            continue;
        }
        int leftIdx=i-2;
        while (leftIdx>=0&&array[leftIdx]<array[leftIdx+1])
            leftIdx-=1;

        int rightIdx=i+2;
        while (rightIdx< array.size()&&array[rightIdx]<array[rightIdx-1])
            rightIdx+=1;
				
        int currentPeakLength=rightIdx-leftIdx-1;
        longestPeakLength=max(currentPeakLength, longestPeakLength);
				i=rightIdx;
    }
    return longestPeakLength;
}
int main(int argc, char** arg) {
    vector<int> v ={ 1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3 };
    cout << longestPeak(v) << endl;
    return 0;
}