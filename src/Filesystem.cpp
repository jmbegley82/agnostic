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
		_strHome = string(getenv("HOME")) + "/";
#elif defined (__CYGWIN__)
		_strHome = string(getenv("USERPROFILE")) + "/";
#elif defined (_MSC_VER)
		char* _strHomeCstr;
		size_t _strHomeCstrLen = 8192;
		_dupenv_s(&_strHomeCstr, &_strHomeCstrLen, "USERPROFILE");
		if (_strHomeCstr) _strHome = _strHomeCstr;
		else _strHome = "(Undefined)";
#else
#error Platform support not written yet!
#endif //platforms
		_homedir = _strHome.c_str();
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
//#warning Platform not detected; using fallback _installdir of current directory during runtime
#if defined (__linux__) || defined (__OpenBSD__) || defined (__MACH__)
		_strInst = string(getenv("PWD")) + "/";
#elif defined (__CYGWIN__)
		_strInst = string(getenv("CD")) + "/";
#elif defined (_MSC_VER)
		char* _installDirCstr;
		size_t _installDirCstrLen = 8192;
		_dupenv_s(&_installDirCstr, &_installDirCstrLen, "CD");
		if (_installDirCstr) _strInst = _installDirCstr;
		else _strInst = "(Undefined)";
#endif //platforms for fallback
#endif //platforms
		_installdir = _strInst.c_str();
	}
	return _installdir;
}

const char* GetTmpDir() {
	if(!_tmpdir) {
#if defined (__linux__) || defined (__OpenBSD__) || defined (__MACH__)
		//_tmpdir = "/tmp";
		_strTemp = string("/tmp/");
#elif defined (__CYGWIN__)
		_strTemp = string(getenv("TEMP"));
#elif defined (_MSC_VER)
		char* _tempDirCstr;
		size_t _tmpDirCstrLen = 8192;
		_dupenv_s(&_tempDirCstr, &_tmpDirCstrLen, "TEMP");
		if (_tempDirCstr) _strTemp = _tempDirCstr;
		else _strTemp = "(Undefined)";
#else
#error Platform support not written yet!
#endif //platforms
		_tmpdir = _strTemp.c_str();
	}
	return _tmpdir;
}
