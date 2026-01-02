#include "classes.cpp"

Monster Bounceshroom("Bounceshroom",6,0,9,1,10,5,0);

Monster Slime("Slime",10,0,7,2,8,6,0);

Monster FangedPuppy("Fanged Puppy",8,0,10,0,5,1,2);

Monster DarkWolf("Dark Wolf",12,0,15,1,10,3,2);

Monster PoisonPetals("Poison Petals",8,0,10,3,10,5,0);

Monster Saberhawk("Saberhawk",10,0,12,0,6,0,0);

Monster MetalCube("Metal Cube",10,0,8,10,6,10,0);

Monster CloakedKnell("Cloaked Knell",20,0,20,10,10,15,0);

//---

Monster compendium[] = { Bounceshroom, Slime, FangedPuppy, DarkWolf, PoisonPetals, Saberhawk, MetalCube, CloakedKnell };

//---

void finaliseMonsters() {
    Bounceshroom.setValues("Spore", "DEF Down 1", "Bounce", "None", 10);
    FangedPuppy.setValues("", "", "", "", 10);
    Slime.setValues("Acid", "DEF Down 1", "Ooze Trap", "Trapped 1", 10);
    DarkWolf.setValues("Shadow Claw", "None", "Restrain", "Trapped 1", 15);
    PoisonPetals.setValues("Acid", "DEF Down 1", "Lash", "None", 15);
}
