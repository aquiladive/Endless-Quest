#include<iostream>
using namespace std;

struct skill {
    string name;
    string type;
    string effect;
    int statModifier[2];
    string description;
};

skill w1 = {"Force Strike", "Attack", "", {1, 1.5}, "A powerful attack that draws on your inner strength."};
skill m1 = {"Fireball", "Attack", "", {1, 1.5}, "A classic in every mage's repertoire."};
skill r1 = {"Shadow Melt", "Defense", "", {0, 0}, "Cradled by the shadows, nothing can find you."};
