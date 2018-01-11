// FeedChannelDevStruct.h
//
//////////////////////////////////////////////////////////////////////////

#ifndef _FEEDCHANNELDEVSTRUCT_H_
#define _FEEDCHANNELDEVSTRUCT_H_

#define GNBFLK_IGNORE			0  // 忽略
#define GNBFLK_RESEND			1  // 重发
#define GNBFLK_INIT				2  // 初始化
#define GNBFLK_STOP				3  // 停止

#define GNBFLK_NORMAL			0  // 正常0
#define GNBFLK_WARNNING			1  // 警告
#define GNBFLK_ERROR			2  // 错误

#define POS_BACK				"BackPaper"	// 退出纸
#define POS_PUSH				"PushPaper"	// 吸入纸
#define POS_STOP				"InitPaper"	// 初始位置

//设备状态
typedef struct  
{
	unsigned char ucPaperPos;		//纸张位置
	//0x00：无纸张在模块中
	//0x01：纸张处于入口处，但右倾斜
	//0x02：纸张处于入口处，但左倾斜
	//0x03：纸张处于模块中间位置
	//0x04：纸张处于出口处
	//0x05：纸张处于入口处可以进纸状态
	//0xFF：检测到纸张处于异常位置
	
	unsigned char ucRecycleBin;		//回收箱 
	//0x00 ---未满 ；其它为满
	unsigned char aucRsv[14];		//保留
	
}tFEED_CHANNEL_MODULE_STATUS;

//硬件版本信息
typedef struct  
{
	char acHwVer[16];				// 版本信息
	char acHwType[16];				// 类型
	char acRsv[16];					// 保留字
	
}tFEED_CHANNEL_DEV_VER;

// 键值名
typedef struct 
{
	char acKeyValue[256];			// 键值名
	
}tFEED_CHANNEL_KEY_VALUE;

// 下载
typedef struct 
{
	char acFileName[MAX_PATH];		// 当前下载文件名
	int  iTotalSize;				// 文件大小
	int  iCurPos;					// 当前下载位置
}tFEED_CHANNEL_PDL_PROGRESS;

#endif	// _FEEDCHANNELDEVSTRUC