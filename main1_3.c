#include "hello_Ariel.h"
#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <stddef.h>

void (*hello_message)();

bool init_library(){
    void* hdl = dlopen("./libHello.so",RTLD_LAZY);
    if(hdl == NULL)return false;
    hello_message =(void(*)())dlsym(hdl,"printHello");
    if(hello_message== NULL) return false;
    return true;
}

int main(){
    if(init_library())
    {
        hello_message();
    }
    else
    {
        printf("Library was not loaded \n");
    }
    return 0;
}
