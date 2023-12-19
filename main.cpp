#include <iostream>
#include <vector>

struct Flag{
    unsigned char dailyctf_flag[25] = { 0x37, 0x3D, 0x32, 0x38, 0x4C, 0x79, 0x26, 0x64, 0x66, 0x30, 0x64, 0x5F, 0x3E, 0x36, 0x30, 0x64, 0x66, 0x43, 0x60, 0x3F, 0x68, 0x64, 0x4E};
};

void rotme()
{
    Flag flag;
    std::vector<unsigned char> rotflag(0);
    for (unsigned char entity : flag.dailyctf_flag)
    {
        entity += 47;
        if (126 < entity) entity -= 94;
        rotflag.push_back(entity);
    }
    
    //std::cout << rotflag.data();
}

void TheJump(void* address)
{
    __asm__ volatile(
        "nop\n\t"
        "push rax\n\t"
        "lea rax, [RIP+3]\n\t"
        "push rax\n\t"
    );

    __asm__ volatile(
        "nop\n\t" //debug
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "pop rax\n\t"
    );
}

int main()
{
    void *jumppoint = (void*)&rotme;
    std::cout << "I don't know if I can make it...that's a far-";

    TheJump(jumppoint);

    return 0;
}
