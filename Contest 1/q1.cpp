// https://www.hackerrank.com/contests/bppc1/challenges/nescafe-coffee/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    cin >> N;
    vector<int> nums(N,0);
    for ( int i = 0 ; i < N; i++)
        cin >> nums[i];
    
    if( N == 1)
    {
        cout<< nums[0] << endl;
        return 0;
    }
    
    int k = 0;
    for( int i = N-1; i >= 1; i--)
    {
        if( nums[i ] <= nums[i - 1])
        {
            k = i;
            break;
        }
    }
    //cout << k << endl;
    long long ans = 0;
    for( int j = k ; j < N; j++)
        ans += nums[j];
    //cout << ans << endl;
    if( k == 0)
    {
        cout << ans << endl;
        return 0;
    }
    
    int a = nums[k];
    for( int j = k-1; j >= 0; j--)
    {
        a = min( a - 1, nums[j]);
        //cout << max( a,0) << endl;
        ans += max(0,a);
    }
    
    cout << ans << endl;
    return 0;
}
