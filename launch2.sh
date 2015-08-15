#!/bin/tcsh
setenv DYLD_LIBRARY_PATH .
setenv DYLD_INSERT_LIBRARIES libft_malloc.so
setenv DYLD_FORCE_FLAT_NAMESPACE 1 
../Push_swap/push_swap 7 3 2
#./test T 3 2 1
