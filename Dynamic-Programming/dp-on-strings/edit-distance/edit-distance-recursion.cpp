#include<iostream>
using namespace std;

int editDistance(int i, int j, string s1, string s2)
{

    if(i<0)
    {
        return j+1;
    }

    if(j<0)
    {
        return i+1;
    }
    

    if(s1[i]==s2[j])
    {
        return 0 + editDistance(i-1, j-1, s1, s2);
    }

    // Insert
    int insert = 1 + editDistance(i, j-1, s1, s2);

    // Remove
    int remove = 1 + editDistance(i-1, j, s1, s2);

    // Replace
    int replace = 1 + editDistance(i-1, j-1, s1, s2);

    return min(insert, min(remove, replace));



}

int main()
{

    string s1 = "horse";
    string s2 = "ros";

    int n1 = s1.length();
    int n2 = s2.length();

    cout<<editDistance(n1-1, n2-1, s1, s2);



}