#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

namespace e {
    class Exception : public std::exception
    {
    public:
        Exception (const char *str) throw () : err_msg_ (str) {}
        virtual ~Exception () throw () {}
        virtual const char *what () { return err_msg_;  }
    private:
        const char* err_msg_;
    };
}


#endif
