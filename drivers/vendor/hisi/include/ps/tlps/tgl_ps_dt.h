

#ifndef __TGL_PS_DT_H__
#define __TGL_PS_DT_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "LPSCommon.h"
#include "Msp_diag_cmd_id.h"
#include "AppTPsInterface.h" 

#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
/* TDS KEY EVENT BASE ID */
#define OM_TPS_KEY_EVENT_BASE_ID         0x10900

#define TDS_DT_COMP_APP_MSG_VOS_HEADER(pDestMsg,MsgLenthNoHeader,ulSendpid,ulOpid,ulMsgid)\
        {\
            (pDestMsg)->ulSenderCpuId   = VOS_LOCAL_CPUID;\
            (pDestMsg)->ulSenderPid     = ulSendpid;\
            (pDestMsg)->ulReceiverCpuId = VOS_LOCAL_CPUID;\
            (pDestMsg)->ulReceiverPid   = PS_PID_APP;\
            (pDestMsg)->ulLength        = (MsgLenthNoHeader);\
            (pDestMsg)->ulOpId          = ulOpid;\
            (pDestMsg)->usOriginalId    = UE_MODULE_PS_OM;\
            (pDestMsg)->usTerminalId    = UE_APP_SUBSYS_ID;\
            (pDestMsg)->ulMsgId         = ulMsgid;\
        }

#define TDS_MAX_RPT_CELL_NUM              (6)
#define TDS_OM_MAX_TS_NUM                 (7)
#define TDS_DT_MAX_RB                     (10) /*tds 实际使用的RB个数,暂时定为10个*/




/*****************************************************************************
  3 枚举定义
*****************************************************************************/
enum DT_RA_MODE_ENUM
{
    DT_RAT_WCDMA                   = 0x00,
    DT_RAT_GSM_GPRS                = 0x01,
    DT_RAT_LTE                     = 0x03,
    DT_RAT_TDSCDMA                 = 0x04,

    DT_RAT_TYPE_BUTT
};
typedef VOS_UINT32  DT_RA_MODE_ENUM_UINT32;

/*****************************************************************************
 结构名    : DT_CMD_ENUM
 结构说明  : DT命令枚举
*****************************************************************************/
enum TDS_DT_CMD_ENUM
{
    TDS_DT_CMD_STOP,        /*停止*/
    TDS_DT_CMD_START,       /*启动*/
    TDS_DT_CMD_BUTT
};
typedef VOS_UINT32 TDS_DT_CMD_ENUM_UINT32;

/*****************************************************************************
 结构名    : DT_RESULT_ENUM
 结构说明  : DT操作结果枚举
*****************************************************************************/
enum TDS_DT_RESULT_ENUM
{
    TDS_DT_RESULT_SUCC = 0,
    TDS_DT_RESULT_FAIL,
    TDS_DT_RESULT_NOT_SUPPORT_MEASURE,
    TDS_DT_RESULT_BUTT
};
typedef VOS_UINT32 TDS_DT_RESULT_ENUM_UINT32;

/*****************************************************************************
 结构名    : OM_TPS_KEY_EVENT_ENUM
 结构说明  : TDS KEY EVENT ID枚举
*****************************************************************************/
enum OM_TPS_KEY_EVENT_ENUM
{
    /*--------------------TRRC key event--------------------*/
    TRRC_OM_EVT_CELL_SEARCH_SUIT = OM_TPS_KEY_EVENT_BASE_ID,
    TRRC_OM_EVT_CELL_SEARCH_ANYCELL,
    TRRC_OM_EVT_SIB_RCV,
    TRRC_OM_EVT_CELL_CAMPED_ON,
    TRRC_OM_EVT_CELL_RESEL,
    TRRC_OM_EVT_RB_SETUP,
    TRRC_OM_EVT_SMC,
    TRRC_OM_EVT_RRC_CONN_REQ,
    TRRC_OM_EVT_RRC_CONN_SETUP,
    TRRC_OM_EVT_RRC_CONN_SETUP_CMPL,
    TRRC_OM_EVT_RRC_CONN_SETUP_FAIL,
    TRRC_OM_EVT_RRC_CONN_RELEASE,
    TRRC_OM_EVT_RRC_CONN_RELEASE_CMPL,
    TRRC_OM_EVT_HANDOVER_START,
    TRRC_OM_EVT_HANDOVER_SUCC,
    TRRC_OM_EVT_RRC_UE_CAP_ENQUIRE,
    TRRC_OM_EVT_T2L_RESEL_STRAT,
    TRRC_OM_EVT_T2L_RESEL_SUCC,
    TRRC_OM_EVT_T2L_RESEL_FAIL,
    TRRC_OM_EVT_T2L_REDIRECTED_STRAT,
    TRRC_OM_EVT_T2L_REDIRECTED_SUCC,
    TRRC_OM_EVT_T2L_REDIRECTED_FAIL,
    TRRC_OM_EVT_T2L_HANDOVER_STRAT,
    TRRC_OM_EVT_T2L_HANDOVER_SUCC,
    TRRC_OM_EVT_T2L_HANDOVER_FAIL,
    TRRC_OM_EVT_T2L_GETUECAPINFO_STRAT,
    TRRC_OM_EVT_T2L_GETUECAPINFO_SUCC,
    TRRC_OM_EVT_T2L_GETUECAPINFO_FAIL,
    TRRC_OM_EVT_T2L_PLMN_SEARCH_STRAT,
    TRRC_OM_EVT_T2L_PLMN_SEARCH_SUCC,
    TRRC_OM_EVT_T2L_PLMN_SEARCH_FAIL,
    TRRC_OM_EVT_L2T_RESEL_START,
    TRRC_OM_EVT_L2T_RESEL_SUCC,
    TRRC_OM_EVT_L2T_RESEL_FAIL,
    TRRC_OM_EVT_L2T_REDIRECTED_START,
    TRRC_OM_EVT_L2T_REDIRECTED_SUCC,
    TRRC_OM_EVT_L2T_REDIRECTED_FAIL,
    TRRC_OM_EVT_L2T_HANDOVER_START,
    TRRC_OM_EVT_L2T_HANDOVER_SUCC,
    TRRC_OM_EVT_L2T_HANDOVER_FAIL,
    TRRC_OM_EVT_L2T_GETUECAPINFO_START,
    TRRC_OM_EVT_L2T_GETUECAPINFO_SUCC,
    TRRC_OM_EVT_L2T_GETUECAPINFO_FAIL,
    TRRC_OM_EVT_G2T_RESEL_STRAT,
    TRRC_OM_EVT_G2T_RESEL_SUCC,
    TRRC_OM_EVT_G2T_RESEL_FAIL,
    TRRC_OM_EVT_G2T_REDIRECTED_STRAT,
    TRRC_OM_EVT_G2T_REDIRECTED_SUCC,
    TRRC_OM_EVT_G2T_REDIRECTED_FAIL,
    TRRC_OM_EVT_G2T_HANDOVER_STRAT,
    TRRC_OM_EVT_G2T_HANDOVER_SUCC,
    TRRC_OM_EVT_G2T_HANDOVER_FAIL,
    TRRC_OM_EVT_G2T_CCO_STRAT,
    TRRC_OM_EVT_G2T_CCO_SUCC,
    TRRC_OM_EVT_G2T_CCO_FAIL,
    TRRC_OM_EVT_T2G_RESEL_START,
    TRRC_OM_EVT_T2G_RESEL_SUCC,
    TRRC_OM_EVT_T2G_RESEL_FAIL,
    TRRC_OM_EVT_T2G_REDIRECTED_START,
    TRRC_OM_EVT_T2G_REDIRECTED_SUCC,
    TRRC_OM_EVT_T2G_REDIRECTED_FAIL,
    TRRC_OM_EVT_T2G_HANDOVER_START,
    TRRC_OM_EVT_T2G_HANDOVER_SUCC,
    TRRC_OM_EVT_T2G_HANDOVER_FAIL,
    TRRC_OM_EVT_T2G_CCO_START,
    TRRC_OM_EVT_T2G_CCO_SUCC,
    TRRC_OM_EVT_T2G_CCO_FAIL,
    TRRC_OM_EVT_CELL_SEARCH_SPEC_PLMN,
    TRRC_OM_EVT_CELL_SEARCH_PLMN_LIST,
    TRRC_OM_EVT_ID_BUTT /* MAX-TDS-KEY-EVENT-RANGE */
};

typedef VOS_UINT32 OM_TPS_KEY_EVENT_ENUM_UINT32;

/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/
/*****************************************************************************
 结构名    : TDS_DT_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : TDS路测请求消息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                             /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;               /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
    TDS_DT_CMD_ENUM_UINT32              enCmd;
    VOS_UINT32                          ulRptPeriod;
}TDS_DT_REQ_STRU;

/*****************************************************************************
 结构名    : TDS_DT_CNF_COMM_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : TDS路测确认消息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                               /*_H2ASN_Skip*/
    VOS_UINT32                             ulMsgId;              /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                             ulOpId;
    TDS_DT_RESULT_ENUM_UINT32              enResult;
} TDS_DT_CNF_COMM_STRU;


/*****************************************************************************
 结构名    : TRRC_DT_SERVING_BASIC_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 服务区基本信息查询消息
*****************************************************************************/
typedef struct
{
    DT_RA_MODE_ENUM_UINT32              enRat;
    VOS_UINT32                          ulCellid;
    VOS_UINT8                           auccellIdentity[4];

    VOS_UINT16                          usFrenquency;
    VOS_UINT16                          usUarfcn;

    VOS_UINT8                           aucPlmnId[3];
    VOS_UINT8                           ucRsv;
    VOS_UINT16                          uslac;/*BIT STRING (SIZE (16))
 */
    VOS_UINT8                           ucrac;
    VOS_UINT8                           ucRsv2;

    VOS_UINT8                           aucSrncIdentiy[2];
    VOS_UINT8                           aucRsv[2];
    VOS_INT32                           lMaxPowerAllowed;

    VOS_UINT8                           ucCurrentMainState;
    VOS_UINT8                           ucLastMainState;

    VOS_UINT8                           ucCurrentSubState;
    VOS_UINT8                           ucLastSubState;

    VOS_UINT32                          ulT3212;
} TRRC_DT_SERVING_BASIC_INFO_STRU;


/*****************************************************************************
 结构名    : TRRC_DT_SERVING_BASIC_INFO_QUERY_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 服务区基本信息查询消息
*****************************************************************************/
typedef TDS_DT_REQ_STRU TRRC_DT_SERVING_BASIC_INFO_REQ_STRU;


/*****************************************************************************
 结构名    : TRRC_DT_SERVING_BASIC_INFO_QUERY_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 服务区基本信息查询确认消息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                           /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;           /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                             ulOpId;
    TDS_DT_RESULT_ENUM_UINT32              enResult;
    TRRC_DT_SERVING_BASIC_INFO_STRU        stServingBasicInfo;
} TRRC_DT_SERVING_BASIC_INFO_CNF_STRU;

/*****************************************************************************
 结构名    : TRRC_DT_SERVING_BASIC_INFO_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 服务区基本信息主动上报消息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                         /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;         /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    TRRC_DT_SERVING_BASIC_INFO_STRU       stServingBasicInfo;
} TRRC_DT_SERVING_BASIC_INFO_IND_STRU;

/*****************************************************************************
 结构名    : TRRC_DT_THROUGHPUT_INFO_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 吞吐量请求消息
*****************************************************************************/
typedef TDS_DT_REQ_STRU TRRC_DT_THROUGHPUT_INFO_REQ_STRU;

/*****************************************************************************
 结构名    : TRRC_DT_THROUGHPUT_INFO_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 吞吐量确认消息
*****************************************************************************/
typedef TDS_DT_CNF_COMM_STRU TRRC_DT_THROUGHPUT_INFO_CNF_STRU;

/*****************************************************************************
 结构名    : TDS_L2_DT_TRACE_PKT_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : TDS L2抓包请求消息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                         /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;         /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    VOS_UINT32                            ulPdcpPktFlg;
    VOS_UINT32                            ulRlcPktFlg;
    VOS_UINT32                            ulMacPktFlg;
} TDS_L2_DT_TRACE_PKT_REQ_STRU;

/*****************************************************************************
 结构名    : TDS_L2_DT_TRACE_PKT_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : TDS L2抓包确认消息
*****************************************************************************/
typedef TDS_DT_CNF_COMM_STRU TDS_L2_DT_TRACE_PKT_CNF_STRU;

/*****************************************************************************
 结构名    : TRRC_DT_SERVING_BASIC_INFO_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 服务区基本信息主动上报消息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                             /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;             /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    VOS_UINT32                            ulRlcUlThp;
    VOS_UINT32                            ulRlcDlThp;
    VOS_UINT32                            ulPdcpUlThp;
    VOS_UINT32                            ulPdcpDlThp;
    VOS_UINT32                            ulAppUlThp;
    VOS_UINT32                            ulAppDlThp;
    VOS_UINT32                            ulHsdschThp;
} TRRC_DT_THROUGHPUT_INFO_IND_STRU;

/*****************************************************************************
 结构名    : TL2_DT_RLC_RB_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                             ucRlcRbId;
    VOS_UINT8                             ucRbUlMode;                 /*0:AM,1:UM,2:TM*/
    VOS_UINT8                             ucRbDlMode;                 /*0:AM,1:UM,2:TM*/
    VOS_UINT8                             ucRbState;
    VOS_UINT32                            ulRlcBo;                    /*RLC当前缓存BO值*/
    VOS_UINT32                            ulRlcAverageBo;             /*RLC平均缓存BO值*/
    VOS_UINT32                            ulRlcUlReTxRatio;
    VOS_UINT32                            ulRlcDlRxErrRatio;
    VOS_INT32                             lRlcVarianceBo;             /*RLC缓存BO值的变化*/
}TL2_DT_RLC_RB_INFO_STRU;

/*****************************************************************************
 结构名    : TDS_MAC_RB_MAPPING_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :
*****************************************************************************/
typedef struct
{
    u8                                    loChNumUl;
    u8                                    loChNumDl;
    u8                                    ucResv[2];
}TDS_MAC_RB_MAPPING_INFO_STRU;

/*****************************************************************************
 结构名    : TDS_MAC_RB_INFORMATION_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :
*****************************************************************************/
typedef struct
{
    u8                                    rbIdentity;
    u8                                    rbMuxNum;
    u8                                    ucResv[2];
    TDS_MAC_RB_MAPPING_INFO_STRU          rbMappingInfo[maxRBMuxOptions];
}TDS_MAC_RB_INFORMATION_STRU;

/*****************************************************************************
 结构名    : TDS_MAC_RB_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :
*****************************************************************************/
typedef struct
{
    u8                                    ucRbNum;
    u8                                    ucResv[3];
    TDS_MAC_RB_INFORMATION_STRU           stRbInfo[maxRB];
}TDS_MAC_RB_INFO_STRU;

/*****************************************************************************
 结构名    : TL2_DT_RB_INFO_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                             /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;             /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    VOS_UINT32                            ulLchNum;
    VOS_UINT32                            ulRbNum;
    TL2_DT_RLC_RB_INFO_STRU               astRbInfo[10];
    TDS_MAC_RB_INFO_STRU                  stMacRbInfo;
} TL2_DT_RB_INFO_IND_STRU;

/*****************************************************************************
 结构名    : TL2_DT_HSDPA_MAC_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                             ucQueId;
    VOS_UINT8                             ucResv;
    VOS_UINT16                            usPduSize;
    VOS_UINT16                            usSubSfn;
    VOS_UINT16                            usTsn;
} TL2_DT_HSDPA_MAC_INFO_STRU;

/*****************************************************************************
 结构名    : TL2_DT_HSDPA_MAC_STATICS_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :
*****************************************************************************/
typedef struct
{
    VOS_UINT32                            ulRbId;
    VOS_UINT32                            ulRecvCnt;
    VOS_UINT32                            ulErrorCnt;
    VOS_UINT32                            ulHISICHCnt;
    VOS_UINT32                            ulPduRecvRate;       /*bps*/
    VOS_UINT32                            ulPduAvgSize;        /*byte*/
} TL2_DT_HSDPA_MAC_STATICS_STRU;

/*****************************************************************************
 结构名    : TL2_DT_HSDPA_INFO_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                             /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;             /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    TL2_DT_HSDPA_MAC_INFO_STRU            stHsdpaMacInfo[80];
    TL2_DT_HSDPA_MAC_STATICS_STRU         stHsdpaStaticsInfo;
} TL2_DT_HSDPA_INFO_IND_STRU;

/*****************************************************************************
 结构名    : TRRC_DT_THROUGHPUT_INFO_IND_SG
 协议表格  :
 ASN.1描述 :
 结构说明  : 服务区基本信息主动上报消息
*****************************************************************************/
typedef struct
{
    VOS_UINT32                            ulRlcUlThp;
    VOS_UINT32                            ulRlcDlThp;
    VOS_UINT32                            ulPdcpUlThp;
    VOS_UINT32                            ulPdcpDlThp;
    VOS_UINT32                            ulAppUlThp;
    VOS_UINT32                            ulAppDlThp;
    VOS_UINT32                            ulMacUlThp;
    VOS_UINT32                            ulMacDlThp;
    VOS_UINT32                            ulUpaHichTotal;
    VOS_UINT32                            ulUpaHichNack;
} TRRC_DT_THROUGHPUT_INFO_IND_SG_STRU;


/*****************************************************************************
 结构名    : TDS_OM_MAC_MEAS_ITEM_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 服务区基本信息主动上报消息
*****************************************************************************/
typedef struct
{
    VOS_UINT8        ucSyncId;
    VOS_UINT8        ucMidamble;
    VOS_UINT16      usCellId;
    VOS_UINT16      usFreq;
    VOS_INT16        sRscp;
    VOS_INT16        sRssi;
    VOS_INT16        asIscp[TDS_OM_MAX_TS_NUM];
} TDS_OM_MAC_MEAS_ITEM_STRU;


/*****************************************************************************
 结构名    : TDS_OM_MAC_MEAS_ITEM_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 服务区基本信息主动上报消息
*****************************************************************************/
typedef struct
{
    VOS_UINT32                    ulProState;
    VOS_UINT32                    ulCellNum;
    VOS_UINT32                    ulIfCampOnPrima;  /*是否驻留在辅载频*/
    VOS_UINT16                    usSecondFreq;       /*辅载频频点*/
    VOS_INT16                      sSecondFreqRssi;   /*辅载频RSSI*/
    TDS_OM_MAC_MEAS_ITEM_STRU     astCellInfo[TDS_MAX_RPT_CELL_NUM];
} TDS_OM_MAC_MEAS_IND_STRU;



typedef struct
{
    APP_TPS_MSG_ID_ENUM_UINT32         enMsgId;            /*_H2ASN_MsgChoice_Export APP_TPS_MSG_ID_ENUM_UINT32*/
    VOS_UINT8                          aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          APP_TPS_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}APP_TPS_DT_INTERFACE_MSG_DATA;
/*_H2ASN_Length UINT32*/


typedef struct
{
    VOS_MSG_HEADER
    APP_TPS_DT_INTERFACE_MSG_DATA      stMsgData;
} AppTPsDtInterface_MSG;


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/








#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of tgl_ps_dt.h */

