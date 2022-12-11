#include <catch2/catch_test_macros.hpp>
#include "../src/bfs.cpp"
#include "../src/bfs.h"
#include "../src/parseInput.cpp"
#include "../src/parseInput.h"
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// #include "../src/main.cpp"

#include "bfs.h"

TEST_CASE("Test1 BFS", "[valgrind][weight=1]"){
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


        vector<string> out = test.runBFS(map, "SFO");

        vector<string> ans;
        ans.push_back("SFO");
        ans.push_back("ORD");
        ans.push_back("JFK");
        ans.push_back("LAX");

        std::sort(out.begin(), out.end());
        std::sort(ans.begin(), ans.end());

        REQUIRE(out == ans);
    } SECTION("Harder BFS test cases work") {
        BFS test;

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

        vector<string> out = test.runBFS(map, "SFO");

        vector<string> ans{"SFO", "LAX", "ORD", "JFK", "AER"};
        std::sort(out.begin(), out.end());
        std::sort(ans.begin(), ans.end());

        //Does not include duplicates into the BFS

        REQUIRE(out == ans);


        // ADX : {ORD}
        vector<string> vec4;
        vec4.push_back("ORD");
        map["ADX"] = vec4;
        
        vector<string> out2 = test.runBFS(map, "SFO");
        /* one way flights are not included in the bfs. for example, if SFO flies to ORD and 
        ADX flies to ORD then ADX will not be included in the BFS traversal stating at SFO */
        std::sort(out2.begin(), out2.end());
        REQUIRE(out2 == ans);

        // EBZ : {LAS}
        vector<string> vec5;
        vec5.push_back("LAS");
        map["EBZ"] = vec5;

        vector<string> out3 = test.runBFS(map, "SFO");
        std::sort(out3.begin(), out3.end());

        // Doesn't include aiports that have no key or values related to starting airport
        REQUIRE(out3 == ans);
    }
}
TEST_CASE("Test2 Data", "[valgrind][weight=1]"){
    SECTION("Parse data and creates adjancecy list") {

        map<string, vector<string>> tmp = parseRoutes("../src/routes.txt");

        // AAE flies to these airports
        vector<string> ans {"ALG", "CDG", "IST", "ORY", "LYS", "ORN", "MRS"};
        std::sort(ans.begin(), ans.end());
        vector<string> out = tmp["AAE"];
        std::sort(out.begin(), out.end());

        //basic test case to see if data stores all the correct info
        REQUIRE(out==ans);
        
        // CEK flies to these airports
        vector<string> ans2 {"KZN", "OVB", "PRG", "FRU", "OSS", "DME", "DYU", "EVN", "LBD", "LED", "SVO", "DWC", "NMA", "TAS"};
        std::sort(ans2.begin(), ans2.end());
        vector<string> out2 = tmp["CEK"];
        std::sort(out2.begin(), out2.end());

        REQUIRE(ans2 == out2);
    }
}

TEST_CASE("Test3 Eulerian Path", "[valgrind][weight=1]"){
    SECTION("Test the Eulerian path algorithm") {
        BFS b;
        map<string, vector<string>> graph; 

        vector<string> vec0;
        vec0.push_back("1");
        graph["0"] = vec0;

        vector<string> vec1;
        vec1.push_back("2");
        graph["1"] = vec1;

        vector<string> vec2;
        vec2.push_back("0");
        graph["2"] = vec2;

        vector<string> vec3;
        vec3.push_back("0");
        vec3.push_back("4");
        graph["3"] = vec3;

        vector<string> vec4;
        vec4.push_back("3");
        graph["4"] = vec4;

        /*running a bfs starting at 4 will create a graph with 
            nodes 0,1,2,3,4 and an euler path will only exist starting at 3 */
        vector<string> bfs = b.runBFS(graph, "4");
        REQUIRE(b.hasEulerPath(bfs, "4") == 0);
        REQUIRE(b.hasEulerPath(bfs, "3") == 1);
        REQUIRE(b.hasEulerPath(bfs, "0") == 0);
        //running a bfs starting at 0 will be a graph with nodes 0,1,2, and will be an euler circuit
        bfs = b.runBFS(graph, "0");
        REQUIRE(b.hasEulerPath(bfs, "0") == 1);
        REQUIRE(b.hasEulerPath(bfs, "1") == 1);

        vector<string> ans = b.findEulerPath(graph, "3");
        for (unsigned i = 0; i <ans.size(); i++) {
            cout << ans.at(i);
        }
    }
}