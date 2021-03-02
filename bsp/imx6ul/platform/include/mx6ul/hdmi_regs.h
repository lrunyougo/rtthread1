/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file hdmi_regs.h
 * @brief registers defination of hdmi tx module.
 * @ingroup diag_hdmi
 */

#ifndef __HDMI_REGS_H__
#define __HDMI_REGS_H__

#include "soc_memory_map.h"

// ANALOG registers
#define HW_ANADIG_PLL_VIDEO         ANATOP_BASE_ADDR + 0x0a0
#define HW_ANADIG_PLL_VIDEO_NUM     ANATOP_BASE_ADDR + 0x0b0
#define HW_ANADIG_PLL_VIDEO_DENUM   ANATOP_BASE_ADDR + 0x0c0

// HDMI PHY REGISTERS
#define CREGS_PLL_DIV_ADDR              0x06
#define CREGS_PLL_GMP_CNTRL_ADDR        0x15
#define CREGS_PLL_PROP_INT_CNTRL_ADDR   0x10
#define CREGS_PATTERNGEN                0x1B
#define CREGS_PGMODE                    0x1C
#define CREGS_DIGTXMODE                 0x1E

//
// Hdmi controller registers
//

// Identification Registers
#define HDMI_DESIGN_ID              HDMI_ARB_BASE_ADDR+0x0000
#define HDMI_REVISION_ID            HDMI_ARB_BASE_ADDR+0x0001
#define HDMI_PRODUCT_ID0            HDMI_ARB_BASE_ADDR+0x0002
#define HDMI_PRODUCT_ID1            HDMI_ARB_BASE_ADDR+0x0003
#define HDMI_CONFIG0_ID             HDMI_ARB_BASE_ADDR+0x0004
#define HDMI_CONFIG1_ID             HDMI_ARB_BASE_ADDR+0x0005
#define HDMI_CONFIG2_ID             HDMI_ARB_BASE_ADDR+0x0006
#define HDMI_CONFIG3_ID             HDMI_ARB_BASE_ADDR+0x0007

// Interrupt Registers
#define HDMI_IH_FC_STAT0            HDMI_ARB_BASE_ADDR+0x0100
#define HDMI_IH_FC_STAT1            HDMI_ARB_BASE_ADDR+0x0101
#define HDMI_IH_FC_STAT2            HDMI_ARB_BASE_ADDR+0x0102
#define HDMI_IH_AS_STAT0            HDMI_ARB_BASE_ADDR+0x0103
#define HDMI_IH_PHY_STAT0           HDMI_ARB_BASE_ADDR+0x0104
#define HDMI_IH_I2CM_STAT0          HDMI_ARB_BASE_ADDR+0x0105
#define HDMI_IH_CEC_STAT0           HDMI_ARB_BASE_ADDR+0x0106
#define HDMI_IH_VP_STAT0            HDMI_ARB_BASE_ADDR+0x0107
#define HDMI_IH_I2CMPHY_STAT0       HDMI_ARB_BASE_ADDR+0x0108
#define HDMI_IH_AHBDMAAUD_STAT0     HDMI_ARB_BASE_ADDR+0x0180
#define HDMI_IH_MUTE_FC_STAT1       HDMI_ARB_BASE_ADDR+0x0181
#define HDMI_IH_MUTE_FC_STAT2       HDMI_ARB_BASE_ADDR+0x0182
#define HDMI_IH_MUTE_AS_STAT0       HDMI_ARB_BASE_ADDR+0x0183
#define HDMI_IH_MUTE_PHY_STAT0      HDMI_ARB_BASE_ADDR+0x0184
#define HDMI_IH_MUTE_I2CM_STAT0     HDMI_ARB_BASE_ADDR+0x0185
#define HDMI_IH_MUTE_CEC_STAT0      HDMI_ARB_BASE_ADDR+0x0186
#define HDMI_IH_MUTE_VP_STAT0       HDMI_ARB_BASE_ADDR+0x0187
#define HDMI_IH_MUTE_I2CMPHY_STAT0  HDMI_ARB_BASE_ADDR+0x0188
#define HDMI_IH_MUTE_AHBDMAAUD_STAT0  HDMI_ARB_BASE_ADDR+0x0189
#define HDMI_IH_MUTE                HDMI_ARB_BASE_ADDR+0x01FF

// Video Sample Registers
#define HDMI_TX_INVID0              HDMI_ARB_BASE_ADDR+0x0200
#define HDMI_TX_INSTUFFING          HDMI_ARB_BASE_ADDR+0x0201
#define HDMI_TX_GYDATA0             HDMI_ARB_BASE_ADDR+0x0202
#define HDMI_TX_GYDATA1             HDMI_ARB_BASE_ADDR+0x0203
#define HDMI_TX_RCRDATA0            HDMI_ARB_BASE_ADDR+0x0204
#define HDMI_TX_RCRDATA1            HDMI_ARB_BASE_ADDR+0x0205
#define HDMI_TX_BCBDATA0            HDMI_ARB_BASE_ADDR+0x0206
#define HDMI_TX_BCBDATA1            HDMI_ARB_BASE_ADDR+0x0207

// Video Packetizer Registers
#define HDMI_VP_STATUS              HDMI_ARB_BASE_ADDR+0x0800
#define HDMI_VP_PR_CD               HDMI_ARB_BASE_ADDR+0x0801
#define HDMI_VP_STUFF               HDMI_ARB_BASE_ADDR+0x0802
#define HDMI_VP_REMAP               HDMI_ARB_BASE_ADDR+0x0803
#define HDMI_VP_CONF                HDMI_ARB_BASE_ADDR+0x0804
#define HDMI_VP_STAT                HDMI_ARB_BASE_ADDR+0x0805
#define HDMI_VP_INT                 HDMI_ARB_BASE_ADDR+0x0806
#define HDMI_VP_MASK                HDMI_ARB_BASE_ADDR+0x0807
#define HDMI_VP_POL                 HDMI_ARB_BASE_ADDR+0x0808

// Frame Composer Registers
#define HDMI_FC_INVIDCONF           HDMI_ARB_BASE_ADDR+0x1000
#define HDMI_FC_INHACTV0            HDMI_ARB_BASE_ADDR+0x1001
#define HDMI_FC_INHACTV1            HDMI_ARB_BASE_ADDR+0x1002
#define HDMI_FC_INHBLANK0           HDMI_ARB_BASE_ADDR+0x1003
#define HDMI_FC_INHBLANK1           HDMI_ARB_BASE_ADDR+0x1004
#define HDMI_FC_INVACTV0            HDMI_ARB_BASE_ADDR+0x1005
#define HDMI_FC_INVACTV1            HDMI_ARB_BASE_ADDR+0x1006
#define HDMI_FC_INVBLANK            HDMI_ARB_BASE_ADDR+0x1007
#define HDMI_FC_HSYNCINDELAY0       HDMI_ARB_BASE_ADDR+0x1008
#define HDMI_FC_HSYNCINDELAY1       HDMI_ARB_BASE_ADDR+0x1009
#define HDMI_FC_HSYNCINWIDTH0       HDMI_ARB_BASE_ADDR+0x100A
#define HDMI_FC_HSYNCINWIDTH1       HDMI_ARB_BASE_ADDR+0x100B
#define HDMI_FC_VSYNCINDELAY        HDMI_ARB_BASE_ADDR+0x100C
#define HDMI_FC_VSYNCINWIDTH        HDMI_ARB_BASE_ADDR+0x100D
#define HDMI_FC_INFREQ0             HDMI_ARB_BASE_ADDR+0x100E
#define HDMI_FC_INFREQ1             HDMI_ARB_BASE_ADDR+0x100F
#define HDMI_FC_INFREQ2             HDMI_ARB_BASE_ADDR+0x1010
#define HDMI_FC_CTRLDUR             HDMI_ARB_BASE_ADDR+0x1011
#define HDMI_FC_EXCTRLDUR           HDMI_ARB_BASE_ADDR+0x1012
#define HDMI_FC_EXCTRLSPAC          HDMI_ARB_BASE_ADDR+0x1013
#define HDMI_FC_CH0PREAM            HDMI_ARB_BASE_ADDR+0x1014
#define HDMI_FC_CH1PREAM            HDMI_ARB_BASE_ADDR+0x1015
#define HDMI_FC_CH2PREAM            HDMI_ARB_BASE_ADDR+0x1016
#define HDMI_FC_AVICONF3            HDMI_ARB_BASE_ADDR+0x1017
#define HDMI_FC_GCP                 HDMI_ARB_BASE_ADDR+0x1018
#define HDMI_FC_AVICONF0            HDMI_ARB_BASE_ADDR+0x1019
#define HDMI_FC_AVICONF1            HDMI_ARB_BASE_ADDR+0x101A
#define HDMI_FC_AVICONF2            HDMI_ARB_BASE_ADDR+0x101B
#define HDMI_FC_AVIVID              HDMI_ARB_BASE_ADDR+0x101C
#define HDMI_FC_AVIETB0             HDMI_ARB_BASE_ADDR+0x101D
#define HDMI_FC_AVIETB1             HDMI_ARB_BASE_ADDR+0x101E
#define HDMI_FC_AVISBB0             HDMI_ARB_BASE_ADDR+0x101F
#define HDMI_FC_AVISBB1             HDMI_ARB_BASE_ADDR+0x1020
#define HDMI_FC_AVIELB0             HDMI_ARB_BASE_ADDR+0x1021
#define HDMI_FC_AVIELB1             HDMI_ARB_BASE_ADDR+0x1022
#define HDMI_FC_AVISRB0             HDMI_ARB_BASE_ADDR+0x1023
#define HDMI_FC_AVISRB1             HDMI_ARB_BASE_ADDR+0x1024
#define HDMI_FC_AUDICONF0           HDMI_ARB_BASE_ADDR+0x1025
#define HDMI_FC_AUDICONF1           HDMI_ARB_BASE_ADDR+0x1026
#define HDMI_FC_AUDICONF2           HDMI_ARB_BASE_ADDR+0x1027
#define HDMI_FC_AUDICONF3           HDMI_ARB_BASE_ADDR+0x1028
#define HDMI_FC_VSDIEEEID0          HDMI_ARB_BASE_ADDR+0x1029
#define HDMI_FC_VSDSIZE             HDMI_ARB_BASE_ADDR+0x102A
#define HDMI_FC_VSDIEEEID1          HDMI_ARB_BASE_ADDR+0x1030
#define HDMI_FC_VSDIEEEID2          HDMI_ARB_BASE_ADDR+0x1031
#define HDMI_FC_VSDPAYLOAD0         HDMI_ARB_BASE_ADDR+0x1032
#define HDMI_FC_VSDPAYLOAD1         HDMI_ARB_BASE_ADDR+0x1033
#define HDMI_FC_VSDPAYLOAD2         HDMI_ARB_BASE_ADDR+0x1034
#define HDMI_FC_VSDPAYLOAD3         HDMI_ARB_BASE_ADDR+0x1035
#define HDMI_FC_VSDPAYLOAD4         HDMI_ARB_BASE_ADDR+0x1036
#define HDMI_FC_VSDPAYLOAD5         HDMI_ARB_BASE_ADDR+0x1037
#define HDMI_FC_VSDPAYLOAD6         HDMI_ARB_BASE_ADDR+0x1038
#define HDMI_FC_VSDPAYLOAD7         HDMI_ARB_BASE_ADDR+0x1039
#define HDMI_FC_VSDPAYLOAD8         HDMI_ARB_BASE_ADDR+0x103A
#define HDMI_FC_VSDPAYLOAD9         HDMI_ARB_BASE_ADDR+0x103B
#define HDMI_FC_VSDPAYLOAD10        HDMI_ARB_BASE_ADDR+0x103C
#define HDMI_FC_VSDPAYLOAD11        HDMI_ARB_BASE_ADDR+0x103D
#define HDMI_FC_VSDPAYLOAD12        HDMI_ARB_BASE_ADDR+0x103E
#define HDMI_FC_VSDPAYLOAD13        HDMI_ARB_BASE_ADDR+0x103F
#define HDMI_FC_VSDPAYLOAD14        HDMI_ARB_BASE_ADDR+0x1040
#define HDMI_FC_VSDPAYLOAD15        HDMI_ARB_BASE_ADDR+0x1041
#define HDMI_FC_VSDPAYLOAD16        HDMI_ARB_BASE_ADDR+0x1042
#define HDMI_FC_VSDPAYLOAD17        HDMI_ARB_BASE_ADDR+0x1043
#define HDMI_FC_VSDPAYLOAD18        HDMI_ARB_BASE_ADDR+0x1044
#define HDMI_FC_VSDPAYLOAD19        HDMI_ARB_BASE_ADDR+0x1045
#define HDMI_FC_VSDPAYLOAD20        HDMI_ARB_BASE_ADDR+0x1046
#define HDMI_FC_VSDPAYLOAD21        HDMI_ARB_BASE_ADDR+0x1047
#define HDMI_FC_VSDPAYLOAD22        HDMI_ARB_BASE_ADDR+0x1048
#define HDMI_FC_VSDPAYLOAD23        HDMI_ARB_BASE_ADDR+0x1049
#define HDMI_FC_SPDVENDORNAME0      HDMI_ARB_BASE_ADDR+0x104A
#define HDMI_FC_SPDVENDORNAME1      HDMI_ARB_BASE_ADDR+0x104B
#define HDMI_FC_SPDVENDORNAME2      HDMI_ARB_BASE_ADDR+0x104C
#define HDMI_FC_SPDVENDORNAME3      HDMI_ARB_BASE_ADDR+0x104D
#define HDMI_FC_SPDVENDORNAME4      HDMI_ARB_BASE_ADDR+0x104E
#define HDMI_FC_SPDVENDORNAME5      HDMI_ARB_BASE_ADDR+0x104F
#define HDMI_FC_SPDVENDORNAME6      HDMI_ARB_BASE_ADDR+0x1050
#define HDMI_FC_SPDVENDORNAME7      HDMI_ARB_BASE_ADDR+0x1051
#define HDMI_FC_SDPPRODUCTNAME0     HDMI_ARB_BASE_ADDR+0x1052
#define HDMI_FC_SDPPRODUCTNAME1     HDMI_ARB_BASE_ADDR+0x1053
#define HDMI_FC_SDPPRODUCTNAME2     HDMI_ARB_BASE_ADDR+0x1054
#define HDMI_FC_SDPPRODUCTNAME3     HDMI_ARB_BASE_ADDR+0x1055
#define HDMI_FC_SDPPRODUCTNAME4     HDMI_ARB_BASE_ADDR+0x1056
#define HDMI_FC_SDPPRODUCTNAME5     HDMI_ARB_BASE_ADDR+0x1057
#define HDMI_FC_SDPPRODUCTNAME6     HDMI_ARB_BASE_ADDR+0x1058
#define HDMI_FC_SDPPRODUCTNAME7     HDMI_ARB_BASE_ADDR+0x1059
#define HDMI_FC_SDPPRODUCTNAME8     HDMI_ARB_BASE_ADDR+0x105A
#define HDMI_FC_SDPPRODUCTNAME9     HDMI_ARB_BASE_ADDR+0x105B
#define HDMI_FC_SDPPRODUCTNAME10    HDMI_ARB_BASE_ADDR+0x105C
#define HDMI_FC_SDPPRODUCTNAME11    HDMI_ARB_BASE_ADDR+0x105D
#define HDMI_FC_SDPPRODUCTNAME12    HDMI_ARB_BASE_ADDR+0x105E
#define HDMI_FC_SDPPRODUCTNAME13    HDMI_ARB_BASE_ADDR+0x105F
#define HDMI_FC_SDPPRODUCTNAME14    HDMI_ARB_BASE_ADDR+0x1060
#define HDMI_FC_SPDPRODUCTNAME15    HDMI_ARB_BASE_ADDR+0x1061
#define HDMI_FC_SPDDEVICEINF        HDMI_ARB_BASE_ADDR+0x1062
#define HDMI_FC_AUDSCONF            HDMI_ARB_BASE_ADDR+0x1063
#define HDMI_FC_AUDSSTAT            HDMI_ARB_BASE_ADDR+0x1064
#define HDMI_FC_AUDSV               HDMI_ARB_BASE_ADDR+0x1065
#define HDMI_FC_AUDSU               HDMI_ARB_BASE_ADDR+0x1066
#define HDMI_FC_AUDSCHNLS0          HDMI_ARB_BASE_ADDR+0x1067
#define HDMI_FC_AUDSCHNLS1          HDMI_ARB_BASE_ADDR+0x1068
#define HDMI_FC_AUDSCHNLS2          HDMI_ARB_BASE_ADDR+0x1069
#define HDMI_FC_AUDSCHNLS3          HDMI_ARB_BASE_ADDR+0x106A
#define HDMI_FC_AUDSCHNLS4          HDMI_ARB_BASE_ADDR+0x106B
#define HDMI_FC_AUDSCHNLS5          HDMI_ARB_BASE_ADDR+0x106C
#define HDMI_FC_AUDSCHNLS6          HDMI_ARB_BASE_ADDR+0x106D
#define HDMI_FC_AUDSCHNLS7          HDMI_ARB_BASE_ADDR+0x106E
#define HDMI_FC_AUDSCHNLS8          HDMI_ARB_BASE_ADDR+0x106F
#define HDMI_FC_DATACH0FILL         HDMI_ARB_BASE_ADDR+0x1070
#define HDMI_FC_DATACH1FILL         HDMI_ARB_BASE_ADDR+0x1071
#define HDMI_FC_DATACH2FILL         HDMI_ARB_BASE_ADDR+0x1072
#define HDMI_FC_CTRLQHIGH           HDMI_ARB_BASE_ADDR+0x1073
#define HDMI_FC_CTRLQLOW            HDMI_ARB_BASE_ADDR+0x1074
#define HDMI_FC_ACP0                HDMI_ARB_BASE_ADDR+0x1075
#define HDMI_FC_ACP28               HDMI_ARB_BASE_ADDR+0x1076
#define HDMI_FC_ACP27               HDMI_ARB_BASE_ADDR+0x1077
#define HDMI_FC_ACP26               HDMI_ARB_BASE_ADDR+0x1078
#define HDMI_FC_ACP25               HDMI_ARB_BASE_ADDR+0x1079
#define HDMI_FC_ACP24               HDMI_ARB_BASE_ADDR+0x107A
#define HDMI_FC_ACP23               HDMI_ARB_BASE_ADDR+0x107B
#define HDMI_FC_ACP22               HDMI_ARB_BASE_ADDR+0x107C
#define HDMI_FC_ACP21               HDMI_ARB_BASE_ADDR+0x107D
#define HDMI_FC_ACP20               HDMI_ARB_BASE_ADDR+0x107E
#define HDMI_FC_ACP19               HDMI_ARB_BASE_ADDR+0x107F
#define HDMI_FC_ACP18               HDMI_ARB_BASE_ADDR+0x1080
#define HDMI_FC_ACP17               HDMI_ARB_BASE_ADDR+0x1081
#define HDMI_FC_ACP16               HDMI_ARB_BASE_ADDR+0x1082
#define HDMI_FC_ACP15               HDMI_ARB_BASE_ADDR+0x1083
#define HDMI_FC_ACP14               HDMI_ARB_BASE_ADDR+0x1084
#define HDMI_FC_ACP13               HDMI_ARB_BASE_ADDR+0x1085
#define HDMI_FC_ACP12               HDMI_ARB_BASE_ADDR+0x1086
#define HDMI_FC_ACP11               HDMI_ARB_BASE_ADDR+0x1087
#define HDMI_FC_ACP10               HDMI_ARB_BASE_ADDR+0x1088
#define HDMI_FC_ACP9                HDMI_ARB_BASE_ADDR+0x1089
#define HDMI_FC_ACP8                HDMI_ARB_BASE_ADDR+0x108A
#define HDMI_FC_ACP7                HDMI_ARB_BASE_ADDR+0x108B
#define HDMI_FC_ACP6                HDMI_ARB_BASE_ADDR+0x108C
#define HDMI_FC_ACP5                HDMI_ARB_BASE_ADDR+0x108D
#define HDMI_FC_ACP4                HDMI_ARB_BASE_ADDR+0x108E
#define HDMI_FC_ACP3                HDMI_ARB_BASE_ADDR+0x108F
#define HDMI_FC_ACP2                HDMI_ARB_BASE_ADDR+0x1090
#define HDMI_FC_ACP1                HDMI_ARB_BASE_ADDR+0x1091
#define HDMI_FC_ISCR1_0             HDMI_ARB_BASE_ADDR+0x1092
#define HDMI_FC_ISCR1_16            HDMI_ARB_BASE_ADDR+0x1093
#define HDMI_FC_ISCR1_15            HDMI_ARB_BASE_ADDR+0x1094
#define HDMI_FC_ISCR1_14            HDMI_ARB_BASE_ADDR+0x1095
#define HDMI_FC_ISCR1_13            HDMI_ARB_BASE_ADDR+0x1096
#define HDMI_FC_ISCR1_12            HDMI_ARB_BASE_ADDR+0x1097
#define HDMI_FC_ISCR1_11            HDMI_ARB_BASE_ADDR+0x1098
#define HDMI_FC_ISCR1_10            HDMI_ARB_BASE_ADDR+0x1099
#define HDMI_FC_ISCR1_9             HDMI_ARB_BASE_ADDR+0x109A
#define HDMI_FC_ISCR1_8             HDMI_ARB_BASE_ADDR+0x109B
#define HDMI_FC_ISCR1_7             HDMI_ARB_BASE_ADDR+0x109C
#define HDMI_FC_ISCR1_6             HDMI_ARB_BASE_ADDR+0x109D
#define HDMI_FC_ISCR1_5             HDMI_ARB_BASE_ADDR+0x109E
#define HDMI_FC_ISCR1_4             HDMI_ARB_BASE_ADDR+0x109F
#define HDMI_FC_ISCR1_3             HDMI_ARB_BASE_ADDR+0x10A0
#define HDMI_FC_ISCR1_2             HDMI_ARB_BASE_ADDR+0x10A1
#define HDMI_FC_ISCR1_1             HDMI_ARB_BASE_ADDR+0x10A2
#define HDMI_FC_ISCR2_15            HDMI_ARB_BASE_ADDR+0x10A3
#define HDMI_FC_ISCR2_14            HDMI_ARB_BASE_ADDR+0x10A4
#define HDMI_FC_ISCR2_13            HDMI_ARB_BASE_ADDR+0x10A5
#define HDMI_FC_ISCR2_12            HDMI_ARB_BASE_ADDR+0x10A6
#define HDMI_FC_ISCR2_11            HDMI_ARB_BASE_ADDR+0x10A7
#define HDMI_FC_ISCR2_10            HDMI_ARB_BASE_ADDR+0x10A8
#define HDMI_FC_ISCR2_9             HDMI_ARB_BASE_ADDR+0x10A9
#define HDMI_FC_ISCR2_8             HDMI_ARB_BASE_ADDR+0x10AA
#define HDMI_FC_ISCR2_7             HDMI_ARB_BASE_ADDR+0x10AB
#define HDMI_FC_ISCR2_6             HDMI_ARB_BASE_ADDR+0x10AC
#define HDMI_FC_ISCR2_5             HDMI_ARB_BASE_ADDR+0x10AD
#define HDMI_FC_ISCR2_4             HDMI_ARB_BASE_ADDR+0x10AE
#define HDMI_FC_ISCR2_3             HDMI_ARB_BASE_ADDR+0x10AF
#define HDMI_FC_ISCR2_2             HDMI_ARB_BASE_ADDR+0x10B0
#define HDMI_FC_ISCR2_1             HDMI_ARB_BASE_ADDR+0x10B1
#define HDMI_FC_ISCR2_0             HDMI_ARB_BASE_ADDR+0x10B2
#define HDMI_FC_DATAUTO0            HDMI_ARB_BASE_ADDR+0x10B3
#define HDMI_FC_DATAUTO1            HDMI_ARB_BASE_ADDR+0x10B4
#define HDMI_FC_DATAUTO2            HDMI_ARB_BASE_ADDR+0x10B5
#define HDMI_FC_DATMAN              HDMI_ARB_BASE_ADDR+0x10B6
#define HDMI_FC_DATAUTO3            HDMI_ARB_BASE_ADDR+0x10B7
#define HDMI_FC_RDRB0               HDMI_ARB_BASE_ADDR+0x10B8
#define HDMI_FC_RDRB1               HDMI_ARB_BASE_ADDR+0x10B9
#define HDMI_FC_RDRB2               HDMI_ARB_BASE_ADDR+0x10BA
#define HDMI_FC_RDRB3               HDMI_ARB_BASE_ADDR+0x10BB
#define HDMI_FC_RDRB4               HDMI_ARB_BASE_ADDR+0x10BC
#define HDMI_FC_RDRB5               HDMI_ARB_BASE_ADDR+0x10BD
#define HDMI_FC_RDRB6               HDMI_ARB_BASE_ADDR+0x10BE
#define HDMI_FC_RDRB7               HDMI_ARB_BASE_ADDR+0x10BF
#define HDMI_FC_STAT0               HDMI_ARB_BASE_ADDR+0x10D0
#define HDMI_FC_INT0                HDMI_ARB_BASE_ADDR+0x10D1
#define HDMI_FC_MASK0               HDMI_ARB_BASE_ADDR+0x10D2
#define HDMI_FC_POL0                HDMI_ARB_BASE_ADDR+0x10D3
#define HDMI_FC_STAT1               HDMI_ARB_BASE_ADDR+0x10D4
#define HDMI_FC_INT1                HDMI_ARB_BASE_ADDR+0x10D5
#define HDMI_FC_MASK1               HDMI_ARB_BASE_ADDR+0x10D6
#define HDMI_FC_POL1                HDMI_ARB_BASE_ADDR+0x10D7
#define HDMI_FC_STAT2               HDMI_ARB_BASE_ADDR+0x10D8
#define HDMI_FC_INT2                HDMI_ARB_BASE_ADDR+0x10D9
#define HDMI_FC_MASK2               HDMI_ARB_BASE_ADDR+0x10DA
#define HDMI_FC_POL2                HDMI_ARB_BASE_ADDR+0x10DB
#define HDMI_FC_PRCONF              HDMI_ARB_BASE_ADDR+0x10E0

#define HDMI_FC_GMD_STAT            HDMI_ARB_BASE_ADDR+0x1100
#define HDMI_FC_GMD_EN              HDMI_ARB_BASE_ADDR+0x1101
#define HDMI_FC_GMD_UP              HDMI_ARB_BASE_ADDR+0x1102
#define HDMI_FC_GMD_CONF            HDMI_ARB_BASE_ADDR+0x1103
#define HDMI_FC_GMD_HB              HDMI_ARB_BASE_ADDR+0x1104
#define HDMI_FC_GMD_PB0             HDMI_ARB_BASE_ADDR+0x1105
#define HDMI_FC_GMD_PB1             HDMI_ARB_BASE_ADDR+0x1106
#define HDMI_FC_GMD_PB2             HDMI_ARB_BASE_ADDR+0x1107
#define HDMI_FC_GMD_PB3             HDMI_ARB_BASE_ADDR+0x1108
#define HDMI_FC_GMD_PB4             HDMI_ARB_BASE_ADDR+0x1109
#define HDMI_FC_GMD_PB5             HDMI_ARB_BASE_ADDR+0x110A
#define HDMI_FC_GMD_PB6             HDMI_ARB_BASE_ADDR+0x110B
#define HDMI_FC_GMD_PB7             HDMI_ARB_BASE_ADDR+0x110C
#define HDMI_FC_GMD_PB8             HDMI_ARB_BASE_ADDR+0x110D
#define HDMI_FC_GMD_PB9             HDMI_ARB_BASE_ADDR+0x110E
#define HDMI_FC_GMD_PB10            HDMI_ARB_BASE_ADDR+0x110F
#define HDMI_FC_GMD_PB11            HDMI_ARB_BASE_ADDR+0x1110
#define HDMI_FC_GMD_PB12            HDMI_ARB_BASE_ADDR+0x1111
#define HDMI_FC_GMD_PB13            HDMI_ARB_BASE_ADDR+0x1112
#define HDMI_FC_GMD_PB14            HDMI_ARB_BASE_ADDR+0x1113
#define HDMI_FC_GMD_PB15            HDMI_ARB_BASE_ADDR+0x1114
#define HDMI_FC_GMD_PB16            HDMI_ARB_BASE_ADDR+0x1115
#define HDMI_FC_GMD_PB17            HDMI_ARB_BASE_ADDR+0x1116
#define HDMI_FC_GMD_PB18            HDMI_ARB_BASE_ADDR+0x1117
#define HDMI_FC_GMD_PB19            HDMI_ARB_BASE_ADDR+0x1118
#define HDMI_FC_GMD_PB20            HDMI_ARB_BASE_ADDR+0x1119
#define HDMI_FC_GMD_PB21            HDMI_ARB_BASE_ADDR+0x111A
#define HDMI_FC_GMD_PB22            HDMI_ARB_BASE_ADDR+0x111B
#define HDMI_FC_GMD_PB23            HDMI_ARB_BASE_ADDR+0x111C
#define HDMI_FC_GMD_PB24            HDMI_ARB_BASE_ADDR+0x111D
#define HDMI_FC_GMD_PB25            HDMI_ARB_BASE_ADDR+0x111E
#define HDMI_FC_GMD_PB26            HDMI_ARB_BASE_ADDR+0x111F
#define HDMI_FC_GMD_PB27            HDMI_ARB_BASE_ADDR+0x1120

#define HDMI_FC_DBGFORCE            HDMI_ARB_BASE_ADDR+0x1200
#define HDMI_FC_DBGAUD0CH0          HDMI_ARB_BASE_ADDR+0x1201
#define HDMI_FC_DBGAUD1CH0          HDMI_ARB_BASE_ADDR+0x1202
#define HDMI_FC_DBGAUD2CH0          HDMI_ARB_BASE_ADDR+0x1203
#define HDMI_FC_DBGAUD0CH1          HDMI_ARB_BASE_ADDR+0x1204
#define HDMI_FC_DBGAUD1CH1          HDMI_ARB_BASE_ADDR+0x1205
#define HDMI_FC_DBGAUD2CH1          HDMI_ARB_BASE_ADDR+0x1206
#define HDMI_FC_DBGAUD0CH2          HDMI_ARB_BASE_ADDR+0x1207
#define HDMI_FC_DBGAUD1CH2          HDMI_ARB_BASE_ADDR+0x1208
#define HDMI_FC_DBGAUD2CH2          HDMI_ARB_BASE_ADDR+0x1209
#define HDMI_FC_DBGAUD0CH3          HDMI_ARB_BASE_ADDR+0x120A
#define HDMI_FC_DBGAUD1CH3          HDMI_ARB_BASE_ADDR+0x120B
#define HDMI_FC_DBGAUD2CH3          HDMI_ARB_BASE_ADDR+0x120C
#define HDMI_FC_DBGAUD0CH4          HDMI_ARB_BASE_ADDR+0x120D
#define HDMI_FC_DBGAUD1CH4          HDMI_ARB_BASE_ADDR+0x120E
#define HDMI_FC_DBGAUD2CH4          HDMI_ARB_BASE_ADDR+0x120F
#define HDMI_FC_DBGAUD0CH5          HDMI_ARB_BASE_ADDR+0x1210
#define HDMI_FC_DBGAUD1CH5          HDMI_ARB_BASE_ADDR+0x1211
#define HDMI_FC_DBGAUD2CH5          HDMI_ARB_BASE_ADDR+0x1212
#define HDMI_FC_DBGAUD0CH6          HDMI_ARB_BASE_ADDR+0x1213
#define HDMI_FC_DBGAUD1CH6          HDMI_ARB_BASE_ADDR+0x1214
#define HDMI_FC_DBGAUD2CH6          HDMI_ARB_BASE_ADDR+0x1215
#define HDMI_FC_DBGAUD0CH7          HDMI_ARB_BASE_ADDR+0x1216
#define HDMI_FC_DBGAUD1CH7          HDMI_ARB_BASE_ADDR+0x1217
#define HDMI_FC_DBGAUD2CH7          HDMI_ARB_BASE_ADDR+0x1218
#define HDMI_FC_DBGTMDS0            HDMI_ARB_BASE_ADDR+0x1219
#define HDMI_FC_DBGTMDS1            HDMI_ARB_BASE_ADDR+0x121A
#define HDMI_FC_DBGTMDS2            HDMI_ARB_BASE_ADDR+0x121B

// HDMI Source PHY Registers
#define HDMI_PHY_CONF0                  HDMI_ARB_BASE_ADDR+0x3000
#define HDMI_PHY_TST0                   HDMI_ARB_BASE_ADDR+0x3001
#define HDMI_PHY_TST1                   HDMI_ARB_BASE_ADDR+0x3002
#define HDMI_PHY_TST2                   HDMI_ARB_BASE_ADDR+0x3003
#define HDMI_PHY_STAT0                  HDMI_ARB_BASE_ADDR+0x3004
#define HDMI_PHY_INT0                   HDMI_ARB_BASE_ADDR+0x3005
#define HDMI_PHY_MASK0                  HDMI_ARB_BASE_ADDR+0x3006
#define HDMI_PHY_POL0                   HDMI_ARB_BASE_ADDR+0x3007

// HDMI Master PHY Registers
#define HDMI_PHY_I2CM_SLAVE_ADDR             HDMI_ARB_BASE_ADDR+0x3020
#define HDMI_PHY_I2CM_ADDRESS_ADDR           HDMI_ARB_BASE_ADDR+0x3021
#define HDMI_PHY_I2CM_DATAO_1_ADDR           HDMI_ARB_BASE_ADDR+0x3022
#define HDMI_PHY_I2CM_DATAO_0_ADDR           HDMI_ARB_BASE_ADDR+0x3023
#define HDMI_PHY_I2CM_DATAI_1_ADDR           HDMI_ARB_BASE_ADDR+0x3024
#define HDMI_PHY_I2CM_DATAI_0_ADDR           HDMI_ARB_BASE_ADDR+0x3025
#define HDMI_PHY_I2CM_OPERATION_ADDR         HDMI_ARB_BASE_ADDR+0x3026
#define HDMI_PHY_I2CM_INT_ADDR               HDMI_ARB_BASE_ADDR+0x3027
#define HDMI_PHY_I2CM_CTLINT_ADDR            HDMI_ARB_BASE_ADDR+0x3028
#define HDMI_PHY_I2CM_DIV_ADDR               HDMI_ARB_BASE_ADDR+0x3029
#define HDMI_PHY_I2CM_SOFTRSTZ_ADDR          HDMI_ARB_BASE_ADDR+0x302a
#define HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR     HDMI_ARB_BASE_ADDR+0x302b
#define HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR     HDMI_ARB_BASE_ADDR+0x302c
#define HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR     HDMI_ARB_BASE_ADDR+0x302d
#define HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR     HDMI_ARB_BASE_ADDR+0x302e
#define HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR     HDMI_ARB_BASE_ADDR+0x302f
#define HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR     HDMI_ARB_BASE_ADDR+0x3030
#define HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR     HDMI_ARB_BASE_ADDR+0x3031
#define HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR     HDMI_ARB_BASE_ADDR+0x3032

// Generic Parallel Audio Interface Registers
#define HDMI_GP_CONF0               HDMI_ARB_BASE_ADDR+0x3500
#define HDMI_GP_CONF1               HDMI_ARB_BASE_ADDR+0x3501
#define HDMI_GP_CONF2               HDMI_ARB_BASE_ADDR+0x3502
#define HDMI_GP_STAT                HDMI_ARB_BASE_ADDR+0x3503
#define HDMI_GP_INT                 HDMI_ARB_BASE_ADDR+0x3504
#define HDMI_GP_MASK                HDMI_ARB_BASE_ADDR+0x3505
#define HDMI_GP_POL                 HDMI_ARB_BASE_ADDR+0x3506

// Audio DMA Registers (TBD)
#define HDMI_AHB_DMA_CONF0          HDMI_ARB_BASE_ADDR+0x3600
#define HDMI_AHB_DMA_START          HDMI_ARB_BASE_ADDR+0x3601
#define HDMI_AHB_DMA_STOP           HDMI_ARB_BASE_ADDR+0x3602
#define HDMI_AHB_DMA_THRSLD         HDMI_ARB_BASE_ADDR+0x3603
#define HDMI_AHB_DMA_STRADDR0       HDMI_ARB_BASE_ADDR+0x3604
#define HDMI_AHB_DMA_STRADDR1       HDMI_ARB_BASE_ADDR+0x3605
#define HDMI_AHB_DMA_STRADDR2       HDMI_ARB_BASE_ADDR+0x3606
#define HDMI_AHB_DMA_STRADDR3       HDMI_ARB_BASE_ADDR+0x3607
#define HDMI_AHB_DMA_STPADDR0       HDMI_ARB_BASE_ADDR+0x3608
#define HDMI_AHB_DMA_STPADDR1       HDMI_ARB_BASE_ADDR+0x3609
#define HDMI_AHB_DMA_STPADDR2       HDMI_ARB_BASE_ADDR+0x360a
#define HDMI_AHB_DMA_STPADDR3       HDMI_ARB_BASE_ADDR+0x360b
#define HDMI_AHB_DMA_BSTADDR0       HDMI_ARB_BASE_ADDR+0x360c
#define HDMI_AHB_DMA_BSTADDR1       HDMI_ARB_BASE_ADDR+0x360d
#define HDMI_AHB_DMA_BSTADDR2       HDMI_ARB_BASE_ADDR+0x360e
#define HDMI_AHB_DMA_BSTADDR3       HDMI_ARB_BASE_ADDR+0x360f
#define HDMI_AHB_DMA_MBLENGTH0      HDMI_ARB_BASE_ADDR+0x3610
#define HDMI_AHB_DMA_MBLENGTH1      HDMI_ARB_BASE_ADDR+0x3611
#define HDMI_AHB_DMA_STAT           HDMI_ARB_BASE_ADDR+0x3612
#define HDMI_AHB_DMA_INT            HDMI_ARB_BASE_ADDR+0x3613
#define HDMI_AHB_DMA_MASK           HDMI_ARB_BASE_ADDR+0x3614
#define HDMI_AHB_DMA_POL            HDMI_ARB_BASE_ADDR+0x3615

// Main Controller Registers
#define HDMI_MC_SFRDIV              HDMI_ARB_BASE_ADDR+0x4000
#define HDMI_MC_CLKDIS              HDMI_ARB_BASE_ADDR+0x4001
#define HDMI_MC_SWRSTZ              HDMI_ARB_BASE_ADDR+0x4002
#define HDMI_MC_OPCTRL              HDMI_ARB_BASE_ADDR+0x4003
#define HDMI_MC_FLOWCTRL            HDMI_ARB_BASE_ADDR+0x4004
#define HDMI_MC_PHYRSTZ             HDMI_ARB_BASE_ADDR+0x4005
#define HDMI_MC_LOCKONCLOCK         HDMI_ARB_BASE_ADDR+0x4006
#define HDMI_MC_HEACPHY_RST         HDMI_ARB_BASE_ADDR+0x4007

// Color Space  Converter Registers
#define HDMI_CSC_CFG                HDMI_ARB_BASE_ADDR+0x4100
#define HDMI_CSC_SCALE              HDMI_ARB_BASE_ADDR+0x4101
#define HDMI_CSC_COEF_A1_MSB        HDMI_ARB_BASE_ADDR+0x4102
#define HDMI_CSC_COEF_A1_LSB        HDMI_ARB_BASE_ADDR+0x4103
#define HDMI_CSC_COEF_A2_MSB        HDMI_ARB_BASE_ADDR+0x4104
#define HDMI_CSC_COEF_A2_LSB        HDMI_ARB_BASE_ADDR+0x4105
#define HDMI_CSC_COEF_A3_MSB        HDMI_ARB_BASE_ADDR+0x4106
#define HDMI_CSC_COEF_A3_LSB        HDMI_ARB_BASE_ADDR+0x4107
#define HDMI_CSC_COEF_A4_MSB        HDMI_ARB_BASE_ADDR+0x4108
#define HDMI_CSC_COEF_A4_LSB        HDMI_ARB_BASE_ADDR+0x4109
#define HDMI_CSC_COEF_B1_MSB        HDMI_ARB_BASE_ADDR+0x410A
#define HDMI_CSC_COEF_B1_LSB        HDMI_ARB_BASE_ADDR+0x410B
#define HDMI_CSC_COEF_B2_MSB        HDMI_ARB_BASE_ADDR+0x410C
#define HDMI_CSC_COEF_B2_LSB        HDMI_ARB_BASE_ADDR+0x410D
#define HDMI_CSC_COEF_B3_MSB        HDMI_ARB_BASE_ADDR+0x410E
#define HDMI_CSC_COEF_B3_LSB        HDMI_ARB_BASE_ADDR+0x410F
#define HDMI_CSC_COEF_B4_MSB        HDMI_ARB_BASE_ADDR+0x4110
#define HDMI_CSC_COEF_B4_LSB        HDMI_ARB_BASE_ADDR+0x4111
#define HDMI_CSC_COEF_C1_MSB        HDMI_ARB_BASE_ADDR+0x4112
#define HDMI_CSC_COEF_C1_LSB        HDMI_ARB_BASE_ADDR+0x4113
#define HDMI_CSC_COEF_C2_MSB        HDMI_ARB_BASE_ADDR+0x4114
#define HDMI_CSC_COEF_C2_LSB        HDMI_ARB_BASE_ADDR+0x4115
#define HDMI_CSC_COEF_C3_MSB        HDMI_ARB_BASE_ADDR+0x4116
#define HDMI_CSC_COEF_C3_LSB        HDMI_ARB_BASE_ADDR+0x4117
#define HDMI_CSC_COEF_C4_MSB        HDMI_ARB_BASE_ADDR+0x4118
#define HDMI_CSC_COEF_C4_LSB        HDMI_ARB_BASE_ADDR+0x4119

// HDCP Encryption Engine Registers
#define HDMI_A_HDCPCFG0             HDMI_ARB_BASE_ADDR+0x5000
#define HDMI_A_HDCPCFG1             HDMI_ARB_BASE_ADDR+0x5001
#define HDMI_A_HDCPOBS0             HDMI_ARB_BASE_ADDR+0x5002
#define HDMI_A_HDCPOBS1             HDMI_ARB_BASE_ADDR+0x5003
#define HDMI_A_HDCPOBS2             HDMI_ARB_BASE_ADDR+0x5004
#define HDMI_A_HDCPOBS3             HDMI_ARB_BASE_ADDR+0x5005
#define HDMI_A_APIINTCLR            HDMI_ARB_BASE_ADDR+0x5006
#define HDMI_A_APIINTSTAT           HDMI_ARB_BASE_ADDR+0x5007
#define HDMI_A_APIINTMSK            HDMI_ARB_BASE_ADDR+0x5008
#define HDMI_A_VIDPOLCFG            HDMI_ARB_BASE_ADDR+0x5009
#define HDMI_A_OESSWCFG             HDMI_ARB_BASE_ADDR+0x500A
#define HDMI_A_TIMER1SETUP0         HDMI_ARB_BASE_ADDR+0x500B
#define HDMI_A_TIMER1SETUP1         HDMI_ARB_BASE_ADDR+0x500C
#define HDMI_A_TIMER2SETUP0         HDMI_ARB_BASE_ADDR+0x500D
#define HDMI_A_TIMER2SETUP1         HDMI_ARB_BASE_ADDR+0x500E
#define HDMI_A_100MSCFG             HDMI_ARB_BASE_ADDR+0x500F
#define HDMI_A_2SCFG0               HDMI_ARB_BASE_ADDR+0x5010
#define HDMI_A_2SCFG1               HDMI_ARB_BASE_ADDR+0x5011
#define HDMI_A_5SCFG0               HDMI_ARB_BASE_ADDR+0x5012
#define HDMI_A_5SCFG1               HDMI_ARB_BASE_ADDR+0x5013
#define HDMI_A_SRMVERLSB            HDMI_ARB_BASE_ADDR+0x5014
#define HDMI_A_SRMVERMSB            HDMI_ARB_BASE_ADDR+0x5015
#define HDMI_A_SRMCTRL              HDMI_ARB_BASE_ADDR+0x5016
#define HDMI_A_SFRSETUP             HDMI_ARB_BASE_ADDR+0x5017
#define HDMI_A_I2CHSETUP            HDMI_ARB_BASE_ADDR+0x5018
#define HDMI_A_INTSETUP             HDMI_ARB_BASE_ADDR+0x5019
#define HDMI_A_PRESETUP             HDMI_ARB_BASE_ADDR+0x501A
#define HDMI_A_SRM_BASE             HDMI_ARB_BASE_ADDR+0x5020

// CEC Engine Registers
#define HDMI_CEC_CTRL               HDMI_ARB_BASE_ADDR+0x7D00
#define HDMI_CEC_STAT               HDMI_ARB_BASE_ADDR+0x7D01
#define HDMI_CEC_MASK               HDMI_ARB_BASE_ADDR+0x7D02
#define HDMI_CEC_POLARITY           HDMI_ARB_BASE_ADDR+0x7D03
#define HDMI_CEC_INT                HDMI_ARB_BASE_ADDR+0x7D04
#define HDMI_CEC_ADDR_L             HDMI_ARB_BASE_ADDR+0x7D05
#define HDMI_CEC_ADDR_H             HDMI_ARB_BASE_ADDR+0x7D06
#define HDMI_CEC_TX_CNT             HDMI_ARB_BASE_ADDR+0x7D07
#define HDMI_CEC_RX_CNT             HDMI_ARB_BASE_ADDR+0x7D08
#define HDMI_CEC_TX_DATA0           HDMI_ARB_BASE_ADDR+0x7D10
#define HDMI_CEC_TX_DATA1           HDMI_ARB_BASE_ADDR+0x7D11
#define HDMI_CEC_TX_DATA2           HDMI_ARB_BASE_ADDR+0x7D12
#define HDMI_CEC_TX_DATA3           HDMI_ARB_BASE_ADDR+0x7D13
#define HDMI_CEC_TX_DATA4           HDMI_ARB_BASE_ADDR+0x7D14
#define HDMI_CEC_TX_DATA5           HDMI_ARB_BASE_ADDR+0x7D15
#define HDMI_CEC_TX_DATA6           HDMI_ARB_BASE_ADDR+0x7D16
#define HDMI_CEC_TX_DATA7           HDMI_ARB_BASE_ADDR+0x7D17
#define HDMI_CEC_TX_DATA8           HDMI_ARB_BASE_ADDR+0x7D18
#define HDMI_CEC_TX_DATA9           HDMI_ARB_BASE_ADDR+0x7D19
#define HDMI_CEC_TX_DATA10          HDMI_ARB_BASE_ADDR+0x7D1a
#define HDMI_CEC_TX_DATA11          HDMI_ARB_BASE_ADDR+0x7D1b
#define HDMI_CEC_TX_DATA12          HDMI_ARB_BASE_ADDR+0x7D1c
#define HDMI_CEC_TX_DATA13          HDMI_ARB_BASE_ADDR+0x7D1d
#define HDMI_CEC_TX_DATA14          HDMI_ARB_BASE_ADDR+0x7D1e
#define HDMI_CEC_TX_DATA15          HDMI_ARB_BASE_ADDR+0x7D1f
#define HDMI_CEC_RX_DATA0           HDMI_ARB_BASE_ADDR+0x7D20
#define HDMI_CEC_RX_DATA1           HDMI_ARB_BASE_ADDR+0x7D21
#define HDMI_CEC_RX_DATA2           HDMI_ARB_BASE_ADDR+0x7D22
#define HDMI_CEC_RX_DATA3           HDMI_ARB_BASE_ADDR+0x7D23
#define HDMI_CEC_RX_DATA4           HDMI_ARB_BASE_ADDR+0x7D24
#define HDMI_CEC_RX_DATA5           HDMI_ARB_BASE_ADDR+0x7D25
#define HDMI_CEC_RX_DATA6           HDMI_ARB_BASE_ADDR+0x7D26
#define HDMI_CEC_RX_DATA7           HDMI_ARB_BASE_ADDR+0x7D27
#define HDMI_CEC_RX_DATA8           HDMI_ARB_BASE_ADDR+0x7D28
#define HDMI_CEC_RX_DATA9           HDMI_ARB_BASE_ADDR+0x7D29
#define HDMI_CEC_RX_DATA10          HDMI_ARB_BASE_ADDR+0x7D2a
#define HDMI_CEC_RX_DATA11          HDMI_ARB_BASE_ADDR+0x7D2b
#define HDMI_CEC_RX_DATA12          HDMI_ARB_BASE_ADDR+0x7D2c
#define HDMI_CEC_RX_DATA13          HDMI_ARB_BASE_ADDR+0x7D2d
#define HDMI_CEC_RX_DATA14          HDMI_ARB_BASE_ADDR+0x7D2e
#define HDMI_CEC_RX_DATA15          HDMI_ARB_BASE_ADDR+0x7D2f
#define HDMI_CEC_LOCK               HDMI_ARB_BASE_ADDR+0x7D30
#define HDMI_CEC_WKUPCTRL           HDMI_ARB_BASE_ADDR+0x7D31

// I2C Master Registers (E-DDC)
#define HDMI_I2CM_SLAVE             HDMI_ARB_BASE_ADDR+0x7E00
#define HDMI_I2CMESS                HDMI_ARB_BASE_ADDR+0x7E01
#define HDMI_I2CM_DATAO             HDMI_ARB_BASE_ADDR+0x7E02
#define HDMI_I2CM_DATAI             HDMI_ARB_BASE_ADDR+0x7E03
#define HDMI_I2CM_OPERATION         HDMI_ARB_BASE_ADDR+0x7E04
#define HDMI_I2CM_INT               HDMI_ARB_BASE_ADDR+0x7E05
#define HDMI_I2CM_CTLINT            HDMI_ARB_BASE_ADDR+0x7E06
#define HDMI_I2CM_DIV               HDMI_ARB_BASE_ADDR+0x7E07
#define HDMI_I2CM_SEGADDR           HDMI_ARB_BASE_ADDR+0x7E08
#define HDMI_I2CM_SOFTRSTZ          HDMI_ARB_BASE_ADDR+0x7E09
#define HDMI_I2CM_SEGPTR            HDMI_ARB_BASE_ADDR+0x7E0A
#define HDMI_I2CM_SS_SCL_HCNT_1_ADDR     HDMI_ARB_BASE_ADDR+0x7E0B
#define HDMI_I2CM_SS_SCL_HCNT_0_ADDR     HDMI_ARB_BASE_ADDR+0x7E0C
#define HDMI_I2CM_SS_SCL_LCNT_1_ADDR     HDMI_ARB_BASE_ADDR+0x7E0D
#define HDMI_I2CM_SS_SCL_LCNT_0_ADDR     HDMI_ARB_BASE_ADDR+0x7E0E
#define HDMI_I2CM_FS_SCL_HCNT_1_ADDR     HDMI_ARB_BASE_ADDR+0x7E0F
#define HDMI_I2CM_FS_SCL_HCNT_0_ADDR     HDMI_ARB_BASE_ADDR+0x7E10
#define HDMI_I2CM_FS_SCL_LCNT_1_ADDR     HDMI_ARB_BASE_ADDR+0x7E11
#define HDMI_I2CM_FS_SCL_LCNT_0_ADDR     HDMI_ARB_BASE_ADDR+0x7E12

// Random Number Generator Registers (RNG)
#define HDMI_RNG_BASE         HDMI_ARB_BASE_ADDR+0x8000

#endif //HDMI_COMMON_H
