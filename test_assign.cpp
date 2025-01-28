//  Stack class test program
//
//  Tests: assign
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int>  one;
        one.push(1); 

        stack<int>  two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one.empty() == false);
        assert(one.top()   == 1);

        // VERIFY 2
        assert(two.empty() == false);
        assert(two.top()   == 1);
     }
     {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<char>  one;
        one.push('A'); 

        stack<char>  two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one.empty() == false);
        assert(one.top()   == 'A');

        // VERIFY 2
        assert(two.empty() == false);
        assert(two.top()   == 'A');
     }
     {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>  one;
        one.push("abc"); 

        stack<String>  two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one.empty() == false);
        assert(one.top()   == "abc");

        // VERIFY 2
        assert(two.empty() == false);
        assert(two.top()   == "abc");
     }
     {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int>  one;
        one.push(119834759); 

        stack<int>  two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one.empty() == false);
        assert(one.top()   == 119834759);

        // VERIFY 2
        assert(two.empty() == false);
        assert(two.top()   == 119834759);
     }
     {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<char>  one;
        one.push('*'); 

        stack<char>  two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one.empty() == false);
        assert(one.top()   == '*');

        // VERIFY 2
        assert(two.empty() == false);
        assert(two.top()   == '*');
     }
     {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>  one;
        one.push("ahgkjadfliasdflkasdgkajnerio4halkdfglkjasirueuncrnugha;kjsrkjrwhfbcmrnfjkshgsiahfajkndgkjherugrencjfbjkahgaeurirbvajnfgkjerhuhrefhdjngadjfngjeahrugral;wieohwoehtuiwhjkjfnvnklrargkahreioghrehs;kkjdfnnwpwqpwownfergiororjioaerutionc48th34htjkdfnvaerhklfjawkehh o34htqjkkwjrgkjdfnkjaenrtu34"); 

        stack<String>  two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one.empty() == false);
        assert(one.top()   == "ahgkjadfliasdflkasdgkajnerio4halkdfglkjasirueuncrnugha;kjsrkjrwhfbcmrnfjkshgsiahfajkndgkjherugrencjfbjkahgaeurirbvajnfgkjerhuhrefhdjngadjfngjeahrugral;wieohwoehtuiwhjkjfnvnklrargkahreioghrehs;kkjdfnnwpwqpwownfergiororjioaerutionc48th34htjkdfnvaerhklfjawkehh o34htqjkkwjrgkjdfnkjaenrtu34");

        // VERIFY 2
        assert(two.empty() == false);
        assert(two.top()   == "ahgkjadfliasdflkasdgkajnerio4halkdfglkjasirueuncrnugha;kjsrkjrwhfbcmrnfjkshgsiahfajkndgkjherugrencjfbjkahgaeurirbvajnfgkjerhuhrefhdjngadjfngjeahrugral;wieohwoehtuiwhjkjfnvnklrargkahreioghrehs;kkjdfnnwpwqpwownfergiororjioaerutionc48th34htjkdfnvaerhklfjawkehh o34htqjkkwjrgkjdfnkjaenrtu34");
     }
     {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>  one;
        one.push("38410438518475980345987134895789465873489572457892375987349857284976589237458972349865729857689234759286289745987498571-39475-197459827489572486789247854678245876203451-192837513989211-190182736587134958718964581632845127359823758961876345130561837465817347598137458713478563147858347891374812613457013408184756143758913653"); 

        stack<String>  two;

        // TEST
        two = one;

        // VERIFY 1
        assert(one.empty() == false);
        assert(one.top()   == "38410438518475980345987134895789465873489572457892375987349857284976589237458972349865729857689234759286289745987498571-39475-197459827489572486789247854678245876203451-192837513989211-190182736587134958718964581632845127359823758961876345130561837465817347598137458713478563147858347891374812613457013408184756143758913653");

        // VERIFY 2
        assert(two.empty() == false);
        assert(two.top()   == "38410438518475980345987134895789465873489572457892375987349857284976589237458972349865729857689234759286289745987498571-39475-197459827489572486789247854678245876203451-192837513989211-190182736587134958718964581632845127359823758961876345130561837465817347598137458713478563147858347891374812613457013408184756143758913653");
     }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing assign." << std::endl;
    return 0;
}

