#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int drawingbook(int number, int page)
{
        int completePage = number % 2 ==0 ? number+1:number+2;
        vector<int> book(completePage, 0); //filled with zero
        int pagenumber;
        for (pagenumber = 0; pagenumber < book.size(); ++pagenumber)
        {
                book[pagenumber] = pagenumber;
        }
        int FrontPageCount = 0;
        int pageStep = 0;

        // loop from the front
        for (int i = 0; i < completePage; i++)
        {
                if (pageStep == 2)
                {
                        FrontPageCount++;
                }
                if (pageStep != 2)
                {
                        pageStep++; //reset page step
                }
                if (i == page-1)
                {
                        break;
                }
        }
        // loop from the back
        int  BackPageCount=0;
        pageStep=0; // resetting pageStep
        for(int i=completePage-3;i>0;i--){
                if (pageStep == 2)
                {
                        BackPageCount++;
                }
                if (pageStep != 2)
                {
                        pageStep++; //reset page step
                }
                if (i == page-1)
                {
                        break;
                }
        }
        cout << "Front :" << FrontPageCount << " <---> Back:" <<BackPageCount <<endl; 
        return BackPageCount<FrontPageCount?BackPageCount:FrontPageCount;
}
 // 6,2
int pageCount(int n,int p) // 12345
{
        int mid = n/2; // 3 
        int right = p/2; // 1
        int left = mid -right; // 3-1=2
        if (right<left)
        {
                return right;
        }
        else
        {
                return left;
        }
}

int main(int argc, char const *argv[])
{
        cout << drawingbook(5, 4) << endl;
        cout << drawingbook(6, 2) << endl;
        return 0;
}
