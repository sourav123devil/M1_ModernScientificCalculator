#include "unity.h"

/* Modify these two lines according to the project */
#include "calculator_operations.h"
#define PROJECT_NAME  "Scientific_Calculator"
#define INT_MAX __INT_MAX__


static arithmatic arithmatic_operands={0,0};
static trignometric trignometric_operands={0};
static single_double_inputs double_opearnd={0};
static single_int_inputs int_operand={0};

/* Prototypes for all the test functions */
void test_add(void);
void test_subtract(void);
void test_multiply(void);
void test_divide(void);
void test_sin(void);
void test_cos(void);
void test_tan(void);
void test_cosec(void);
void test_sec(void);
void test_cot(void);
void test_exponent(void);
void test_natural_log(void);
void test_base_10_log(void);
void test_square_root(void);
void test_nth_root(void);
void test_square(void);
void test_nth_power(void);
void test_x_th_power_of_10(void);
void test_factorial(void);


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_add);
  RUN_TEST(test_subtract);
  RUN_TEST(test_multiply);
  RUN_TEST(test_divide);
  RUN_TEST(test_sin);
  RUN_TEST(test_cos);
  RUN_TEST(test_tan);
  RUN_TEST(test_cosec);
  RUN_TEST(test_sec);
  RUN_TEST(test_cot);
  RUN_TEST(test_exponent);
  RUN_TEST(test_natural_log);
  RUN_TEST(test_base_10_log);
  RUN_TEST(test_square_root);
  RUN_TEST(test_nth_root);
  RUN_TEST(test_square);
  RUN_TEST(test_nth_power);
  RUN_TEST(test_x_th_power_of_10);
  RUN_TEST(test_factorial);


  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_add(void) {
  arithmatic_operands.operand1=10;
  arithmatic_operands.operand2=20;
  TEST_ASSERT_EQUAL(SUCCESS, add(&arithmatic_operands));
  TEST_ASSERT_EQUAL(30.00, arithmatic_operands.output);
  
  arithmatic_operands.operand1=2.3;
  arithmatic_operands.operand2=-1.2;
  TEST_ASSERT_EQUAL(SUCCESS, add(&arithmatic_operands));
  TEST_ASSERT_EQUAL(1.10, arithmatic_operands.output);
}

void test_subtract(void) {
  arithmatic_operands.operand1=10;
  arithmatic_operands.operand2=20;
  TEST_ASSERT_EQUAL(SUCCESS, subtract(&arithmatic_operands));
  TEST_ASSERT_EQUAL(-10.00, arithmatic_operands.output);
  
  arithmatic_operands.operand1=2.3;
  arithmatic_operands.operand2=-1.2;
  TEST_ASSERT_EQUAL(SUCCESS, subtract(&arithmatic_operands));
  TEST_ASSERT_EQUAL(3.30, arithmatic_operands.output);
}

void test_multiply(void) {
  arithmatic_operands.operand1=10;
  arithmatic_operands.operand2=20;
  TEST_ASSERT_EQUAL(SUCCESS, multiply(&arithmatic_operands));
  TEST_ASSERT_EQUAL(200.00, arithmatic_operands.output);
  
  arithmatic_operands.operand1=2.3;
  arithmatic_operands.operand2=-1.2;
  TEST_ASSERT_EQUAL(SUCCESS, multiply(&arithmatic_operands));
  TEST_ASSERT_EQUAL(-2.76, arithmatic_operands.output);
}

void test_divide(void) {
  arithmatic_operands.operand1=20;
  arithmatic_operands.operand2=10;
  TEST_ASSERT_EQUAL(SUCCESS, divide(&arithmatic_operands));
  TEST_ASSERT_EQUAL(2.00, arithmatic_operands.output);
  
  arithmatic_operands.operand1=2.3;
  arithmatic_operands.operand2=-1.2;
  TEST_ASSERT_EQUAL(SUCCESS, divide(&arithmatic_operands));
  TEST_ASSERT_EQUAL(-1.92, arithmatic_operands.output);

//  we are assuming output=0 for operand=0
  arithmatic_operands.operand1=2.3;
  arithmatic_operands.operand2=0;
  TEST_ASSERT_EQUAL(ERROR_DIVISION_BY_ZERO, divide(&arithmatic_operands));
  TEST_ASSERT_EQUAL(0, arithmatic_operands.output);
}

void test_sin(void){
  trignometric_operands.operand=30;
  TEST_ASSERT_EQUAL(SUCCESS, sine(&trignometric_operands));
  TEST_ASSERT_EQUAL(0.50, trignometric_operands.output);

  trignometric_operands.operand=-60;
  TEST_ASSERT_EQUAL(SUCCESS, sine(&trignometric_operands));
  TEST_ASSERT_EQUAL(-0.87, trignometric_operands.output);

}
void test_cos(void){
  trignometric_operands.operand=30;
  TEST_ASSERT_EQUAL(SUCCESS, Cos(&trignometric_operands));
  TEST_ASSERT_EQUAL(0.87, trignometric_operands.output);

  trignometric_operands.operand=-60;
  TEST_ASSERT_EQUAL(SUCCESS, Cos(&trignometric_operands));
  TEST_ASSERT_EQUAL(0.50, trignometric_operands.output);

}
void test_tan(void){
  trignometric_operands.operand=30;
  TEST_ASSERT_EQUAL(SUCCESS, Tan(&trignometric_operands));
  TEST_ASSERT_EQUAL(0.58, trignometric_operands.output);

  trignometric_operands.operand=-60;
  TEST_ASSERT_EQUAL(SUCCESS, Tan(&trignometric_operands));
  TEST_ASSERT_EQUAL(-1.73, trignometric_operands.output); 

  trignometric_operands.operand=90;
  TEST_ASSERT_EQUAL(UNDEFINED, Tan(&trignometric_operands));
}
void test_cosec(void){
  trignometric_operands.operand=30;
  TEST_ASSERT_EQUAL(SUCCESS, Cosec(&trignometric_operands));
  TEST_ASSERT_EQUAL(2, trignometric_operands.output); 

  trignometric_operands.operand=0;
  TEST_ASSERT_EQUAL(UNDEFINED, Cosec(&trignometric_operands));
}
void test_sec(void){
  trignometric_operands.operand=30;
  TEST_ASSERT_EQUAL(SUCCESS, Sec(&trignometric_operands));
  TEST_ASSERT_EQUAL(1.15, trignometric_operands.output); 

  // trignometric_operands.operand=90;
  // TEST_ASSERT_EQUAL(UNDEFINED, Sec(&trignometric_operands));
}
void test_cot(void){
  trignometric_operands.operand=30;
  TEST_ASSERT_EQUAL(SUCCESS, Cot(&trignometric_operands));
  TEST_ASSERT_EQUAL(1.73, trignometric_operands.output); 

  trignometric_operands.operand=0;
  TEST_ASSERT_EQUAL(UNDEFINED, Cot(&trignometric_operands)); 
}
void test_exponent(void){

double_opearnd.operand=2;
TEST_ASSERT_EQUAL(SUCCESS, Exponent(&double_opearnd));
TEST_ASSERT_EQUAL(7.39,double_opearnd.output);

}
void test_natural_log(void){
double_opearnd.operand=-3;
TEST_ASSERT_EQUAL(UNDEFINED, Natural_log(&double_opearnd)); 

double_opearnd.operand=2;
TEST_ASSERT_EQUAL(SUCCESS, Natural_log(&double_opearnd));
TEST_ASSERT_EQUAL(0.69, double_opearnd.output);
}
void test_base_10_log(void){
double_opearnd.operand=-3;
TEST_ASSERT_EQUAL(UNDEFINED, base_10_log(&double_opearnd)); 

double_opearnd.operand=2;
TEST_ASSERT_EQUAL(SUCCESS, base_10_log(&double_opearnd));
TEST_ASSERT_EQUAL(0.30, double_opearnd.output);

}
void test_square_root(void){
double_opearnd.operand=-3;
TEST_ASSERT_EQUAL(UNDEFINED, square_root(&double_opearnd)); 

double_opearnd.operand=2;
TEST_ASSERT_EQUAL(SUCCESS, square_root(&double_opearnd));
TEST_ASSERT_EQUAL(1.41,double_opearnd.output);
}
void test_nth_root(void){
arithmatic_operands.operand1=-3;
arithmatic_operands.operand2=4;
TEST_ASSERT_EQUAL(UNDEFINED, nth_root(&arithmatic_operands)); 
arithmatic_operands.operand1=8;
arithmatic_operands.operand2=5;
TEST_ASSERT_EQUAL(SUCCESS, nth_root(&arithmatic_operands));
TEST_ASSERT_EQUAL(1.52, arithmatic_operands.output);
}
void test_square(void){
double_opearnd.operand=2;
TEST_ASSERT_EQUAL(SUCCESS, square(&double_opearnd));
TEST_ASSERT_EQUAL(4.00,double_opearnd.output);
}
void test_nth_power(void){
 
arithmatic_operands.operand1=8;
arithmatic_operands.operand2=5;
TEST_ASSERT_EQUAL(SUCCESS, nth_power(&arithmatic_operands));
TEST_ASSERT_EQUAL(32768.00, arithmatic_operands.output);

}
void test_x_th_power_of_10(void){
double_opearnd.operand=2.3;
TEST_ASSERT_EQUAL(SUCCESS, xth_power_of_10(&double_opearnd));
TEST_ASSERT_EQUAL(199.53, double_opearnd.output);
}
void test_factorial(void){
  // int_operand.operand=-3;
  // TEST_ASSERT_EQUAL(UNDEFINED, factorial(& int_operand));

  int_operand.operand=0;
  TEST_ASSERT_EQUAL(SUCCESS, factorial(&int_operand));
  TEST_ASSERT_EQUAL(1, int_operand.output);

  int_operand.operand=5;
  TEST_ASSERT_EQUAL(SUCCESS, factorial(&int_operand));
  TEST_ASSERT_EQUAL(120, int_operand.output);
}