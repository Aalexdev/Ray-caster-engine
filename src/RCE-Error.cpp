#include "RCE-Error.hpp"

using namespace RCE;

Error::Error(){
    _function = "unlnown";
    _error = "none";
    _reason = "none";
    _type = error::ERR_invalid_error; 
}

Error::Error(std::string function, std::string error, std::string reason, error::Type type){
    _function = function;
    _error = error;
    _reason = reason;
    _type = type;
}

Error::~Error(){}

const std::string Error::function(void) const{
    return _function;
}

const std::string Error::func(void) const{
    return function();
}

const std::string Error::error(void) const{
    return _error;
}

const std::string Error::err(void) const{
    return error();
}

const std::string Error::reason(void) const{
    return _reason;
}

const std::string Error::what(void) const{
    return reason();
}

const std::string Error::why(void) const{
    return reason();
}

const error::Type Error::type(void) const{
    return _type;
}

void Error::print(std::ostream &stream) const{
    stream << "ERROR :: in \"" << function() << "\" : error id : " << type() << std::endl;
    stream << "\t" << error() << " : " << reason() << std::endl;
    stream << std::endl;
}