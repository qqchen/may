#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H
#include "../third/jsoncpp/include/json/json.h"
#include <fstream>
#include <vector>
#include <string>

class Serializable
{
public:
	virtual Json::Value serialize() = 0;
	virtual bool deserialize(Json::Value root) = 0;
};

class JsonObject : public Serializable
{
public:
	JsonObject()
	{
		m_empty = true;
		init_keys();
	}

	virtual std::string to_json_string()
	{
		Json::Value root = serialize();
		std::string json_string = writer.write(root);
		return json_string;
	}

	virtual void write(std::string& file)
	{
		std::string json_string = to_json_string();
		std::ofstream ofs;
		ofs.open(file);
		if (ofs.is_open())
		{
			ofs << json_string;
		}
		ofs.close();
	}

	virtual bool read(std::string& file)
	{
		std::ifstream ifs;
		ifs.open(file);
		Json::Value root;
		bool res = false;
		if (reader.parse(ifs, root, false))
		{
			res = deserialize(root);
		}
		ifs.close();
		return res;
	}

	virtual bool read_document(std::string& document)
	{
		Json::Value root;
		bool res = false;
		if (reader.parse(document, root, false))
		{
			res = deserialize(root);
		}
		return res;
	}

	virtual void init_keys() {}

	virtual bool parse_error(Json::Value root)
	{
		bool error = false;
		for (size_t i = 0; i < m_keys.size(); ++i)
		{
			if (root[m_keys[i]].isNull())
			{
				error = true;
				break;
			}
		}
		return error;
	};

	bool is_empty()
	{
		return m_empty;
	}

protected:
	Json::FastWriter writer;
	Json::Reader reader;
	std::vector<std::string> m_keys;
	bool m_empty;
};


#endif
