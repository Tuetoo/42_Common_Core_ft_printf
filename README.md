# ft_printf

## Overview
`ft_printf` is a custom implementation of the `printf` function in C. The project is divided into two versions:
- **Version 1 (Mandatory Only):** A clean and minimal implementation of `printf` without any external libraries.
- **Version 2 (With Libft):** An extended version that includes all mandatory and bonus requirements and integrates the `libft` library.

## Versions
### Version 1 Simple Version (Mandatory Only)

**File Structure**
ft_printf_project/
├── ft_printf.h 
├── ft_printf.c  
├── ft_printf_utils.c  
├── Makefile  

**Purpose**
This version aims to practice implementing the core features of printf while keeping the code simple and free from external dependencies.

**Features**
- Handles conversion specifiers: c, s, p, d, i, u, x, X, %.
- Supports basic alignment.
- Handles NULL strings and zero values correctly.
- Minimal implementation without libft dependency.

### Version 2: First Try Version (Basis + Bonus with Libft)

**File Structure**
ft_printf_project/
├── ft_printf.h                 
├── ft_printf.c                 
├── ft_putchar_format.c         
├── ft_putdigit_format.c        
├── ft_putnbr_base.c            
├── ft_putnchar.c               
├── ft_putpointer_format.c      
├── libft/                      
├── Makefile                    

**Purpose**
This version includes both mandatory and bonus requirements, extending the functionality of printf by supporting additional format specifiers and integrating the libft library. This version offers more advanced formatting and improved flexibility in handling various data types.

**Features**
 - Implements all conversion specifiers and formatting options.
 - Supports flags: -, 0, #, , +.
 - Handles width and precision formatting.
 - Uses functions from libft (e.g., ft_strlen, ft_strchr, ft_strdup, ft_strjoin).
 - Includes advanced formatting, including handling for padding, signs, and pointer formatting.
 - Makefile compiles both libft and ft_printf into a static library (libftprintf.a) and allows you to generate the executable with the command make exec.

## Author
**Jiemin (Jenny) Zhang**  
42 Login: jiezhang