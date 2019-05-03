/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   test.c
 * Author: Jarrett Pierse 18375813
 *
 * Created on 30 April 2019, 10:01
 */
 

#include <stdio.h>
#include <stdlib.h>
#include "avg_and_max.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void all_same_avg_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 9;

    double array_1[3] = {2,2,2}; // arrays where all elements are the same
    double array_2[5] = {4,4,4,4,4};
    double array_3[9] = {7,7,7,7,7,7,7,7,7};

    CU_ASSERT_EQUAL(average(array_1, size_1), 2); // assertions for each array
    CU_ASSERT_EQUAL(average(array_2, size_2), 4);
    CU_ASSERT_EQUAL(average(array_3, size_3), 7);
}

void all_same_zero_avg_testcase(void)
{
    int size_1 = 4; // various size for different arrays
    int size_2 = 6;
    int size_3 = 10;

    double array_1[4] = {5,5,5,0}; // arrays where all elements are the same and last element is zero
    double array_2[6] = {3,3,3,3,3,0};
    double array_3[10] = {2,2,2,2,2,2,2,2,2,0};

    CU_ASSERT_EQUAL(average(array_1, size_1), 3.75); // assertions for each array
    CU_ASSERT_EQUAL(average(array_2, size_2), 2.5);
    CU_ASSERT_EQUAL(average(array_3, size_3), 1.8);
}

void all_different_avg_testcase(void)
{
    int size_1 = 4; // various size for different arrays
    int size_2 = 5;
    int size_3 = 8;

    double array_1[4] = {1,2,3,4}; // arrays where all elements are different
    double array_2[5] = {1,2,3,4,5};
    double array_3[8] = {1,2,3,4,5,6,7,8};

    CU_ASSERT_EQUAL(average(array_1, size_1), 2.5); // assertions for each array
    CU_ASSERT_EQUAL(average(array_2, size_2), 3);
    CU_ASSERT_EQUAL(average(array_3, size_3), 4.5);
}

void normal_array_avg_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {1,2,0}; // normal array with positive values
    double array_2[5] = {1,9,3,0,2};
    double array_3[7] = {1,2,3,6,5,11,4};

    CU_ASSERT_EQUAL(average(array_1, size_1), 1); // assertions
    CU_ASSERT_EQUAL(average(array_2, size_2), 3);
    CU_ASSERT_EQUAL(average(array_3, size_3), 4.5714285714286);
}

void pos_array_avg_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {1,2,5}; // arrays where all elements are positive
    double array_2[5] = {3,1,3,5,8};
    double array_3[7] = {12,13,9,8,15,15,0};

    CU_ASSERT_EQUAL(average(array_1, size_1), 2.6666666666667); // assertions
    CU_ASSERT_EQUAL(average(array_2, size_2), 4);
    CU_ASSERT_EQUAL(average(array_3, size_3), 10.285714285714);
}

void neg_array_avg_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {-1,-2,-4}; // arrays where all elements are negative 
    double array_2[5] = {-9,-3,-3,-2,-5};
    double array_3[7] = {-1,-2,-3,-6,-5,-11,-8};

    CU_ASSERT_EQUAL(average(array_1, size_1), -2.3333333333333); // assertions
    CU_ASSERT_EQUAL(average(array_2, size_2), -4.4);
    CU_ASSERT_EQUAL(average(array_3, size_3), -5.1428571428571);
}

void pos_neg_doubles_avg_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {-4.1,-1.1,4}; // arrays where elements are both positive and negative doubles, including zeros
    double array_2[5] = {-1.5, 2.2, 3, 0, -1.4};
    double array_3[7] = {1,4.16,0,3.3,6,-1.1,8};

    CU_ASSERT_EQUAL(average(array_1, size_1), -0.4); // assertions
    CU_ASSERT_EQUAL(average(array_2, size_2), 0.46);
    CU_ASSERT_EQUAL(average(array_3, size_3), 3.0514285714286);
}

void last_ele_zero_avg_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {1,2,0}; // arrays where last element is always a zero
    double array_2[5] = {-1,9,3,2,0};
    double array_3[7] = {-2,12,-1,9,2,1,0};

    CU_ASSERT_EQUAL(average(array_1, size_1), 1); // assertions
    CU_ASSERT_EQUAL(average(array_2, size_2), 2.6);
    CU_ASSERT_EQUAL(average(array_3, size_3), 3);
}


void empty_array_avg_testcase(void) // finished
{
    int size_1 = 0; // size of array

    double array_1[0] = {}; // array with no elements (empty)

    CU_ASSERT_TRUE(average(array_1, size_1)); // assertions
    CU_ASSERT_DOUBLE_NOT_EQUAL(average(array_1, size_1),0,0);
}

void one_element_array_avg_testcase(void) // finished
{
    int size_1 = 1; // various size for different arrays
    int size_2 = 1;
    int size_3 = 1;

    double array_1[1] = {1}; // arrays with only one element
    double array_2[1] = {-9};
    double array_3[1] = {5};

    CU_ASSERT_EQUAL(average(array_1, size_1), 1); // assertions
    CU_ASSERT_EQUAL(average(array_2, size_2), -9);
    CU_ASSERT_EQUAL(average(array_3, size_3), 5);
}

void all_zero_array_avg_testcase(void) // finished
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {0,0,0}; // arrays where all elements are zeroes
    double array_2[5] = {0,0,0,0,0};
    double array_3[7] = {0,0,0,0,0,0,0};

    CU_ASSERT_EQUAL(average(array_1, size_1), 0); // assertions
    CU_ASSERT_EQUAL(average(array_2, size_2), 0);
    CU_ASSERT_EQUAL(average(array_3, size_3), 0);
}

/////////////////////////////////////////////////////////////////////////////////////////////

void all_same_max_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 9;

    double array_1[3] = {2,2,2}; // arrays where all elements are the same
    double array_2[5] = {6,6,6,6,6};
    double array_3[9] = {15,15,15,15,15,15,15,15,15};

    CU_ASSERT_EQUAL(max(array_1, size_1), 2); // assertions for each array
    CU_ASSERT_EQUAL(max(array_2, size_2), 6);
    CU_ASSERT_EQUAL(max(array_3, size_3), 15);
}

void all_same_zero_max_testcase(void)
{
    int size_1 = 4; // various size for different arrays
    int size_2 = 7;
    int size_3 = 9;

    double array_1[4] = {5,5,5,0}; // arrays where all elements are the same and last element is zero
    double array_2[7] = {8,8,8,8,8,8,0};
    double array_3[9] = {2,2,2,2,2,2,2,2,0};

    CU_ASSERT_EQUAL(max(array_1, size_1), 5); // assertions for each array
    CU_ASSERT_EQUAL(max(array_2, size_2), 8);
    CU_ASSERT_EQUAL(max(array_3, size_3), 2);
}

void all_different_max_testcase(void)
{
    int size_1 = 4; // various size for different arrays
    int size_2 = 5;
    int size_3 = 8;

    double array_1[4] = {1,2,3,4}; // arrays where all elements are different
    double array_2[5] = {5,3,7,0,9};
    double array_3[8] = {7,4,3,1,2,8,5,6};

    CU_ASSERT_EQUAL(max(array_1, size_1), 4); // assertions for each array
    CU_ASSERT_EQUAL(max(array_2, size_2), 9);
    CU_ASSERT_EQUAL(max(array_3, size_3), 8);
}

void normal_array_max_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {1,2,0}; // normal arrays with positive values
    double array_2[5] = {1,9,3,2,0};
    double array_3[7] = {1,2,3,6,5,11,4};

    CU_ASSERT_EQUAL(max(array_1, size_1), 2); // assertions for each case
    CU_ASSERT_EQUAL(max(array_2, size_2), 9);
    CU_ASSERT_EQUAL(max(array_3, size_3), 11);
}

void pos_array_max_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {5,2,1}; // arrays where all elements are positive
    double array_2[5] = {7,3,4,18,5};
    double array_3[7] = {12,13,9,8,15,15,0};

    CU_ASSERT_EQUAL(max(array_1, size_1), 5); // assertions
    CU_ASSERT_EQUAL(max(array_2, size_2), 18);
    CU_ASSERT_EQUAL(max(array_3, size_3), 15);
}

void neg_array_max_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {-1,-2,-4}; // arrays where all elements are negative
    double array_2[5] = {-9,-3,-3,-2,-5};
    double array_3[7] = {-1,-2,-3,-6,-5,-11,-8};

    CU_ASSERT_EQUAL(max(array_1, size_1), -1); // assertions
    CU_ASSERT_EQUAL(max(array_2, size_2), -2);
    CU_ASSERT_EQUAL(max(array_3, size_3), -1);
}

void pos_neg_doubles_max_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {-4.1,-1.1,4}; // arrays where elements are both positive and negative doubles, including zeroes
    double array_2[5] = {-1.5, 2.2, 4, 0, -1.4};
    double array_3[7] = {1,4.16,0,3.3,6,-1.1,8};

    CU_ASSERT_EQUAL(max(array_1, size_1), 4); // assertions
    CU_ASSERT_EQUAL(max(array_2, size_2), 4);
    CU_ASSERT_EQUAL(max(array_3, size_3), 8);
}

void last_ele_zero_max_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {1,2,0}; // arrays where the last element is a zero
    double array_2[5] = {-1,9,3,2,0};
    double array_3[7] = {1,2,3,-6,5,11,0};

    CU_ASSERT_EQUAL(max(array_1, size_1), 2); // assertions
    CU_ASSERT_EQUAL(max(array_2, size_2), 9);
    CU_ASSERT_EQUAL(max(array_3, size_3), 11);
}


void empty_array_max_testcase(void)
{
    int size_1 = 0; // size for array

    double array_1[0] = {}; // empty array

    CU_ASSERT_EQUAL(max(array_1, size_1), 0); // assertion
}

void one_element_array_max_testcase(void)
{
    int size_1 = 1; // various size for different arrays
    int size_2 = 1;
    int size_3 = 1;

    double array_1[1] = {1}; // arrays with only one element
    double array_2[1] = {-9};
    double array_3[1] = {5};

    CU_ASSERT_EQUAL(max(array_1, size_1), 1); // assertions
    CU_ASSERT_EQUAL(max(array_2, size_2), -9);
    CU_ASSERT_EQUAL(max(array_3, size_3), 5);
}

void all_zero_array_max_testcase(void)
{
    int size_1 = 3; // various size for different arrays
    int size_2 = 5;
    int size_3 = 7;

    double array_1[3] = {0,0,0}; // arrays where all elements are zero
    double array_2[5] = {0,0,0,0,0};
    double array_3[7] = {0,0,0,0,0,0,0};
    
    CU_ASSERT_EQUAL(max(array_1, size_1), 0); // assertions
    CU_ASSERT_EQUAL(max(array_2, size_2), 0);
    CU_ASSERT_EQUAL(max(array_3, size_3), 0);
}

//////////////////////////////////////////////////////////////////////////////////////////////

void runAllTests()
{
    printf("----------------------------------------------------------------------\n");

    CU_initialize_registry(); // suite for average function
    CU_pSuite suite1 = CU_add_suite("average_suite", 0, 0);
            
    CU_add_test(suite1, "Testing: all_same_avg_testcase", all_same_avg_testcase);
    CU_add_test(suite1, "Testing: all_same_zero_avg_testcase", all_same_zero_avg_testcase);
    CU_add_test(suite1, "Testing: all_different_avg_testcase", all_different_avg_testcase);
    CU_add_test(suite1, "Testing: normal_array_avg_testcase", normal_array_avg_testcase);
    CU_add_test(suite1, "Testing: pos_array_avg_testcase", pos_array_avg_testcase);
    CU_add_test(suite1, "Testing: neg_array_avg_testcase", neg_array_avg_testcase);
    CU_add_test(suite1, "Testing: pos_neg_doubles_avg_testcase", pos_neg_doubles_avg_testcase);
    CU_add_test(suite1, "Testing: last_ele_zero_avg_testcase", last_ele_zero_avg_testcase);
    CU_add_test(suite1, "Testing: empty_array_avg_testcase", empty_array_avg_testcase);
    CU_add_test(suite1, "Testing: one_element_array_avg_testcase", one_element_array_avg_testcase);
    CU_add_test(suite1, "Testing: all_zero_array_avg_testcase", all_zero_array_avg_testcase);
 
    CU_pSuite suite2 = CU_add_suite("max_suite", 0, 0);
    
    CU_add_test(suite2, "Testing: all_same_max_testcase", all_same_max_testcase);
    CU_add_test(suite2, "Testing: all_same_zero_max_testcase", all_same_zero_max_testcase);
    CU_add_test(suite2, "Testing: all_different_max_testcase", all_different_max_testcase);
    CU_add_test(suite2, "Testing: normal_array_max_testcase", normal_array_max_testcase);
    CU_add_test(suite2, "Testing: pos_array_max_testcase", pos_array_max_testcase);
    CU_add_test(suite2, "Testing: neg_array_max_testcase", neg_array_max_testcase);
    CU_add_test(suite2, "Testing: pos_neg_doubles_max_testcase", pos_neg_doubles_max_testcase);
    CU_add_test(suite2, "Testing: last_ele_zero_max_testcase", last_ele_zero_max_testcase);
    CU_add_test(suite2, "Testing: empty_array_max_testcase", empty_array_max_testcase);
    CU_add_test(suite2, "Testing: one_element_array_max_testcase", one_element_array_max_testcase);
    CU_add_test(suite2, "Testing: all_zero_array_max_testcase", all_zero_array_max_testcase);
       
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    printf("----------------------------------------------------------------------\n");
}


int main(void)
{
    
    runAllTests(); // call to function to run all tests on functions
    
    printf("End of Program.\n"); // signals end of program
    
    return 0;
}

