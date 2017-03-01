cmake_minimum_required(VERSION 3.6)
project(sunday)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ft_isdigit.c
        ft_print_struct.c
        ft_print_text.c
        ft_printf.h
        ft_struct.c
        ft_struct_fill.c
        main.c
        ft_putnbr.c
        ft_printf.c
        pf_cast.c)

add_executable(sunday ${SOURCE_FILES})