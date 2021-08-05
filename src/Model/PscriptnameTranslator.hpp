/*
 * Copyright (C) 2010-2011 Daniel Richter <danielrichter2007@web.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * 
 * Additional permission under GNU GPL version 3 section 7
 *
 * If you modify this program, or any covered work, by linking or combining
 * it with the OpenSSL library (or a modified version of that library),
 * containing parts covered by the terms of the OpenSSL license, the licensors
 * of this program grant you additional permission to convey the resulting work.
 * Corresponding source for a non-source form of such a combination shall include
 * the source code for the parts of the OpenSSL library used as well as that of
 * the covered work.
 */
#ifndef PSCRIPTNAME_TRANSLATOR_INCLUDED
#define PSCRIPTNAME_TRANSLATOR_INCLUDED

#include <string>
#include <sstream>

class Model_PscriptnameTranslator {
public:
	static std::string decode(std::string const& input) {
		std::string result = input;
		int last_nonnum_pos = input.find_last_not_of("0123456789");
		if (last_nonnum_pos != -1 && result[last_nonnum_pos] == '~' && last_nonnum_pos != input.length()-1)
			result = result.substr(0, last_nonnum_pos);
		return result;
	}

	static std::string encode(std::string const& input, int x) {
		std::ostringstream out;
		out << input;
		int last_nonnum_pos = input.find_last_not_of("0123456789");
		if (x != 0 || ((last_nonnum_pos != -1 && input[last_nonnum_pos] == '~') && last_nonnum_pos != input.length()-1))
			out << "~" << x;
		return out.str();
	}

};

#endif
