
#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    char a;
    for(int i=0; i< input.size(); i++){
        a = input.at(i);
        if(a == ' ' || a == '\t' || a == '\n' || a == '\r'){
            input.erase(i,1);
        }
    }
	return input;
}



TEST_CASE("Good input") {
    CHECK(nospaces(mat(1,1,'@',')')) == ("@"));
 
    CHECK(nospaces(mat(3,3,'a','b')) == nospaces(("a a a\n"
                                                 "a b a\n"
                                                 "a a a")));




    CHECK(nospaces(mat(5,5,'a','c')) == nospaces(("a a a a a\n"
                                                 "a c c c a\n"
                                                 "a c a c a\n"
                                                 "a c c c a\n"
                                                 "a a a a a")));




    CHECK(nospaces(mat(7,7,'@','-')) == nospaces(("@ @ @ @ @ @ @"
                                                "@ - - - - - @"
                                                "@ - @ @ @ - @"
                                                "@ - @ - @ - @"
                                                "@ - @ @ @ - @"
                                                "@ - - - - - @"
                                                "@ @ @ @ @ @ @")));



    CHECK(nospaces(mat(9,9,')','(')) == nospaces(") ) ) ) ) ) ) ) )"
                                                 ") ( ( ( ( ( ( ( )"
                                                 ") ( ) ) ) ) ) ( )"
                                                 ") ( ) ( ( ( ) ( )"
                                                 ") ( ) ( ) ( ) ( )"
                                                 ") ( ) ( ( ( ) ( )"
                                                 ") ( ) ) ) ) ) ( )"
                                                 ") ( ( ( ( ( ( ( )"
                                                 ") ) ) ) ) ) ) ) )"
                                                 ));





   CHECK(nospaces(mat(11,11,'I', 'Q')) == nospaces(("I I I I I I I I I I I"
                                                   "I Q Q Q Q Q Q Q Q Q I"
                                                   "I Q I I I I I I I Q I"
                                                   "I Q I Q Q Q Q Q I Q I"
                                                   "I Q I Q I I I Q I Q I"
                                                   "I Q I Q I Q I Q I Q I"
                                                   "I Q I Q I I I Q I Q I"
                                                   "I Q I Q Q Q Q Q I Q I"
                                                   "I Q I I I I I I I Q I"
                                                   "I Q Q Q Q Q Q Q Q Q I"
                                                   "I I I I I I I I I I I")));





    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces( (           "@@@@@@@@@\n"
                                                                "@-------@\n"
                                                                "@-@@@@@-@\n"
                                                                "@-@---@-@\n"
                                                                "@-@@@@@-@\n"
                                                                "@-------@\n"
                                                                "@@@@@@@@@")));


    CHECK(nospaces(mat(9, 7, '$', '2')) == nospaces(("$ $ $ $ $ $ $ $ $\n"
                                                     "$ 2 2 2 2 2 2 2 $\n"
                                                     "$ 2 $ $ $ $ $ 2 $\n"
                                                     "$ 2 $ 2 2 2 $ 2 $\n"
                                                     "$ 2 $ $ $ $ $ 2 $\n"
                                                     "$ 2 2 2 2 2 2 2 $\n"
                                                     "$ $ $ $ $ $ $ $ $")));





    /* Add more test here */
}
// The difference between the two integers given must be even
TEST_CASE("Bad input") {
    CHECK_THROWS(nospaces(mat(0,0,'0','1')));
    CHECK_THROWS(mat(10, 5, '$', '%'));
    for (int i=0; i< 50; i+=2){
        CHECK_THROWS(mat(0,i,'$','%'));
        CHECK_THROWS(mat(i,0,'^','*'));
    }
    CHECK_THROWS(nospaces(mat(12,12,'G','f')));

    
    CHECK_THROWS(nospaces(mat(14 ,11,'!','-')));
    

    CHECK_THROWS(nospaces(mat(5,10,'A','V')));


    CHECK_THROWS(nospaces(mat(10,5,'A','V')));

    
    CHECK_THROWS(nospaces(mat(10,10,'1', '0')));
    
    CHECK_THROWS(nospaces(mat(8,8,'O','X')));

    
    CHECK_THROWS(nospaces(mat(6,6,'A','B')));
    

    CHECK_THROWS(nospaces(mat(4,4,'a','b')));


    CHECK_THROWS(nospaces(mat(2,2,'a','b')));


}


