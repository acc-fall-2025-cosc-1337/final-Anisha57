#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Die.h"
#include "Shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main()
{
    srand(time(0));

    Die die1, die2;
    Shooter shooter;
    Roll* roll = nullptr;

    ComeOutPhase come_out_phase;

    roll = shooter.throw_dice(die1, die2);

    while (come_out_phase.get_outcome(roll) == RollOutcome::natural ||
           come_out_phase.get_outcome(roll) == RollOutcome::craps)
    {
        std::cout << "Rolled " << roll->roll_value() << " roll again\n";
        roll = shooter.throw_dice(die1, die2);
    }

    int point = roll->roll_value();
    std::cout << "Rolled " << point << " start of point phase\n";
    std::cout << "Roll until " << point << " or a 7 is rolled\n";

    PointPhase point_phase(point);
    roll = shooter.throw_dice(die1, die2);

    while (point_phase.get_outcome(roll) == RollOutcome::nopoint)
    {
        std::cout << "Rolled " << roll->roll_value() << " roll again\n";
        roll = shooter.throw_dice(die1, die2);
    }

    std::cout << "Rolled " << roll->roll_value() << " end of point phase\n\n";

    shooter.display_rolled_values();

    return 0;
}
