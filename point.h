#ifndef POINT_H
#define POINT_H

namespace point {

    class Point {
    private:
        int pnumber_ = 0;
        int x_ = 0
          , y_ = 0
          , z_ = 0;
        int sphere_id_ = -1;
    public:
        Point (int number, int x, int y, int z) : pnumber_ (number), x_ (x), y_ (y), z_ (z) {}
        ~Point () {}
        Point (const Point &that) = default;
        Point (Point &&that) = default;
        Point& operator= (const Point &that) = default;
        Point& operator= (Point &&that) = default;

        int operator[] (int idx);
        void set_sphere_id (int n) { sphere_id_ = n; }
    };

}



#endif
