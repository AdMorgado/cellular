// main.cxx

import Layer;
import Application;

int main()
{
    App app;
    Layer layer;
    app.setActiveLayer(&layer);
    app.run();
    return 0;
}