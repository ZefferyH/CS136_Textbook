// constant pointer

int main(void) {
    int i = 1;

    int *p = &i;
    // p can point at any mutable integer, you can modify the int (via *p)

    const int *p = &i;
    // p can point at any integer, you can NOT modify the integer (via *p)

    int * const p = &i;
    // p always points at the integer i , i must be mutable and can be modified (via *p)

    const int * const p = &i;
    // p always points at the integer i , you can not modify i (via *p)

}