#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VN_S 0
#define VN_A 1
#define VN_B 2
#define VN_C 3
#define VN_C1 4
#define VN_D 5
#define VN_E 6
#define VN_E1 7
#define VN_F 8
#define VN_G 9
#define VN_G1 10








int main()
{
    int RPs[19][7]={
    {Code_MC_SELECT,VN_A,Code_MC_FROM,VN_C1,VN_D,Code_SEP_PTVIRG,-1}, //...........0
    {Code_MC_COUNT,Code_ACCOLADE_OVR,VN_B,Code_ACCOLADE_FER,-1,-1,-1}, //...........1
    {VN_B,-1,-1,-1,-1,-1,-1}, //...........2
    {Code_MC_DISTINCT,VN_C1,-1,-1,-1,-1,-1}, //...........3
    {VN_C1,-1,-1,-1,-1,-1,-1}, //...........4
    {Code_IDENT,VN_C2,-1,-1,-1,-1,-1}, //...........5
    {Code_SEP_VIRG,VN_B,-1,-1,-1,-1,-1}, //...........6
    {EPSILONE,-1,-1,-1,-1,-1,-1}, //...........7
    {Code_MC_WHERE,VN_E1,-1,-1,-1,-1,-1}, //...........8
    {EPSILONE,-1,-1,-1,-1,-1,-1}, //...........9
    {VN_F,VN_E2,-1,-1,-1,-1,-1}, //...........10
    {Code_OP_LOG,VN_E1,-1,-1,-1,-1,-1}, //...........11
    {EPSILONE,-1,-1,-1,-1,-1,-1}, //...........12
    {VN_G1,Code_OP_REL,VN_G1,-1,-1,-1,-1}, //...........13
    {Code_ACCOLADE_OVR,VN_G1,Code_ACCOLADE_FER,VN_G2,-1,-1,-1}, //...........14
    {Code_IDENT,VN_G2,-1,-1,-1,-1,-1}, //...........15
    {Code_NOMBRE,VN_G2,-1,-1,-1,-1,-1}, //...........16
    {Code_OP_ARTH,VN_G1,-1,-1,-1,-1,-1}, //...........17
    {EPSILONE,-1,-1,-1,-1,-1,-1}, //...........18
    };


    return 0;
}
