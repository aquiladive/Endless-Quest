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

class Protag: public Character {
    //using Character::Character;
    public:
    Protag () {

    }
    Protag (string n, int a, int b, int x, int y, int z, int i, int j) {
        Name=n;
        HP=a;
        MP=b;
        ATK=x;
        DEF=y;
        MATK=z;
        MDEF=i;
        LUCK=j;
    }

    int Level=1;
    int battleExp=0;
    int Beyonder[2];
    int Ability[3];
    string Class;
    
    int attack() {
        return ATK;
    }
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

Protag mainchar("\0",25,5,5,5,5,5,5);

//--

Monster Bounceshroom("Bounceshroom",6,0,9,1,10,5,0);
Monster Slime("Slime",10,0,7,4,8,6,0);
Monster DarkWolf("Dark Wolf",12,0,15,4,10,3,2);
Monster MetalCube("Metal Cube",10,0,8,10,6,10,0);

//--
