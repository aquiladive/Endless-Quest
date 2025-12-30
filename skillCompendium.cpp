#include<iostream>
using namespace std;

struct skill {
    string name;
    string type;
    int turnCount;
    int manaCost;
    string effect;
    double statModifier[2];
    string description;
};

//list of skill types: Attack 1, Attack All, Heal, Defense, Boost, Counter, Summon, Drain, BleedBoost (combines Bleed effect with Boost)
//list of skill effects: Recover, Blind, Freeze
//current idea for class progression: Warrior to either Paladin or Berserker, Mage to either Elementalist or Guardian (summons, large scale boosts) or Lich, Rogue to either Sacrificer or Assassin

skill w1 = {"Force Strike", "Attack 1", 1, 5, "", {3, 1.5}, "A powerful attack that draws on your inner strength."};
skill w2 = {"Meditate", "Heal", 1, 8, "Recover 1", {0, 0}, "You find your core of strength and draw on it to better heal your wounds."};
skill w3 = {"Fury Barrage", "Attack 1", 1, 10, "", {3, 2}, "Your fast but fierce attacks unravel your opponent."};
skill wa1 = {"Holy Shield", "Counter", 1, 8, "", {4, 2}, "The light protects yourself from attacks and strikes back at your opponent."};
skill wb1 = {"Charge of Blood", "Boost", 2, 8, "", {3, 2}, "The heat of battle empowers you to strike harder."};
skill wa2 = {"Divine Charge", "Attack 1", 1, 10, "", {5, 2}, "Light swells around and as you rush forward, it rushes with you- a blade honed with the force of the heavens."};
skill wb2 = {"Desperate Dive", "BleedBoost", 2, 12, "", {3, 3}, "Your wounds bleed more but rather than dizziness, a great strength surges from your limbs."};

skill m1 = {"Fireball", "Attack 1", 1, 5, "", {5, 1.5}, "A classic in every mage's repertoire."};
skill m2 = {"Light Strike", "Attack 1", 1, 8, "Blind", {5, 1.5}, "You cradle light in your hands and target your opponent."};
skill m3 = {"Icicle", "Attack 1", 1, 8, "Freeze", {5, 1.5}, "The water in the air crystallises and sharp icy daggers fly at your opponent."};
skill ma1 = {"Tidal Wave", "Attack All", 1, 12, "", {5, 1.5}, "The water around you gathers and flows at your enemies as one unstoppable force."};
skill mb1 = {"Arise, Ifrit", "Summon", 1, 20, "", {0, 0}, "The grand fire demon, Ifrit, is brought forth from its dimension to accompany you."};

skill r1 = {"Shadow Melt", "Defense", 1, 5, "", {0, 0}, "Cradled by the shadows, nothing can find you."};
skill r2 = {"Piercing Gaze", "Boost", 1, 8, "", {3, 2}, "With your sharp eyes, you discover weaknesses."};
skill r3 = {"Flash Strike", "Attack 1", 1, 8, "Blind", {3, 1.5}, "Your strikes are barely visible as you dart in and out."};
skill ra1 = {"Bloodletting", "BleedBoost", 2, 8, "", {3, 2}, "You give up some of your blood to the gods to gain their righteous force."};
skill rb1 = {"Life Steal", "Drain", 1, 10, "", {3, 1.5}, "Your blade cuts your opponent and their life force is drawn to you."};
skill ra2 = {"Giver to Shadows", "Attack All", 1, 12, "", {3, 1.5}, "You raise your hands and the shadows obey, lashing out like snakes."};
