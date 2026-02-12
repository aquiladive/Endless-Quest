#include <map>
#include "classes.cpp"

//TODO remove LUCK from Monsters? Maybe make MP matter for them as well?
//Monster constructor: HP, ATK, DEF, MATK, MDEF, LUCK, MP

Monster Bounceshroom("Bounceshroom",6,9,3,8,0,0,0);

Monster Slime("Slime",10,7,0,8,6,0,0);

Monster FangedPuppy("Fanged Puppy",8,10,0,5,1,2,0);

Monster DarkWolf("Dark Wolf",12,15,1,10,3,2,0);

Monster PoisonPetals("Poison Petals",8,10,3,10,5,0,0);

Monster Saberhawk("Saberhawk",10,12,0,6,0,0,0);

Monster ArmouredDillo("Armored Dillo",15,7,10,7,10,0,0);

Monster LavaSnake("Lava Snake",13,4,5,9,7,0,0);

Monster MetalCube("Metal Cube",10,8,10,6,10,0,0);

Monster CloakedKnell("Cloaked Knell",20,20,10,10,15,0,0);

Monster ThornyWisp("Thorny Wisp",12,9,3,9,10,0,0);

//---

Monster compendium[] = { Bounceshroom, Slime, FangedPuppy, DarkWolf, PoisonPetals, Saberhawk, ArmouredDillo, LavaSnake, MetalCube, CloakedKnell, ThornyWisp };

//---

void finaliseMonsters() {
    compendium[0].setValues("Spore", "DEF Down 1", "Bounce", "None", 10); // Bounceshroom
    compendium[1].setValues("Acid", "DEF Down 1", "Ooze Trap", "Trapped 1", 10); // Slime
    compendium[2].setValues("", "", "", "", 10); // FangedPuppy
    compendium[3].setValues("Shadow Claw", "None", "Restrain", "Trapped 1", 15); // DarkWolf
    compendium[4].setValues("Acid", "DEF Down 1", "Lash", "None", 15); // PoisonPetals
    compendium[5].setValues("Cleave", "None", "", "", 20); // Saberhawk
    compendium[8].setValues("Layer", "DEF Up 2", "", "", 20); // MetalCube
}
