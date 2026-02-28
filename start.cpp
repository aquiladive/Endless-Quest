#include<iostream>
#include "battle.cpp"
using namespace std;

//--

void battleMechanic(int opponents[]);

extern Protag mainchar;

extern void finaliseMonsters();

//--

void townGladius(), forestsBeyond_pt1(), forestsBeyond_pt2(), forestsBeyond_pt3(), forestsBeyond_pt4();
void plotCall(int battleCount);

//--


int initiateBattles() {
    int battleCount=0;
    
    finaliseMonsters();

    cout<<"The endless battles have begun."<<endl;
    while(true) {
        int number = 0;
        srand(time(0));
        if(mainchar.level < 5)
            number = rand() % 2 + 1;
        else
            number = rand() % 4 + 1;
    
        int opponents[number+1];
        opponents[0] = number;
        
        int opponentRange = 0;
        if(battleCount < 4)
            opponentRange = 3;
        else if(battleCount < 10)
            opponentRange = 6;
        else
            opponentRange = 6; //TODO comment: rough solution, to be changed for increasing battleCounts
            
        for(int i = 1; i < number + 1; i++)
            opponents[i] = rand() % opponentRange + 1;

        battleMechanic(opponents);
        battleCount++;
        if(battleCount % 3 == 1) {
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
        case 4: forestsBeyond_pt1();
        break;
        case 7: forestsBeyond_pt2();
        break;
        case 10: forestsBeyond_pt3();
        break;
        case 13: forestsBeyond_pt4();
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
    cout<<"The shout catches you by surprise and you whirl around, weapon already held at the ready--"<<endl;
    cin>>pause;
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
    cin>>pause;
    cout<<"As you make your way to the union, you clear up some of the lesser monsters in the vicinity..."<<endl;
    cout<<mainchar.battleExp<<endl;
}

void forestsBeyond_pt1() {
    string pause;

    cout<<"You haven't been to the forest before, but you're familiar with them through the many tales."<<endl;
    cout<<"You are part of a team of six. It is too little to walk into the Aragin Forest, and yet it is too much to assign to a quest of the farmers' union."<<endl;
    cout<<"It's the pay, you believe. You hadn't expected the union could scrounge up that much, but clearly the gravity of the issue had surpassed such matters."<<endl;
    cout<<"It wasn't just that wolves were attacking the agricultural outskirts; the intensity and timing didn't match their usual actiivty, and the union wanted an investigation into it as much as possible, to remove the issue at its root."<<endl;
    cout<<"You're passingly familiarly with most people in the team, with all of you being from Gladius... there's Franz from the Renic Quarter, Asha and Sheila from the School of Arcane Arts, and Lain from the Steria Quarter."<<endl;
    cout<<"And that leaves just one who you don't know."<<endl;
    cin>>pause;
    cout<<"Verun, he calls himself."<<endl;
    cout<<"He's dressed in a muted gray, a hood pulled up though it doesn't hide his ageless face from view, and carrying a massive longbow on his back. It's large enough you're not certain any of you could lift it, let alone fire with it."<<endl;
    cout<<"He isn't the silent type, despite appearances. He does add to the conversation, but he drifts in and out of it at will and answers nothing about himself."<<endl;
    cout<<"That mystery makes it feel like there's something important about him, but you choose to ignore him -- there's no use taking a horse to water if it won't drink, as a saying in your town goes."<<endl;
    cin>>pause;
    cout<<"Instead, you try to get to know Asha and Lain better. You recall them faintly from your elementary schooling days; the school you studied in is the largest and most well-known in Gladius, and it isn't unusual to run into other graduates of it."<<endl;
    cout<<"Lain was the same year but a different class, while Asha was a few years your senior."<<endl;
    cout<<"Asha and Sheila teamed up for their graduation project, which is a year-long affair requiring them to gain practical experience and master some subset of their magic branch."<<endl;
    cout<<"Meanwhile, Lain is working to be one of the Kriskitters, the elite guards of the district capital Estoc."<<endl;
    cout<<"He's been studying for it for years, and this mission will help him cover another important area for his qualification, as monster hunting tends to do for most combat professions."<<endl;
    cout<<"Lain and Asha are both rather serious and take time to relax in the conversation, unsurprisingly, but you find that Asha has a sense for beauty in the (natural) flora and fauna around, and Lain has a cheerful sense of humour."<<endl;
    cout<<"Though you don't tend to be the heart of a gathering, it makes the journey far more bearable to have friendly company."<<endl;
    cout<<"You can't help but wonder briefly what it would have been like if Solia shared your dreams, before you force yourself to cast that way. It's a selfish thought; she has the right to choose her own path just as you do, even though she's a fabulous archer..."<<endl;
    cin>>pause;
    cout<<"You don't need to distract yourself however. Your attention, and that of the group's, sharpens as you all go deeper in and the denizens of the forest emerge..."<<endl;
}

void forestsBeyond_pt2() {
    string pause;
    
    cout<<"Wolves with fur dark enough to have been stolen from the fabric of night, poisonous flora that wait for you to lower your guard before it comes to life...."<<endl;
    cout<<"It's been four days that you all have been in this forest and there's no end to the parade of viciousness."<<endl;
    cout<<"\"Watch out!\" you cry, attacking wildly to the right, but it's too little and too late; the dark wolf leaps at Franz and in a blur of movement, blood sprays through the air as its fangs tear through flesh."<<endl;
    cout<<"The scream that follows is sharp and ear-piercing, and your jaw clenches in pained sympathy."<<endl;
    cout<<"You refuse to look further, fearing it'll make you lose your nerve (and whatever is in your guts), and you leave with the others. There's nothing that can be rescued..."<<endl;
    cin>>pause;
    cout<<"You all travel the next few miles in utter silence, the only sounds being those of fending off monsters."<<endl;
    cout<<"Though formed out of necessity rather than intent, it's easy to see this team works well together."<<endl;
    cout<<"Asha's defensive spells reduces the painful injuries that the monsters are all too capable of inflicting. Lain, heavily armoured with lance in hand, draws attention and stands his ground while you and Verun take advantage to attack. Sheila rounds up with her healing magic, keeping attrition at bay."<<endl;
    cout<<"Franz was also one of the main attackers..."<<endl;
    cout<<"You clench your jaw as your thoughts drift to him, wondering if there'll be anything of his body left."<<endl;
    cin>>pause;
    cout<<"It doesn't strike you until much later, when everyone settles in for the night and you take the first watch, what it means that your team is *good*."<<endl;
    cout<<"Aragin Forest is dangerous, but only on the level of townspeople wandering in. For even two adventurers, it shouldn't possess a threat to navigate."<<endl;
    cout<<"Your team is going deeper in to flush out the wolves, true, but with six people, it should have been a breeze."<<endl;
    cout<<"Then... what exactly is going on here?"<<endl;
    cout<<"It's not just the wolves, but every denizen of the forest?"<<endl;
    cout<<"You don't get much time to ponder that, as monsters test the boundaries of the camp."<<endl;
}

void forestsBeyond_pt3() {
    string pause;
    
    cout<<"The night goes by in waves of activity, rising and receding by its own rhythm. By morning, most of you are rather weary, but still prepared to continue."<<endl;
    cout<<"You mention your thoughts to Lain as you travel."<<endl;
    cout<<"\"It could be the rise of evil,\" he suggests after listening to you with a creased brow. \"The Age of Darkness isn't just a name; it's a corruptive force plunging the world into worse straits. The forest creatures could be more susceptible to it.\""<<endl;
    cout<<"It's a fair proposition. You haven't quite studied the background of the Age in detail, but from what you know, that explanation doesn't sound off."<<endl;
    cout<<"\"That's not quite how it works,\" a small voice pipes up, and the two of you turn to see Sheila."<<endl;
    cout<<"She flushes a little in the embarrassment of being caught listening in, but she attempts to keep eye contact as obvious as it is that she wants to turn her face away."<<endl;
    cout<<"\"What do you mean?\" you ask, giving her a quick out from it."<<endl;
    cout<<"\"The urchontic force is indeed corrupting the existences of less sapient beings and distorting the barrier between the chaos realms to our world,\" she starts, taking on a lecture-like cadence that seems to remove her previous shyness."<<endl;
    cout<<"\"However, it works progressively and on a large scale, as ascertained by using certain formulae. If the creatures of Aragin Forest are showing unexpected developments that spiked recently, then it should be something more than urchontism.\""<<endl;
    cin>>pause;
    cout<<"That... was definitely a fair amount to take in. You and Lain don't stay quiet for long though, with the latter asking, \"What do you think could be the cause, then?\""<<endl;
    cout<<"\"It's hard to say,\" Sheila answers, looking a little nervous again. \"It could be one of several things or multiple of them. An artifact, a spell, a ritual, a trait of some other creature... or even a Void Gate.\""<<endl;
    cout<<"Void Gates... those were myths, though tiny ones were known to exist. So more like theory, you guess. Those were considered direct ways to travel to the chaos realms, though they appeared like holes in the barrier."<<endl;
    cout<<"\"Of course, I'm just saying!\" Sheila waved her hands in a warding gesture. \"It's completely unlikely it's here, but it can cause issues in surroundings like this.\""<<endl;
    cout<<"... you share a glance with Lain, and you can see your hope reflected in his eyes -- that she hasn't jinxed you all."<<endl;
    cin>>pause;
    cout<<"Asha, who was leading the group alongside Verun, casting and maintaining defensive spells over everyone, steps back for a break. Lain switches with Asha and takes point, leaving you with her and Sheila."<<endl;
    cout<<"\"You seem to be deep in discussion,\" Asha says softly, tilting her head at Sheila, who flushes a little simply at the inquiry."<<endl;
    cout<<"You had not planned to make your still-blossoming thoughts known to all, but you would have chosen Asha more than Sheila to confide even after the comradery of your previous days. And so you explain the matter to her as well."<<endl;
    cout<<"\"I did notice more difficulty here than expected,\" she validates you. \"But I've never studied Aragin Forest before, so I thought perhaps it was just an issue of my perception.\""<<endl;
    cout<<"\""<<mainchar.Name<<" is right on that,\" Lain says. \"I've cleared out the edges of the forest a few times; they're hostile but not this much.\""<<endl;
    cout<<"\"You haven't been to the forest before though?\" Asha asks you in a tone that's more of a statement."<<endl;
    cout<<"\"You feel just a tad embarrassed, but you answer, \"I've studied it. I always planned to leave home once I was old enough.\""<<endl;
    cout<<"Luckily neither of them ask you any more questions; to tell Solia you want to be the next Hero is one thing, and telling it to people you've known only for a few days is another."<<endl;
    cout<<"The rest of the day goes by in the tedious grind of fighting off monsters."<<endl;
}

void forestsBeyond_pt4() {
    string pause;
    //to be done

    cout<<"Three days afterwards, you've all scoured further into the forest than you ever expected you would. Your pace is slowing though and your supplies flagging."<<endl;
    cout<<"All of you unanimously come to a decision -- if you can't find out more in the next two days, you'll be heading back. Sure, it won't be a mission *success*, but what you've done is already worth far more than what you're being paid."<<endl;
    cout<<"As the first afternoon rolls by, you've made your way into a clearing, where the canopy is so thick that not a beam of light makes its way through to the forest floor."<<endl;
    cout<<"The gentle sounds of a flowing river reach you, and you tilt your head as you try to figure from which direction it is and how close it might be."<<endl;
    cout<<"Verun suddenly takes point, bypassing Lain, who makes a sound of confusion."<<endl;
    cout<<"\"Quiet,\" Verun says in a barely audible whisper, taking his bow off his back and nocking an arrow in a quicksilver movement."<<endl;
    cout<<"A bit of indignation radiates from Lain, but only for a second before he takes a prepared stance as well."<<endl;
}
