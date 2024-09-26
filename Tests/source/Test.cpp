//
// Created by ionik on 18.09.2024.
//

#include <iostream>
#include <format>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "Part.h"
#include "process.h"

TEST_CASE("TEST_STRUCT_TO_STRING") {
    Part p = create("zxrtyhjm", "detail1", 54);
    SECTION("CHECK_CORRECT_INPUT") {
        CHECK(process::structToString(p) == "{\n  \"id\": \"zxrtyhjm\",\n  \"name\": \"detail1\",\n  \"count\": 54\n}");
    }
}

TEST_CASE("TEST_STRING_TO_STRUCT") {
    Part p;
    SECTION("CHECK_CORRECT_INPUT") {
        Part part;
        part.id = "rtfgvbyu";
        part.name = "detail2";
        part.count = 54;
        Part part2 = process::stringToStruct(R"({"id":"rtfgvbyu","name":"detail2","count":54})");
        CHECK(compare(part, part2) == true);

        CHECK_THROWS(p = process::stringToStruct(""));

        CHECK_THROWS(p = process::stringToStruct(R"("id":"rtfgvbyu","name":"detail2","count":54})"));

        CHECK_THROWS(p = process::stringToStruct(R"({id":"rtfgvbyu","name":"detail2","count":54})"));

        CHECK_THROWS(p = process::stringToStruct(R"({"":"rtfgvbyu","name":"detail2","count":54})"));

        CHECK_THROWS(p = process::stringToStruct(R"({"id""rtfgvbyu","name":"detail2","count":54})"));

        CHECK_THROWS(p = process::stringToStruct(R"({"id":"rtfu","name":"detail2","count":54})"));

        CHECK_THROWS(p = process::stringToStruct(R"({"id":"rtfgvby)"));

        CHECK_THROWS(p = process::stringToStruct(R"({"id":"rtfgvbyu""name":"detail2","count":54})"));

        part.name = "";
        part2 = process::stringToStruct(R"({"id":"rtfgvbyu","name":"","count":54})");
        CHECK(compare(part, part2) == true);

        CHECK_THROWS(p = process::stringToStruct(R"({"id":"rtfgvbyu","name":"detail2","":54})"));

        CHECK_THROWS(p = process::stringToStruct(R"({"id":"rtfgvbyu","name":"detail2","count":dfgh})"));
    }
}

