Besides functions you can also write documentation for structs, unions, enums and typedefs.
Instead of the function name you must write the name of the declaration;
the struct/union/enum/typedef must always precede the name. Nesting of declarations is not supported.
Use the argument mechanism to document members or constants.

Example 1:

/**
 * struct my_struct - Short description
 * @a: First member
 * @b: Second member
 *
 * Description: Longer description
 */
struct my_struct
{
	int a;
	int b;
	/**
	 * @c: This is longer description of C
	 *
	 * Description: You can use paragraphs to describe arguments
	 * using this method.
	 */
	int c;
};


Example 2:
/**
 * u_int - Typedef for unsigned int
 */
typedef unsigned int u_int;
