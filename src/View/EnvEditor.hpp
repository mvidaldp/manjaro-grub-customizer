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
#ifndef GRUBENVEDITOR_H_
#define GRUBENVEDITOR_H_
#include <map>
#include <functional>

#include "../lib/Trait/LoggerAware.hpp"
#include "../Model/DeviceDataListInterface.hpp"

class View_EnvEditor :
	public Trait_LoggerAware,
	public Model_DeviceDataListInterface_Connection
{
public:
	virtual inline ~View_EnvEditor() {};

	std::function<void (std::string const& submountpoint)> onMountSubmountpointClick;
	std::function<void (std::string const& submountpoint)> onUmountSubmountpointClick;
	std::function<void (std::string const& newPartition)> onSwitchPartition;
	std::function<void (int newTypeIndex)> onSwitchBootloaderType;
	std::function<void ()> onOptionChange;
	std::function<void (bool saveConfig)> onApplyClick;
	std::function<void ()> onExitClick;

	enum MountExceptionType {
		MOUNT_FAILED,
		UMOUNT_FAILED,
		MOUNT_ERR_NO_FSTAB,
		SUB_MOUNT_FAILED,
		SUB_UMOUNT_FAILED
	};
	virtual void show(bool resetPartitionChooser = false) = 0;
	virtual void hide() = 0;
	virtual void removeAllSubmountpoints() = 0;
	virtual void addSubmountpoint(std::string const& name, bool isActive) = 0;
	virtual void setEnvSettings(std::map<std::string, std::string> const& props, std::list<std::string> const& requiredProps, std::list<std::string> const& validProps) = 0;
	virtual std::map<std::string, std::string> getEnvSettings() = 0;
	virtual void setRootDeviceName(std::string const& rootDeviceName) = 0;
	virtual int getBootloaderType() const = 0;
	virtual void setSubmountpointSelectionState(std::string const& submountpoint, bool new_isSelected) = 0;
	virtual void showErrorMessage(MountExceptionType type)=0;
};

#endif /* GRUBENVEDITOR_H_ */
