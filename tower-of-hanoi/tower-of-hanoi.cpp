#include<iostream>
using namespace std;

void towerOfHanoi(int n, char src, char dest, char aux)
{
    if(n==1)
    {
        cout<<"Move ring from "<<src<<" to "<<dest<<endl;
        return;
    }
    towerOfHanoi(n-1, src, aux, dest);
    cout<<"Move ring from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1, aux, dest, src);
}

int main()
{
    towerOfHanoi(3, 'A', 'C', 'B');
}