//-------------------------------------------------
//! Prints graphics and tells what this program is.
//-------------------------------------------------
void start_intro(void);

//-------------------------------------------------------------------------
//! Prints question whether the user wants to choose console or file input.
//-------------------------------------------------------------------------
void input_choice_text(void);

//--------------------------------------------------------------------------
//! Prints question whether the user wants to choose console or file output.
//--------------------------------------------------------------------------
void output_choice_text(void);

//--------------------------------------------------------------------------
//! Prints example of how to enter coefficients to there was no input error.
//--------------------------------------------------------------------------
void example_of_input_coefficients(void);

//--------------------------------------------------------------------------------------------------------
//! Prints the mistake text when the number you entered is not correct (for example, it is char, not int).
//--------------------------------------------------------------------------------------------------------
void problem_with_input_one_text(void);

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Prints the mistake text when 3 numbers you entered from the console are not correct to the type or amount. Also, it proposes the idea of entering them one again.
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
void problem_with_input_three_text(void);

//---------------------------------------------------------------------------------------------------------
//! Prints the mistake text when 3 numbers you entered from the file are not correct to the type or amount.
//---------------------------------------------------------------------------------------------------------
void problem_with_input_three_text_file(void);

void assert_true(void);