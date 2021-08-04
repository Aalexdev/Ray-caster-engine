#ifndef __RCE_COLOR__HPP__
    #define __RCE_COLOR__HPP__

    #include <iostream>
    #include "RCE-begin_code.hpp"

    namespace RCE{
        class Color{
            public:
                Color();
                Color(unsigned char r, unsigned char g, unsigned char b);
                Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
                ~Color();

                unsigned char red(void) const;
                unsigned char green(void) const;
                unsigned char blue(void) const;
                unsigned char alpha(void) const;

                void set_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
                void set_rgb(unsigned char r, unsigned char g, unsigned char b);

                void set_red(unsigned char red);
                void set_green(unsigned char green);
                void set_blue(unsigned char blue);
                void set_alpha(unsigned char alpha);
                
            private:
                unsigned char r, g, b, a;
        };
    }

#endif