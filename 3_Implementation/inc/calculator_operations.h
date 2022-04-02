
#ifndef __CALCULATOR_OPERATIONS_H__
#define __CALCULATOR_OPERATIONS_H__

#include <stdio.h>
#include <stdlib.h>
// #include <stdio_ext.h>

// structure variable for arithmatic inputs
typedef struct{
    double operand1;
    double operand2;
    double output;
}arithmatic;

// structure variable for trignometric inputs
typedef struct{
    double operand;
    double output;
}trignometric;

// structure variable for single input as type integer
typedef struct{
    unsigned int operand;
    unsigned long long int output;
}single_int_inputs;

// structure variable for single input as type float
typedef struct{
    double operand;
    double output;
}single_double_inputs;


// errors enum
typedef enum error_t{
    SUCCESS=1,
    FAILURE=0,
    UNDEFINED=-1,
    ERROR_DIVISION_BY_ZERO=-2,
}error_t;



/**
*  adds the operand1 and operand2 and returns the result
* @param[in] operand1 
* @param[in] operand2 
* @return Result of operand1 + operand2
*/
error_t add(arithmatic* data);

/**
*  subtracts the operand1, operand2 and returns the result
* @param[in] operand1 
* @param[in] operand2 
* @return Result of operand1 - operand2
*/
error_t subtract(arithmatic* data);

/**
*  multiply the operand1, operand2 and returns the result
* @param[in] operand1 
* @param[in] operand2 
* @return Result of operand1 * operand2
*/
error_t multiply(arithmatic* data);


/**
* divides the operand1 by operand2 and returns the result 
* @param[in] operand1 
* @param[in] operand2 
* @return integer value of the operand1 / operand2
* @note returns 0 for divide by 0 error
*/
error_t divide(arithmatic* data);
/**
 * @brief 
 * 
 * @param operand 
 * @return double 
 */
error_t sine(trignometric* data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t Cos(trignometric* data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t Tan(trignometric* data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t Cot(trignometric* data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t Sec(trignometric* data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t Cosec(trignometric* data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t Exponent(single_double_inputs* data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t Natural_log(single_double_inputs* data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t base_10_log(single_double_inputs* data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t square_root(single_double_inputs*data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t nth_root(arithmatic* data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t square(single_double_inputs* data);
/**
 * @brief 
 * 
 * @param data 
 * @return error_t 
 */
error_t nth_power(arithmatic* data);
/**
 * @brief function to calculate xth power of 10
 * 
 * @param data 
 * @return error_t 
 */
error_t xth_power_of_10(single_double_inputs* data);
/**
 * @brief function to calculate factorial of number
 * 
 * @param data 
 * @return error_t 
 */
error_t factorial(single_int_inputs* data);


#endif  /* #define __CALCULATOR_OPERATIONS_H__ */