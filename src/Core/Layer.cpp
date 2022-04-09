export module cell.core.layer;

import <iostream>;

export
class Layer
{
public:

    virtual void update() 
    {
        std::cout << "Hello world!\n";
    }

private:

};
