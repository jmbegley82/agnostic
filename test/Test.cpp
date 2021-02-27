#include <string>
#include <iostream>
#include "Filesystem.h"
#include "Timing.h"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
	cout << "Begin Filesystem test:" << endl;
	cout << "GetHomeDir returns: " << string(GetHomeDir()) << endl;
	cout << "GetInstallDir returns: " << string(GetInstallDir()) << endl;
	cout << "GetTmpDir returns: " << string(GetTmpDir()) <<endl;
	cout << endl;
	cout << "Begin Timing test:" << endl;
	cout << "GetTimeInMsec returns: " << GetTimeInMsec() << endl;
	cout << "Attempting to wait 1000msec..." << endl;
	SleepMsec(1000);
	cout << "GetTimeInMsec returns: " << GetTimeInMsec() << endl;
	return 0;
}
