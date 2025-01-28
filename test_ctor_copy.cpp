//  String class test program
// 
//  Tests: swap
//
  
#include "string.hpp"
#include <cassert>
#include <iostream> 


int main() {
    {
        // SETUP
        String s1 = "a";

        String s2(s1);

        // VERIFY
        assert(s1 == s2);
    }
    {
        // SETUP
        String s1 = "abcdefghijklmnopqrstuvwxyz";

        String s2(s1);

        // VERIFY
        assert(s1 == s2);
    }
    {
        // SETUP
        String s1("11341231");

        String s2(s1);

        // VERIFY
        assert(s1 == s2);
    }
    {
        // SETUP
        String s1 = '*';

        String s2(s1);

        // VERIFY
        assert(s1 == s2);
    }
    {
        // SETUP
        String s1 = "asdfhjhjoiwenceriiu902375-18475981734581879701983409783745hjhwenkncuaewuh892y48hfqkadskgjakjeituwencuie";

        String s2(s1);

        // VERIFY
        assert(s1 == s2);
    }
    {
        // SETUP
        String s1 = "149873980475674100912847692948987843758971248971010918237487358613857103847601893274182150981734698712837847817458710923847891236571374548123794";

        String s2(s1);

        // VERIFY
        assert(s1 == s2);
    }
    {
        // SETUP
        String s1("99999");

        String s2(s1);

        // VERIFY
        assert(s1 == s2);
    }
    {
        // SETUP
        String s1 = 'a';

        String s2(s1);

        // VERIFY
        assert(s1 == s2);
    }
    {
        // SETUP
        String s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaacccccccccccccccccccccccccccccccccccccccc";

        String s2(s1);

        // VERIFY
        assert(s1 == s2);
    }

    std::cout << "Done testing ctor copy." << std::endl;
    return 0;
}
