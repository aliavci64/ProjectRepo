#include "project.h"

#define _StockNoSize        10
#define _StockNo            5993600200 // K78 Inova D Class Convertible + Connected + Servis Buton Task 92437 ref : 5929769700_V21R59_V02R06
#define _StockVersion       4
#define _StockRevision      39
#define _ProductStockCode   700000000

#pragma location = 0x1E000
const stRefrigerator_Flash refrigerator_F = 
{
    .Stock = {
        .No[0] = (_StockNo % (10000)),
        .No[1] = (_StockNo / 10000) % 10000,
        .No[2] = ((_StockNo / 10000) / 10000) % 10000,
        .Version = _StockVersion,
        .Revision = _StockRevision,
    },

    .Sets = {
        .configs = 
        {
            .functions = 
            {
                .Sabbath = 0,
                .EcoExtra = 1,
                .DoorsClosed = 0,
                .Silent = 1,
                .PumpOut = {
                  .isActive = 1,
                  .type = _PumpOut_OpenALL,
                },
            },
        },
    },

    .Parameters = {
        .I2CDevices = {
          .device = {
            .rgbLEDUsage = 0,
            .HumiditySensor = 1,
          },
        },
        //.fairMode =1,
        .autoDispOff = 1,
        .dispOff = 0,
        .realTemp = 0,
        .fahrenheit = 1,
        .onBoardBuzzer = 1,
        .ecoExtraTime = (6 * 60),           // 6 hour
        .sabbathTime = (72 * 60),           // 72hour
        .doorsClosedTime = 65000,       // 26 hour
        .doorsClosedBlockTime = (120 * 60), // 120 hour
        .maxDoorsClosedStateStayTime = 28800,
        .doorsOpenedCount = 1,
        .doorsAlertTime = {90, 120, 180, 240, 300, 60}, // second.      //GOCAK_V05R00 ==>     //.doorsAlertTime parametreleri güncellendi.         //..doorsAlertTime = {60, 120, 180, 240, 300, 90}, // second.
        .doorsAlertingCloseLightTime = 10, // minute
        .displayData = 0,
        .displayValue = 1,
        .displayUnit = 2,
        .silentTime = (12 * 60), // 12 hour
        .shoppingModeTime = (1 * 60),

        //.quickIceTermalCutOutTimer = 40,
        //.quickFrzTermalCutOutTimer = 40,
    },
    .Connected = {
        // Device Specific Number Definitons
        .definitions = {
            // Connected Appliances
            .brand = 1, // Arcelik:1 , Grundig:2, Beko:3

            .stockCode = _ProductStockCode,
            .machineID = 2,             // CM : 1; RF: 2; BM :3; Oven:4 ;TD:5
            .wgVersion = _StockVersion,
            .wgRevision = _StockRevision,
            .productVersion = 3,        // 0: ARWEN I, 1: ARWEN II, 2: ARWEN III 3: End2End
            .dateDay = 15,
            .dateMonth = 12,
            .dateYear = 16,
        },

        // Connected Appiance Main Function availability / activation
        .funcConnectedApp = {
            .connectedAppAct = 1,       // 1: Connected appliance,  0: non-connected
            .swapConnButtons = 0,       // use connected appliance button setup
                                        // please note that connectedApplianceAct is the main activation switch. To activate any other function, this connectedApplianceAct has to be set "1" too
        },

        // Mercek / Log Function availability / activation
        .funcLog = {
            .logAct = 1,                // 1: Mercek logging functionaliy active 0: Mercek Array is not valid and can not be read.
                                        // please note that connectedApplianceAct is the main activation switch. To activate any other function, this connectedApplianceAct has to be set "1" too
        },

        // Show High Temp Error in Application Function availability / activation
        .funcShowHighTempError = {
            .showHighTempErrorAct = 1,  // 1: Show high temperature error temperature in WifiArray, 0: always write 0x00 to the dedicated wifi arrray address
                                        // please note that connectedApplianceAct is the main activation switch. To activate any other function, this connectedApplianceAct has to be set "1" too
        },

        // Defrost Delay Function availability / activation (�ok zamanl?Tarife uyumlu; defrost'un ucuz tarifeye �telenmesi)
        .funcdelayDefrost = {
            .delayFRZDefrostAct = 1,                                       // 1: Delay Defrost to cheap time, 0: do deforst based on run times.
            .timeOptionTableF = {0, 30, -30, 60, -60, 90, -90, 120, -120}, // delay/early options
            .minDefrostPeriod = 60,                                        // min required time to defrost take place (60 = 60)
                                                                           // please note that connectedApplianceAct is the main activation switch. To activate any other function, this connectedApplianceAct has to be set "1" too
        },
    },
    .IceMachine = {
        .type = _IceMachineType_NONE,
        .components = {
            .caseTempSensor = {
                .type = _TempSensorType_NONE,
                .index = 0XFF,
                //.order = 4,
            },
            .caseRotator = {
                .type = _RotatorType_NONE,
                .index = 0XFF,
                .test = 
                {
                    .cwStartTime = 0,
                    .cwEndTime = 0,
                    .ccwStartTime = 0,
                    .ccwEndTime = 0, 
                },
            },
            .caseTactSwitch = {
                //buz makinesi dengeleme
                .type = _SwitchType_NONE,
                .index = 2,
            },
            .boxTactSwitch = {
                .type = _SwitchType_NONE,
                .index = 4,
            },
        },
        .parameters = {
            .waterPumpTime = 255,
            .checkIceTempAtLongWait = -110,
            .checkIceTempAtShortWait = -110,
            .makeIceLongWaitTime = 40,
            .makeIceShortWaitTime = 1,
            .checkWaterEnabled = false,
            .checkWaterTime = 300,
            .checkWaterTempTime = 60,
            .checkWaterTemp = -40,
        },
    },

    .IceSource = {
        .type = _IceSourceType_NONE,
        .components = {
            .selector = {
                .type = _SelectorType_NONE,
                .index = 0XFF,
                .test = {
                    .selAStartTime = 0,
                    .selAEndTime = 0,
                    .selBStartTime = 0,
                    .selBEndTime = 0,
                },
            },
            .shutter = {
                .type = _ShutterType_NONE,
                .index = 0XFF,
                .test = {
                    .openStartTime = 0,
                    .openEndTime = 0,
                    .closeStartTime = 0,
                    .closeEndTime = 0,
                },
            },
            .pusher = {
                .type = _PusherType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 0,
                    .endTime = 0,
                },
            },
        },
    },

    .WaterSource = {
        .type = {
            .supply = _WaterSupplyType_NONE,
            .filter = _WaterFilterType_NONE,
        },
        .components = {
            .mainPump = {
                .type = _PumpType_NONE,
                .index = 0XFF,
                .test = {
                    .pumpStartTime = 0,
                    .pumpEndTime = 0,  
                    .vacumStartTime = 0,
                    .vacumEndTime = 0, 
                },
            },
            .mainValve = {
                .type = _ValveType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 0,
                    .endTime = 0,
                },
            },
            .dispenserValve = {
                .type = _ValveType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 0,
                    .endTime = 0,
                },
            },
            .iceMachineValve = {
                .type = _ValveType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 0,
                    .endTime = 0,
                },
            },
            .waterVentilHeater = {
                .type = _HeaterType_NONE, 
                .index = 0XFF,
                .test = {
                    .startTime = 122,
                    .endTime = 140,
                },
            },
        },
        .parameters = {
            .waterVentilHeater = {
                .OnTimeA = 1000,
                .OffTimeA = 3,
                .OnTimeB = 1 * 60,
                .OffTimeB = 25 * 60,
            },
        },
    },

    .Dispenser = {
        .waterType = _DispenserWaterType_NONE,
        .iceType = _DispenserIceType_NONE,
        .components = {
            .tactSwitch = {
                .type = _SwitchType_NONE,
                .index = 0xFF,
            },
            .light = {
                .type = _LightType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 0,
                    .endTime = 0, 
                },
            },
            .doorSwitch = {
                .type = _SwitchType_NONE,
                .index = 0xFF,
            },
        },
        .parameters = {
            .OFFState = false,
            .lightTime = 50,
        },
    },

    .IceCreamMachine = {
        .type = _IceCreamMachineType_NONE,
        .components = {
            .mixer = {
                .type = _MixerType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 142,
                    .endTime = 160,
                },
            },
            .tempSensor = {
                .type = _TempSensorType_NONE,
                .index = 0XFF,
                //.order = 0xFF,
            },
            .doorSwitch = {
                .type = _SwitchType_NONE, 
                .index = 0XFF,
            },
        },
        .sets = {
            .sizes = {
                .iceCream = 3,
            },
            .indexes = {
                .iceCream = {
                    0,
                    1,
                    2,
                }, // iceCream[9]
            },
        },
        .parameters = {
            .relatedCabin = 1,
            .checkTemp = -50 // -5.0 C
        },
    },

    .Cooler = {
        .type = _CoolerType_PARALLEL,
        .components = {
            .condenserFan = {
                .type = _FanType_NONE,
                .index = 0xFF,
                .pulseCount = 5,
                .speedCalc = 1,
                .pwm = 1,
                .power = 1,
                .rpm = 2200,
                .test = {
                    .startTime = 2,
                    .endTime = 50,
                },
            },
            .compressor = {
                .type = _CompressorType_VCC_EKI,
                .index = 0,
                .test = {
                    .startTime = 142,
                    .endTime = 192,
                },
            },
            .ambientSensor = {
                .type = _TempSensorType_NONE,
                .index = 4,
            },
            .solenoidValve0 = {
                .type = _SolenoidValveType_StepMotor,
                .index = 0,
                .positionsSize = 4, // max 5
                .positions = {34, 195, 100, 154, 0xFF}, // allClose, COpen, BOpen, AllOpen
                .test = {
                    .startTime = 0,
                    .endTime = 0,
                },
            },
            .solenoidValve1 = {
                .type = _SolenoidValveType_NONE,
                .index = 0xFF,  
                .positionsSize = 4,                     // max 5
                .positions = {34, 195, 100, 154, 0xFF}, // allClose, COpen, BOpen, AllOpen
                .test = {
                    .startTime = 142,
                    .endTime = 160,
                },
            },
        },
        .parameters = {
            //.ByPass = 0,
            .minStayTimeAtPresGasLevel = 15,
            .maxStayTimeAtPresGasLevel = 60,
            
            .compressor = {
                .minOnTime = 6,
                .minOffTime = 8,
                .speedLevel = { 36, 38, 38, 56, 68, 110, 122, 150, 150 },
                .speedLevelFF =  { 60, 70, 75, 80, 85, 90, 110, 120, 128 },
                .speedLevelFRZ = { 50, 60, 70, 75, 80, 90, 110, 120, 128 },
                /// NER
               .FF = {                   /* L1, L2, L3, L4, LD, LH */
                  .speedLevel[_Ambient_0] = {43,  45,  50,  55,  50,  55},
                  .speedLevel[_Ambient_1] = {43,  48,  55,  60,  55, 128},
                  .speedLevel[_Ambient_2] = {43,  50,  65,  90,  65, 135},
                  .speedLevel[_Ambient_3] = {55,  55,  65, 128,  90, 128},
                  .speedLevel[_Ambient_4] = {90, 128, 128, 128, 120, 128},
                },
                .FRZ = {                  /* L1, L2, L3, L4, LD, LH */
                  .speedLevel[_Ambient_0] = {43,  45,  50,  90,  50,  55},
                  .speedLevel[_Ambient_1] = {43,  48,  55,  90,  55, 128},
                  .speedLevel[_Ambient_2] = {43,  53,  55,  90,  55, 135},
                  .speedLevel[_Ambient_3] = {70,  70,  83, 128, 128, 128},
                  .speedLevel[_Ambient_4] = {90, 128, 128, 128, 120, 128},
                },
                .speedSilent = 40,
                .speedStartUp = 50,
                .speedPumpOut = 128,
                //.speedHotStartLevel = 7, //hotstart ve defrost sonrası bu devirden başlar maxStayTimeAtPresGasLevelHS dk da bir level arttırır.
                .timeStartUp = 1,
                .timeForMaxLevel_DO = 180,
                .timeForMaxLevel_DC = 180,
                .workTimeAtMaxLevel = 255,
            },

            .condenserFan = {
                .speedLevel = { 68, 68, 68, 68, 68, 68, 68, 68 }, ///< { 150, 150, 150, 150, 150, 150, 150, 150, 150 },
                .speedLevelFF = { 68, 68, 68, 68, 68, 68, 68, 68 },
                .speedLevelFRZ = {  68, 68, 68, 68, 68, 68, 68, 68 },
                /// NER
                .FF = {                   /* L1, L2, L3, L4, LD, LH */
                  .speedLevel[_Ambient_0] = { 68,  68,  68,  68,  68,  68},
                  .speedLevel[_Ambient_1] = { 68,  68,  68,  68,  68,  68},
                  .speedLevel[_Ambient_2] = { 68,  68,  68,  68,  68,  68},
                  .speedLevel[_Ambient_3] = { 68,  68,  68,  68,  68,  68},
                  .speedLevel[_Ambient_4] = {100, 100, 100, 100, 100, 100},
                },
                .FRZ = {                  /* L1, L2, L3, L4, LD, LH */
                  .speedLevel[_Ambient_0] = { 68,  68,  68,  68,  68,  68},
                  .speedLevel[_Ambient_1] = { 68,  68,  68,  68,  68,  68},
                  .speedLevel[_Ambient_2] = { 68,  68,  68,  68,  68,  68},
                  .speedLevel[_Ambient_3] = { 68,  68,  68,  68,  68,  68},
                  .speedLevel[_Ambient_4] = {100, 100, 100, 100, 100, 100},
                },
                .speedSilent = 68,
                .speedPumpOut = 68,
                .speedCheckCorrection = 0,
                .speedCheckTime = 15,
                .speedCheckTemp = -100, //_DegC_n10_0,
            },
            /// NER
            .ambient = {
                .temperatures = { 130, 200, 300, 370 }, // value / 10 = temperature
                .hysteresis = { 10, 10, 10, 10 },  // value / 10 = temperature
                .errorType = _Ambient_3,
                .humidity = { 
                  .intervals = {60, 70, 80, 90},
                  .hysteresis = {1,  1,  1, 1},
                  .errorType = _Humidity_4,
                },
            },

            .sysStates = {      
              {//0 Default position
                .queue = false,
                //.valvesDefPosition = _ALL_OPEN,
                .valvesDefPosition = _FRZ_OPEN,
                .valvesAltPosition = _FF_OPEN,
                .valvesDefPositionTime = 5,
                .valvesAltPositionTime = 5,
              },
              {//1
                .logic = _L_OR,
                .queue = false,
                .gasSpecs[ 0 ] = { .type = _GT_Failed, .priority = 1, },
                .gasSpecs[ 1 ] = { .type = _GT_Failed, .priority = 2, },
                //.valvesDefPosition = _ALL_OPEN,
                .valvesDefPosition = _FRZ_OPEN,
                .valvesAltPosition = _FF_OPEN,
                .valvesDefPositionTime = 5,
                .valvesAltPositionTime = 5,
              },
              {//2
                .logic = _L_OR,
                .queue = false,
                .gasSpecs[ 0 ] = { .type = _GT_Forced, .priority = 2, },
                .gasSpecs[ 1 ] = { .type = _GT_Forced, .priority = 1, },
                .valvesDefPosition = _ALL_OPEN,
              },
              {//3
                .logic = _L_OR,
                .queue = false,
                .gasSpecs[ 0 ] = { .type = _GT_LPT, .priority = 2, },
                .gasSpecs[ 1 ] = { .type = _GT_LPT, .priority = 1, },
                .valvesDefPosition = _FRZ_OPEN,
                .valvesAltPosition = _FF_OPEN,
                .valvesDefPositionTime = 30,
                .valvesAltPositionTime = 50,
              },
              {//2
                .logic = _L_OR,
                .queue = false,
                .gasSpecs[ 0 ] = { .type = _GT_SPT, .priority = 2, },
                .gasSpecs[ 1 ] = { .type = _GT_SPT, .priority = 1, },
                .valvesDefPosition = _ALL_OPEN,
                .valvesAltPosition = _FF_OPEN,
                .valvesDefPositionTime = 5,
                .valvesAltPositionTime = 45,
              },
              {//2
                .logic = _L_AND,
                .queue = false,
                .gasSpecs[ 0 ] = { .type = _GT_HotStart, .priority = 1, },
                .gasSpecs[ 1 ] = { .type = _GT_HotStart, .priority = 2, },
                .valvesDefPosition = _FF_OPEN,
                .valvesAltPosition = _FRZ_OPEN,
                .valvesDefPositionTime = 250,
                .valvesAltPositionTime = 145,
              },
              {//2
                .logic = _L_OR,
                .queue = false,
                .gasSpecs[ 0 ] = { .type = _GT_HotStart, .priority = 2, },
                .valvesDefPosition = _FF_OPEN,
                .valvesDefPositionTime = 250,
              },
              {//2
                .logic = _L_OR,
                .queue = false,
                .gasSpecs[ 1 ] = { .type = _GT_HotStart, .priority = 2, },
                .valvesDefPosition = _FRZ_OPEN,
                .valvesDefPositionTime = 145,
              },
              {//3		
		.logic = _L_AND,
                .queue = false,
                .gasSpecs[ 0 ] = { .type = _GT_No, .priority = 2, },
                .gasSpecs[ 1 ] = { .type = _GT_No, .priority = 1, },
                .valvesDefPosition = _ALL_CLOSE,
              },
              {//4
                .logic = _L_AND,
                .queue = false,
                .gasSpecs[ 0 ] = { .type = _GT_Hot, .priority = 2, },
                .gasSpecs[ 1 ] = { .type = _GT_No,  .priority = 1, },
                .valvesDefPosition = _ALL_CLOSE,
              },
              {//5
                .logic = _L_OR,
                .queue = false,
                // .gasSpecs[ 0 ] = { .type = _GT_No,  .priority = 1, },
                .gasSpecs[ 1 ] = { .type = _GT_Hot, .priority = 2, },
                .valvesDefPosition = _ALL_CLOSE,
              },
              {//6
                .logic = _L_AND,
                .queue = false,
                .gasSpecs[ 0 ] = { .type = _GT_Hot, .priority = 2, },
                .gasSpecs[ 1 ] = { .type = _GT_Hot, .priority = 1, },
                .valvesDefPosition = _ALL_CLOSE,
              },
              /*
              {//7
                .logic = _L_AND,
                .queue = true,
                .gasSpecs[ 0 ] = { .type = _GT_Cold, .priority = 2, },
                .gasSpecs[ 1 ] = { .type = _GT_Hot,  .priority = 1, },
                .valvesDefPosition = _FF_OPEN,
                .valvesDefPositionTime = 75,
              },
              */
              {//8
                .logic = _L_AND,
                .queue = true,
                .gasSpecs[ 0 ] = { .type = _GT_Cold, .priority = 2, },
                .gasSpecs[ 1 ] = { .type = _GT_Cold, .priority = 1, },
                .valvesDefPosition = _FF_OPEN,
                .valvesAltPosition = _FRZ_OPEN,
                .valvesDefPositionTime = 45,
                .valvesAltPositionTime = 30,
              },
              {//9
                .logic = _L_AND,
                .queue = true,
                .gasSpecs[ 0 ] = { .type = _GT_Hot,  .priority = 1, },
                .gasSpecs[ 1 ] = { .type = _GT_Cold, .priority = 2, },
                .valvesDefPosition = _FRZ_OPEN,
                .valvesDefPositionTime = 30,
              },
              {//10
                .logic = _L_AND,
                .queue = true,
                .gasSpecs[ 0 ] = { .type = _GT_No, .priority = 1, },
                .gasSpecs[ 1 ] = { .type = _GT_Cold,   .priority = 2, },
                .valvesDefPosition = _FRZ_OPEN,
                .valvesDefPositionTime = 30,
              },
              {//11
                .logic = _L_AND,
                .queue = true,
                .gasSpecs[ 0 ] = { .type = _GT_Cold, .priority = 1, },
                .gasSpecs[ 1 ] = { .type = _GT_Cold, .priority = 2, },
                .valvesDefPosition = _FRZ_OPEN,
                .valvesAltPosition = _FF_OPEN,
                .valvesDefPositionTime = 30,
                .valvesAltPositionTime = 45,
              },
              {//12
                .logic = _L_OR,
                .queue = false,
                .gasSpecs[ 0 ] = { .type = _GT_Cold, .priority = 2, },
                .valvesDefPosition = _FF_OPEN,
                .valvesDefPositionTime = 45,
              },
              {//13
                .logic = _L_OR,
                .queue = false,
                .gasSpecs[ 1 ] = { .type = _GT_Cold, .priority = 2, },
                .valvesDefPosition = _FRZ_OPEN,
                .valvesDefPositionTime = 30,
              },
            },
            .valveGasStates = {
              { .valve0Position = 0, .valve1Position = 0, .gas = 0x00, .enough = 0x00, },
              { .valve0Position = 1, .valve1Position = 0, .gas = 0x01, .enough = 0x01, },
              { .valve0Position = 2, .valve1Position = 0, .gas = 0x02, .enough = 0x02, },
              { .valve0Position = 3, .valve1Position = 0, .gas = 0x03, .enough = 0x03, },
            },
        },
    },
    
    .Cabin[0] = {
        .type = _CabinType_FF,
        .components = {
            .knob = {
                .type = _KnobType_NONE,
                .index = 0xFF,
            },
            .fan = {
                .type = _FanType_VDC,
                .index = 0,
                .pulseCount = 5,
                .speedCalc = 0,
                .pwm = 1,
                .power = 0,
                .rpm = 2200,
                .test = {
                    .startTime = 2,
                    .endTime = 40,
                },
            },
            .flap = {
                .type = _FlapType_NONE,
                .index = 0,
            },
            .heaterA = {
                .type = _HeaterType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 2,
                    .endTime = 20,
                },
            },
            .heaterB = {
                .type = _HeaterType_AC,
                .index = 2,
                .test = {
                    .startTime = 2,
                    .endTime = 20,
                },
            },
            .heaterC = {
                .type = _HeaterType_AC,
                .index = 0,
                .test = {
                    .startTime = 122,
                    .endTime = 140,
                },
            },
            .ionizer = {
                .type = _IonizerType_NONE,
                .index = 1,
                .test = {
                    .startTime = 42,
                    .endTime = 60,
                },
            },
            .innerLight = {
                .type = _LightType_PWM,
                .index = 0,
                .test = {
                    .startTime = 42,
                    .endTime = 60,
                },
            },
            .blueLight = {
                .type = _LightType_DC,
                .index = 2,
                .test = {
                    .startTime = 2,
                    .endTime = 192,
                },
            },
            .handleLight = {
                .type = _LightType_PWM,
                .index = 3,
                .test = {
                    .startTime = 2,
                    .endTime = 192,
                },
            },
            .doorSwitch0 = {
                .type = _SwitchType_DC,
                .index = 0,
            },
            .doorSwitch1 = {
                .type = _SwitchType_NONE,
                .index = 1,
            },
            .airTempSensor = {
                .type = _TempSensorType_NTCwithADC,
                .index = 0,
                //.order = 4,
            },
            .evaTempSensor = {
                .type = _TempSensorType_NTCwithADC,
                .index = 1,
                //.order = 1,
            },
            .zeroStarTempSensor = {
                .type = _TempSensorType_NTCwithADC,
                .index = 5,
                //.order = 4,
            },
            .violed = {
                .type = _VioLedType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 42,
                    .endTime = 80,
                },
            },
        },
        .sets = {
            .configs = {
                .FF = 8,
                .FRZ = 0,
                .functions = {
                    .QuickFF = 1, .QuickFRZ = 0, .Vacation = 1, .Rice = 0, .QuickIce = 0, // Quick Ice Active
                    .Convertible = 0, .CabinOff = 0,
                },
            },
            .indexes = {
                .FF  = { 6, 7, 8, 9, 10, 3, 4, 5, 0xFF, 0xFF, }, // FF[10]
                .FRZ = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, }, // FRZ[10]
                .functions = {
                    .QuickFF = 0, .QuickFRZ = 0xFF, .Vacation = 1, .Rice = 0xFF, .QuickIce = 6, // Quick Ice Set from table
                    .Convertible = 0xFF, .CabinOff = 0xFF,
                },
            },
        },
        .parameters = {
            .Performance = {
                .timeEva1 = _Performance_TimeEva1, .timeEva2 = _Performance_TimeEva2, .tempEva1 = _Performance_TempEva1, .tempEva2 = _Performance_TempEva2, .timeAir = _Performance_TimeAir, .deltaTempAir = _Performance_DeltaTempAir,
                //.thermalCutOut = 28,  //can cetin
            },
            .Quick = {
                .timeFFMode = _Quick_TimeFFMode,
                .timeFRZMode = _Quick_TimeFRZMode,
            },
            .Cool = {
                .SabbathMaxIdleTime = _Cool_FFAirEva_SabbathMaxIdleStateTime,
                .MaxIdleTime = 255,
                .ErrorMaxIdleTime = _Cool_FFAirEva_ErrorMaxIdleTime,
                .ErrorMaxCoolTime = _Cool_FFAirEva_ErrorMaxCoolTime,
                .ErrorCutInTemp = _Cool_FFAirEva_ErrorCutInTemp,
                .ErrorCutOutTemp = _Cool_FFAirEva_ErrorCutOutTemp,
                .QuickFRZCutOutTemp = _Cool_FFAirEva_QuickFRZCutOutTemp,
                .MaxIdleTimeElapsedCoolTime = 15,
                .isEvaCutInActive = 0,
                .EvaCutInTemp = 25,
                .pumpOutTime = 30,
                .HotStartTime = 395, // _Cool_HotStartTime,
                .ShortPerformanceTestTime = 51,
                .LongPerformanceTest = 80,
                .specialCool = {
                  .priority = 1,
                  .setIndex = 0,
                  .afterDefrost = 1,
                  .passiveActive = 0,
                  .coolingLevel = 6,
                  .doorOpenTime = 30,
                  .doorClosedTime = 10,
                  .tempDifference = 20,
                  .time = 20 * 60,
                  .nonStopCooling = 10 * 60,
                  .thermalCutOut = 1,
                  .thermalCutOutForNonStopCooling = 0,
                  .defrostDelayTime = 10 * 60,
                },
            },
            .Defrost = {
                .Type = _DefrostType_Variable,
                .MaxRealTime_DO = 600, //_Defrost_FFAirEva_MaxRealTime_DO,
                .MaxRealTime_DC = 600, //_Defrost_FFAirEva_MaxRealTime_DC,
                .MaxRealTime_QuickFRZ = _Defrost_FFAirEva_MaxRealTime_QuickFRZ,
                .MaxWorkTime_DO = 1000,
                .MaxWorkTime_DC = 1000,
                .MaxCycle_DO = 250, //_Defrost_FFAirEva_MaxCycle_DO,
                .MaxCycle_DC = 250, //_Defrost_FFAirEva_MaxCycle_DC,
                .DefrostCutOutTemp = _Defrost_FFAirEva_DefrostCutOutTemp,
                .MaxNoCoolTime = _Defrost_FFAirEva_MaxNoCoolTime,
                .MaxDelayTimeForIceCream = (8 * 60),
                .ErrorMaxCycle = _Defrost_FFAirEva_ErrorMaxCycle,
                .ErrorMaxNoCoolTime = _Defrost_FFAirEva_ErrorMaxNoCoolTime,
                .RealTimeAfterHotStart = 0,
                .RealTimeAfterService = 0,
                .DoorOpenedIntervals =             { 1*30,  1*60,  2*60,  4*60,  7*60 }, // min
                .VariableMaxRealTime[_Ambient_0] = {300, 280, 260, 240, 220, 200 },
                .VariableMaxRealTime[_Ambient_1] = {600, 280, 260, 240, 220, 200 },
                .VariableMaxRealTime[_Ambient_2] = {400, 300, 280, 260, 240, 220 },
                .VariableMaxRealTime[_Ambient_3] = {600, 300, 280, 260, 240, 220 },
                .VariableMaxRealTime[_Ambient_4] = {600, 300, 280, 260, 240, 220 },
                .VariableDefrostCutOutTemp = { 40,  40,  40,  40,  40,  40 }, // Celcius *10
            },
            .Fan = {
                .SpeedLevel = { 100, 100, 100, 100, 100, 100, 100, 100, 100 },
                /// NER
                .AmbientSpeedLevel[_Ambient_0] = { 55,  55, 100, 100, 100, 100},
                .AmbientSpeedLevel[_Ambient_1] = { 55,  55, 100, 100, 100, 100},
                .AmbientSpeedLevel[_Ambient_2] = { 55, 100, 100, 100, 100, 100},
                .AmbientSpeedLevel[_Ambient_3] = {100, 100, 100, 100, 100, 100},
                .AmbientSpeedLevel[_Ambient_4] = {100, 100, 100, 100, 100, 100},
                .CompressorOFF    = {true, false, true, false, true},
                .CompressorON_FRZ = {true, false, true, true, true},
                .SpeedError = 80,
                .SpeedQuick = 100,
                .SpeedSilent = 55,
                .SpeedPumpOut = 0,
                .SpeedHotStart = 100,
                .SpeedConvertible = 0,
                //.SpeedLowCompLevel = 50,
                .MinDuty_DO = 5, //_Fan_FFAirEva_MinDuty_DO,
                .MaxDuty_DO = 7, //_Fan_FFAirEva_MaxDuty_DO,
                .MinDuty_DC = 5,
                .MaxDuty_DC = 7,
                .CutOutHysteresis = 1, // Artyk ADC degil sycaklyk 0.1C
                .WorkTimeAfterCool = 5, // minutes
                .HotStartDelayTime = 5, // _Fan_HotStartDelay,
                .minStayTimeAtPresFanLevel = 10,
                .maxStayTimeAtPresFanLevel = 75,
                .CoolDelay = 2,
            },
            .Drainage = {
                .MaxDrainageTime = 5,
            },
            .Flap = {
                .PositionA = _Flap_ALL_PositionA,
                .PositionB = _Flap_ALL_PositionB,
                .OnTimeA = _Flap_ALL_OnTimeA,
                .OffTimeA = _Flap_ALL_OffTimeA,
                .OnTimeB = _Flap_ALL_OnTimeB,
                .OffTimeB = _Flap_ALL_OffTimeB,
            },
            .HeaterB = {
                .OnTimeA = _HeaterB_ALL_OnTimeA,
                .OffTimeA = _HeaterB_ALL_OffTimeA,
                .OnTimeB = _HeaterB_ALL_OnTimeB,
                .OffTimeB = _HeaterB_ALL_OffTimeB,
            },
            .HeaterC = {
                .OnTimeA = _HeaterC_ALL_OnTimeA,
                .OffTimeA = _HeaterC_ALL_OffTimeA,
                .OnTimeB = _HeaterC_ALL_OnTimeB,
                .OffTimeB = _HeaterC_ALL_OffTimeB,
                .humidityHeater = {
                  .OnTime [_Humidity_0] = { 0,  0,  0,  0,  0},
                  .OffTime[_Humidity_0] = {20, 20, 20, 20, 20},
                  .OnTime [_Humidity_1] = { 0,  0,  0,  2,  0},
                  .OffTime[_Humidity_1] = {20, 20, 20,  8, 20},
                  .OnTime [_Humidity_2] = { 0,  0,  2, 17,  0},
                  .OffTime[_Humidity_2] = {20, 20,  8,  3, 20},
                  .OnTime [_Humidity_3] = { 1,  1, 18, 18, 18},
                  .OffTime[_Humidity_3] = { 9,  9,  2,  2,  2},
                  .OnTime [_Humidity_4] = { 2,  2, 19, 19, 19},
                  .OffTime[_Humidity_4] = { 8,  8,  1,  1,  1},
                },
            },
            .Level = {
                .dutyFF  = { .low = 50, .hgh = 90, },
                .dutyFRZ = { .low = 50, .hgh = 90, },
                .dtFF  = { .lowDuty = {20, 40}, .medDuty = {20, 30, 32, 35, 38, 40}, .hghDuty = {5, 10}, },
                .dtFRZ = { .lowDuty = {20, 40}, .medDuty = {20, 30, 32, 35, 38, 40}, .hghDuty = {5, 10}, },
                .levelFanFF =  { .lowDuty = {1, 2, 3}, .medDuty = {2, 3, 4, 5, 6, 7, 8}, .hghDuty = {7, 8, 9}, },
                .levelFanFRZ = { .lowDuty = {1, 2, 3}, .medDuty = {2, 3, 4, 5, 6, 7, 8}, .hghDuty = {7, 8, 9}, },
                .levelGasFF =  { .lowDuty = {1, 2, 3}, .medDuty = {2, 3, 4, 5, 6, 7, 8}, .hghDuty = {9, 9, 9}, },
                .levelGasFRZ = { .lowDuty = {1, 2, 3}, .medDuty = {2, 3, 4, 5, 6, 7, 8}, .hghDuty = {9, 9, 9}, },
            },
            /// NER
            .AmbientLevel = {
              .FF ={ 
                .dt[_Ambient_0] = {10, 30, 50},
                .dt[_Ambient_1] = {10, 30, 50},
                .dt[_Ambient_2] = {15, 30, 50},
                .dt[_Ambient_3] = {12, 30, 50},
                .dt[_Ambient_4] = {10, 30, 50},
              },
              .FanFF = {
                .level[_Ambient_0] = {1, 2, 3, 4},
                .level[_Ambient_1] = {1, 2, 3, 4},
                .level[_Ambient_2] = {1, 2, 3, 4},
                .level[_Ambient_3] = {1, 2, 3, 4},
                .level[_Ambient_4] = {1, 2, 3, 4},
              },
              .GasFF = {
                .level[_Ambient_0] = {1, 2, 3, 4},
                .level[_Ambient_1] = {1, 2, 3, 4},
                .level[_Ambient_2] = {1, 2, 3, 4},
                .level[_Ambient_3] = {1, 2, 3, 4},
                .level[_Ambient_4] = {1, 2, 3, 4},
              },
            },
            .VioLed = {
                .maxOnTime = (2 * 60),     // dk
                .maxOffTime = (14 * 60),   // dk   // bug_68498'e gore violed max off time 840 dk yapilmistir.
                .maxDisplayActivation = 3, // count
                .maxDelayTime = 15,        // dk
                .maxOffTimeFirstStart = (48 * 60) , // dk ilk kalkış durma süresi
            },
        },
    },

    .Cabin[1] = {
        .type = _CabinType_FRZ,
        .components = {
            .knob = {
                .type = _KnobType_NONE,
                .index = 0xFF,
            },
            .fan = {
                .type = _FanType_VDC,
                .index = 1,
                .pulseCount = 2,
                .speedCalc = 1,
                .pwm = 1,
                .power = 0,
                .rpm = 2200,
                .test = {
                    .startTime = 82, 
                    .endTime = 120,
                },
            },
            .flap = {
                .type = _FlapType_NONE,
                .index = 0xFF,
            },
            .heaterA = {
                .type = _HeaterType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 0,
                    .endTime = 0,
                },
            },
            .heaterB = {
                .type = _HeaterType_AC,
                .index = 3,
                .test = {
                    .startTime = 82,
                    .endTime = 100,
                },
            },
            .heaterC = {
                .type = _HeaterType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 0,
                    .endTime = 0,
                },
            },
            .ionizer = {
                .type = _IonizerType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 0,
                    .endTime = 0,
                },
            },
            .innerLight = {
                .type = _LightType_NONE, // _LightType_NONE, //_LightType_DC, // ozgur - up to V01R66
                .index = 0,
                .test = {
                    .startTime = 122,
                    .endTime = 140,
                },
            },

            .blueLight = {
                .type = _LightType_NONE,
                .index = 0xFF,
                .test = {
                    .startTime = 0,
                    .endTime = 0,
                },
            },
            .doorSwitch0 = {
                .type = _SwitchType_DC, ///Fiziksel olarak ReedSwitch FRZ için bulunmuyor.
                .index = 0, //0xFF,     ///FF kapı açıldığında FRZ doorOpenedTimer sayması için aynı Index ile açıldı.
            },
            .doorSwitch1 = {
                .type = _SwitchType_NONE,
                .index = 0xFF,
            },
            .airTempSensor = {
                .type = _TempSensorType_NTCwithADC,
                .index = 2,
                //.order = 2,
            },
            .evaTempSensor = {
                .type = _TempSensorType_NTCwithADC,
                .index = 3,
                //.order = 0,
            },
        },
        .sets = {
            .configs = {
                .FF = 0,
                .FRZ = 7,
                .functions = {
                    .QuickFF = 0, .QuickFRZ = 1, .Vacation = 0, .Rice = 0, .QuickIce = 0, // Quick Ice Active
                    .Convertible = 1, .CabinOff = 1,
                },
            },
            .indexes = {
                .FF =  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, }, // FF[10]
                .FRZ = { 17, 11, 12, 13, 14, 15, 16, 0xFF, 0xFF, 0xFF,               }, // FRZ[10]
                .functions = {
                    .QuickFF = 0xFF, .QuickFRZ = 2, .Vacation = 0xFF, .Rice = 0xFF, .QuickIce = 2, // Quick Ice Set from table
                    .Convertible = { 18, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, },
                    .CabinOff = 19,
                },
            },
        },
        .parameters = {
            //
            .permannentHighTempError = 0,
            //
            .HighTempError = {
              .HighTempErrCutIN = -23, 
              .HighTempErrCutOUT = -90,
              
              .HighTmp_Time_PowerUp = 1,
              .HighTmp_Time_Defrost = 1500,
              .HighTmp_Time_Normal = 1500,
              .HighTmp_Algorithm_Activation = 1440 * 3,
              .HighTmp_DelayAlarm = 360,
            },
            .Performance = {
                .timeEva1 = _Performance_TimeEva1, .timeEva2 = _Performance_TimeEva2, .tempEva1 = _Performance_TempEva1, .tempEva2 = _Performance_TempEva2, .timeAir = _Performance_TimeAir, .deltaTempAir = _Performance_DeltaTempAir,
                //.thermalCutOut = -170, //can cetin
            },
            .Quick = {
                .timeFFMode = _Quick_TimeFFMode,
                .timeFRZMode = 48*60, // _Quick_TimeFRZMode,
            },
            .Cool = {
                .SabbathMaxIdleTime = _Cool_FRZAirEva_SabbathMaxIdleTime,
                .MaxIdleTime = _Cool_FRZAirEva_MaxIdleTime,
                .ErrorMaxIdleTime = _Cool_FRZAirEva_ErrorMaxIdleTime,
                .ErrorMaxCoolTime = _Cool_FRZAirEva_ErrorMaxCoolTime,
                .MaxIdleTimeElapsedCoolTime = 15,
                .HotStartTime = 395, // _Cool_HotStartTime,
                .ShortPerformanceTestTime = 51,
                .pumpOutTime = 30,
                .LongPerformanceTest = 80,
                .specialCool = {
                  .priority = 3,
                  .setIndex = 2,
                  .afterDefrost = 1,
                  .passiveActive = 1,
                  .coolingLevel = 6,
                  .doorOpenTime = 25,
                  .doorClosedTime = 10,
                  .tempDifference = 12,
                  .time = 20 * 60,
                  .nonStopCooling = 10 * 60,
                  .defrostDelayTime = 15 * 60,
                  .coolBlockTime = 150,
                },
            },
            .Defrost = {
                .Type = _DefrostType_Variable,
                .MaxRealTime_DO = 1800,
                .MaxRealTime_DC = 1800,
                .MaxQuickTime = 16*60, //_Defrost_FRZAirEva_MaxQuickTime,
                .MaxWorkTime_DO = 24*60,
                .DefrostCutOutTemp = _Defrost_FRZAirEva_DefrostCutOutTemp,
                .MaxDefrostTime_DO = _Defrost_FRZAirEva_MaxDefrostTime_DO,
                .MaxDefrostTime_DC = _Defrost_FRZAirEva_MaxDefrostTime_DC,
                .ErrorMaxDefrostTime = 30, // _Defrost_FRZAirEva_ErrorMaxDefrostTime,
                .MaxDelayTimeForIceCream = (8 * 60),
                .RealTimeAfterHotStart = 0,
                .RealTimeAfterService = 0, //840,
                .DoorOpenedIntervals =             { 1*60,  2*60,  4*60,  8*60,  12*60 }, // min
                .VariableMaxRealTime[_Ambient_0] = {26*60, 26*60, 23*60, 19*60, 15*60, 12*60 },
                .VariableMaxRealTime[_Ambient_1] = {96*60, 26*60, 23*60, 19*60, 15*60, 12*60 },
                .VariableMaxRealTime[_Ambient_2] = {96*60, 34*60, 30*60, 26*60, 16*60, 12*60 },
                .VariableMaxRealTime[_Ambient_3] = {96*60, 84*60, 70*60, 50*60, 30*60, 12*60 },
                .VariableMaxRealTime[_Ambient_4] = {96*60, 84*60, 70*60, 50*60, 30*60, 12*60 },
                .VariableDefrostCutOutTemp = {   60,  100,  100,  100,  100,  100 }, // Celcius *10
                .delayTime = 60,
            },
            .Drainage = {
                .MaxDrainageTime = _Drainage_FRZ_MaxDrainageTime,
            },
            .Fan = {
                .SpeedLevel = { 65, 65, 85, 85, 90, 93, 95, 97, 100 },
                /// NER                        /* L1, L2, L3, L4, LD, LH */
                .AmbientSpeedLevel[_Ambient_0] = {60, 60, 65, 65, 65,  65},
                .AmbientSpeedLevel[_Ambient_1] = {60, 65, 65, 85, 65,  85},
                .AmbientSpeedLevel[_Ambient_2] = {60, 65, 85, 85, 85, 100}, 
                .AmbientSpeedLevel[_Ambient_3] = {85, 85, 85, 85, 85,  85},
                .AmbientSpeedLevel[_Ambient_4] = {85, 85, 85, 85, 85,  85},
                .CompressorOFF   = {false, false, false, false, false},
                .CompressorON_FF = {false, false, false, false, false},
                .SpeedError = 65,
                .SpeedQuick = 100,
                .SpeedSilent = 45,
                .SpeedHotStart = 100,
                .SpeedPumpOut = 0,
                .SpeedConvertible = 0,
                .CutInEvaTemp = _Fan_FRZAirEva_CutInTemp, //-5 DERECE
                .CutInTime = 5,
                .WorkTimeAfterCool = 5,
                .HotStartDelayTime = 15,
                .minStayTimeAtPresFanLevel = 10,
                .maxStayTimeAtPresFanLevel = 75,
            },
            .Flap = {
                .PositionA = _Flap_ALL_PositionA,
                .PositionB = _Flap_ALL_PositionB,
                .OnTimeA = _Flap_ALL_OnTimeA,

                .OffTimeA = _Flap_ALL_OffTimeA,
                .OnTimeB = _Flap_ALL_OnTimeB,
                .OffTimeB = _Flap_ALL_OffTimeB,
            },
            .HeaterB = {
                .OnTimeA = _HeaterB_ALL_OnTimeA,
                .OffTimeA = _HeaterB_ALL_OffTimeA,
                .OnTimeB = _HeaterB_ALL_OnTimeB,
                .OffTimeB = _HeaterB_ALL_OffTimeB,
            },
            .HeaterC = {
                .OnTimeA = _HeaterC_ALL_OnTimeA,
                .OffTimeA = _HeaterC_ALL_OffTimeA,
                .OnTimeB = _HeaterC_ALL_OnTimeB,
                .OffTimeB = _HeaterC_ALL_OffTimeB,
            },
            .Level = {
                .dutyFF  = { .low = 50, .hgh = 90, },
                .dutyFRZ = { .low = 50, .hgh = 90, },
                .dtFF  = { .lowDuty = {20, 40,}, .medDuty = {20, 30, 32, 35, 38, 40}, .hghDuty = {5, 10,}, },
                .dtFRZ = { .lowDuty = {20, 40,}, .medDuty = {20, 30, 32, 35, 38, 40}, .hghDuty = {5, 10,}, },
                .levelFanFF =  { .lowDuty = {1, 2, 3}, .medDuty = {2, 3, 4, 5, 6, 7, 8}, .hghDuty = {7, 8, 9}, },
                .levelFanFRZ = { .lowDuty = {1, 2, 3}, .medDuty = {2, 3, 4, 5, 6, 7, 8}, .hghDuty = {7, 8, 9}, },
                .levelGasFF =  { .lowDuty = {1, 2, 2}, .medDuty = {2, 3, 4, 5, 6, 7, 8}, .hghDuty = {9, 9, 9}, },
                .levelGasFRZ = { .lowDuty = {3, 3, 3}, .medDuty = {2, 3, 4, 5, 6, 7, 8}, .hghDuty = {9, 9, 9}, },
            },
            /// NER
            .AmbientLevel = {
              .FRZ ={ 
                .dt[_Ambient_0] = {10, 30, 50},
                .dt[_Ambient_1] = {10, 30, 50},
                .dt[_Ambient_2] = {15, 30, 50},
                .dt[_Ambient_3] = {10, 30, 50},
                .dt[_Ambient_4] = {10, 30, 50},
              },
              .FanFRZ = {
                .level[_Ambient_0] = {1, 2, 3, 4},
                .level[_Ambient_1] = {1, 2, 3, 4},
                .level[_Ambient_2] = {1, 2, 3, 4},
                .level[_Ambient_3] = {1, 2, 3, 4},
                .level[_Ambient_4] = {1, 2, 3, 4},
              },
              .GasFRZ = {
                .level[_Ambient_0] = {1, 2, 3, 4},
                .level[_Ambient_1] = {1, 2, 3, 4},
                .level[_Ambient_2] = {1, 2, 3, 4},
                .level[_Ambient_3] = {1, 2, 3, 4},
                .level[_Ambient_4] = {1, 2, 3, 4},
              },
        },
      },
    },
    .Cabin[2] = {
        .type = _CabinType_NONE,
    }, //joker kabin
    .Cabin[3] = {
        .type = _CabinType_NONE,
    }, //var olanda yok ilerisi icin tanimlanmis
};
//#pragma pack()
