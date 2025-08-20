typedef enum {
    kZeroRoots = 0,
    kOneRoot   = 1,
    kTwoRoots  = 2,
    kInfRoots  = INT_MAX
} RootsCount;

void start_intro(void);

int input_choice(void);
int output_choice(void);
int input_transfer(int input_choice_result); 
int input_with_file(void);
void input_with_console(void);
void clear_input_buffer(void);
int output(int output_choice_result);

int find_result(float a, float b, float c, float *result1, float *result2);
bool is_zero(float number);
float calculate_discriminant(float a, float b, float c);
RootsCount find_linear_root(float b, float c, float *result1);
RootsCount find_quadratic_roots(float a, float b, float c, float *result1, float *result2);
void sort_result(float *result1, float *result2);