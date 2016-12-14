#include "io.h"
#include <cassert>
#include "exception.h"
#include <iostream>

void algorithm (std::vector<point::Point> &p);

int main (int argc, char* argv[]) {
    try {
        if (argc != 4)
            throw e::Exception ("Please, run program as ./spheres rmin rmax distance");
        io::IO_helper helper (argv[1], argv[2], argv[3]);
        auto p = helper.get_points ();
        algorithm (p);
        helper.set_points (p);
        helper.write_points (argv[1], argv[2], argv[3]);
    }
    catch (e::Exception exp) {
        std::cout << exp.what () << std::endl;
    }

    return 0;
}


void algorithm (std::vector<point::Point> &p) {
    for (unsigned i = 0; i < p.size (); i++)
        p[i].set_sphere_id (i);
}