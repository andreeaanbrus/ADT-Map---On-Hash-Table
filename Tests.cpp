//
// Created by andreea on 25.05.2018.
//

#include "Tests.h"
#include "Car.h"
#include "HashTable.h"
#include "Map.h"

// Terminal : gcov main.gcno && lcov --capture --directory . --output-file LCOVOUTPUT.info && genhtml LCOVOUTPUT.info --output-directory CODE_COVERAGE
TEST_F (Tests, testCar){
    Car c("BN03LXF", 3);
    Car c2("", 0);
    ASSERT_EQ(c.getArea(), 3);
    ASSERT_EQ(c.getLicence(), "BN03LXF");
    ASSERT_EQ(c.isEmpty(), false);
    ASSERT_EQ(c2.isEmpty(), true);
    ASSERT_EQ(c.isEmpty(), false);
    ASSERT_EQ(c==c2, false);
    ASSERT_EQ(c != c2, true);
}

TEST_F(Tests, testHashTable){
    HashTable t;
    Car c("BN03LXF", 3);
    Car c1("CJ10AIA", 1);
    Car c2("BN96VAD", 2);
    Car c3("BN98AAA", 1);
    t.setLength(5);
    t.add(c);
    t.add(c1);
    t.add(c2);
    t.add(c3);
    ASSERT_EQ(t.getElems()[0].getLicence(), "BN96VAD");
    ASSERT_EQ(t.getElems()[1].getLicence(), "");
    ASSERT_EQ(t.getElems()[2].getLicence(), "BN03LXF");
    ASSERT_EQ(t.getElems()[3].getLicence(), "CJ10AIA");
    ASSERT_EQ(t.getElems()[4].getLicence(), "BN98AAA");
    t.remove(c);
    ASSERT_EQ(t.getElems()[2].getLicence(), "DELETED");
    t.search(c3);
    ASSERT_EQ(t.search(c3), 4);
    ASSERT_EQ(t.search(c), -1);

}

TEST_F(Tests, testMap) {
    Map m;
    m.setLength(5);
    TValue v = 1;
    TKey k1 = "BN03LXF";
    m.add(k1, v);
    ASSERT_EQ(m.getTable().getElems()[2].getLicence(), k1);
    TKey k2 = "CJ10AIA";
    m.add(k2, v);
    ASSERT_EQ(m.getTable().getElems()[3].getLicence(), k2);
    TKey k3 = "BN96VAD";
    m.add(k3, v);
    ASSERT_EQ(m.getTable().getElems()[0].getLicence(), k3);
    TKey k4 = "BN98AAA";
    m.add(k4, v);
    ASSERT_EQ(m.getTable().getElems()[4].getLicence(), k4);
    m.remove(k1);
    ASSERT_EQ(m.getTable().getElems()[2].getLicence(), "DELETED");
    ASSERT_ANY_THROW(m.search(k1, 1));
    ASSERT_ANY_THROW(m.add(k3, v));
    ASSERT_EQ(m.search(k4, 1), 1);
    Iterator i(m);
    ASSERT_EQ(i.getCurrent().getLicence(), k3);
    i.next();
    ASSERT_EQ(i.valid(), true);
    ASSERT_EQ(i.getCurrent().getLicence(), k2);
}