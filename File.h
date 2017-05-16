#ifndef _File
#define _File
#include<string>


class File
{
public:
	File() {}
	File(std::string address, std::string name) : m_address(address),m_name(name) {}
	virtual ~File() {}

	virtual std::string  GetName() = 0;
	virtual std::string  GetAddress() = 0;
	virtual std::string  GetPath() = 0;

protected:
	std::string m_name;
	std::string m_address;
};


class InputFile : public File
{
public:
	InputFile(){}
	InputFile(std::string address, std::string name) : File(address, name) {}

	std::string  GetName() override
	{
		return m_name;
	}
	std::string  GetAddress() override
	{
		return m_address;
	}
	std::string  GetPath() override
	{
		return m_address + "\\" + m_name;
	}
private:
};


class OutFile : public File
{
public:
	OutFile() {}
	OutFile(std::string address, std::string name) : File(address,name),m_flag(false) {}


	std::string  GetName() override
	{
		return m_name;
	}
	std::string  GetAddress() override
	{
		return m_address;
	}
	std::string  GetPath() override
	{
		return m_address + "\\" + m_name;
	}

	std::string  GetCommand()
	{
		return m_command;
	}
	void SetCommand(std::string command)
	{
		m_command = command;
	}


	bool GetFlag()
	{
		return m_flag;
	}
	void SetFlag(bool flag)
	{
		m_flag = flag;
	}


private:
	std::string m_command;
	bool m_flag;
};

#endif