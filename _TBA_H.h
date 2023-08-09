#ifndef _TBA_H
#define _TBA_H

#include <string>

#define UTF8_encoded_file	1						//Indicates that the source file is encoded in utf8 
													//(1 if yes, and 0 if no (i.e. if the file encoding is in ANSI)).

#if defined (_WIN32) && UTF8_encoded_file
#include <windows.h>
#include <vector>
#define _TBA UTF8_to_CP1251

std::string UTF8_to_CP1251(const std::string&);

#else
#define _TBA
#endif

#endif
