
ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = \
	test_solve_kdv \
        print_results

test_solve_kdv_SOURCES = test_solve_kdv.c
print_results_SOURCES = print_results.c

lib_LIBRARIES = liblinalg.a
liblinalg_a_SOURCES = \
	kdv.h \
        rhs.c \
	rhs_form.c \
        rk4.c

LDADD = liblinalg.a

TESTS = \
	test_solve_kdv \
        print_results
