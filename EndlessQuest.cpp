/************************************************************************
 * Endless Quest, v.0.0.1

 * (please refer to documentation log for further details)

**************************************************************************/

#include<iostream>
#include<fstream>
#include "start.cpp"
using namespace std;

//--

extern int yn(), chartoint();
extern int inventoryCheck();
extern int inventoryCheckName(string item);
extern void inventoryArrange();
extern int initiateBattles();

extern int saveLoc;
extern int itemUse(string Item);

extern Protag mainchar;

//--
//misc functions
//--

int yn() {
    char yven;
    cout<<"(insert 'y' for yes or 'n' for no)"<<endl;
    cin>>yven;
    if(yven=='y')
        return 1;
    if(yven=='n')
        return 0;
    else {
        cout<<"Invalid choice."<<endl;
        yn();
    }
}

int chartoint() {
    string ch;
    cin>>ch;
    return ch[0]-'0';
}

//--

void Intro() {
    cout<<"The Alliance of Exenta spans the entire continent, each kingdom an uneasy member of this coalition and all governed by a neutral establishment known as the Stage of Communion. Though each kingdom has its own culture and tales, together they sing many a glorious tales of heroes from an age long past. Such a beautiful time is known as the Age of Peace in history."<<endl;
    cout<<"Now, with the death of Averr, the patron divine of the continent, historians have named the time to come as the Age of Darkness."<<endl;
    cout<<"In a continent besieged by monsters from all sides, as the skies and earth tear apart alike, heroes are in great need and short supply."<<endl;
    cout<<"You are from an ancient bloodline known for possessing the great hero Menara among its descendants, and you have lived your whole life training to become someone that can meet the needs of the time."<<endl;
    cout<<endl;
    cout<<"Now, as your adulthood has approached, it is time for you to set out, set your blade against the threats to come and measure yourself once and for all."<<endl;
    cout<<endl;
    cout<<"Welcome to-"<<endl;
    cout<<"ENDLESS QUEST"<<endl;
    cout<<endl;
}

void about() {
    cout<<"\n\"Endless Quest\" is, as the name suggests, a game of endless fighting."<<endl;
    cout<<"You will battle various opponents, become stronger, choose different paths to improve yourself in myriad ways, and forge a story of excellence."<<endl;
    cout<<"Battles run according to standard JRPG. If you have no experience with it, the in-game tutorial will guide you through your first battle."<<endl;
    cout<<"This is currently only a trial version. Hope you enjoy!\n"<<endl;
}

void openingMenu() {
    cout<<"1) Start\t 2) Load"<<endl;
    cout<<"3) About\t 4) Quit"<<endl;
    cout<<"(insert choice)"<<endl;
    int opchoice, test=1, surety=0;
    string name;

    cin>>opchoice;
    switch (opchoice) {
        case 1:
        while(surety==0) {
            int saveLoc;
            cout<<"Choose location to save: 1, 2, 3"<<endl;
            saveLoc=chartoint();
            if(saveLoc<0 || saveLoc>3) {
                while(saveLoc<0 || saveLoc>3) {
                    cout<<"Invalid location. Please input again."<<endl;
                    saveLoc=chartoint();
                }
            }
            cout<<"Are you sure? If there is an existing save in this location, it will be overwritten."<<endl;
            surety=yn();
        }
        cout<<"Give your character's name."<<endl;
        cin>>name;
        mainchar.Name = name;
        initiateBattles();
        break;
        
        case 2: {
            int saveLoc;
            cout<<"Choose which to load:"<<endl;
            cout<<"1. Save_1\n2. Save_2\n3. Save_3"<<endl;
            fstream file;
            cin>>saveLoc;
            if(saveLoc==1)
                file.open("save_1.txt",ios::in);
            else if(saveLoc==2)
                file.open("save_2.txt",ios::in);
            else if(saveLoc==3)               
                file.open("save_3.txt",ios::in);
            else
                cout<<"Invalid choice."<<endl;
            
            if(!file)
                cout<<"Save cannot be found."<<endl;
                
            cout<<"This function is under construction."<<endl;
        }
        break;
        
        case 3:
        about();
        openingMenu();
        break;
        
        case 4:
        exit(0);
        
        default:
        cout<<"Invalid choice.\n";
    }
}

int main()
{
    Intro();
    openingMenu();
    return 0;
}

//--
// tutorials
//--

void Tutorial1() {
    string blankSpace;
    int tutorial;
    cout<<"You are about to enter a battle. Would you like a short tutorial on this game's battle aspect?"<<endl;
    tutorial=yn();
    if(tutorial==1) {
        cout<<"In battle, the poor hero you are will have to face off against some number of opponents."<<endl;
        cout<<"This is turn-based, starting with your turn."<<endl;
        cout<<"On your turn, you can choose to do one of three things: attack, defend or use an item."<<endl;
        cout<<"Attacking damages the opponent and lowers their health."<<endl;
        cout<<"Defending puts you in a stance where you take less damage from the opponent than you would otherwise."<<endl;
        cout<<"Items can have varied effects, some useful in battle and some not."<<endl;
        cout<<"However, items have usage limits. Once they reach that limit, they can no longer be used."<<endl;
        cout<<"You will not know the breaking point until it has been reached. So it's good to be careful with item usage, but at the same time, don't stockpile them."<<endl;
        cout<<"They're there to be used."<<endl;
        cout<<"Now go on and protect yourself!"<<endl;
        cout<<"[tutorial end]"<<endl;
        cin>>blankSpace;
        cout<<endl;
    }
    else {
        cout<<endl;
    }
}

void Tutorial2() {
    string blankSpace;
    int tutorial;
    cout<<"By levelling up, you can allocate stat points. Would you like a short tutorial on this?"<<endl;
    tutorial=yn();
    if(tutorial==1) {
        cout<<"After battling opponents, you may feel that you have gotten stronger."<<endl;
        cout<<"This rise in strength is in-game reflected by your level."<<endl;
        cout<<"After every rise in level, you will be given 5 stat points to allocate as you wish."<<endl;
        cout<<"Your character has six main stats:"<<endl;
        cout<<"Health Points (HP) which show the amount of damage you can take and remain standing."<<endl;
        cout<<"Attack (ATK) which show the amount of normal damage you can deal to enemies."<<endl;
        cout<<"Defense (DEF) which helps reduce damage taken from normal attacks."<<endl;
        cout<<"Magic Attack (MATK) which shows the amount of magical damage you can deal to enemies."<<endl;
        cout<<"Magic Defense (MDEF) which helps reduce damage taken from magical attacks."<<endl;
        cout<<"And finally, Luck (LUCK) which has no battle relevance but affects the course of events around you."<<endl;
        cout<<"Each stat has its own importance, so distribute your points wisely."<<endl;
        cout<<"[tutorial end]"<<endl;
        cin>>blankSpace;
        cout<<endl;
    }
    else {
        cout<<endl;
    }
}

void battleEnding() {
    string blankSpace;
    cout<<"\nYou can no longer hold yourself upright."<<endl;
    cout<<"Every breath hurts, and your vision blurs at the edges as darkness takes over."<<endl;
    cout<<"You collapse, consciousness fleeing you to never return, and your body remains forever in the ruins."<<endl;
    cin>>blankSpace;
    cout<<"THE END"<<endl;
    cout<<"..."<<endl;
    cin>>blankSpace;
    
    cout<<"1. Return to Menu\t\t 2. Quit"<<endl;
    int ch;
    cin>>ch;
    if(ch==1)
        openingMenu();
    else
        exit(0);
}
