#include<iostream>

using namespace std;

int lcs(int index1, int index2, string& s1, string& s2)
{

    if(index1<0 || index2<0)
    {
        return 0;
    }
    

    if(s1[index1]==s2[index2])
    {
        return 1+lcs(index1-1, index2-1, s1, s2);
    }

    return 0 + max( lcs(index1-1, index2, s1, s2), lcs(index1, index2-1, s1, s2) );

}

int main()
{


    string s1 = "acd";

    string s2 = "ced";

    int n1 = s1.length();
    int n2 = s2.length();

    cout<<lcs(n1-1, n2-1, s1, s2);



}