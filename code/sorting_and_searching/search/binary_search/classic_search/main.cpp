#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (nums[m] == target) {
            return m;
        }
        
        else if (nums[m] < target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}	
/*
example:

input:
6 9
-1 0 3 5 9 12

output:
4 (index of 9)
*/

int main() {

    int n, target;
    cin >> n >> target; 
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
    	cin >> v[i];
    }
    cout << search(v, target) << endl;
}

