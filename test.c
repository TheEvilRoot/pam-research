#include <stdio.h>
#define _TEST
#include "api.h"

#include <unistd.h>
#include <dlfcn.h>
#include <errno.h>


int main() {
	printf("%p\n", dlopen("/lib/x86_64-linux-gnu/security/libevilauth.so", RTLD_NOW));
	printf("%s\n", dlerror());
	return req_auth("auth", "admin", "admin");
}
