#include "measure.h"

static char cpm = 0;

void init_measure()
{

}
void measure_update()
{
    cpm++;
}
char measure_data()
{
    return cpm;
}