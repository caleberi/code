#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
public:
        int height;
        int right;
        int left;
        int index;

        Rectangle(int h, int idx, int l, int r) : height{h}, left{l}, right{r}, index{idx} {}
        long getArea()
        {
                // subtract the left building from the right to get the length;
                return static_cast<long>(height * (right - left));
        }
};

long largestRectangle(vector<int> h)
{
        stack<Rectangle> stk; // for storing the current building
        long maxArea = 0;
        Rectangle first = Rectangle(h[0], 0, 0, -1);
        stk.push(first);                   // push into the building stack to show that we are working with this current building firstly
        for (int i = 1; i < h.size(); i++) // for h[i] i -> [i .... n]
        {
                Rectangle b = Rectangle(h[i], i, -1, -1); // next rectangle
                if (b.height > first.height)
                { // if the building's height is greater than the first building then push to the stack
                        // the next building  becomes b position;
                        b.left = i;
                        stk.push(b);
                }
                else
                {
                        /**
                          *  if the stack<Rectangle> is not empty check to see if it's height is >=  the current building's height
                         */
                        while (!stk.empty() && stk.top().height >= b.height)
                        {
                                Rectangle stktop = stk.top();
                                stk.pop();
                                stktop.right = i;
                                maxArea = max(maxArea, stktop.getArea()); // swap the area
                        }
                        if (!stk.empty())
                        {
                                if (b.height > stk.top().height)
                                {
                                        b.left = stk.top().index + 1;
                                }
                                else
                                {
                                        Rectangle first = stk.top();
                                        stk.pop();
                                        b.left = first.left;
                                        first.right = i;
                                        maxArea = max(maxArea, first.getArea());
                                }
                        }
                        else
                        {
                                b.left = 0;
                        }
                        stk.push(b);
                }
                first = b;
        }

        while (!stk.empty())
        {
                Rectangle b = stk.top();
                stk.pop();
                if (b.right < 0)
                {
                        b.right = h.size();
                }
                maxArea = max(maxArea, b.getArea());
        }
        return maxArea;
}

int main(int argc, const char **argv)
{
        return 0;
}