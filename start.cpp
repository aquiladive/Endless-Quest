#include<iostream>
#include "battle.cpp"
using namespace std;

//--

void battleMechanic(int opponents[]);

extern void statAllocation(int statpt);

extern Protag mainchar;

//--


int initiateBattles() {
    int testchoice, n;
    cout<<"The endless battles have begun."<<endl;
    while(true) {
        srand(time(0));
        int number=rand()%4+1;
        int opponents[number+1];
    
        opponents[0]=number;
        for(int i=1;i<number+1;i++)
            opponents[i]=rand()%3+1;
        battleMechanic(opponents);
    }
}
