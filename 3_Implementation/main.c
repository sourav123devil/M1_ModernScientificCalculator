#include"calculator_operations.h"
#include<stdio.h>

/* Status of the operation requested */
#define VALID   (1)
#define INVALID (0)

/* Calculator operation requested by user*/
unsigned int calculator_operation = 0;

/* Operands on which calculation is performed */
arithmatic arithmatic_operands={0,0};
trignometric trignometric_operands={0};
single_double_inputs double_opearnd={0};
single_int_inputs int_operand={0};

/* Valid operations */
enum operations{ ADD=1, SUBTRACT, MULTIPLY, DIVIDE,SIN,COS,TAN, COSEC, SEC,COT,EXP, NATURAL_LOG, BASE_10_LOG ,SQUARE_ROOT, SQUARE,  xth_POWER_of_10,Nth_ROOt, NTH_POWER,FACTORIAL, EXIT };

error_t (*arithmatic_function[4])(arithmatic*)={add,subtract,multiply,divide};
char arithmatic_symbol[4][3]={"+","-","*","/"};

/* Display the menu of operations supported */
void calculator_menu(void);
/* Verifies the requested operations validity */
int valid_operation(int operation);


error_t (*trignometric_function[6])(trignometric*)={sine,Cos,Tan,Cosec,Sec,Cot};
char trignometric_symbol[6][8]={"sin","cos","tan","cosec","sec","cot"};

error_t (*other_mathemaical_functions[6])(single_double_inputs*)={Exponent, Natural_log, base_10_log ,square_root, square, xth_power_of_10};
char other_mathemaical_function_symbol[6][12]={"e^","ln","log10","square root","square","10^"};



/* Start of the application */
int main(int argc, char *argv[])
{
    
    printf("\n\t\t\t\t****Calculator****\n");
    while(1)
    {
        calculator_menu();
    }
}

void calculator_menu(void)
{
    printf("\n\t\tAvailable functions \n");
    printf("\n 1. Addition\t\t2. Subtraction\t3. Multiplication \t4. Division ");
    printf("\n 5. sin()\t6. cos()\t7. tan()");
    printf("\n 8. cosec()\t9. sec()\t10. cot()");
    printf("\n11. exp()\t12. ln()\t13. log10()\n14. Square root 15. Square\t16. 10^x");
    printf("\n17. nth root\t18. nth power\t19. Factorial\n20. Exit");
    printf("\n\n\t\t\t\tEnter your choice\n");
   
    //  __fpurge(stdin);
    scanf("%d", &calculator_operation);


    if(EXIT == calculator_operation)
    {
        printf("\nThank you. Exiting the Application\n");
        exit(0);
    }

     if(INVALID != valid_operation(calculator_operation) && calculator_operation<=4)
    {
        printf("\n\tEnter your Numbers with space between them\n");
        // __fpurge(stdin);
        scanf("%lf %lf", &arithmatic_operands.operand1, &arithmatic_operands.operand2);
        (arithmatic_function[calculator_operation-1]) (&arithmatic_operands);
        printf("\n\t%.2lf %s %.2lf = %.2lf\n\n\n", 
            arithmatic_operands.operand1,arithmatic_symbol[calculator_operation-1],
            arithmatic_operands.operand2,arithmatic_operands.output);

    }else if(INVALID != valid_operation(calculator_operation) &&( calculator_operation>4 && calculator_operation<=10) ){
        printf("\n\tEnter your Number \n");
        // __fpurge(stdin);
        scanf("%lf", &trignometric_operands.operand);
        (trignometric_function[calculator_operation-5]) (&trignometric_operands);
        printf("\n\t%s(%.2lf) = %.2lf\n\n\n", 
            trignometric_symbol[calculator_operation-5],
            trignometric_operands.operand,trignometric_operands.output);
    }
    else  if(INVALID != valid_operation(calculator_operation) && (calculator_operation>10 && calculator_operation<=16 ))
    {
        printf("\n\tEnter your Number\n");
        // __fpurge(stdin);
        scanf("%lf", &double_opearnd.operand);
        (other_mathemaical_functions[calculator_operation-11]) (&double_opearnd);
        printf("\n\t%s(%.2lf) = %.2lf\n\n\n", 
            other_mathemaical_function_symbol[calculator_operation-11],
            double_opearnd.operand,double_opearnd.output);
    }else if(INVALID != valid_operation(calculator_operation) && calculator_operation==Nth_ROOt){

            printf("\n\tEnter your Number and then root with space between them \n");
            scanf("%lf %lf", &arithmatic_operands.operand1, &arithmatic_operands.operand2);
            nth_root(&arithmatic_operands);
            printf("\n\t%dth root of %.2lf = %.2lf\n\n\n", 
            (int)(arithmatic_operands.operand2),arithmatic_operands.operand1,
            arithmatic_operands.output);

    }else if(INVALID != valid_operation(calculator_operation) && calculator_operation==NTH_POWER){
            printf("\n\tEnter your Number and then power  with space between them  \n");
            scanf("%lf %lf", &arithmatic_operands.operand1, &arithmatic_operands.operand2);
            nth_power(&arithmatic_operands);
            printf("\n\t%.2lf^%.2lf = %.2lf\n\n\n", 
            arithmatic_operands.operand1,arithmatic_operands.operand2,
            arithmatic_operands.output);

    }else if(INVALID != valid_operation(calculator_operation) && calculator_operation==FACTORIAL){
        printf("\n\tEnter your Number for factorial\n");
        // __fpurge(stdin);
        scanf("%d", &int_operand.operand);
        factorial(&int_operand);
        printf("\n\t%d! = %lld\n\n\n", 
            int_operand.operand,int_operand.output );
        
    }
    else
    {
        printf("\n\t---Wrong choice---\nEnter to continue\n");
        // __fpurge(stdin);
        getchar();
        return;
        
    }

}

int valid_operation(int operation)
{
    /* Check if the operation is a valid operation */
    return ((ADD <= operation) && (EXIT >= operation)) ? VALID: INVALID;
}