#include <catch2/catch_test_macros.hpp>
#include "../src/bfs.cpp"
#include "../src/bfs.h"
// #include "../src/parseInput.cpp"
// #include "../src/parseInput.h"
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// #include "../src/main.cpp"

#include "bfs.h"

TEST_CASE("Test1", "[valgrind][weight=1]"){
    SECTION("Basic BFS test cases work") {
        BFS test;
        vector<string> vec;
        vec.push_back("ORD");
        vec.push_back("JFK");

        std::map<string, vector<string>> map;
        map["SFO"] = vec;

        vector<string> vec2;
        vec2.push_back("LAX");
        map["ORD"] = vec2;


        vector<string> out = runBFS(map, "SFO");

        vector<string> ans;
        ans.push_back("SFO");
        ans.push_back("ORD");
        ans.push_back("JFK");
        ans.push_back("LAX");

        std::sort(out.begin(), out.end());
        std::sort(ans.begin(), ans.end());

        REQUIRE(out == ans);
    } SECTION("Harder BFS test cases work") {
        std::map<string, vector<string>> map;

        // SFO : {LAX, ORD}
        vector<string> vec;
        vec.push_back("LAX");
        vec.push_back("ORD");
        map["SFO"] = vec;
        // ORD : {LAX, SFO}
        vector<string> vec2;
        vec2.push_back("LAX");
        vec2.push_back("SFO");
        map["ORD"] = vec2;
        // LAX : {JFK, AER, SFO}
        vector<string> vec3;
        vec3.push_back("JFK");
        vec3.push_back("AER");
        vec3.push_back("SFO");
        map["LAX"] = vec3;

        vector<string> out = runBFS(map, "SFO");

        vector<string> ans{"SFO", "LAX", "ORD", "JFK", "AER"};
        std::sort(out.begin(), out.end());
        std::sort(ans.begin(), ans.end());

        //Does not include duplicates into the BFS

        REQUIRE(out == ans);


        // ADX : {ORD}
        vector<string> vec4;
        vec4.push_back("ORD");
        map["ADX"] = vec4;
        
        vector<string> out2 = runBFS(map, "SFO");
        /* one way flights are not included in the bfs. for example, if SFO flies to ORD and 
        ADX flies to ORD then ADX will not be included in the BFS traversal stating at SFO */
        std::sort(out2.begin(), out2.end());
        REQUIRE(out2 == ans);

        // EBZ : {LAS}
        vector<string> vec5;
        vec5.push_back("LAS");
        map["EBZ"] = vec5;

        vector<string> out3 = runBFS(map, "SFO");
        std::sort(out3.begin(), out3.end());

        // Doesn't include aiports that have no key or values related to starting airport
        REQUIRE(out3 == ans);
    }
}
// TEST_CASE("Test2", "[valgrind][weight=1]"){
//     SECTION("Parse data and creates adjancecy list") {
//         parseInput in;

//         map<string, vector<string>> out = parseRoutes("test1.txt");
        
//         for (auto const &pair: out) {
//             std::cout << "{" << pair.first <<  "}\n";
//         }

//     }
// }
