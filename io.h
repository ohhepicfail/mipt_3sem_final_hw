#ifndef IO_H
#define IO_H

#include <vector>
#include <stdexcept>
#include "point.h"

namespace io {

    class IO_helper {
    private:
        std::vector<point::Point> points_;
    public:
        IO_helper (const char* rmin, const char* rmax, const char* dist);
        IO_helper (const IO_helper &that) : points_ (that.points_) {}
        IO_helper (IO_helper &&that) : points_ (std::move (that.points_)) {}
        ~IO_helper () {}
        IO_helper& operator= (const IO_helper &that);
        IO_helper& operator= (IO_helper &&that) { points_ = std::move (that.points_); return *this;}
        decltype (points_) get_points () const { return points_; }
        void set_points (decltype (points_) p) { points_ = p; }
        void write_points (const char* rmin, const char* rmax, const char* dist);

    };

}



#endif