
#include "Core/Layer.hpp"
#include "Core/Application.hpp"

extern Layer* getLayer();

int main(int argc, char** argv)
{
    App app;
    app.setActiveLayer(getLayer());
    app.run();

    return 0;
}
