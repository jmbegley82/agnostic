/* Filesystem.c
 *
 */

#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>
#include "Filesystem.h"

using std::string;

#if defined DEBUGEXTRA
#include "Logger.h"
#endif //DEBUGEXTRA

const char* _homedir = 0;
const char* _installdir = 0;
const char* _tmpdir = 0;

string _strHome = "";
string _strInst = "";
string _strTemp = "";

const char* GetHomeDir() {
	if(!_homedir) { 
#if defined (__linux__) || defined (__OpenBSD__) || defined (__MACH__)
		//_homedir = getenv("HOME");
		_strHome = string(getenv("HOME")) + "/";
		_homedir = _strHome.c_str();
#else
#error Platform support not written yet!
#endif //platforms
	}
	return _homedir;
}

const char* GetInstallDir() {
	if(!_installdir) {
/*
#if defined NOINSTALL
		//_installdir = getenv("PWD");
		_strInst = string(getenv("PWD")) + "/";
		_installdir = _strInst.c_str();
#else
#error Platform support not written yet!
#endif //NOINSTALL
*/
#if defined __SOME_PLATFORM_THAT_TOTALLY_EXISTS
#else
#warning Platform not detected; using fallback _installdir of whatever $PWD is during runtime
		_strInst = string(getenv("PWD")) + "/";
		_installdir = _strInst.c_str();
#endif //platforms
	}
	return _installdir;
}

const char* GetTmpDir() {
	if(!_tmpdir) {
#if defined (__linux__) || defined (__OpenBSD__) || defined (__MACH__)
		//_tmpdir = "/tmp";
		_strTemp = string("/tmp/");
		_tmpdir = _strTemp.c_str();
#else
#error Platform support not written yet!
#endif //platforms
	}
	return _tmpdir;
}
