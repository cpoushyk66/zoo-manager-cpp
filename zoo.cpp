

#include "Animal.h"
#include <iostream>

using namespace class1020;

int main( int argc, char** argv )
{
/*
 * Currently this main function has hardwired values for
 * the numbers of tigers, hyenas, possums, and chickens.
 * Modify it so that these numbers are entered on the command
 * line.  For example, the command line should work line this:
 *
 *     ./zoo 3 2 10 10
 *
 *  to reproduce the hardwired values.  Hint: the C function
 *  atoi(char*) is a handy tool for converting a text string
 *  to an integer value.
 */
//                     tigers,         hyenas,        possums,        chickens
    Animal* zoo = Zoo(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

    ShowTheZoo();

    for( int i=0;i<15;i++ )
    {
        std::cout << "\t\tYEAR " << i << std::endl;
        std::cout << "Spawning Cycle \n";
        SpawningCycle(zoo);
        std::cout << "Feeding Cycle \n";
        FeedingCycle(zoo);
        std::cout << "Aging Cycle \n";
        zoo = AgingCycle(zoo);
        ShowTheZoo();	
    }

    CleanTheZoo(zoo);

    std::cout << "Terminated normally" << std::endl;
    return 0;

}
