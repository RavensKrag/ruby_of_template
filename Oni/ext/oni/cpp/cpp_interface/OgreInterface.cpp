#include "OgreInterface.h"

// General Ruby-class non-specific functions here

extern "C" {
    void Ogre_cpp_test(){
        std::cout << "testing c++ level call" << std::endl;
    }
}
