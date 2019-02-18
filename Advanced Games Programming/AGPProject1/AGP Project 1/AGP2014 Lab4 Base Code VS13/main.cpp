#if _DEBUG
#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

#include "Lights.h"

using namespace std;

// Program entry point - SDL manages the actual WinMain entry point for us
int main(int argc, char *argv[]) {
  
	Lights app;

	app.init();
	app.run();
	app.~Lights();
    
    return 0;
}