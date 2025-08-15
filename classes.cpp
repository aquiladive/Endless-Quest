#include <iostream>
#include <ctime>
#include <cstdlib> //ctime and cstdlib used for the srand(time(0)) and rand())
using namespace std;

class Character {
    public:
    int HP, MP, DEF, ATK, MATK, MDEF, LUCK;
    string Name,Status[4];
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
    int Level=1;
    int battleExp=0;
    int Beyonder[2];
    string Ability[3];
    string Class;

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

    void getAbilities() {
        if(Class=="w")
            warriorAbilities(*this);
        if(Class=="m")
            mageAbilities(*this);
        if(Class=="r")
            rogueAbilities(*this);
    }
};

//--

void warriorAbilities(Protag& p) {
    p.Ability[0] = "Focus Strike";
    if(p.Level > 5)
        p.Ability[1] = "Meditate";
    if(p.Level > 10)
        p.Ability[2] = "Fury Barrage";
};

void mageAbilities(Protag& p) {
    p.Ability[0] = "Fireball";
    if(p.Level > 5)
        p.Ability[1] = "Light Strike";
    if(p.Level > 10)
        p.Ability[2] = "Icicle";
};

void rogueAbilities(Protag& p) {
    p.Ability[0] = "Shadow Melt";
    if(p.Level > 5)
        p.Ability[1] = "Piercing Gaze";
    if(p.Level > 10)
        p.Ability[2] = "Flash Strike";
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
    //all new public members are initialised to null as they are properly initialised in battleMechanic()
    
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
Monster DarkWolf("Dark Wolf",12,0,15,1,10,3,2);
Monster MetalCube("Metal Cube",10,0,8,10,6,10,0);

//--
