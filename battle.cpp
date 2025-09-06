#include<iostream>
#include "classes.cpp"
using namespace std;

//--

extern Protag mainchar;

int hp; //for the same thing as in "ADiU"
int battleCounter[3]; //for factors that affect certain battles
int globalDamage; //inelegant solution for the drain issue, fix it later

//--

int chartoint();

int itemUse(string Item);
void levelUp(int battleExp);
void statAllocation(int statpt);
void statusEffects(string effect[], int count);
int statusCheck(string effect[], int count);
string statusAlign(string effect[], int count, int pos);

void battleMechanic(int opponents[]);

void battleEnding(), Tutorial2();

//--

void statusEffects(string effect[], int count) {
    for(int i=0;i<count;i++) {
        if(effect[i]=="DEF Down 1") {
            cout<<"The spell weakens you."<<endl;
        }
        else if(effect[i]=="Dizzy") {
            cout<<"The spell makes it hard for you to concentrate."<<endl;
        }
        else if(effect[i]=="Trapped 1") {
            cout<<"The spell tightens around you painfully."<<endl;
        }
    }
}

int statusCheck(string effect[], int count) {
    for(int i=0;i<count;i++) {
        for(int j=1;j<count;j++) {
            if(effect[i]==effect[j] && effect[i]!="None") {
                effect[j]="None";
                count--;
            }
        }
    }
    return count;
}

//a very inelegant solution, the whole multiple status thing has to be improved on
string statusAlign(string effect[], int count, int pos) {
    for(int i=0;i<count-1;i++) {
        if(effect[i]=="None") {
            effect[i]=effect[i+1];
            effect[i+1]="None";
        }
    }
    return effect[pos];
}

void levelUp(int battleExp) {
    //this only holds good for if the MC can level up only once by battle EXP
    //ie battles should not provide EXP that will boost level multiple times
    int initialExp=0, expReq=20;
    for(int i=1;i<mainchar.level;i++) {
        expReq+=i*5;
    }
    if(battleExp>=expReq) {
        mainchar.level+=1;
        mainchar.battleExp-=expReq;
        cout<<"You have levelled up to Lv."<<mainchar.level<<"."<<endl;
        if(mainchar.level==2)
            Tutorial2();
        statAllocation(5);
    }
}

void statAllocation(int statpt) {
    //this also only holds for levelling up once
    int stat, pt;
    while (statpt>0) {
        cout<<"Your current stats are:\n(1) HP = "<<mainchar.HP<<endl;
        cout<<"(2) ATK = "<<mainchar.ATK<<endl;
        cout<<"(3) DEF = "<<mainchar.DEF<<endl;
        cout<<"(4) MATK = "<<mainchar.MATK<<endl;
        cout<<"(5) MDEF = "<<mainchar.MDEF<<endl;
        cout<<"(6) LUCK = "<<mainchar.LUCK<<endl;
        cout<<"You have "<<statpt<<" stat points left to allocate."<<endl;
        cout<<"Choose stat you wish to assign points to, using the numbered index."<<endl;
        cin>>stat;
        if(stat<1 || stat>6)
            cout<<"Invalid stat.\n"<<endl;
        else {
            cout<<"How many points do you want to assign?"<<endl;
            cin>>pt;
            if (pt<=statpt && pt>0) {
                switch(stat) {
                    case 1: cout<<"Your HP has been boosted by "<<pt;
                    mainchar.HP+=pt;
                    break;
                
                    case 2: cout<<"Your ATK has been boosted by "<<pt;
                    mainchar.ATK+=pt;
                    break;
                
                    case 3: cout<<"Your DEF has been boosted by "<<pt;
                    mainchar.DEF+=pt;
                    break;
                
                    case 4: cout<<"Your MATK has been boosted by "<<pt;
                    mainchar.MATK+=pt;
                    break;
                
                    case 5: cout<<"Your MDEF has been boosted by "<<pt;
                    mainchar.MDEF+=pt;
                    break;

                    case 6: cout<<"Your LUCK has been boosted by "<<pt;
                    mainchar.LUCK+=pt;
                    break;
                }
                if(pt>1)
                    cout<<" points."<<endl;
                else
                    cout<<" point."<<endl;
                statpt-=pt;
            }
            else {
                cout<<"Invalid stat points.\n"<<endl;
            }
        }
    }
}

//--

void initialiseOpponents(int opponents[], Monster Enemy[], int battleExp) {
    for(int i=0;i<opponents[0];i++) {
        switch(opponents[i+1]) {
            case 1:
            battleExp+=10;
            Enemy[i]=Bounceshroom;
            break;
            
            case 2:
            battleExp+=15;
            Enemy[i]=DarkWolf;
            break;

            case 3:
            battleExp+=10;
            Enemy[i]=Slime;
            break;
        }
    }
}

//--

void attackOpponent(Monster Enemy[], Protag Reader, int attackType, double damageBonus, int& enemyCount, int& invalid, int& turn) {
    int attackChoice, damage;

    cout<<"Which enemy do you attack?"<<endl;
    for(int i=1;i<=enemyCount;i++) {
        cout<<i<<") "<<Enemy[i-1].Name<<endl;
    }
    attackChoice=chartoint();
    if(attackChoice>0 && attackChoice<=enemyCount) {
        attackChoice--;
        if(attackType==0)
            damage=Reader.attack()*damageBonus-Enemy[attackChoice].DEF;
        else if(attackType==1)
            damage=Reader.magicAttack()*damageBonus-Enemy[attackChoice].MDEF;
        if(damage<=0)
            damage=1;
        globalDamage = damage;
        cout<<Reader.Name<<" deals "<<damage<<" damage."<<endl;
        Enemy[attackChoice].HP=Enemy[attackChoice].HP-damage;
        if(Enemy[attackChoice].HP<=0) {
            cout<<Enemy[attackChoice].Name<<" has been defeated."<<endl;
            enemyCount--;
            for(int i=attackChoice;i<enemyCount;i++) {
                Enemy[i]=Enemy[i+1];
            }
        }
        else
            cout<<Enemy[attackChoice].Name<<" has "<<Enemy[attackChoice].HP<<" health remaining."<<endl;
        }
    else {
        cout<<"Invalid choice."<<endl;
        invalid=1;
        turn++;
    }
}

void attackAll(Monster Enemy[], Protag Reader, int attackType, double damageBonus, int& enemyCount) {
    int damage;
    for(int i = 1; i <= enemyCount; i++) {
        if(attackType==0)
            damage=Reader.attack()*damageBonus-Enemy[i].DEF;
        else if(attackType==1)
            damage=Reader.magicAttack()*damageBonus-Enemy[i].MDEF;
        if(damage<=0)
            damage=1;

        cout<<Reader.Name<<" deals "<<damage<<" damage."<<endl;

        if(Enemy[i].HP<=0) {
            cout<<Enemy[i].Name<<" has been defeated."<<endl;
            enemyCount--;
            Enemy[i]=Enemy[i+1];
        }
        else
            cout<<Enemy[i].Name<<" has "<<Enemy[i].HP<<" health remaining."<<endl;
    }
}

void skillSwitch(skill chosenSkill, Monster Enemy[], Protag Reader, int attackType, double damageBonus, int& enemyCount, int& invalid, int& turn) {
    if(chosenSkill.type=="Attack 1") {
        if(chosenSkill.statModifier[0]==3)
            attackType=0;
        else if(chosenSkill.statModifier[0]==5)
            attackType=1;
        damageBonus = chosenSkill.statModifier[1];
        //add MP cost for every skill
        attackOpponent(Enemy, Reader, attackType, damageBonus, enemyCount, invalid, turn);
    }
    else if(chosenSkill.type=="Attack All") {
        if(chosenSkill.statModifier[0]==3)
            attackType=0;
        else if(chosenSkill.statModifier[0]==5)
            attackType=1;
        damageBonus = chosenSkill.statModifier[1];
        attackAll(Enemy, Reader, attackType, damageBonus, enemyCount);
    }
    else if(chosenSkill.type=="Heal") {
        if(chosenSkill.effect=="Recover 1") {
            Reader.HP += 10;
            cout<<"You feel a renewed energy in your tired bones."<<endl;
        }
    }
    else if(chosenSkill.type=="Summon") {
        battleCounter[0]=1;
        //set battleCounter[1] to an integer value according to the being that is summoned
    }
    else if(chosenSkill.type=="Drain") {
        if(chosenSkill.statModifier[0]==3)
            attackType=0;
        else if(chosenSkill.statModifier[0]==5)
            attackType=1;
        damageBonus = chosenSkill.statModifier[1];
        attackOpponent(Enemy, Reader, attackType, damageBonus, enemyCount, invalid, turn);
        int heal = globalDamage/2;
        cout<<"You have healed "<< heal << " points of HP."<<endl;
        Reader.HP += heal;
    }
}

//--

void battleMechanic(int opponents[]) {
    //array opponents should have [0] be number of enemies, followed by each position integer indicating which enemy it is
    int turn=0, statusCount=0;
    int choice, skillChoice, attackChoice, attackType, itemChoice, damage=0;
    int enemyCount=opponents[0];
    int enemyAttack[2]; //2 to hold choice + damage
    int battleExp=0;
    Monster Enemy[opponents[0]];
    Protag Reader=mainchar; //so that stat/status changes in battle don't affect overworld mainchar

    initialiseOpponents(opponents, Enemy, battleExp);

    do {
        if(turn%2==0) {
            //player's turn
            int invalid=0;
            double damageBonus=1;
            
            statusCount=statusCheck(Reader.Status, statusCount);
            for(int i=0;i<statusCount;i++) {
                Reader.Status[i]=statusAlign(Reader.Status, statusCount, i);
            }

            for(int i=0;i<statusCount;i++) {
                if(Reader.Status[i]=="DEF Down 1") {
                    Reader.Status[i]="None";
                    Reader.DEF=mainchar.DEF;
                    statusCount--;
                }
                if(Reader.Status[i]=="Trapped 1") {
                    cout<<"You feel as if you're being squeezed painfully."<<endl;
                    cout<<"You take 2 points of damage."<<endl;
                    Reader.HP-=2;
                    Reader.Status[i]="None";
                    statusCount--;
                }
                if(Reader.Status[i]=="Strengthened") {
                    cout<<"A prayer of light is embedded in you."<<endl;
                    damageBonus=1.25;
                    Reader.Status[i]="None";
                    statusCount--;
                }
            }

            if(Reader.HP<=0)
                battleEnding();
            
            cout<<"\nYour turn:"<<endl;
            cout<<"Do you:\n1) Attack\n2) Defend\n3) Use Skill\n"<<endl;
            choice=chartoint();
            switch(choice) {
                case 1:
                attackType=0;
                attackOpponent(Enemy, Reader, attackType, damageBonus, enemyCount, invalid, turn);
                break;
                
                
                case 2:
                break;


                case 3:
                cout<<"Which skill do you use?"<<endl;
                for(int i = 0; i < Reader.abilityCount; i++)
                    cout<<(i+1)<<") "<<Reader.ability[i].name<<": "<<Reader.ability[i].description<<"\n";
                skillChoice=chartoint();
                //to be done
                if (skillChoice <= Reader.abilityCount) {
                    skillSwitch(Reader.ability[skillChoice-1], Enemy, Reader, attackType, damageBonus, enemyCount, invalid, turn);
                }
                else {
                    cout<<"Invalid choice."<<endl;
                    invalid=1;
                    turn++;
                }
            } turn++; //end of user turn
        } //end of the first if

        else {
            cout<<"\nEnemy turn:"<<endl;

            //please remember in the future to add conditions for if the enemy is inflicted by a status
            //or unite both Reader and Enemy status effects under one function... which was what statusEffect was intended to be...
            for(int i=0;i<enemyCount;i++) {
                if(Enemy[i].HP<=0) {
                    cout<<Enemy[i].Name<<" has been defeated."<<endl;
                    enemyCount--;
                    for(int i=attackChoice;i<enemyCount;i++) {
                        Enemy[i]=Enemy[i+1];
                    }
                }
            }

            for(int i=0;i<enemyCount;i++) {
                damage=Enemy[i].attack();
                if(monsterChoice!=1) {
                    if(monsterChoice==2) {
                        Reader.Status[statusCount]=Enemy[i].mattack1effect;
                        statusCount++;
                        statusCount=statusCheck(Reader.Status, statusCount);
                    }
                    else if(monsterChoice==3) {
                        Reader.Status[statusCount]=Enemy[i].mattack2effect;
                        statusCount++;
                        statusCount=statusCheck(Reader.Status, statusCount);
                    }
                    statusEffects(Reader.Status, statusCount);
                }
                for(int i=0;i<statusCount;i++) {
                    Reader.Status[i]=statusAlign(Reader.Status, statusCount, i);
                }
                for(int i=0;i<statusCount;i++) {
                    if(Reader.Status[statusCount]=="DEF Down 1") {
                        Reader.DEF-=2;
                    }
                }
                if(monsterChoice==1)
                    damage=damage-Reader.DEF;
                else if(monsterChoice>1)
                    damage=damage-Reader.MDEF;
                if(choice==2 && monsterChoice==1)
                    damage=damage-2*Reader.DEF;
                else if(choice==2 && monsterChoice>1)
                    damage=damage-2*Reader.MDEF;
                if(damage<=0)
                    damage=1;
                Reader.HP=Reader.HP-damage;
                cout<<Enemy[i].Name<<" deals "<<damage<<" damage."<<endl;
            }
            
            if(Reader.HP<=0)
                battleEnding();
            
            else
                cout<<Reader.Name<<" has "<<Reader.HP<<" health remaining."<<endl;
            
            turn++;
        }
    } while(enemyCount!=0);

    hp=Reader.HP;
    mainchar.battleExp+=battleExp;
    cout<<endl;
    levelUp(mainchar.battleExp);
}
