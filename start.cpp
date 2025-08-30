#include<iostream>
#include "battle.cpp"
using namespace std;

//--

void battleMechanic(int opponents[]);

extern Protag mainchar;

extern void finaliseMonsters();

//--

void townGladius(), forestsBeyond();
void plotCall(int battleCount);

//--


int initiateBattles() {
    int battleCount=0;
    
    finaliseMonsters();

    cout<<"The endless battles have begun."<<endl;
    while(true) {
        srand(time(0));
        int number=rand()%4+1;
        int opponents[number+1];
    
        opponents[0]=number;
        for(int i=1;i<number+1;i++)
            opponents[i]=rand()%3+1;
        battleMechanic(opponents);
        battleCount++;
        if(battleCount%3 == 1) {
            plotCall(battleCount);
        }
        else
            cout<<"You have emerged victorious, but the battles never cease."<<endl;
    }
}

void plotCall(int battleCount) {
    switch(battleCount) {
        case 1: townGladius();
        break;
        case 4: forestsBeyond();
        break;
    }
}

void townGladius() {
    string pause;

    cout<<"It is a lovely morning in Gladius. Dawn has just given way to the full light of the Sun and bathed in that golden glow, the town slowly stirs into life."<<endl;
    cout<<"You breathe heavily as your opponents crumble into dust, and consider your practice done for the day."<<endl;
    cout<<"You have been here for hours, your secret practice known only to the waning moon."<<endl;
    cout<<"Illusions such as these cannot fully capture the experience of fighting actual monsters, but your family will not let you venture beyond Gladius solely to sate your need for realism. Especially not when you haven't reached adulthood."<<endl;
    cout<<"Now that you've finally accomplished that last week, they can no longer stop you. You need only wait for the right opportunity."<<endl;
    cout<<"\""<<mainchar.Name<<"!"<<endl;
    cin>>pause;
    cout<<"The shout catches you by surprise and you whirl around, weapon already held at the ready--"<<endl;
    cout<<"--But it's only Solia, your childhood friend."<<endl;
    cout<<"\"Whoa! Relax,\" she says, hands held out in front of her."<<endl;
    cout<<"\"Sorry, I only finished training. What's the matter?\""<<endl;
    cout<<"Solia is one of the few that knows of your dreams and plans outside your family. She would not come to these grounds without reason; while she doesn't prevent you, she isn't fully supportive of your choices either."<<endl;
    cout<<"Once upon a time, you took that lack of trust harshly. Nowadays, you've made more peace with it. At least she doesn't try to endlessly change your mind. She's only worried, and you can understand that with how dangerous the world has become."<<endl;
    cout<<"\"The meeting of the farmers' union finished just now,\" Solia says. \"They're tired of how the town hall doesn't take their complaints about the wolves seriously, and are planning to pay out of their own pocket for an adventuring team. I thought... you might...\""<<endl;
    cout<<"The words are hard for her to say. Her expression collapses into a strange medley of emotions, worry the most prominent of them."<<endl;
    cout<<"And yet, she's here, before anyone else, knowing full well what this news will mean to you."<<endl;
    cout<<"You're surprised by the slight burning in your eyes."<<endl;
    cin>>pause;
    cout<<"\"Thank you,\" you say weakly."<<endl;
    cout<<"\"Take care,\" she says. There's still worry but it's muted now, as if she's trying to make peace with it."<<endl;
    cout<<"You close the distance and, in a rare display of physical affection, hug her. She returns it without a moment's pause."<<endl;
    cout<<"\"This is the first step towards what I want. Whatever happens, I won't regret it. Don't regret it for me\", you tell her softly."<<endl;
    cout<<"Only after you feel her nod do you let go and leave the grounds."<<endl;
    cout<<"You have a union to find, and a quest to volunteer yourself for."<<endl;
}

void forestsBeyond() {
    //to be done
    cout<<"You haven't been to the forest before, but you're familiar with them through the many tales."<<endl;
}
