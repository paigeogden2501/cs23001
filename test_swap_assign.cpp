//  String class test program
// 
//  Tests: swap
//
  
#include "string.hpp"
#include <cassert>
#include <iostream> 


int main() {

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String one(1);

        String  two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one == 1);

        // VERIFY 2
        assert(two == 1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String one('A');

        String two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one == 'A');

        // VERIFY 2
        assert(two == 'A');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String one("abc");

        String two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one == "abc");

        // VERIFY 2
        assert(two == "abc");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String one("119834759");

        String  two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one == "119834759");

        // VERIFY 2
        assert(two == "119834759");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String one('*'); 

        String two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one == '*');

        // VERIFY 2
        assert(two == '*');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String one("ahgkjadfliasdflkasdgkajnerio4halkdfglkjasirueuncrnugha;kjsrkjrwhfbcmrnfjkshgsiahfajkndgkjherugrencjfbjkahgaeurirbvajnfgkjerhuhrefhdjngadjfngjeahrugral;wieohwoehtuiwhjkjfnvnklrargkahreioghrehs;kkjdfnnwpwqpwownfergiororjioaerutionc48th34htjkdfnvaerhklfjawkehh o34htqjkkwjrgkjdfnkjaenrtu34");

        String two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one == "ahgkjadfliasdflkasdgkajnerio4halkdfglkjasirueuncrnugha;kjsrkjrwhfbcmrnfjkshgsiahfajkndgkjherugrencjfbjkahgaeurirbvajnfgkjerhuhrefhdjngadjfngjeahrugral;wieohwoehtuiwhjkjfnvnklrargkahreioghrehs;kkjdfnnwpwqpwownfergiororjioaerutionc48th34htjkdfnvaerhklfjawkehh o34htqjkkwjrgkjdfnkjaenrtu34");

        // VERIFY 2
        assert(two == "ahgkjadfliasdflkasdgkajnerio4halkdfglkjasirueuncrnugha;kjsrkjrwhfbcmrnfjkshgsiahfajkndgkjherugrencjfbjkahgaeurirbvajnfgkjerhuhrefhdjngadjfngjeahrugral;wieohwoehtuiwhjkjfnvnklrargkahreioghrehs;kkjdfnnwpwqpwownfergiororjioaerutionc48th34htjkdfnvaerhklfjawkehh o34htqjkkwjrgkjdfnkjaenrtu34");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String one("38410438518475980345987134895789465873489572457892375987349857284976589237458972349865729857689234759286289745987498571-39475-197459827489572486789247854678245876203451-192837513989211-190182736587134958718964581632845127359823758961876345130561837465817347598137458713478563147858347891374812613457013408184756143758913653");

        String two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one == "38410438518475980345987134895789465873489572457892375987349857284976589237458972349865729857689234759286289745987498571-39475-197459827489572486789247854678245876203451-192837513989211-190182736587134958718964581632845127359823758961876345130561837465817347598137458713478563147858347891374812613457013408184756143758913653");

        // VERIFY 2
        assert(two == "38410438518475980345987134895789465873489572457892375987349857284976589237458972349865729857689234759286289745987498571-39475-197459827489572486789247854678245876203451-192837513989211-190182736587134958718964581632845127359823758961876345130561837465817347598137458713478563147858347891374812613457013408184756143758913653");
    }


    std::cout << "Done testing swap assign." << std::endl;
    return 0;
}
