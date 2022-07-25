
#include "Core/Layer.hpp"
#include "Core/Application.hpp"

extern Layer* getLayer();

int main(int argc, char** argv)
{
    try {
        App app {std::unique_ptr<Layer>(getLayer()) };
        app.run();
    } 
    catch(const std::exception& exc) {
        std::cerr << "An unhandled exception has been caught.\n" << exc.what() << std::endl;
    } 
 
    return 0;
}
