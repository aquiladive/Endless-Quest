#include<iostream>
using namespace std;

struct skill {
    string name;
    string type;
    int manaCost;
    string effect;
    double statModifier[2];
    string description;
};

//list of skill types: Attack 1, Attack All, Heal, Defense, Boost (1, 2), Counter, Summon
//list of skill effects: Recover, Blind, Freeze
//current idea for class progression: Warrior to either Paladin or Berserker, Mage to either Elementalist or Guardian (summons, large scale boosts)

skill w1 = {"Force Strike", "Attack 1", 5, "", {3, 1.5}, "A powerful attack that draws on your inner strength."};
skill w2 = {"Meditate", "Heal", 8, "Recover 1", {0, 0}, "You find your core of strength and draw on it to better heal your wounds."};
skill w3 = {"Fury Barrage", "Attack 1", 10, "", {3, 2}, "Your fast but fierce attacks unravel your opponent."};
skill wa1 = {"Holy Shield", "Counter", 8, "", {4, 2}, "The light protects yourself from attacks and strikes back at your opponent."};
skill wb1 = {"Charge of Blood", "Boost 2", 8, "", {3, 2}, "The heat of battle empowers you to strike harder."};

skill m1 = {"Fireball", "Attack 1", 5, "", {5, 1.5}, "A classic in every mage's repertoire."};
skill m2 = {"Light Strike", "Attack 1", 8, "Blind", {5, 1.5}, "You cradle light in your hands and target your opponent."};
skill m3 = {"Icicle", "Attack 1", 8, "Freeze", {5, 1.5}, "The water in the air crystallises and sharp icy daggers fly at your opponent."};
skill ma1 = {"Tidal Wave", "Attack All", 12, "", {5, 1.5}, "The water around you gathers and flows at your enemies as one unstoppable force."};
skill mb1 = {"Arise, Ifrit", "Summon", 20, "", {0, 0}, "The grand fire demon, Ifrit, is brought forth from its dimension to accompany you."};

skill r1 = {"Shadow Melt", "Defense", 5, "", {0, 0}, "Cradled by the shadows, nothing can find you."};
skill r2 = {"Piercing Gaze", "Boost 1", 8, "", {3, 2}, "With your sharp eyes, you discover weaknesses."};
skill r3 = {"Flash Strike", "Attack 1", 8, "Blind", {3, 1.5}, "Your strikes are barely visible as you dart in and out."};
