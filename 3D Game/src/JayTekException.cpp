#include "JayTekException.h"
#include <sstream>

JayTekException::JayTekException(int line, const char* file) noexcept : line(line), file(file) {}

const char* JayTekException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* JayTekException::GetType() const noexcept
{
	return "JayTek Exception";
}

int JayTekException::GetLine() const noexcept
{
	return line;
}

const std::string& JayTekException::GetFile() const noexcept
{
	return file;
}

std::string JayTekException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl << "[Line] " << line;
	return oss.str();
}