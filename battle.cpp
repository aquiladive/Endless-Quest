#include<iostream>
#include "monsterCompendium.cpp"
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
        if(effect[i]=="Stat Down") {
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
        expReq+=i*10;
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
    mainchar.statList[6].value += 5;

    while (statpt>0) {
        cout<<"Your current stats are:"<<endl;
        for(int i = 0; i < 6; i++) {
            cout<<i+1<<") "<<mainchar.statList[i].name<<" = "<<mainchar.statList[i].value<<endl;
        }
        cout<<"You have "<<statpt<<" stat points left to allocate."<<endl;
        cout<<"Choose stat you wish to assign points to, using the numbered index."<<endl;
        cin>>stat;
        if(stat<1 || stat>6)
            cout<<"Invalid stat.\n"<<endl;
        else {
            cout<<"How many points do you want to assign?"<<endl;
            cin>>pt;
            if (pt<=statpt && pt>0) {
                mainchar.statList[stat+1].value += pt;
                cout<<"Your "<<mainchar.statList[stat+1].name<<" has been boosted by"<<pt;
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

int initialiseOpponents(int opponents[], Monster Enemy[]) {
    int battleExp = 0;
    for(int i=0;i<opponents[0];i++) {
        Enemy[i] = compendium[i];
        battleExp += compendium[i].exppoint;
    }
    return battleExp;
}

//--

void attackOpponent(Monster Enemy[], Protag Reader, int attackType, double damageBonus, int& enemyCount, int& invalid, int& turn) {
    int attackChoice, damage;

    cout<<"Which enemy do you attack?"<<endl;
    for(int i=1;i<=enemyCount;i++) {
        cout<<i<<") "<<Enemy[i-1].Name<<" ("<<Enemy[i-1].statList[0].value<<" HP)"<<endl;
    }
    attackChoice=chartoint();
    if(attackChoice>0 && attackChoice<=enemyCount) {
        attackChoice--;
        if(attackType==0)
            damage=Reader.attack()*damageBonus-Enemy[attackChoice].statList[2].value;
        else if(attackType==1)
            damage=Reader.magicAttack()*damageBonus-Enemy[attackChoice].statList[4].value;
        if(damage<=0)
            damage=1;
        globalDamage = damage;
        cout<<Reader.Name<<" deals "<<damage<<" damage."<<endl;
        Enemy[attackChoice].statList[0].value=Enemy[attackChoice].statList[0].value-damage;
        if(Enemy[attackChoice].statList[0].value <= 0) {
            cout<<Enemy[attackChoice].Name<<" has been defeated."<<endl;
            enemyCount--;
            for(int i = attackChoice; i < enemyCount; i++) {
                Enemy[i]=Enemy[i+1];
            }
        }
        else
            cout<<Enemy[attackChoice].Name<<" has "<<Enemy[attackChoice].statList[0].value<<" health remaining."<<endl;
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
            damage=Reader.attack()*damageBonus-Enemy[i].statList[2].value;
        else if(attackType==1)
            damage=Reader.magicAttack()*damageBonus-Enemy[i].statList[4].value;
        if(damage<=0)
            damage=1;

        cout<<Reader.Name<<" deals "<<damage<<" damage."<<endl;

        if(Enemy[i].statList[0].value <= 0) {
            cout<<Enemy[i].Name<<" has been defeated."<<endl;
            enemyCount--;
            Enemy[i]=Enemy[i+1];
        }
        else
            cout<<Enemy[i].Name<<" has "<<Enemy[i].statList[0].value<<" health remaining."<<endl;
    }
}

void skillSwitch(skill chosenSkill, Monster Enemy[], Protag& Reader, int attackType, double damageBonus, int& statusCount, int& enemyCount, int& invalid, int& turn) {
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
    else if(chosenSkill.type=="Defense") {
        Reader.Status[statusCount]="Invincible";
        statusCount++;
        statusCount=statusCheck(Reader.Status, statusCount);
    }
    else if(chosenSkill.type=="Heal") {
        if(chosenSkill.effect=="Recover 1") {
            Reader.statList[0].value += 10;
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
        Reader.statList[0].value += heal;
    }
}

//--

void battleMechanic(int opponents[]) {
    //array opponents should have [0] be number of enemies, followed by each position integer indicating which enemy it is
    int turn=0, statusCount=0;
    int choice, skillChoice, attackChoice, attackType, itemChoice, damage=0;
    int enemyCount=opponents[0];
    int enemyAttack[2]; //2 to hold choice + damage
    Monster Enemy[opponents[0]];
    Protag Reader=mainchar; //so that stat/status changes in battle don't affect overworld mainchar

    int battleExp = initialiseOpponents(opponents, Enemy);

    do {
        if(turn%2==0) {
            //player's turn
            //TODO idk why an invalid variable is needed, check its purpose and remove if required
            int invalid=0;
            double damageBonus=1;
            
            statusCount=statusCheck(Reader.Status, statusCount);
            for(int i=0;i<statusCount;i++) {
                Reader.Status[i]=statusAlign(Reader.Status, statusCount, i);
            }

            for(int i=0;i<statusCount;i++) {
                if(Reader.Status[i]=="Stat Down") {
                    Reader.Status[i]="None";
                    Reader.statList[2].value = mainchar.statList[2].value-2;
                    statusCount--;
                }
                if(Reader.Status[i]=="Trapped") {
                    cout<<"You feel as if you're being squeezed painfully."<<endl;
                    cout<<"You take 2 points of damage."<<endl;
                    Reader.statList[0].value -= 2;
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

            if(Reader.statList[0].value <= 0)
                battleEnding();
            
            cout<<"\nYour turn:"<<endl;
            cout<<"You face: "<<endl;
            for(int i=1;i<=enemyCount;i++) {
                cout<<Enemy[i-1].Name<<endl;
            }
            cout<<"Do you:\n1) Attack\n2) Defend\n3) Use Skill\n4) Check Status"<<endl;
            choice=chartoint();
            switch(choice) {
                case 1:
                attackType=0;
                attackOpponent(Enemy, Reader, attackType, damageBonus, enemyCount, invalid, turn);
                break;
                
                
                case 2:
                //comment: TODO make "Defend" actually do something, or remove the option altogether - it's likely unnecessary
                break;


                case 3:
                cout<<"Which skill do you use?"<<endl;
                for(int i = 0; i < Reader.abilityCount; i++)
                    cout<<(i+1)<<") "<<Reader.ability[i].name<<": "<<Reader.ability[i].description<<"\n";
                skillChoice=chartoint();
                //to be done
                if (skillChoice <= Reader.abilityCount && Reader.statList[6].value >= Reader.ability[skillChoice-1].manaCost) {
                    Reader.statList[6].value -= Reader.ability[skillChoice-1].manaCost;
                    skillSwitch(Reader.ability[skillChoice-1], Enemy, Reader, attackType, damageBonus, statusCount, enemyCount, invalid, turn);
                }
                else {
                    if(Reader.statList[6].value < Reader.ability[skillChoice-1].manaCost)
                        cout<<"Too little MP for this spell."<<endl;
                    cout<<"Invalid choice."<<endl;
                    invalid=1;
                    turn++;
                }
                break;


                case 4:
                cout<<"HP: "<<Reader.statList[0].value<<"/"<<mainchar.statList[0].value<<" | MP: "<<Reader.statList[6].value<<"/"<<mainchar.statList[6].value<<endl;
                cout<<"Current list of effects: "<<endl;
                if(statusCount == 0)
                    cout<<"None"<<endl;
                else {
                    for(int i = 0; i < statusCount; i++)
                        cout<<Reader.Status[i]<<endl;
                }
                turn++;
                break;
            } turn++; //end of user turn
        } //end of the first if

        else {
            cout<<"\nEnemy turn:"<<endl;

            //please remember in the future to add conditions for if the enemy is inflicted by a status
            //or unite both Reader and Enemy status effects under one function... which was what statusEffect was intended to be...
            for(int i=0;i<enemyCount;i++) {
                if(Enemy[i].statList[0].value <= 0) {
                    cout<<Enemy[i].Name<<" has been defeated."<<endl;
                    enemyCount--;
                    for(int i=attackChoice;i<enemyCount;i++) {
                        Enemy[i]=Enemy[i+1];
                    }
                }
            }

            for(int i=0;i<enemyCount;i++) {
                if(Reader.Status[statusCount-1] == "Invincible") {
                    cout<<"The hero takes no damage, no matter what the monsters do."<<endl;
                    Reader.Status[statusCount--] = "None";
                    break;
                }
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
                        Reader.statList[2].value -= 2;
                    }
                }
                if(monsterChoice == 1)
                    damage = damage - Reader.statList[2].value;
                else if(monsterChoice > 1)
                    damage = damage-Reader.statList[4].value;
                if(choice == 2 && monsterChoice == 1)
                    damage = damage - 2 * Reader.statList[2].value;
                else if(choice == 2 && monsterChoice > 1)
                    damage = damage - 2 * Reader.statList[4].value;
                if(damage <= 0)
                    damage = 1;
                Reader.statList[0].value = Reader.statList[0].value - damage;
                cout<<Enemy[i].Name<<" deals "<<damage<<" damage."<<endl;
            }
            
            if(Reader.statList[0].value <= 0)
                battleEnding();
            
            else
                cout<<Reader.Name<<" has "<<Reader.statList[0].value<<" health remaining."<<endl;
            
            turn++;
        }
    } while(enemyCount!=0);

    hp=Reader.statList[0].value;
    mainchar.battleExp+=battleExp;
    cout<<endl;
    levelUp(mainchar.battleExp);
}
