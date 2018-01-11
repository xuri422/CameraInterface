// CameraInterface.h : main header file for the CameraInterface DLL
//
/*

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "stdafx.h"
  */
#include "resource.h"		// main symbols
#include "mINIT.h"
#include "DialogEX.h"

// mINIT strInit;
// FeedChannelDevDll.h
//
//////////////////////////////////////////////////////////////////////////

//		typedef void (*VideoEvent)(int para);	
//		void _Dialog(int strinit);
//  		int strTemp,m_VideoStateFun;
 
//#ifndef __FEEDCHANNELDEVDLL_H__
//#define __FEEDCHANNELDEVDLL_H__
// #endif	// __FEEDCHANNELDEVDLL_H__
		typedef void (*VideoEvent)(int para);
		void _Dialog(int strinit);
		void  Recordlog(CString cmd);
//     	DWORD WINAPI InitDevice(DWORD deviceID);
//		BOOL WINAPI CloseDevice( DWORD DeviceHandle);
//		BOOL WINAPI getFormat(DWORD DeviceHandle, INT index, long* width, long* height);
//		BOOL WINAPI setCaptureSizeByIndex(DWORD DeviceHandle, INT index);
// 		BOOL WINAPI setPreviewWindow(DWORD DeviceHandle, HWND previewHwnd);
//		BOOL WINAPI startPreview(DWORD DeviceHandle);
//		BOOL WINAPI stopPreview(DWORD DeviceHandle);
//		BOOL WINAPI captureBitmap(DWORD DeviceHandle, BYTE* strFileName );
//		BYTE* WINAPI getLastErrorMessage();
//		BOOL WINAPI setAutoCrop(DWORD DeviceHandle, BOOL enabled);
//		BOOL WINAPI setCameraProperty(DWORD DeviceHandle);
//		BOOL WINAPI startAutoCapture(DWORD DeviceHandle, INT captureCount, INT captureInterval,BYTE* strFolder);
//		BOOL WINAPI stopAutoCapture(DWORD DeviceHandle);
//		BOOL WINAPI setRotateMode(DWORD DeviceHandle,INT mode);
//		BOOL WINAPI setColorType(DWORD DeviceHandle,INT type);
//		BOOL WINAPI setPictureQuality(DWORD DeviceHandle, INT qualityRatio);
//		BOOL WINAPI GetReslutionCount();
//		BOOL WINAPI SetScanSize();
// 		BOOL WINAPI SetScanSizeCustom();

enum ScanSize 
{ 
	eScanSize_ALL = 0, // 所有
	eScanSize_A3 = 1, // A4
	eScanSize_A4 = 2, // A4
	eScanSize_A5 = 3, // A5
	eScanSize_A6 = 4, // A6
	eScanSize_A7 = 5, // A7
	eScanSize_CALLINGCARD = 6, // 名片
	eScanSize_ID = 7, // 身份证
};


#ifdef __cplusplus
extern "C" {
#endif
		
		
	  __declspec(dllexport) CString  getDllVersion(DWORD DeviceHandle);
	  __declspec(dllexport) CString  getFirmWareVersion(DWORD DeviceHandle);
	  __declspec(dllexport) void  SetVideoCallBack(VideoEvent _event);
	  __declspec(dllexport) bool  GetVideoParameter(DWORD DeviceHandle,int para1,int para2,long & min,long & max,long &lvalue,long &ldefault,long &flag);
  	  __declspec(dllexport) int  getVideoState(DWORD DeviceHandle);
	  __declspec(dllexport) bool  SetVideoParameter(DWORD DeviceHandle,int para1,int para2,long lvalue,long flag);
       __declspec(dllexport) int SetScanSize(DWORD DeviceHandle,ScanSize p_eScanSize);
        __declspec(dllexport) int SetScanSizeCustom(DWORD DeviceHandle,CRect p_oArea);
		int strTemp,m_VideoStateFun=0,strSetPreviewSign,strStartAutoCaptureSign;
#ifdef __cplusplus
}
#endif	// __cplusplus
 

/*
typedef void (*VideoEvent)(int para); 
		void _Dialog(int strinit);

typedef DWORD (* __stdcall lpInitDevice)(DWORD); 
typedef BOOL (* __stdcall lpCloseDevice)(DWORD); 
typedef int (* __stdcall lpGetReslutionCount)(DWORD); 
typedef BOOL (* __stdcall lpgetFormat)(DWORD,int,long*,long*); 
typedef BOOL (* __stdcall lpsetCaptureSizeByIndex)(DWORD,int); 
typedef BOOL (* __stdcall lpsetPreviewWindow)(DWORD,HWND); 
typedef BOOL (* __stdcall lpstartPreview)(DWORD); 
typedef BOOL (* __stdcall lpisPreview)(DWORD); 
typedef BOOL (* __stdcall lpstopPreview)(DWORD); 
typedef BOOL (* __stdcall lpcaptureBitmap)(DWORD,BYTE*); 
typedef BYTE * (* __stdcall lpgetLastErrorMessage)(); 
typedef BOOL (* __stdcall lpsetAutoCrop)(DWORD,BOOL); 
typedef BOOL (* __stdcall lpsetCameraProperty)(DWORD); 
typedef BOOL (* __stdcall lpstartAutoCapture)(DWORD,int,int,BYTE*); 
typedef BOOL (* __stdcall lpstopAutoCapture)(DWORD); 
typedef BOOL (* __stdcall lpsetRotateMode)(DWORD,int); 
typedef BOOL (* __stdcall lpsetColorType)(DWORD,int); 
typedef BOOL (* __stdcall lpsetPictureQuality)(DWORD,int); 
typedef int (* __stdcall lpgetVideoState)(DWORD); 
//added by zzhen 20140908 新增接口 
typedef CString (* __stdcall lpgetDllVersion)(DWORD); 
typedef CString (* __stdcall lpgetFirmWareVersion)(DWORD); 
typedef  bool  (* __stdcall lpGetVideoParameter)(DWORD DeviceHandle,int para1,int para2,long & min,long & max, 
                                     long &lvalue,long &ldefault,long &flag); 
typedef  bool  (* __stdcall lpSetVideoParameter)(DWORD DeviceHandle,int para1,int para2,long lvalue,long flag); 
typedef void (* __stdcall lpSetVideoCallBack)(VideoEvent); 
typedef int (* __stdcall lpSetScanSizeCustom)(DWORD DeviceHandle,CRect p_oArea); 
typedef int (* __stdcall lpSetScanSize)(DWORD DeviceHandle,enum ScanSize p_eScanSize); 
//end added
*/


 
#define STDCALL
class basevirtualclass
{
public:

/**********************************************************
 ********************** 端口类API *************************
**********************************************************/
virtual DWORD STDCALL InitDevice(DWORD deviceID);
virtual BOOL  STDCALL CloseDevice( DWORD DeviceHandle);
virtual int  STDCALL getVideoState(DWORD DeviceHandle);
virtual	BOOL STDCALL getFormat(DWORD DeviceHandle, INT index, long* width, long* height);
virtual	BOOL STDCALL setCaptureSizeByIndex(DWORD DeviceHandle, INT index);
virtual	BOOL STDCALL setPreviewWindow(DWORD DeviceHandle, HWND previewHwnd);
virtual BOOL STDCALL startPreview(DWORD DeviceHandle);

virtual		BOOL STDCALL stopPreview(DWORD DeviceHandle);
virtual		BOOL STDCALL captureBitmap(DWORD DeviceHandle, BYTE* strFileName );
virtual		BYTE* STDCALL getLastErrorMessage();
virtual		BOOL STDCALL setAutoCrop(DWORD DeviceHandle, BOOL enabled);
virtual		BOOL STDCALL setCameraProperty(DWORD DeviceHandle);
virtual		BOOL STDCALL startAutoCapture(DWORD DeviceHandle, INT captureCount, INT captureInterval,BYTE* strFolder);
virtual		BOOL STDCALL stopAutoCapture(DWORD DeviceHandle);
virtual		BOOL STDCALL setRotateMode(DWORD DeviceHandle,INT mode);
virtual		BOOL STDCALL setColorType(DWORD DeviceHandle,INT type);
virtual		BOOL STDCALL setPictureQuality(DWORD DeviceHandle, INT qualityRatio);
virtual		BOOL STDCALL GetReslutionCount();
virtual		int STDCALL SetScanSize(DWORD DeviceHandle,enum ScanSize p_eScanSize); 

virtual		int STDCALL SetScanSizeCustom(DWORD DeviceHandle,CRect p_oArea); 
};
 

