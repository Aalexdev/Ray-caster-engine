g++ -c -D RCE_BUILD_DLL .\src\*.cpp -I .\include\ -o .\.obj\RC-engine.o
g++ -shared -o .\out\RC_engine_lib.dll .\.obj\RC-engine.o -Wl,--out-implib,.\out\libshared_lib.a