#ifndef __RC_ENGINE_HPP__
    #define __RC_ENGINE_HPP__

    #ifdef RCE_BUILD_DLL
        #define DECLSPEC __declspec(dllexport)
    #else
        #define DECLSPEC __declspec(dllimport)
    #endif

    #ifndef RCECALL
        #if (defined(__WIN32__) || defined(__WINRT__)) && !defined(__GNUC__)
            #define RCECALL __cdecl

        #elif defined(__OS2__) || defined(__EMX__)
            #define RCECALL _System

            #if defined (__GNUC__) && !defined(_System)
                #define _System /* for old EMX/GCC compat.  */
                
            #endif
        #else
            #define RCECALL
        #endif
    #endif

    #include <iostream>
    #include <list>
    #include <fstream>

    namespace RCE{
        namespace err{
            enum Type{
                ERR_invalid_error,
                // libs init
                ERR_SDL2_image_init,
                ERR_SDL2_ttf_init,
                ERR_SDL2_mixer_init,
                ERR_SDL2_gpu_init,
                ERR_SDL2_window_init,

                ERR_SDL2_CreateWindow
            };

            /**
             * @brief convert an error type into a string error
             * 
             * @param type the error type
             * @return std::string 
             */
            extern DECLSPEC RCECALL std::string typeToErr(Type type);
        }
        class Error{
            public:

                Error();
                Error(std::string function, std::string error, std::string reason, err::Type type);
                ~Error();

                /**
                 * @brief return the function where the error happened
                 * @return the name of the faulty function
                 */
                const std::string function(void) const;

                /**
                 * @brief return the function where the error happened
                 * @return the name of the faulty function
                 * @sa function
                 */
                const std::string func(void) const;

                /**
                 * @brief get the error details
                 * @return return precisions about the error
                 */
                const std::string error(void) const;

                /**
                 * @brief get the error details
                 * @return return precisions about the error
                 * @sa error
                 */
                const std::string err(void) const;

                /**
                 * @brief get the reason of the error
                 * @return return the reason of return
                 */
                const std::string reason(void) const;

                /**
                 * @brief get the reason of the error
                 * @return return the reason of return
                 * @sa reason
                 */
                const std::string what(void) const;

                /**
                 * @brief get the reason of the error
                 * @return return the reason of return
                 * @sa reason
                 */
                const std::string why(void) const;

                /**
                 * @brief get the type of error
                 * @return return the type of the error
                 */
                const err::Type type(void) const;

                /**
                 * @brief print the error into the input stream
                 * 
                 */
                void print(std::ostream &stream) const;
            
            private:

                std::string _function;
                std::string _error;
                std::string _reason;
                err::Type _type;
        };

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
             * 
             * @return true on sucess, false otherwise
             */
            bool init(void);
            
            /**
             * @brief quit the RC engine library
             * 
             */
            void quit(void);
        
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
    };

    


#endif