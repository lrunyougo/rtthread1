/*
 * File Name:cmd_parser.c
 * Descriptions: uart and usb command parser /ARM/IAR/GCC compiler
 * Change Logs:
 * Date             Author       Notes
 * 2020-11-23       Eric      first implementation
*/

/*----------------------------------------------------------------------------*
**                             Dependencies                                   *
**----------------------------------------------------------------------------*/
/* <Header file of standard Library> */
#include <stdio.h>
#include <rtthread.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*----------------------------------------------------------------------------*/
/* "Header file of nonstandard Library" */
#include "cmd_parser.h"
#include "strref.h"
#include "util.h"
#include "app.h"
#include "board_config.h"

/**---------------------------------------------------------------------------*
 **                            Debugging Flag                                 *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
**                             Compiler Flag                                  *
**----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
 **                            Debugging Flag                                 *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
**                             Compiler Flag                                  *
**----------------------------------------------------------------------------*/
#ifdef __cplusplus
extern   "C"
{
#endif

/*----------------------------------------------------------------------------*
**                             Mcaro Definitions                              *
**----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*
**                             Data Structures                                *
**----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef struct
{
	const char* Cmd_Titel_Head;
	const char* Cmd_Titel_Content_First;
	const char* Cmd_Titel_Content_Cecond;
	const char* Cmd_Titel_Content_Third;
	const char* Cmd_Titel_Tail;
}Cmd_Titel;

static Cmd_Titel cmd_titel[]   =
{
"\r\n/*---------------------------------------------------*/",
"$ Cmd_list:",
"Ignore Upper Lower\r\n",
	NULL,
"/*---------------------------------------------------*/\r\n",
};

static Cmd_Titel cmd_content[] = 
{
	NULL, 
"Error! Please use cmd_list to check cmd menue and retry !",
"is sending to vcom device !",
	NULL,
	NULL,
	NULL,
};
/*----------------------------------------------------------------------------*
**                             Local Vars                                     *
**----------------------------------------------------------------------------*/
static cmd_t *_cmd_begin, *_cmd_end;
/* communication mode */
static CmdPacketBuf_T s_tCmdPacketBuf = {CMD_PACKET_EMPTY};

/*----------------------------------------------------------------------------*
**                             Extern Function                                *
**----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*
**                             Local Function                                 *
**----------------------------------------------------------------------------*/
static void _CMD_Response(const char* pcszFmt, ...);
static void _CMD_HandlerVER(const StrConstRef_T* pctStrRefParam);
static void _CMD_ClearPacketBuf(void);
static void CMD_ClearPacketBuf(void);
static int _cmd_to_lower(int c);
static unsigned int _cmd_hash(const char* str);
static void _cmd_init(const void *begin, const void *end);
static cmd_t* _get_next_cmd(cmd_t *cmd);
static int _cmd_match(const char *str, const char *cmd);
/*
* Function: _list()
* Descriptions: This function will list all command
* Author: Eric
* Returns:
* Parameter:
* History:
*/
static void _list(void)
{
//	cmd_titel.Cmd_Titel_Head           =  "\r\n/*---------------------------------------------------*/";
//	cmd_titel.Cmd_Titel_Content_First  =  "$ Cmd_list:";
//	cmd_titel.Cmd_Titel_Content_Cecond =  "Ignore Upper Lower\r\n";
//	cmd_titel.Cmd_Titel_Tail           =  "/*---------------------------------------------------*/\r\n";	
	_CMD_Response("%s",cmd_titel->Cmd_Titel_Head);
  	_CMD_Response("%-28s   %-s",cmd_titel->Cmd_Titel_Content_First,cmd_titel->Cmd_Titel_Content_Cecond);

	rt_kprintf("%s\r\n",cmd_titel->Cmd_Titel_Head);
  	rt_kprintf("%-28s   %-s\r\n",cmd_titel->Cmd_Titel_Content_First,cmd_titel->Cmd_Titel_Content_Cecond);
	
    cmd_t *index;
    for (index = _cmd_begin; index < _cmd_end; index = _get_next_cmd(index)) {
    rt_kprintf("$ %-28s %-s\r\n",index->cmd ,index->desc);
	_CMD_Response("$ %-28s %-s",index->cmd ,index->desc);
			
    }
	rt_kprintf("%s\r\n",cmd_titel->Cmd_Titel_Tail);
	_CMD_Response("%s",cmd_titel->Cmd_Titel_Tail);
}
REGISTER_CMD(cmd_list, _list,list all command);

/*
* Function: _CMD_Response()
* Descriptions: This function Will parser cmd to data and lenth
* Author: Eric
* Returns:
* Parameter:
* History:
*/
static void _CMD_Response(const char* pcszFmt, ...)
{
	
	char szCmdRspBuf[CMD_PACKET_MAX_LEN] = "";
	int iCmdRspLen = 0;
	va_list ap;
	va_start(ap, pcszFmt);
	iCmdRspLen = rt_vsnprintf(szCmdRspBuf, sizeof(szCmdRspBuf), pcszFmt, ap);
	va_end(ap);
	if ((iCmdRspLen > 0) && (iCmdRspLen <= (sizeof(szCmdRspBuf) - 2)))
	{
		szCmdRspBuf[iCmdRspLen++] = '\r';
		szCmdRspBuf[iCmdRspLen++] = '\n';
		/* ues the set channel send data */
		com_send_data((const uint8_t*)szCmdRspBuf, (uint32_t)iCmdRspLen);
	}
}

/*
* Function: _CMD_HandlerVER()
* Descriptions: This function is a cmd of VER
* Author: Eric
* Returns:
* Parameter:
* History:
*/
static void _CMD_HandlerVER(const StrConstRef_T* pctStrRefParam)
{
	_CMD_Response("[VER]=%s  [BUILD]=%s", VERSION, BUILD);
}
REGISTER_CMD(VER, _CMD_HandlerVER,show the version);


/*
* Function: _CMD_ClearPacketBuf
* Description: This function Will clea Packet Buffer
* Author: Eric
* Returns:
* Parameter:
* History:
*/
static void _CMD_ClearPacketBuf(void)
{
	//memset(&s_tCmdPacketBuf, 0, sizeof(s_tCmdPacketBuf));
	s_tCmdPacketBuf.ePacketStatus = CMD_PACKET_EMPTY;
	s_tCmdPacketBuf.u32PacketLen = 0;
}

/*************************************************
* Function: CMD_ClearPacketBuf
* Description: This function is CMD_ClearPacketBuf handler 
* Author: wangk
* Returns:
* Parameter:
* History:
*************************************************/
static void CMD_ClearPacketBuf(void)
{
	_CMD_ClearPacketBuf();
}

/*
* Function: _cmd_to_lower()
* Descriptions: This function will turn upper to lower
* Author: Eric
* Returns:
* Parameter:
* History:
*/
static int _cmd_to_lower(int c)
{
    if ((c >= 'A') && (c <= 'Z'))
        return c + ('a' - 'A');
    return c;
}

/*
* Function: _cmd_hash()
* Descriptions: This function will calculate cmd hash
* Author: Eric
* Returns:
* Parameter:
* History:
*/
static unsigned int _cmd_hash(const char* str)
{
    int tmp, c = *str;
    unsigned int seed = CMD_HASH;  //my hash
    unsigned int hash = 0;
    
    while(*str) {
        tmp = _cmd_to_lower(c);
        hash = (hash ^ seed) + tmp;
        str++;
        c = *str;
    }
    return hash;
}

/*
* Function: _cmd_init()
* Descriptions: This function is _cmd_init handler
* Author: Eric
* Returns:
* Parameter:
* History:
*/
static void _cmd_init(const void *begin, const void *end)
{
    _cmd_begin = (cmd_t*) begin;
    _cmd_end = (cmd_t*) end;
}

/*
* Function: _get_next_cmd()
* Descriptions: This function is pointer to next cmd
* Author: Eric
* Returns:
* Parameter:
* History:
*/
static cmd_t* _get_next_cmd(cmd_t *cmd)
{
    unsigned int *ptr;
    ptr = (unsigned int*) (cmd + 1);
    while ((*ptr == 0) && ((unsigned int*)ptr < (unsigned int*) _cmd_end))
        ptr ++;
    return (cmd_t*) ptr;
}
/*
* Function: _cmd_match()
* Descriptions: This function will match the cmd
* Author: Eric
* Returns:
* Parameter:
* History:
*/
static int _cmd_match(const char *str, const char *cmd)
{
    int c1, c2;
    do {
        c1 = _cmd_to_lower(*str++);
        c2 = _cmd_to_lower(*cmd++);
    } while((c1 == c2) && c1);

    return c1 - c2;
}
/*----------------------------------------------------------------------------*
**                             Public Function                                *
**----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*
**                             Function Define                                *
**----------------------------------------------------------------------------*/

/*
* Function: cmd_init()
* Descriptions: This function will initialize cmd parser
* Author: Eric
* Returns:
* Parameter:
* History:
*/
void cmd_init(void)
{
    cmd_t *index;

#if defined(__CC_ARM) || defined(__CLANG_ARM)          /* ARM C Compiler */
    extern const int CMDS$$Base;
    extern const int CMDS$$Limit;
    _cmd_init(&CMDS$$Base, &CMDS$$Limit);
#elif defined (__ICCARM__) || defined(__ICCRX__)      /* for IAR Compiler */
    _cmd_init(__section_begin("CMDS"), __section_end("CMDS"));
#elif defined (__GNUC__) || defined(__TI_COMPILER_VERSION__)
    /* GNU GCC Compiler and TI CCS */
    extern const int __cmds_start;
    extern const int __cmds_end;
    _cmd_init(&__cmds_start, &__cmds_end);
//#elif defined(__ADSPBLACKFIN__) /* for VisualDSP++ Compiler */
//    _cmd_init(&__cmds_start, &__cmds_end);
//#elif defined(_MSC_VER)
//    unsigned int *ptr_begin, *ptr_end;
//    rt_kprintf("No compiler, please check it!\n");
#endif

    for (index = _cmd_begin; index < _cmd_end; index = _get_next_cmd(index)) {
        index->hash = _cmd_hash(index->cmd);
    }
}

/*
* Function: cmd_parsing()
* Descriptions: This function will parser cmd
* Author: Eric
* Returns:
* Parameter:
* History:
*/
void cmd_parsing(char *str)
{
    cmd_t *index;
		rt_uint8_t error_conut=0;
    unsigned int hash = _cmd_hash(str);   
    for (index = _cmd_begin; index < _cmd_end; index = _get_next_cmd(index)) {
        if (hash == index->hash) {
            if (_cmd_match(str, index->cmd) == 0) {
								rt_kprintf("$ %s %s\r\n",index->cmd ,cmd_content->Cmd_Titel_Content_Cecond); //"is sending to vcom device !"
                index->handler();
								error_conut = 0;							
                break;
            }
        }
				else
				{
					error_conut+= 1;
				}
    }		
		if(error_conut != 0)
		{
			rt_kprintf("%s\r\n",cmd_content->Cmd_Titel_Content_First);//"Error! Please use cmd_list to check cmd menue and retry !"
			_CMD_Response("%s",cmd_content->Cmd_Titel_Content_First); //"Error! Please use cmd_list to check cmd menue and retry !"
			
		}		
}

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef   __cplusplus
}
#endif
// End of xxx
