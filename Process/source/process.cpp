//
// Created by ionik on 09.09.2024.
//
#include <string>
#include "process.h"
#include "Part.h"


std::string process::structToString(const Part& part) {
    std::string result = "{\n  \"id\": \"" + part.id +
                    "\",\n  \"name\": \"" + part.name +
                    "\",\n  \"count\": " + std::to_string(part.count) + "\n}";

    return result;
}


std::string f(const std::string& json, std::string::size_type& start, const std::string& field) {
    using string_size = std::string::size_type;
    string_size end = start;

    if(field == "id") {
        start = json.find_first_not_of(' ', start);
        if(json[start] != '{' or start == std::string::npos)
            throw std::runtime_error(R"(stringToStruct: '{' not found)");
    }

    start = json.find_first_not_of(' ', start + 1);
    if(json[start] != '\"' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '"' not found (1))");
    end = json.find('\"', start + 1);
    if(json[end] != '\"' or end == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '"' not found (2))");
    if(json.substr(start + 1, end - start - 1) != field)
        throw std::runtime_error("stringToStruct: \"" + field + "\" not found)");
    start = json.find_first_not_of(' ', end + 1);
    if(json[start] != ':' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: ":" not found)");
    start = json.find_first_not_of(' ', start + 1);

    if(field == "id" or field == "name") {
        if(json[start] != '\"' or start == std::string::npos)
            throw std::runtime_error(R"(stringToStruct: '"' not found (3))");
        end = json.find('\"', start + 1);
        if(end == std::string::npos)
            throw std::runtime_error(R"(stringToStruct: unexpected end of string ('"' (4)))");
        std::string _idOrName = json.substr(start + 1, end - start - 1);
        if (field == "id" and _idOrName.length() != 8) // если это id
            throw std::runtime_error("stringToStruct: incorrect \"" + field + "\"");
        start = json.find_first_not_of(' ', end + 1);
        if(json[start] != ',' or start == std::string::npos)
            throw std::runtime_error(R"(stringToStruct: ',' not found)");

        return _idOrName;
    }
    else if(field == "count") {
        end = json.find('}', start);
        if(end == std::string::npos)
            throw std::runtime_error(R"(stringToStruct: '}' not found)");
        std::string _sCount = json.substr(start, end - start);
        long _lCount = std::stol(_sCount);
        if(_lCount < 0)
            throw std::runtime_error(R"(stringToStruct: count < 0)");

        return _sCount;
    }
    else
        throw std::runtime_error(R"(stringToStruct->f: invalid field)");
}


Part process::stringToStruct(const std::string& json) { // {"id": "qawsedrf", "name": "det", "count": 5}
    using string_size = std::string::size_type;
    string_size start = 0, end = 0;

    start = json.find_first_not_of(' ', start);
    if(json[start] != '{' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '{' not found)");

    Part p;
    p.id = f(json, start, "id");
    p.name = f(json, start, "name");
    p.count = static_cast<unsigned int>(std::stol(f(json, start, "count")));

    return p;
}


/*
Part process::stringToStruct(const std::string& json) { // {"id": "qawsedrf", "name": "det", "count": 5}
    using string_size = std::string::size_type;
    string_size start = 0, end = 0;

    start = json.find_first_not_of(' ', start);
    if(json[start] != '{' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '{' not found)");

    start = json.find_first_not_of(' ', start + 1);
    if(json[start] != '\"' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '"' not found (1))");
    end = json.find('\"', start + 1);
    if(json[end] != '\"' or end == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '"' not found (2))");
    if(json.substr(start + 1, end - start - 1) != "id")
        throw std::runtime_error(R"(stringToStruct: "id" not found)");
    start = json.find_first_not_of(' ', end + 1);
    if(json[start] != ':' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: ":" not found)");
    start = json.find_first_not_of(' ', start + 1);
    if(json[start] != '"' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '"' not found (3))");
    end = json.find('\"', start + 1); // как эту кавычку проверять?
    if(end == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: unexpected end of string ('"' (4)))");
    std::string _id = json.substr(start + 1, end - start - 1);
    if(_id.length() != 8)
        throw std::runtime_error(R"(stringToStruct: incorrect "id")");
    start = json.find_first_not_of(' ', end + 1);
    if(json[start] != ',' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: ',' not found)");

    start = json.find_first_not_of(' ', start + 1);
    if(json[start] != '\"' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '"' not found (5))");
    end = json.find('\"', start + 1);
    if(json[end] != '\"' or end == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '"' not found (6))");
    if(json.substr(start + 1, end - start - 1) != "name")
        throw std::runtime_error(R"(stringToStruct: "name" not found)");
    start = json.find_first_not_of(' ', end + 1);
    if(json[start] != ':' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: ':' not found)");
    start = json.find_first_not_of(' ', start + 1);
    if(json[start] != '"' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '"' not found (7))");
    end = json.find('\"', start + 1); // как эту кавычку проверять?
    if(end == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: unexpected end of string ('"' (8)))");
    std::string _name = json.substr(start + 1, end - start - 1);
    start = json.find_first_not_of(' ', end + 1);
    if(json[start] != ',' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: ',' not found)");

    start = json.find_first_not_of(' ', start + 1);
    if(json[start] != '\"' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '"' not found (9))");
    end = json.find('\"', start + 1);
    if(json[end] != '\"' or end == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '"' not found (10))");
    if(json.substr(start + 1, end - start - 1) != "count")
        throw std::runtime_error(R"(stringToStruct: "count" not found)");
    start = json.find_first_not_of(' ', end + 1);
    if(json[start] != ':' or start == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: ":" not found)");
    end = json.find('}', start);
    if(end == std::string::npos)
        throw std::runtime_error(R"(stringToStruct: '}' not found)");
    std::string _sCount = json.substr(start + 1, end - start - 1);
    long _lCount = std::stol(_sCount);
    if(_lCount < 0)
        throw std::runtime_error(R"(stringToStruct: count < 0)");

    Part p;
    p.id = _id;
    p.name = _name;
    p.count = static_cast<unsigned int>(_lCount);

    return p;
}
 */