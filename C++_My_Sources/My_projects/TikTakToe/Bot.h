#ifndef BOT_H_INCLUDED
#define BOT_H_INCLUDED

#include "Tree.h"
#include "TreeInt.h"

using namespace std;

void mainloop();



void mainloop()
{
    GAME g;
    bool i = 0;
    while (g.check_for_endgame() == '0')
    {
        if (i == 0) ;//<- X
        else ;//<- Y
        ++i;
    }
}



#endif // BOT_H_INCLUDED
