
#include "Core/Layer.hpp"
#include "Core/Application.hpp"

extern Layer* getLayer();

int main(int argc, char** argv)
{
    try {
        App app;

        Layer* layer = getLayer();

        app.setActiveLayer(layer);
        app.run();
        delete layer;
    } 
    catch(const std::exception& exc) {
        std::cerr << "An unhandled exception has been caught.\n" << exc.what() << std::endl;
    } 
 
    return 0;
}
