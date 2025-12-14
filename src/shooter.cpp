#include "Shooter.h"
#include <iostream>

Roll* Shooter::throw_dice(Die& d1, Die& d2)
{
    Roll* roll = new Roll(d1, d2);
    roll->roll_dice();
    rolls.push_back(roll);
    return roll;
}

void Shooter::display_rolled_values()
{
    for (auto roll : rolls)
    {
        std::cout << roll->roll_value() << std::endl;
    }
}

Shooter::~Shooter()
{
    for (auto roll : rolls)
    {
        delete roll;
    }
}
