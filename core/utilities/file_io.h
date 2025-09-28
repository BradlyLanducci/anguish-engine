#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <glog/logging.h>

namespace FileIO
{
	static inline std::string toString(std::string path)
	{
		std::stringstream buffer;
		std::string data{""};
		std::ifstream file(path);
		if (file.is_open())
		{
			buffer << file.rdbuf();
		}
		else
		{
			LOG(WARNING) << "Failed to load " << path;
		}
		return buffer.str();
	}
}
