#include "doctest.h"
#include "Matrix.hpp"
#include <string>

TEST_CASE("good inputs"){
    zich::Matrix mat_eq1{{1,2,3,4,5,6,7,8,9},3,3};
    zich::Matrix mat_eq2{{1,2,3,4,5,6,7,8,9},3,3};
    zich::Matrix mat_eq3{{-1,-2,-3,-4,-5,-6,-7,-8,-9},3,3};
    zich::Matrix mat_eq4{{2,4,6,8,10,12,14,16,18},3,3};

    zich::Matrix mat_morerow1{{1,2,3,4,5,6,7,8,9,10,11,12},4,3};
    zich::Matrix mat_morerow2{{1,2,3,4,5,6,7,8,9,10,11,12},4,3};
    zich::Matrix mat_morerow3{{-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12},4,3};
    zich::Matrix mat_morerow4{{2,4,6,8,10,12,14,16,18,20,22,24},4,3};

    zich::Matrix mat_morecolum1{{1,2,3,4,5,6,7,8,9,10,11,12},3,4};
    zich::Matrix mat_morecolum2{{1,2,3,4,5,6,7,8,9,10,11,12},3,4};
    zich::Matrix mat_morecolum3{{-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12},3,4};
    zich::Matrix mat_morecolum4{{2,4,6,8,10,12,14,16,18,20,22,24},3,4};
    
    //check equal 
    CHECK((mat_eq1 == mat_eq2));
    CHECK((mat_morecolum1 == mat_morecolum2));
    CHECK((mat_morerow1 == mat_morerow2));

    //check not equal
    CHECK((mat_eq1  != mat_eq3));
    CHECK((mat_eq1 != mat_eq4));

    CHECK((mat_morecolum1 != mat_morecolum3));
    CHECK((mat_morecolum1 != mat_morecolum4));

    CHECK((mat_morerow1 != mat_morerow3));
    CHECK((mat_morerow1 != mat_morerow4));

    //check +

    CHECK((+mat_eq1 == mat_eq2));
    CHECK((+mat_morecolum1 == mat_morecolum2));
    CHECK((+mat_morerow1 == mat_morerow2));
    
    //check -

    CHECK((-mat_eq1 == mat_eq3));
    CHECK((-mat_morecolum1 == mat_morecolum3));
    CHECK((-mat_morerow1 == mat_morerow3));

    CHECK((-(-mat_eq1) == mat_eq2));
    CHECK((-(-mat_morecolum1) == mat_morecolum2));
    CHECK((-(-mat_morerow1) == mat_morerow2));

    CHECK((-mat_eq3 == mat_eq2));
    CHECK((-mat_morecolum3 == mat_morecolum2));
    CHECK((-mat_morerow3 == mat_morerow2));

    //+
    CHECK(((mat_eq1 + mat_eq2)== mat_eq4));
    CHECK(((mat_morecolum1 + mat_morecolum2)== mat_morecolum4));
    CHECK(((mat_morerow1 + mat_morerow2) == mat_morerow4));
    //+=
    CHECK(((mat_eq1 += mat_eq2)== mat_eq4));
    CHECK(((mat_morecolum1 += mat_morecolum2 )== mat_morecolum4));
    CHECK(((mat_morerow1 += mat_morerow2) == mat_morerow4));
    
    // - 
    CHECK(((mat_eq4 - mat_eq2)== mat_eq2));
    CHECK(((mat_morecolum4 - mat_morecolum2) == mat_morecolum2));
    CHECK(((mat_morerow4 - mat_morerow2) == mat_morerow2));
    
    //-=
    CHECK(((mat_eq1 -= mat_eq2)== mat_eq2));
    CHECK(((mat_morecolum1 -= mat_morecolum2 )== mat_morecolum2));
    CHECK(((mat_morerow1 -= mat_morerow2) == mat_morerow2));
    
    //>
    CHECK((mat_eq4>mat_eq1));
    CHECK((mat_morecolum4 > mat_morecolum1));
    CHECK((mat_morerow4 > mat_morerow1));

    CHECK((mat_eq1 > mat_eq3));
    CHECK((mat_morecolum1 > mat_morecolum3));
    CHECK((mat_morerow1 > mat_morerow3));
    //>=
    CHECK((mat_eq1 >= mat_eq2));
    CHECK((mat_morecolum1 >= mat_morecolum2));
    CHECK((mat_morerow1 >= mat_morerow2));

    CHECK((mat_eq4 >= mat_eq1));
    CHECK((mat_morecolum4 >= mat_morecolum1));
    CHECK((mat_morerow4 >= mat_morerow1));

    //<
    CHECK((mat_eq1 < mat_eq4));
    CHECK((mat_morecolum1 < mat_morecolum4));
    CHECK((mat_morerow1 < mat_morerow4));  

    CHECK((mat_eq3 < mat_eq1));
    CHECK((mat_morecolum3 < mat_morecolum1));
    CHECK((mat_morerow3 < mat_morerow1));  
    //<=
    CHECK((mat_eq1 <= mat_eq2));
    CHECK((mat_morecolum1 <= mat_morecolum2));
    CHECK((mat_morerow1 <= mat_morerow2));

    CHECK((mat_eq1 <= mat_eq4));
    CHECK((mat_morecolum1 <= mat_morecolum4));
    CHECK((mat_morerow1 <= mat_morerow4));   

    // ++  

    CHECK((mat_eq1 != mat_eq1++));
    CHECK((mat_morecolum1 != mat_morecolum1++));
    CHECK((mat_morerow1 != mat_morerow1++));

    CHECK((mat_eq1 == ++mat_eq1));
    CHECK((mat_morecolum1 == ++mat_morecolum1));
    CHECK((mat_morerow1 == ++mat_morerow1)); 

    // -- 

    CHECK((mat_eq1 != mat_eq1--));
    CHECK((mat_morecolum1 != mat_morecolum1--));
    CHECK((mat_morerow1 != mat_morerow1--));

    CHECK((mat_eq1 == --mat_eq1));
    CHECK((mat_morecolum1 == --mat_morecolum1));
    CHECK((mat_morerow1 == --mat_morerow1)); 

    //*
    CHECK(((mat_eq1 *2)== mat_eq4));
    CHECK(((mat_morecolum1 * 2) == mat_morecolum4));
    CHECK(((mat_morerow1 * 2 )== mat_morerow4));

    CHECK(((2* mat_eq1)== mat_eq4));
    CHECK(((2* mat_morecolum1 )== mat_morecolum4));
    CHECK(((2 * mat_morerow1) == mat_morerow4));
    
    zich::Matrix mat1{{30,36,42,66,81,96,102,126,150},3,3};
    CHECK(((mat_eq1 * mat_eq2) == mat1));
    zich::Matrix mat2{{70,80,90,158,184,210,246,288,330},3,3};
    CHECK(((mat_morecolum1 * mat_morerow2)== mat2));
    zich::Matrix mat3{{38,44,50,56,83,98,113,128,128,152,176,200,173,206,239,272},4,4};
    CHECK(((mat_morerow1 * mat_morecolum2) == mat3));
    
    //*=
    CHECK(((mat_eq1 *= 2)== mat_eq4));
    CHECK(((mat_morecolum1 *= 2 )== mat_morecolum4));
    CHECK(((mat_morerow1 *= 2) == mat_morerow4));



    }

TEST_CASE("bad inputs"){

    zich::Matrix mat_eq1{{1,2,3,4,5,6,7,8,9},3,3};
    zich::Matrix mat_eq2{{1,2,3,4,5,6,7,8,9},3,3};
    zich::Matrix mat_eq3{{-1,-2,-3,-4,-5,-6,-7,-8,-9},3,3};
    zich::Matrix mat_eq4{{2,4,6,8,10,12,14,16,18},3,3};

    zich::Matrix mat_morerow1{{1,2,3,4,5,6,7,8,9,10,11,12},4,3};
    zich::Matrix mat_morerow2{{1,2,3,4,5,6,7,8,9,10,11,12},4,3};
    zich::Matrix mat_morerow3{{-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12},4,3};
    zich::Matrix mat_morerow4{{2,4,6,8,10,12,14,16,18,20,22,24},4,3};

    zich::Matrix mat_morecolum1{{1,2,3,4,5,6,7,8,9,10,11,12},3,4};
    zich::Matrix mat_morecolum2{{1,2,3,4,5,6,7,8,9,10,11,12},3,4};
    zich::Matrix mat_morecolum3{{-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12},3,4};
    zich::Matrix mat_morecolum4{{2,4,6,8,10,12,14,16,18,20,22,24},3,4};
    // == 
    CHECK_THROWS((mat_eq1.operator==(mat_morerow1)));
    CHECK_THROWS((mat_eq1.operator==(mat_morecolum1)));
    CHECK_THROWS((mat_morecolum1.operator==(mat_morerow1)));

    // !=
    CHECK_THROWS((mat_eq1.operator!=(mat_morerow1)));
    CHECK_THROWS((mat_eq1.operator!=(mat_morecolum1)));
    CHECK_THROWS((mat_morecolum1.operator!=(mat_morerow1)));

    // <
    CHECK_THROWS((mat_eq1.operator<(mat_morerow1)));
    CHECK_THROWS((mat_eq1.operator<(mat_morecolum1)));
    CHECK_THROWS((mat_morecolum1.operator<(mat_morerow1)));

    // >
    CHECK_THROWS((mat_eq1.operator>(mat_morerow1)));
    CHECK_THROWS((mat_eq1.operator>(mat_morecolum1)));
    CHECK_THROWS((mat_morecolum1.operator>(mat_morerow1)));

    // <=
    CHECK_THROWS((mat_eq1.operator<=(mat_morerow1)));
    CHECK_THROWS((mat_eq1.operator<=(mat_morecolum1)));
    CHECK_THROWS((mat_morecolum1.operator<=(mat_morerow1)));

    // >=
    CHECK_THROWS((mat_eq1.operator>=(mat_morerow1)));
    CHECK_THROWS((mat_eq1.operator>=(mat_morecolum1)));
    CHECK_THROWS((mat_morecolum1.operator>=(mat_morerow1)));

    // +

    CHECK_THROWS((mat_eq1 + mat_morerow1));
    CHECK_THROWS((mat_eq1 + mat_morecolum1));
    CHECK_THROWS((mat_morecolum1 + mat_morerow1));

    // - 

    CHECK_THROWS((mat_eq1 - mat_morerow1));
    CHECK_THROWS((mat_eq1 - mat_morecolum1));
    CHECK_THROWS((mat_morecolum1 - mat_morerow1));

    // *
    CHECK_THROWS((mat_eq1 * mat_morerow1));
    CHECK_THROWS((mat_morecolum1 * mat_eq1));


    
}