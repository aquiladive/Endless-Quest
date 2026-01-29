#include <iostream>
#include <ctime>
#include <cstdlib> //ctime and cstdlib used for the srand(time(0)) and rand())
#include "skillCompendium.cpp"
#include "stats.cpp"
using namespace std;

//--

extern skill w1, w2, w3, m1, m2, m3, r1, r2, r3;

//--

class Character {
    public:
    stat statList[7] = {HP, ATK, DEF, MATK, MDEF, LUCK, MP};
    string Name, Status[6];
    Character() {
        //only Monster array initialisation
    }
    Character (string n, int a, int b, int x, int y, int z, int i, int j) {
        Name=n;
        statList[0].value=a;
        statList[1].value=b;
        statList[2].value=x;
        statList[3].value=y;
        statList[4].value=z;
        statList[5].value=i;
        statList[6].value=j;
    }
    virtual int attack()=0;
};

class NPC: public Character {
    //using Character::Character; //copies the constructor from Character
    public:
    NPC () {

    }
    NPC (string n, int a, int b, int x, int y, int z, int i, int j) {
        Name=n;
        statList[0].value=a;
        statList[1].value=b;
        statList[2].value=x;
        statList[3].value=y;
        statList[4].value=z;
        statList[5].value=i;
        statList[6].value=j;
    }
    
    int attack() {
        int choice=rand()%4+1;
        return choice;
    }
};

//--

class Protag;
void warriorAbilities(Protag& p);
void mageAbilities(Protag& p);
void rogueAbilities(Protag& p);

//--

class Protag: public Character {
    //using Character::Character;
    public:
    string charClass;
    int level=1;
    int battleExp=0;
    skill ability[6];
    int abilityCount;

    Protag () {

    }
    Protag (string n, string c, int a, int b, int x, int y, int z, int i, int j) {
        Name=n;
        charClass=c;
        statList[0].value=a;
        statList[1].value=b;
        statList[2].value=x;
        statList[3].value=y;
        statList[4].value=z;
        statList[5].value=i;
        statList[6].value=j;
    }
    
    int attack() {
        return statList[1].value;
    }

    int magicAttack() {
        return statList[3].value;
    }

    //TODO maybe optimise, having to use getAbilities and scrolling through already set abilities seems off
    void getAbilities() {
        if(charClass[0]=='w')
            warriorAbilities(*this);
        if(charClass[0]=='m')
            mageAbilities(*this);
        if(charClass[0]=='r')
            rogueAbilities(*this);
    }
};

//--

void warriorAbilities(Protag& p) {
    int count = 1;
    p.ability[0] = w1;
    if(p.level > 5) {
        p.ability[1] = w2;
        count++;
    }
    if(p.level > 10) {
        p.ability[2] = w3;
        count++;
    }
    p.abilityCount = count;
};

void mageAbilities(Protag& p) {
    int count = 1;
    p.ability[0] = m1;
    if(p.level > 5) {
        p.ability[1] = m2;
        count++;
    }
    if(p.level > 10) {
        p.ability[2] = m3;
        count++;
    }
    p.abilityCount = count;
};

void rogueAbilities(Protag& p) {
    int count = 1;
    p.ability[0] = r1;
    if(p.level > 5) {
        p.ability[1] = r2;
        count++;
    }
    if(p.level > 10) {
        p.ability[2] = r3;
        count++;
    }
    p.abilityCount = count;
};

//--

int monsterChoice; //for the monster attack function and allowing it to be accessed by the battleMechanic() function

class Monster: public Character {
    //using Character::Character;
    public:
    Monster () {

    }
    Monster (string n, int a, int b, int x, int y, int z, int i, int j) {
        Name=n;
        statList[0].value=a;
        statList[1].value=b;
        statList[2].value=x;
        statList[3].value=y;
        statList[4].value=z;
        statList[5].value=i;
        statList[6].value=j;
    }

    string mattack1="\0", mattack1effect="\0";
    string mattack2="\0", mattack2effect="\0";
    int exppoint=0;
    //all new public members are initialised to null as they are properly initialised in finaliseMonsters()

    void setValues(string ma1, string mae1, string ma2, string mae2, int exp) {
        mattack1 = ma1;
        mattack1effect = mae1;
        mattack2 = ma2;
        mattack2effect = mae2;
        exppoint = exp;
    }
    
    int attack() {
        int choice, damage=0;
        srand(time(0));
        choice=rand()%3+1;
        monsterChoice=choice;
        switch(choice) {
            case 1:
            cout<<Name<<" attacks."<<endl;
            damage=statList[1].value;
            break;
                
            case 2:
            cout<<Name<<" uses "<<mattack1<<endl;       
            damage=statList[3].value;
            break;
                
            case 3:
            cout<<Name<<" uses "<<mattack2<<endl;
            damage=statList[3].value;
            break;
        }
        return damage;
    }
};

//--

class Item {
    public:
    string itemName, Description;
    int useCount;
    Item() {
        //only for inventory initialisation
    }
    Item(string i, string d, int u) {
        itemName=i;
        Description=d;
        useCount=u;
    }
    void obtain() {
        cout<<"You have obtained "<<itemName<<"."<<endl;
    }
    void clear() {
        itemName="\0";
        Description="\0";
    }
};

//--

Protag mainchar("\0","\0",25,5,5,5,5,5,5);
