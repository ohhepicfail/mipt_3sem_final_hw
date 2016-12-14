#include "io.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include "exception.h"

namespace io {

    IO_helper& IO_helper::operator= (const IO_helper &that) { 
        if (this == &that)
            return *this;

        IO_helper tmp (that); 
        *this = std::move (tmp);
        return *this;
    }

    IO_helper::IO_helper (const char* rmin, const char* rmax, const char* dist) {
        using namespace std;
        using namespace point;

        ifstream f;

        string filename = string (rmin) + "-" + string(rmax) + "_" + string(dist) + ".csv";
        f.open (filename);
        if (!f.is_open ())
            throw e::Exception ("cannot open the file");

        char line[256];
        f.getline (line, 256);
        while (1) {
            int number;
            int p[3];
            f.getline (line, 256);
            if (f.eof())
                break;
            sscanf (line, "%d;%d;%d;%d", &number, &p[0], &p[1], &p[2]);
            points_.push_back (Point (number, p[0], p[1], p[2]));
        }
        f.close ();
    }


    void IO_helper::write_points (const char* rmin, const char* rmax, const char* dist) {
        using namespace std;

        ofstream f;

        string filename = string (rmin) + "-" + string(rmax) + "_" + string(dist) + "result" + ".csv";
        f.open (filename);
        if (!f.is_open ())
            throw e::Exception ("cannot open the file");

        for (unsigned i = 0; i < points_.size (); i++)
            f << points_[i][0] << ";" << points_[i][1] << ";" << points_[i][2] << ";" << points_[i][3] << ";" << points_[i][4] << std::endl;

        f.close ();
    }



}