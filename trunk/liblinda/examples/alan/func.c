#include "linda.h"

int main(int argc, char* argv[]) {
    LindaValue tuple;
    LindaValue r;
    LindaValue func;
    LindaValue args;

    Linda_connect(Linda_port);

    LindaValue type = Linda_type("func :: int -> int;");

    tuple = Linda_tuple(1);
    Linda_tupleSet(tuple, 0, type); /* steals reference to value */

    r = Linda_in(Linda_uts, tuple);

    func = Linda_tupleGet(r, 0);

    args = Linda_tuple(1);
    Linda_tupleSet(args, 0, Linda_int(1));

    r = Linda_eval(func, args);

    printf("Turned %i into %i.\n", 1, Linda_getInt(r));

    Linda_disconnect();
}
