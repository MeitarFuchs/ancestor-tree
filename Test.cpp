#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace std;
using namespace family;

//family::Tree T("meitar");
//
//T.addFather("meitar" , "moshe")
//.addMother("meitar" ,"naama")
//.addFather("moshe" , "yair")
//.addMother("moshe" , "sara")
//.addFather("naama" , "yonathan")
//.addMother("naama" , "rivka")
//.addFather("yair" , "reouven")
//.addMother("yair" , "hila")
//.addFather("sara" , "gavriel")
//.addMother("sara" , "roni")
//.addFather("yonathan" , "amihai")
//.addMother("yonathan" , "talia")
//.addFather("rivka" , "ori")
//.addMother("rivka" , "oriya")
//.addFather("reouven" , "doron")
//.addMother("reouven" , "hodaya")
//.addFather("hila" , "itamar")
//.addMother("hila" , "shira")
//.addFather("gavriel" , "nathan")
//.addMother("gavriel" , "shir")
//.addFather("roni" , "shai")
//.addMother("roni" , "shoshana")
//.addFather("amihai" , "michael")
//.addMother("amihai" , "hadar")
//.addFather("talia" , "yehouda")
//.addMother("talia" , "eden")
//.addFather("ori" , "gil")
//.addMother("ori" , "renana")
//.addFather("oriya" , "netanel")
//.addMother("oriya" , "shahar");


TEST_CASE("relation"){
    family::Tree T("meitar");

    T.addFather("meitar" , "moshe")
            .addMother("meitar" ,"naama")
            .addFather("moshe" , "yair")
            .addMother("moshe" , "sara")
            .addFather("naama" , "yonathan")
            .addMother("naama" , "rivka")
            .addFather("yair" , "reouven")
            .addMother("yair" , "hila")
            .addFather("sara" , "gavriel")
            .addMother("sara" , "roni")
            .addFather("yonathan" , "amihai")
            .addMother("yonathan" , "talia")
            .addFather("rivka" , "ori")
            .addMother("rivka" , "oriya")
            .addFather("reouven" , "doron")
            .addMother("reouven" , "hodaya")
            .addFather("hila" , "itamar")
            .addMother("hila" , "shira")
            .addFather("gavriel" , "nathan")
            .addMother("gavriel" , "shir")
            .addFather("roni" , "shai")
            .addMother("roni" , "shoshana")
            .addFather("amihai" , "michael")
            .addMother("amihai" , "hadar")
            .addFather("talia" , "yehouda")
            .addMother("talia" , "eden")
            .addFather("ori" , "gil")
            .addMother("ori" , "renana")
            .addFather("oriya" , "netanel")
            .addMother("oriya" , "shahar");

            CHECK(T.relation("moshe")==string("father"));
            CHECK(T.relation("naama")==string("mother"));
            CHECK(T.relation("yair")==string("grandfather"));
            CHECK(T.relation("sara")==string("grandmother"));
            CHECK(T.relation("yonathan")==string("grandfather"));
            CHECK(T.relation("rivka")==string("grandmother"));
            CHECK(T.relation("reouven")==string("great-grandfather"));
            CHECK(T.relation("hila")==string("great-grandmother"));
            CHECK(T.relation("gavriel")==string("great-grandfather"));
            CHECK(T.relation("roni")==string("great-grandmother"));
            CHECK(T.relation("amihai")==string("great-grandfather"));
            CHECK(T.relation("talia")==string("great-grandmother"));
            CHECK(T.relation("ori")==string("great-grandfather"));
            CHECK(T.relation("oriya")==string("great-grandmother"));
            CHECK(T.relation("doron")==string("great-great-grandfather"));
            CHECK(T.relation("hodaya")==string("great-great-grandmother"));
            CHECK(T.relation("itamar")==string("great-great-grandfather"));
            CHECK(T.relation("shira")==string("great-great-grandmother"));
            CHECK(T.relation("nathan")==string("great-great-grandfather"));
            CHECK(T.relation("shir")==string("great-great-grandmother"));
            CHECK(T.relation("shai")==string("great-great-grandfather"));
            CHECK(T.relation("shoshana")==string("great-great-grandmother"));
            CHECK(T.relation("michael")==string("great-great-grandfather"));
            CHECK(T.relation("hadar")==string("great-great-grandmother"));
            CHECK(T.relation("yehouda")==string("great-great-grandfather"));
            CHECK(T.relation("eden")==string("great-great-grandmother"));
            CHECK(T.relation("gil")==string("great-great-grandfather"));
            CHECK(T.relation("renana")==string("great-great-grandmother"));
            CHECK(T.relation("nethanel")==string("great-great-grandfather"));
            CHECK(T.relation("shahar")==string("great-great-grandmother"));
            CHECK(T.relation("Roei")==string("unrelated"));
            CHECK(T.relation("shimon")==string("unrelated"));
            CHECK(T.relation("bibi")==string("unrelated"));
            CHECK(T.relation("mazal")==string("unrelated"));
            CHECK(T.relation("beni")==string("unrelated"));
            CHECK(T.relation("neria")==string("unrelated"));
            CHECK(T.relation("orelle")==string("unrelated"));
            CHECK(T.relation("noa")==string("unrelated"));
            CHECK(T.relation("ido")==string("unrelated"));
            CHECK(T.relation("or")==string("unrelated"));

}

TEST_CASE("find"){
    family::Tree T("meitar");

    T.addFather("meitar" , "moshe")
            .addMother("meitar" ,"naama")
            .addFather("moshe" , "yair")
            .addMother("moshe" , "sara")
            .addFather("naama" , "yonathan")
            .addMother("naama" , "rivka")
            .addFather("yair" , "reouven")
            .addMother("yair" , "hila")
            .addFather("sara" , "gavriel")
            .addMother("sara" , "roni")
            .addFather("yonathan" , "amihai")
            .addMother("yonathan" , "talia")
            .addFather("rivka" , "ori")
            .addMother("rivka" , "oriya")
            .addFather("reouven" , "doron")
            .addMother("reouven" , "hodaya")
            .addFather("hila" , "itamar")
            .addMother("hila" , "shira")
            .addFather("gavriel" , "nathan")
            .addMother("gavriel" , "shir")
            .addFather("roni" , "shai")
            .addMother("roni" , "shoshana")
            .addFather("amihai" , "michael")
            .addMother("amihai" , "hadar")
            .addFather("talia" , "yehouda")
            .addMother("talia" , "eden")
            .addFather("ori" , "gil")
            .addMother("ori" , "renana")
            .addFather("oriya" , "netanel")
            .addMother("oriya" , "shahar");

    CHECK(T.find("father")==string("moshe"));
            CHECK(T.find("mother")==string("naama"));
            CHECK(T.find("grandfather")==string("yair"));
            CHECK(T.find("grandfather")==string("yonathan"));
            CHECK(T.find("grandmother")==string("sara"));
            CHECK(T.find("grandmother")==string("rivka"));
            CHECK(T.find("great-grandfather")==string("reouven"));
            CHECK(T.find("great-grandfather")==string("gavriel"));
            CHECK(T.find("great-grandfather")==string("amihai"));
            CHECK(T.find("great-grandfather")==string("ori"));
            CHECK(T.find("great-grandmother")==string("hila"));
            CHECK(T.find("great-grandmother")==string("roni"));
            CHECK(T.find("great-grandmother")==string("talia"));
            CHECK(T.find("great-grandmother")==string("oriya"));
            CHECK(T.find("great-great-grandfather")==string("doron"));
            CHECK(T.find("great-great-grandfather")==string("itamar"));
            CHECK(T.find("great-great-grandfather")==string("nathan"));
            CHECK(T.find("great-great-grandfather")==string("shai"));
            CHECK(T.find("great-great-grandfather")==string("michael"));
            CHECK(T.find("great-great-grandfather")==string("yehouda"));
            CHECK(T.find("great-great-grandfather")==string("gil"));
            CHECK(T.find("great-great-grandfather")==string("nethanel"));
            CHECK(T.find("great-great-grandmother")==string("hodaya"));
            CHECK(T.find("great-great-grandmother")==string("shira"));
            CHECK(T.find("great-great-grandmother")==string("shir"));
            CHECK(T.find("great-great-grandmother")==string("shoshana"));
            CHECK(T.find("great-great-grandmother")==string("hadar"));
            CHECK(T.find("great-great-grandmother")==string("eden"));
            CHECK(T.find("great-great-grandmother")==string("renana"));
            CHECK(T.find("great-great-grandmother")==string("shahar"));

}

TEST_CASE("remove"){
    family::Tree T("meitar");

    T.addFather("meitar" , "moshe")
            .addMother("meitar" ,"naama")
            .addFather("moshe" , "yair")
            .addMother("moshe" , "sara")
            .addFather("naama" , "yonathan")
            .addMother("naama" , "rivka")
            .addFather("yair" , "reouven")
            .addMother("yair" , "hila")
            .addFather("sara" , "gavriel")
            .addMother("sara" , "roni")
            .addFather("yonathan" , "amihai")
            .addMother("yonathan" , "talia")
            .addFather("rivka" , "ori")
            .addMother("rivka" , "oriya")
            .addFather("reouven" , "doron")
            .addMother("reouven" , "hodaya")
            .addFather("hila" , "itamar")
            .addMother("hila" , "shira")
            .addFather("gavriel" , "nathan")
            .addMother("gavriel" , "shir")
            .addFather("roni" , "shai")
            .addMother("roni" , "shoshana")
            .addFather("amihai" , "michael")
            .addMother("amihai" , "hadar")
            .addFather("talia" , "yehouda")
            .addMother("talia" , "eden")
            .addFather("ori" , "gil")
            .addMother("ori" , "renana")
            .addFather("oriya" , "netanel")
            .addMother("oriya" , "shahar");

    T.remove("reouven");
            CHECK(T.relation("reouven")==string("unrelated"));
            CHECK(T.relation("doron")==string("unrelated"));
            CHECK(T.relation("hodaya")==string("unrelated"));
    T.remove("hila");
            CHECK(T.relation("hila")==string("unrelated"));
            CHECK(T.relation("itamar")==string("unrelated"));
            CHECK(T.relation("shira")==string("unrelated"));
    T.remove("gavriel");
            CHECK(T.relation("gavriel")==string("unrelated"));
            CHECK(T.relation("nathan")==string("unrelated"));
            CHECK(T.relation("shir")==string("unrelated"));
    T.remove("roni");
            CHECK(T.relation("roni")==string("unrelated"));
            CHECK(T.relation("shai")==string("unrelated"));
            CHECK(T.relation("shoshana")==string("unrelated"));
    T.remove("amihai");
            CHECK(T.relation("amihai")==string("unrelated"));
            CHECK(T.relation("michael")==string("unrelated"));
            CHECK(T.relation("hadar")==string("unrelated"));
    T.remove("talia");
            CHECK(T.relation("talia")==string("unrelated"));
            CHECK(T.relation("yahouda")==string("unrelated"));
            CHECK(T.relation("eden")==string("unrelated"));
    T.remove("ori");
            CHECK(T.relation("ori")==string("unrelated"));
            CHECK(T.relation("gil")==string("unrelated"));
            CHECK(T.relation("renana")==string("unrelated"));
    T.remove("oriya");
            CHECK(T.relation("oriya")==string("unrelated"));
            CHECK(T.relation("nathanel")==string("unrelated"));
            CHECK(T.relation("shahar")==string("unrelated"));
    T.remove("yair");
            CHECK(T.relation("yair")==string("unrelated"));
    T.remove("sara");
            CHECK(T.relation("sara")==string("unrelated"));
    T.remove("yonathan");
            CHECK(T.relation("yonathan")==string("unrelated"));
    T.remove("rivka");
            CHECK(T.relation("rivka")==string("unrelated"));
    T.remove("moshe");
            CHECK(T.relation("moshe")==string("unrelated"));
    T.remove("naama");
            CHECK(T.relation("naama")==string("unrelated"));
}