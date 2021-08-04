#include "RCE-Version.hpp"

using namespace RCE;

void version::GetVersion(RCE_Version *v){

    // check the validity of the version ptr
    if (!v) return;

    v->major = RCE_VERSION_MAJOR;
    v->minor = RCE_VERSION_MINOR;
    v->patch = RCE_VERSION_PATCH;
}