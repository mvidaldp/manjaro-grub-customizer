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
#ifndef GRUB_INSTALLER_INCLUDED
#define GRUB_INSTALLER_INCLUDED
#include <string>
#include <cstdio>
#include <functional>
#include "../lib/Trait/LoggerAware.hpp"
#include "Env.hpp"

class Model_Installer :
	public Trait_LoggerAware,
	public Model_Env_Connection
{
	std::string install_result;
public:
	std::function<void (std::string const& msg)> onFinish;

	void threadable_install(std::string const& device) {
		this->install_result = this->install(device);
		if (this->onFinish) {
			this->onFinish(this->install_result);
		}
	}

	std::string install(std::string const& device) {
		FILE* install_proc = popen((this->env->install_cmd+" '"+device+"' 2>&1").c_str(), "r");
		std::string output;
		int c;
		while ((c = fgetc(install_proc)) != EOF){
			output += c;
		}
		int success = pclose(install_proc);
		if (success == 0)
			return ""; //empty return string = no error
		else
			return output;
	}

};

class Model_Installer_Connection
{
	protected: std::shared_ptr<Model_Installer> installer;

	public: virtual ~Model_Installer_Connection(){}

	public: void setInstaller(std::shared_ptr<Model_Installer> installer)
	{
		this->installer = installer;

		this->initInstallerEvents();
	}

	public: virtual void initInstallerEvents()
	{
		// override to initialize specific view events
	}
};

#endif
