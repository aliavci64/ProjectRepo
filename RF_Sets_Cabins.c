#include "project.h"
//#include "Refrigerator.h"
//#include "DisplaySpecials.h"

#define _dispQFF    1
#define _dispQFRZ   -27
#define _dispVAC    _Specials_MidLine
#define _dispFRZOFF _Specials_MidLine

const stCabinSetsTemperature_Flash fahrenheitCelciusTable = {    
    .QFRD_ValueCelcius = 1,
    .QFRZ_ValueCelcius = -27,
    .lookUpTable = 
    {  //Fahrenheit   celcius      pointer
      
      {39,             4} ,        //0
      {38,             4} ,        //1
      {37,             3} ,        //2
      {36,             3} ,        //3
      {35,             2} ,        //4
      {34,             2} ,        //5
      {33,             1} ,        //6
      {46,             8} ,        //7
      {45,             8} ,        //8
      {44,             7} ,        //9
      {43,             7} ,        //10
      {42,             6} ,        //11 
      {41,             5} ,        //12
      {40,             5} ,        //13
 
      {0,              -18} ,      //14
      {-1,             -18} ,      //15
      {-2,             -19} ,      //16
      {-3,             -20} ,      //17
      {-4,             -20} ,      //18
      {-5,             -21} ,      //19
      {-6,             -21} ,      //20
      {-7,             -22} ,      //21
      {-8,             -22} ,      //22
      {-9,             -23} ,      //23
      {-10,            -23} ,      //24
      {-11,            -24} ,      //25
      {-12,            -24} ,      //26
      
      {-16,            -27} ,      //27
    },
};

#pragma location = 0x1E000 + sizeof(stRefrigerator_Flash)
const stCabinSetsDatas_Flash cabinSetsDatasTable_F[] = {                                //<-------- Door Open---------><-------Door Close--------->
//      {                 display   , c_CI_Temp   , c_CO_Temp   , f_CI_Temp   , fCO_Temp    , lTH_CI_Temp , lTH_CO_Temp , lTH_CI_Temp , lTH_CO_Temp },
/* 0*/  { (unsigned char) _dispQFF  , 10          , 0           , 10          , 0          , -5    , -3    , -5     , -3    },
/* 1*/  { (unsigned char) _dispVAC  , 138         , 115         , 138         , 115         , 25    , 35    , 25    , 35    },
/* 2*/  { (unsigned char) _dispQFRZ , -250        , -350        , -250        , -350        , 0     , 0     , 0     , 0     },
  
/* 3*/  { (unsigned char) 1        , 3     , 0     , 3     , 0     , 0     ,  5    , 0     , 5     },
/* 4*/  { (unsigned char) 2        , 12    , 9     , 12    , 9     , 0     , 10    , 0     , 10    },
/* 5*/  { (unsigned char) 3        , 17    , 14    , 17    , 14    , 10    , 15    , 10    , 15    },
/* 6*/  { (unsigned char) 4        , 20    , 17    , 20    , 17    , 10    , 15    , 10    , 15    },
/* 7*/  { (unsigned char) 5        , 26    , 23    , 26    , 23    , 15    , 25    , 15    , 25    },
/* 8*/  { (unsigned char) 6        , 29    , 26    , 29    , 26    , 20    , 30    , 20    , 30    },
/* 9*/  { (unsigned char) 7        , 36    , 33    , 36    , 33    , 20    , 30    , 20    , 30    },
/*10*/  { (unsigned char) 8        , 45    , 42    , 45    , 42    , 20    , 30    , 20    , 30    },

/*11*/  { (unsigned char)-24       , -203  , -207  , -203  , -207  , 0     , 0     , 0     ,  0    },
/*12*/  { (unsigned char)-23       , -202  , -206  , -202  , -206  , 0     , 0     , 0     ,  0    },
/*13*/  { (unsigned char)-22       , -200  , -204  , -200  , -204  , 0     , 0     , 0     ,  0    },
/*14*/  { (unsigned char)-21       , -189  , -193  , -189  , -193  , 0     , 0     , 0     ,  0    },
/*15*/  { (unsigned char)-20       , -183  , -187  , -183  , -187  , 0     , 0     , 0     ,  0    },
/*16*/  { (unsigned char)-19       , -174  , -178  , -174  , -178  , 0     , 0     , 0     ,  0    },
/*17*/  { (unsigned char)-18       , -168  , -172  , -168  , -172  , 0     , 0     , 0     ,  0    },

/*18*/  { (unsigned char) 4         , 50    , 45    , 50    , 45    , 0     , 0     , 0     ,  0    },

/*19*/  { (unsigned char) _dispFRZOFF , 138 , 115   , 138   , 115   , 0     , 0     , 0     ,  0    },
};

const signed int CoolAmbientOffsetDO[] =  { 26, 9, 6, 9, 0};
const signed int CoolAmbientOffsetDC[] =  { 26, 9, 6, 9, 0};
const signed int FRZAmbientOffset[] = {10, 0, 0, 0, 0};

//#pragma default_variable_attributes =       // ozgur