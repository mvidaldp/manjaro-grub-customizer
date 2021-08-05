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
#ifndef ENTRY_PATH_BUILDER_INCLUDED
#define ENTRY_PATH_BUILDER_INCLUDED
#include <string>
#include <list>
#include <memory>
#include "../Model/Entry.hpp"

class Model_EntryPathBilder {
public:
	virtual inline ~Model_EntryPathBilder() {};

	virtual std::list<std::string> buildPath(std::shared_ptr<Model_Entry> entry) const =0;
	virtual std::string buildPathString(std::shared_ptr<Model_Entry> entry, bool withOtherEntriesPlaceholder = false) const =0;
	virtual std::string buildScriptPath(std::shared_ptr<Model_Entry> entry) const =0;
};

#endif
