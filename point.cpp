#include "point.h"
#include "exception.h"

namespace point {

    int Point::operator[] (int idx) { 
        switch (idx) { 
            case 0: return pnumber_; 
            case 1: return x_; 
            case 2: return y_; 
            case 3: return z_; 
            case 4: return sphere_id_;
            default: throw e::Exception ("out of range");
        } 
    }

}