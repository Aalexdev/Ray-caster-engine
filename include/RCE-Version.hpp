#ifndef __RCE_VERSION__HPP__
    #define __RCE_VERSION__HPP__

    #include "RCE-begin_code.hpp"

    #define RCE_VERSION_MAJOR 0
    #define RCE_VERSION_MINOR 1
    #define RCE_VERSION_PATCH 0

    namespace RCE{
        namespace version{
            
            struct RCE_Version{
                int major;
                int minor;
                int patch;
            };

            void GetVersion(RCE_Version *v);

            #define RCE_GetVersio(x) RCE::version::GetVersion(x);
        }
    }

#endif