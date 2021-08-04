#ifndef __RCE_ERROR__HPP__
    #define __RCE_ERROR__HPP__

    #include "RCE-begin_code.hpp"

    #include <iostream>

    namespace RCE{
        namespace error{
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
                Error(std::string function, std::string error, std::string reason, error::Type type);
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
                const error::Type type(void) const;

                /**
                 * @brief print the error into the input stream
                 * 
                 */
                void print(std::ostream &stream) const;
            
            private:

                std::string _function;
                std::string _error;
                std::string _reason;
                error::Type _type;
        };
    }

#endif