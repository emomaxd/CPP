

struct numbers{
    int a;
    int b;
};

program MYAPP_PROG {
    version MYAPP_VERSION {
        int add(numbers)=1;
    }=1;
}=0x12345;
