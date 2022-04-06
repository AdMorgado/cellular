// main.cxx

import Layer;
import Application;

int main()
{
    App app;
    Layer* layer = new Layer();
    app.setActiveLayer(layer);
    app.run();
    delete layer;
    return 0;
}