#include "ApplicationBuilder.h"

static ApplicationBuilder application;

void setup()
{
    application.init();
}

void loop()
{
    application.run();
}
