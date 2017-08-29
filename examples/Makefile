LUASRC:= ../lua/src/

CC:= gcc
CFLAGS:= -std=gnu99 -O2 -Wall -Wextra -DLUA_COMPAT_5_2 -fPIC -g
CPPFLAGS:= -I$(LUASRC)

.PHONY: all clean

all: \
    fill_table_titan.so \
    selection_sort_titan.so \
    sieve_titan.so \
    sum_1_N_typed_titan.so \
    sum_1_N_dynamic_titan.so

clean:
	rm -rf ./*.o ./*.so

%.so:
	$(CC) -shared $^ -o $@

libtitan.o: libtitan.c libtitan.h
fill_table_titan.o: fill_table_titan.c libtitan.h
selection_sort_titan.o: selection_sort_titan.c libtitan.h
sieve_titan.o: sieve_titan.c libtitan.h
sum_1_N_dynamic_titan.o: sum_1_N_dynamic_titan.c libtitan.h
sum_1_N_typed_titan.o: sum_1_N_typed_titan.c libtitan.h

fill_table_titan.so: fill_table_titan.o libtitan.o
selection_sort_titan.so: selection_sort_titan.o libtitan.o
sieve_titan.so: sieve_titan.o libtitan.o
sum_1_N_dynamic_titan.so : sum_1_N_dynamic_titan.o libtitan.o
sum_1_N_typed_titan.so : sum_1_N_typed_titan.o libtitan.o
