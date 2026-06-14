#include<iostream>
using namespace std;

bool checkValidString(string s) {
    
    int min_val = 0;
    int max_val = 0;

    int n = s.length();

    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            min_val++;
            max_val++;
        }

        else if(s[i]==')')
        {
            if(min_val>0)
            {
                min_val--;
            }
            max_val--;

            if(max_val<0)
            {
                return false;
            }
        }
        else
        {
            if(min_val>0)
            {
                min_val--;
            }
            max_val++;
        }
    }

    if(min_val==0)
    {
        return true;
    }

    return false;

}

int main()
{
    string s = "()(*)";
    cout<<checkValidString(s);
}
