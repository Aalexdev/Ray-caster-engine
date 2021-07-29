#ifndef __RC_ENGINE_HPP__
    #define __RC_ENGINE_HPP__

    #include <iostream>
    #include <string>

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

    namespace RCE{
        extern DECLSPEC void RCECALL test(void);
    };

#endif