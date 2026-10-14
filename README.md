*This project has been created as part of the 42 curriculum by maalruwa*

# ft_printf

##  Description
`ft_printf` is a project from the 42 curriculum that aims to rebuild the standard C `printf` function.  
The goals of the project are:
- Learn how to handle **variadic functions** using `va_list`.
- Support the required format specifiers: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`.
- Practice memory management, string manipulation, and type conversions.
- Strengthen low-level programming skills while following the strict **Norminette** coding style.

---

##  Instructions
### Compilation
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd ft_printf
### make
make clean     # remove object files
make fclean    # remove object files and the library
make re        # rebuild everything from scratch


That entire block is the **Instructions section**. It tells anyone unfamiliar with the project how to set it up and run it.  

If you want, I can expand it with a **“Execution” subsection** that shows how to run a test program using `ft_printf` (for example compiling `main.c` with `libftprintf.a`). Would you like me to add that so the Instructions section is more complete?
##  Resources
- [C Standard Library Documentation](https://en.cppreference.com/w/c)

- Tutorials:
  - GeeksforGeeks: Variadic Functions in C
  - Learn C: Pointers and Memory
###  AI Usage
AI (Microsoft Copilot) was used to:
- Draft and refine the README.md structure.
- Provide guidance on handling `NULL` values and edge cases.
- Recommend references and documentation links.

##  Algorithm & Data Structure Justification
- **Variadic arguments**: Implemented using `va_list`, `va_start`, `va_arg`, and `va_end` to handle an arbitrary number of arguments safely.
- **String conversion**: Custom `ft_itoa` and `ft_uitoa` functions convert integers to strings using dynamic memory allocation. This ensures flexibility and control over memory.
- **Hex conversion**: Implemented with repeated division by 16, building the string backwards. This is efficient and simple for base conversion.
- **Data structures**: Only simple arrays and strings are used. No complex structures are required, since the project’s focus is on memory management and formatted output.
- **Justification**: The chosen algorithms are minimalistic, efficient, and aligned with the constraints of the 42 curriculum (no use of standard `printf`, limited library functions, strict coding style). They provide clarity, maintainability, and compliance with Norminette.
