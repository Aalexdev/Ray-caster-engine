#ifndef __RC_ENGINE_HPP__
    #define __RC_ENGINE_HPP__

    #include "RCE-begin_code.hpp"
    #include <iostream>
    #include <list>
    #include <fstream>
    #include <functional>

    #include "RCE-Keypad.hpp"
    #include "RCE-Mouse.hpp"
    #include "RCE-Error.hpp"
    #include "RCE-Version.hpp"
    #include "RCE-Color.hpp"

    namespace RCE{

        enum DBG_level{
            DBG_level_1,
            DBG_level_2,
            DBG_level_3,
            DBG_level_4
        };

        #define RCE_DBG_LEVEL_MAX RCE::DBG_level::DBG_level_4
        #define RCE_DBG_LEVEL_MIN RCE::DBG_level::DBG_level_1
    }

    class RC_Engine{
        public:
            RC_Engine();
            ~RC_Engine();
            
            /**
             * @brief init RC engine library
             * @return true on sucess, false otherwise
             */
            bool init(void);
            
            /**
             * @brief quit the RC engine library
             */
            void quit(void);

            /**
             * @brief start the engine mainloop
             */
            void run(void);

            /**
             * @brief get the last occurred error
             * @return return a pointer to the last error
             */
            RCE::Error* get_error(void);

            /**
             * @brief get the last occured error and supressing it from the error handler
             * @return return an error instance
             */
            RCE::Error pop_error(void);

            /**
             * @brief print the last occured error in the stream withou supressing it
             * @param stream the stream where the error will be printed
             */
            void print_error(std::ostream stream);

            /**
             * @brief get the number of errors in the error handler
             * @return the size of the error list
             */
            const int get_errors_size(void) const;

            /**
             * @brief get if the error list is not empty
             * @return true if the error list size is greater than 0, false if it's equal 
             */
            bool is_error(void) const;

            /**
             * @brief set the function who is call every ticks
             * @param fnc the function
             */
            void set_Ontick(std::function<void(const int)> fnc);

            /**
             * @brief set the clear color of the window
             * 
             * @param r the red channel
             * @param g the green channel
             * @param b the blue channel
             */
            void set_clear_color(unsigned char r, unsigned char g, unsigned char b);

        private:
            void *window;
            void *target;

            bool init_SDL2_ttf(void);
            bool init_SDL2_image(void);
            bool init_SDL2_mixer(void);
            bool init_SDL2_gpu(void);
            bool init_SDL2_window(void);

            void quit_SDL2_ttf(void);
            void quit_SDL2_image(void);
            void quit_SDL2_mixer(void);
            void quit_SDL2_gpu(void);
            void quit_SDL2(void);

            bool is_ttf_init;
            bool is_image_init;
            bool is_mixer_init;
            bool is_gpu_init;
            bool is_window_init;

            void reset_init(void);

            void destroy_target(void);
            void destroy_window(void);

            std::list<RCE::Error> errors;
            RCE::DBG_level dbg_level;

            bool running;

            RCE::events::Keypad keypad;
            RCE::events::Mouse mouse;

            void event(void);
            void update(void);
            void clear(void);
            void flip(void);

            std::function<void(const int)> OnTick;

            RCE::Color clear_color;
    };

#endif