// The Phi Project
// Copyright 2026 C3PO Authors
// Use of this source code is governed by the GPL-3.0 license, found in the LICENSE file
//
// Date created: 02-05-2026
// Original author: Zevi Berlin (zeviberlin@gmail.com)
// Latest editor: Zevi Berlin (zeviberlin@gmail.com)

#ifndef C3PO_PARSE_HPP
#define C3PO_PARSE_HPP

#include <string>
#include <vector>
#include <limits>

#ifndef C3PO_VECTOR_SEPARATOR
	#define C3PO_VECTOR_SEPARATOR ','
#endif

#ifdef __has_include
#	 if __has_include(<filesystem>)
#    include <filesystem>
#    ifdef __cpp_lib_filesystem
#      define C3PO_FILESYSTEM
#    endif
#  endif
#endif


namespace C3PO {

/// Simplest parse, just a plain string
bool parse_argument(const std::string& arg, std::string* result) {
	*result = arg;
	return true;
}

/// Parse the string into a character
bool parse_argument(const std::string& arg, char* result) {
	*result = (arg.empty() ? 0 : arg[0]);
	return *result != 0;
}


/* NUMBERS */

/// this function is only complex because there is no `std::stos()`
bool parse_argument(const std::string& arg, short* result) {
	long long num = 0;
	try {
		num = std::stoll(arg);
	} catch (...) { // any exceptions
		return false;
	}

	if (num >= std::numeric_limits<short>::max() ||
			num <= std::numeric_limts<short>::min()) return false;

	*result = reinterpret_cast<short>(num);
	return true;
}

bool parse_argument(const std::string& arg, int* result) {
	try {
		*result = std::stoi(arg);
	} catch (...) {
		return false;
	}
	
	return true;
}

bool parse_argument(const std::string& arg, long* result) {
	try {
			*result = std::stol(arg);
	} catch (...) {
		return false;
	}
	
	return true;
}

bool parse_argument(const std::string& arg, long long* result) {
	try {
		*result = std::stoll(arg);
	} catch (...) {
		return false;
	}
	
	return true;
}

bool parse_argument(const std::string& arg, ssize_t* result) {
	try {
		*result = std::reinterpret_cast<ssize_t>(std::stoll(arg));
	} catch (...) {
		return false;
	}
	
	return true;
}

bool parse_argument(const std::string& arg, size_t* result) {
	try {
		*result = std::reinterpret_cast<size_t>(std::stoull(arg));
	} catch (...) {
		return false;
	}
	
	return true;
}

bool parse_argument(const std::string& arg, float* result) {
	try {
			*result = std::stof(arg);
		} catch (...) {
			return false;
		}
		
		return true;
}

bool parse_argument(const std::string& arg, double* result) {
	try {
		*result = std::stod(arg);
	} catch (...) {
		return false;
	}
		
	return true;
}

/* */

bool parse_argument(const std::string& arg, bool* result) {
	if (!arg.empty()) {
		if (arg[0] == 'T' || arg[0] == 't' || arg[0] == 1 || arg[0] == 'Y' || arg[0] == 'y') return true;
		if (arg[0] == 'F' || arg[0] == 'f' || arg[0] == 0 || arg[0] == 'N' || arg[0] == 'n') return false;
	}
	
	return false;
}

/* SPECIALS */

#ifdef C3PO_FILESYSTEM
bool parse_argument(const std::string& arg, std::filesystem::path* result) {
	result->assign(arg);
}
#endif
	
}

#endif /* C3PO_PARSE_HPP */
