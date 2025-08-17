#include<iostream>
using namespace std;

struct skill {
    string name;
    string type;
    string effect;
    double statModifier[2];
    string description;
};

//list of skill types: Attack, Heal, Defense, Boost
//list of skill effects: Recover, Blind, Freeze

skill w1 = {"Force Strike", "Attack 1", "", {3, 1.5}, "A powerful attack that draws on your inner strength."};
skill w2 = {"Meditate", "Heal", "Recover", {0, 0}, "You find your core of strength and draw on it to better heal your wounds."};
skill w3 = {"Fury Barrage", "Attack1", "", {3, 2}, ""};

skill m1 = {"Fireball", "Attack 1", "", {5, 1.5}, "A classic in every mage's repertoire."};
skill m2 = {"Light Strike", "Attack 1", "Blind", {5, 1.5}, "You cradle light in your hands and target your opponent."};
skill m3 = {"Icicle", "Attack 1", "Freeze", {5, 1.5}, "The water in the air crystallises and sharp icy daggers fly at your opponent."};

skill r1 = {"Shadow Melt", "Defense", "", {0, 0}, "Cradled by the shadows, nothing can find you."};
skill r2 = {"Piercing Gaze", "Boost", "", {3, 2}, "With your sharp eyes, you discover weaknesses."};
skill r3 = {"Flash Strike", "Attack 1", "Blind", {3, 1.5}, "Your strikes are barely visible as you dart in and out."};
