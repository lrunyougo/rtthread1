MEMORY
{
PAGE 0 :
   /* BEGIN is used for the "boot to SARAM" bootloader mode   */

    BEGIN          : origin = 0x000000, length = 0x000002
    RAMM0          : origin = 0x000122, length = 0x0002DE
    RESET          : origin = 0x3FFFC0, length = 0x000002
    RAMGS8_15      : origin = 0x014000, length = 0x008000

PAGE 1 :

    BOOT_RSVD      : origin = 0x000002, length = 0x000120     /* Part of M0, BOOT rom will use this for stack */
    RAMD0          : origin = 0x00B000, length = 0x000800
    RAMLS0_4       : origin = 0x008000, length = 0x002800     /* RAMLS0-4, 5*0x0800   */
    RAMLS5         : origin = 0x00A800, length = 0x000800     /* RAMLS5,   1*0x0800   */
    RAMM1          : origin = 0x000400, length = 0x000400     /* on-chip RAM block M1 */
    RAMD1          : origin = 0x00B800, length = 0x000800

    RAMGS0_2       : origin = 0x00C000, length = 0x003000     /* RAMGS0-2, 3*0x1000   */
    RAMGS3_7       : origin = 0x00F000, length = 0x005000     /* RAMGS3-7, 5*0x1000   */
   
    CPU2TOCPU1RAM  : origin = 0x03F800, length = 0x000400
    CPU1TOCPU2RAM  : origin = 0x03FC00, length = 0x000400
}


SECTIONS
{
   codestart        : > BEGIN,     PAGE = 0
   
#ifdef __TI_COMPILER_VERSION__
   #if __TI_COMPILER_VERSION__ >= 15009000
    .TI.ramfunc : {} > RAMM0,      PAGE = 0
   #else
   ramfuncs         : > RAMM0      PAGE = 0   
   #endif
#endif   
   .text            : > RAMGS8_15, PAGE = 0
   .cinit           : > RAMM0,     PAGE = 0
   .pinit           : > RAMM0,     PAGE = 0
   .switch          : > RAMM0,     PAGE = 0
   .reset           : > RESET,     PAGE = 0, TYPE = DSECT /* not used, */
   .rti_fn.0.end    : > RAMD0,     PAGE = 1
   .rti_fn.0        : > RAMD0,     PAGE = 1
   .rti_fn.1.end    : > RAMD0,     PAGE = 1
   .rti_fn.6.end    : > RAMD0,     PAGE = 1
   .rti_fn.6        : > RAMD0,     PAGE = 1
   .stack           : > RAMM1,     PAGE = 1
   .ebss            : > RAMGS0_2,  PAGE = 1
   .econst          : > RAMGS3_7,  PAGE = 1
   .esysmem         : > RAMLS5,    PAGE = 1

   /* finsh symbol table */
   FSymTab          : > RAMD0,     PAGE = 1, ALIGN(4)
   LOAD_START(___fsymtab_start)
   LOAD_END(___fsymtab_end)

   /* The following section definitions are required when using the IPC API Drivers */ 
    GROUP : > CPU1TOCPU2RAM, PAGE = 1 
    {
        PUTBUFFER 
        PUTWRITEIDX 
        GETREADIDX 
    }
    
    GROUP : > CPU2TOCPU1RAM, PAGE = 1
    {
        GETBUFFER :    TYPE = DSECT
        GETWRITEIDX :  TYPE = DSECT
        PUTREADIDX :   TYPE = DSECT
    }  
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
