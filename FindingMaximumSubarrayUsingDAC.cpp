#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int max_sub_lr(int a[],int low,int high)
{
    int max_n = -999;
    int sum = 0; 
    for(int i=high;i>=low;i--)
    {
        sum += a[i];
        if(sum > max_n)
        max_n = sum;
    }
    
    return max_n;
}

int max_sub_rl(int a[],int low,int high)
{
    int max_n = -999;
    int sum = 0; 
    for(int i=low;i<=high;i++)
    {
        sum += a[i];
        if(sum > max_n)
        max_n = sum;
    }
    return max_n;
}

int getmaxsubarr(int a[],int low,int high)
{
    if(low == high)
        return a[low];
    
    int mid = (low+high)/2,ls,rs,lss,rss,cs,ms;
    
    ls = getmaxsubarr(a,low,mid);   //left sum of the current array
    rs = getmaxsubarr(a,mid+1,high);  //right sum of the current array
    lss = max_sub_lr(a,low,mid);                    // maximum element of array while moving left to right
    rss = max_sub_rl(a,mid+1,high);
    cs = lss+rss;                    //cross sum
    ms = max(ls,max(rs,cs));     // maximum sum for parent array
    
    return ms;
}

int main()
{
    int a[] = {-2,-3,4,-1,-2,1,5,-3};
    
    cout << getmaxsubarr(a,0,7);
    
    return 0;
}