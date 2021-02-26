/* Filesystem.h
 *
 */

#if !defined FILESYSTEM_H
#define FILESYSTEM_H

const char* GetHomeDir();		//!< Return C-string containing a path to our user's home directory
const char* GetInstallDir();		//!< Return C-string containing a path to our installation directory
const char* GetTmpDir();		//!< Return C-string containing a path to a system-approved temporary storage space

/*
#if defined DEBUG
int Filesystem_Test();			//!< Run tests
#endif //DEBUG
*/

#endif //FILESYSTEM_H
