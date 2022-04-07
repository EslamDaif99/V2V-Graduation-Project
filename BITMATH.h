#ifndef BITMATH_H_
#define BITMATH_H_

#define SET_BIT(Reg,Bit)                 ( (Reg) |=  ( (1) << (Bit) )  )
#define CLR_BIT(Reg,Bit)                 ( (Reg) &= ~( (1) << (Bit) )  )
#define TGL_BIT(Reg,Bit)                 ( (Reg) ^=  ( (1) << (Bit) )  )
#define GET_BIT(Reg,Bit)                 ( (Reg) >>   (Bit) & ( 1  )  )

#endif
