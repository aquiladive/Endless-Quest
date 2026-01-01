#include <iostream>
#include <ctime>
#include <cstdlib> //ctime and cstdlib used for the srand(time(0)) and rand())
#include "skillCompendium.cpp"
using namespace std;

//--

extern skill w1, w2, w3, m1, m2, m3, r1, r2, r3;

//--

class Character {
    public:
    int HP, MP, DEF, ATK, MATK, MDEF, LUCK;
    string Name, Status[4];
    Character() {
        //only Monster array initialisation
    }
    Character (string n, int a, int b, int x, int y, int z, int i, int j) {
        Name=n;
        HP=a;
        MP=b;
        ATK=x;
        DEF=y;
        MATK=z;
        MDEF=i;
        LUCK=j;
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
        HP=a;
        MP=b;
        ATK=x;
        DEF=y;
        MATK=z;
        MDEF=i;
        LUCK=j;
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
        HP=a;
        MP=b;
        ATK=x;
        DEF=y;
        MATK=z;
        MDEF=i;
        LUCK=j;
    }
    
    int attack() {
        return ATK;
    }

    int magicAttack() {
        return MATK;
    }

    void getAbilities() {
        if(charClass=="w")
            warriorAbilities(*this);
        if(charClass=="m")
            mageAbilities(*this);
        if(charClass=="r")
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
        HP=a;
        MP=b;
        ATK=x;
        DEF=y;
        MATK=z;
        MDEF=i;
        LUCK=j;
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
            damage=ATK;
            break;
                
            case 2:
            cout<<Name<<" uses "<<mattack1<<endl;       
            damage=MATK;
            break;
                
            case 3:
            cout<<Name<<" uses "<<mattack2<<endl;
            damage=MATK;
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

//--

Monster Bounceshroom("Bounceshroom",6,0,9,1,10,5,0);

Monster Slime("Slime",10,0,7,2,8,6,0);

Monster FangedPuppy("Fanged Puppy",8,0,10,0,5,1,2);

Monster DarkWolf("Dark Wolf",12,0,15,1,10,3,2);

Monster PoisonPetals("Poison Petals",8,0,10,3,10,5,0);

Monster Saberhawk("Saberhawk",10,0,12,0,6,0,0);

Monster MetalCube("Metal Cube",10,0,8,10,6,10,0);

Monster CloakedKnell("Cloaked Knell",20,0,20,10,10,15,0);

//--

void finaliseMonsters() {
    Bounceshroom.setValues("Spore", "DEF Down 1", "Bounce", "None", 10);
    Slime.setValues("Acid", "DEF Down 1", "Ooze Trap", "Trapped 1", 10);
    DarkWolf.setValues("Shadow Claw", "None", "Restrain", "Trapped 1", 15);
    PoisonPetals.setValues("Acid", "DEF Down 1", "Lash", "None", 15);
}
