#!/bin/tcsh
setenv DYLD_LIBRARY_PATH .
setenv DYLD_INSERT_LIBRARIES libft_malloc.so
setenv DYLD_FORCE_FLAT_NAMESPACE 1 
#../Push_swap/push_swap 7 3 32 1
#../cdeniau5/./ft_minishell1
../fdf/fdf ../fdf/test_maps/10-2.fdf
