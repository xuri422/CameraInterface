// CameraInterface.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "CameraInterface.h"


HANDLE hd;
char logicname[128];

VideoEvent handler=NULL;

DWORD WINAPI testThread(void *)
{
	Sleep(1000);
	MessageBox(NULL,"@@@@@@@@@",NULL,MB_OK);
	handler(32768);
return 0;
}

void  Recordlog(CString cmd)
{
	char lpcTempBuffer[256];
	memset(lpcTempBuffer, 0, sizeof(lpcTempBuffer));
	int liBufferLen = sizeof(lpcTempBuffer);
	memset( lpcTempBuffer, 0, sizeof(lpcTempBuffer) );
	liBufferLen = sizeof(lpcTempBuffer);
	CString m_strSpVersion;
	CString  sIniFile ,strstmp;	
 	HKEY lhkey;  

    LONG lret = RegOpenKeyEx( HKEY_LOCAL_MACHINE,  "SOFTWARE\\GrgBanking\\SPTrueBack\\CameraInterface", 0, KEY_ALL_ACCESS, &lhkey );
	if ( ERROR_SUCCESS == lret ) {
		DWORD dwSize = liBufferLen;
		long lReturn = RegQueryValueEx( lhkey, "path", NULL, NULL, (BYTE*)lpcTempBuffer, &dwSize );
		if ( lReturn == ERROR_SUCCESS )
		{
		sIniFile  =   lpcTempBuffer  ;
		}
	}

    GetPrivateProfileString(  "GrgVirDev_CameraInterface_Menu" ,"WriteLog",NULL,strstmp.GetBuffer(MAX_PATH),MAX_PATH,sIniFile);          // read an integer from the specified config file 

	if (strstmp=="1")
	{

	CFile destfile; 
	CTime t = CTime::GetCurrentTime();
    CString strTime = t.Format("%Y%m%d%H%M%S");
	CString strDate="D:\\GrgBanking\\TrueBack\\VirDevLog\\CameraInterface"+t.Format("%Y%m%d")+".txt";
	destfile.Open(strDate, CFile::modeNoTruncate |CFile::modeCreate| CFile::modeWrite | CFile::typeBinary);

	//destfile.Open("aa.txt",CFile::modeWrite|CFile::typeBinary);
	destfile.SeekToEnd();
	//destfile.WriteString(cmd);
	destfile.Write(strTime,strlen(strTime)); 
	destfile.Write(":  ",3); 
	destfile.Write(cmd,strlen(cmd)); 
	destfile.Write("\r\n",2);
	destfile.Close(); 
		}
}
 
DWORD STDCALL InitDevice(DWORD deviceID)
{   
	Recordlog("Enter InitDevice");
//	MessageBox(NULL,"1",NULL,MB_OK);
     mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="1",tem;
 	strinit.OnBtnRead(m_cmd);
	
//	CloseHandle(CreateThread(NULL,0, testThread, NULL,0,NULL));
 //		return 23954201;

	if(strinit.m_resulf=="0")
	{
		Recordlog("InitDevice Suss");
		m_VideoStateFun=1;
		if (deviceID==1)
			return 23954200;
		else
			return 23954201;
		

	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
			Recordlog("InitDevice Suss");
		if (strTemp==1)
		{
		m_VideoStateFun=1;
 		if (deviceID==1)
			return 23954200;
		else
			return 23954201;
		
		}
		else
		{
			Recordlog("InitDevice Fail");
			return -1;
		

		}
	}
	else
	{
		Recordlog("InitDevice Fail");
			return -1;
			
	}
	
	
}



BOOL STDCALL GetReslutionCount()
{
		Recordlog("Enter GetReslutionCount");

//		MessageBox(NULL,"2",NULL,MB_OK);
	return 0;
}
	
int STDCALL SetScanSize(DWORD DeviceHandle,enum ScanSize p_eScanSize)
{
//		MessageBox(NULL,"3",NULL,MB_OK);
			Recordlog("Enter SetScanSize");

	return 1;
}
	
int STDCALL SetScanSizeCustom(DWORD DeviceHandle,CRect p_oArea)
{
	Recordlog("Enter SetScanSizeCustom");

//		MessageBox(NULL,"4",NULL,MB_OK);
	return 1;
}
	

BOOL STDCALL CloseDevice( DWORD DeviceHandle)
{
	Recordlog("Enter CloseDevice");
	    mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="2",tem;
 	strinit.OnBtnRead(m_cmd);
 
	if(strinit.m_resulf=="0")
	{
				Recordlog("CloseDevice Suss");
		m_VideoStateFun=0;
			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
				Recordlog("CloseDevice Suss");

			m_VideoStateFun=0;
				return TRUE;
		}
		else
		{
				Recordlog("CloseDevice Fail");

			return FALSE;
		}
	}
	else
	{
				Recordlog("CloseDevice Fail");

			return FALSE;
	}
}

BOOL STDCALL getFormat(DWORD DeviceHandle, INT index, long* width, long* height)
{
					Recordlog("Enter getFormat");

//		MessageBox(NULL,"6",NULL,MB_OK);
 mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="3",tem;
			long strint1w=2592,strint1h=1944,strint2w=640,strint2h=480,strint3w=1024,strint3h=768,strint4w=1280,strint4h=720,strint5w=1920,strint5h=1080;
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
		if(index==0)
		{
			Recordlog("getFormat Suss");
		 *width  = strint1w;
 		*height= strint1h;
		return TRUE;
		}
		else if(index==1)
		{
			Recordlog("getFormat Suss");
		 *width  = strint2w;
 		*height= strint2h;
		return TRUE;
		}
	    else if(index==2)
		{
			Recordlog("getFormat Suss");
		 *width  = strint3w;
 		*height= strint3h;
		return TRUE;
		}
		 else if(index==3)
		{
			 Recordlog("getFormat Suss");
		 *width  = strint4w;
 		*height= strint4h;
		return TRUE;
		}
		else if(index==4)
		{
				Recordlog("getFormat Suss");
		 *width  = strint5w;
 		*height= strint5h;
		return TRUE;
		}
		else
		{
				Recordlog("getFormat Fail");

			return FALSE;
		}
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			if(index==0)
			{
				Recordlog("getFormat Suss");
			 *width  = strint1w;
 			*height= strint1h;
			return TRUE;
			}
			else if(index==1)
			{
				Recordlog("getFormat Suss");
			*width  = strint2w;
 			*height= strint2h;
			return TRUE;
			}
			else if(index==2)
			{
				Recordlog("getFormat Suss");
			 *width  = strint3w;
 			*height= strint3h;
			return TRUE;
			}
			 else if(index==3)
			{
				 Recordlog("getFormat Suss");
			 *width  = strint4w;
 			*height= strint4h;
			return TRUE;
			}
			else if(index==4)
			{
				Recordlog("getFormat Suss");
			 *width  = strint5w;
 			*height= strint5h;
			return TRUE;
			}
			else
			{
				Recordlog("getFormat Fail");
			return FALSE;
			}
		}
		else
		{
			Recordlog("getFormat Fail");
			return FALSE;
		}
	}
	else
	{
		Recordlog("getFormat Fail");
			return FALSE;
	}
}		


 

BOOL STDCALL setCaptureSizeByIndex(DWORD DeviceHandle, INT index)
{
	Recordlog("Enter setCaptureSizeByIndex"); 
	mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="4",tem;
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
			Recordlog("setCaptureSizeByIndex Suss"); 

			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			Recordlog("setCaptureSizeByIndex Suss"); 
				return TRUE;
		}
		else
		{
			Recordlog("setCaptureSizeByIndex Fail"); 
			return FALSE;
		}
	}
	else
	{
		Recordlog("setCaptureSizeByIndex Fail"); 
			return FALSE;
	}
}
		
BOOL STDCALL setPreviewWindow(DWORD DeviceHandle, HWND previewHwnd)
{
Recordlog("Enter setPreviewWindow"); 
 mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="5",tem;
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
		Recordlog("setPreviewWindow Suss"); 

		strSetPreviewSign=1;
			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			Recordlog("setPreviewWindow Suss");
			strSetPreviewSign=1;
				return TRUE;
		}
		else
		{
			Recordlog("setPreviewWindow Fail");
			return FALSE;
		}
	}
	else
	{
		Recordlog("setPreviewWindow Fail");
			return FALSE;
	}
}

BOOL STDCALL startPreview(DWORD DeviceHandle)
{
	
Recordlog("Enter startPreview"); 
    mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="6",tem;
 	strinit.OnBtnRead(m_cmd);
	if(strSetPreviewSign!=1)
	{
		Recordlog("startPreview Fail");

			return FALSE;
	}
	
	if(strinit.m_resulf=="0")
	{
		Recordlog("startPreview Suss");
		m_VideoStateFun=2;
//		strStartPreviewSign=1;
			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			Recordlog("startPreview Suss");
			m_VideoStateFun=2;
//			strStartPreviewSign=1;
				return TRUE;
		}
		else
		{
			Recordlog("startPreview Fail");
			return FALSE;
		}
	}
	else
	{
		Recordlog("startPreview Fail");
			return FALSE;
	}
}
		
BOOL STDCALL stopPreview(DWORD DeviceHandle)
{
Recordlog("Enter stopPreview"); 
    mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="7",tem;
 	strinit.OnBtnRead(m_cmd);
	if (m_VideoStateFun!=2)
	{
		Recordlog("stopPreview Fail"); 

		return FALSE;
	}
	else
	{
		if(strinit.m_resulf=="0")
		{
					Recordlog("stopPreview Suss"); 

			m_VideoStateFun=1;
				return TRUE;
		}
		else if(strinit.m_resulf=="1")
		{
		    _Dialog(strTemp);
			if (strTemp==1)
			{
						Recordlog("stopPreview Suss"); 

				m_VideoStateFun=1;
					return TRUE;
			}
			else
			{
					Recordlog("stopPreview Fail"); 

				return FALSE;
			}
		}
		else
		{
			Recordlog("stopPreview Fail"); 

			return FALSE;
		}
	}
}
BOOL STDCALL captureBitmap(DWORD DeviceHandle, BYTE* strFileName )
{
Recordlog("Enter captureBitmap"); 
		  /*
  mINIT strinit;

 //	strinit.DoModal();
	CString m_cmd="8",tem;
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
		m_VideoStateFun=2;
			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			m_VideoStateFun=2;
				return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
			return FALSE;
	}
*/

		mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="8",tem;
    //读取配置项
	char lpcTempBuffer[256];
	memset(lpcTempBuffer, 0, sizeof(lpcTempBuffer));
	int liBufferLen = sizeof(lpcTempBuffer);
	//读取是否存在卡
	memset( lpcTempBuffer, 0, sizeof(lpcTempBuffer) );
	liBufferLen = sizeof(lpcTempBuffer);
	CString m_strSpVersion;
	CString  sIniFile ;	
 	HKEY lhkey;  

    LONG lret = RegOpenKeyEx( HKEY_LOCAL_MACHINE,  "SOFTWARE\\GrgBanking\\SPTrueBack\\CameraInterface", 0, KEY_ALL_ACCESS, &lhkey );
	if ( ERROR_SUCCESS == lret ) {
		DWORD dwSize = liBufferLen;
		long lReturn = RegQueryValueEx( lhkey, "imppath", NULL, NULL, (BYTE*)lpcTempBuffer, &dwSize );
		if ( lReturn == ERROR_SUCCESS )
		{
		
		sIniFile  =   lpcTempBuffer  ;
 
		}

	}

 	strinit.OnBtnRead(m_cmd);

	
 
	if(strinit.m_resulf=="0")
	{
 
 			char szDest[MAX_PATH]={0};
			sprintf(szDest, "%s",strFileName);
			CopyFile(sIniFile,szDest,false);
 
 Recordlog("captureBitmap Suss"); 

			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
 			char szDest[MAX_PATH]={0};
			sprintf(szDest, "%s",strFileName );
			CopyFile(sIniFile,szDest,false);
			 Recordlog("captureBitmap Suss"); 
	 

			
				return TRUE;
		}
		else
		{
			 Recordlog("captureBitmap Fail"); 

			return FALSE;
		}
	}
	else
	{
		 Recordlog("captureBitmap Fail"); 

			return FALSE;
	}
}

BYTE*  STDCALL getLastErrorMessage()
{
 Recordlog("Enter getLastErrorMessage"); 
	return 0x00;
}

BOOL STDCALL setAutoCrop(DWORD DeviceHandle, BOOL enabled)
{
 Recordlog("Enter setAutoCrop"); 
 mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="10",tem;
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
	Recordlog("setAutoCrop Suss"); 

			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
	Recordlog("setAutoCrop Suss"); 

				return TRUE;
		}
		else
		{
		 Recordlog("setAutoCrop Fail"); 

			return FALSE;
		}
	}
	else
	{
		 Recordlog("setAutoCrop Fail"); 

			return FALSE;
	}
}

BOOL STDCALL setCameraProperty(DWORD DeviceHandle)
{
 Recordlog("Enter setCameraProperty"); 
 mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="11",tem;
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
		Recordlog("setCameraProperty Suss"); 

			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
					Recordlog("setCameraProperty Suss"); 

				return TRUE;
		}
		else
		{
			Recordlog("setCameraProperty Fail"); 

			return FALSE;
		}
	}
	else
	{
			Recordlog("setCameraProperty Fail"); 

			return FALSE;
	}
}

BOOL STDCALL startAutoCapture(DWORD DeviceHandle, INT captureCount, INT captureInterval,BYTE* strFolder)
{
 Recordlog("Enter startAutoCapture"); 
	mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="12",tem;
    //读取配置项
	char lpcTempBuffer[256];
	memset(lpcTempBuffer, 0, sizeof(lpcTempBuffer));
	int liBufferLen = sizeof(lpcTempBuffer);
	//读取是否存在卡
	memset( lpcTempBuffer, 0, sizeof(lpcTempBuffer) );
	liBufferLen = sizeof(lpcTempBuffer);
	CString m_strSpVersion;
	CString  sIniFile ;	
 	HKEY lhkey;  

    LONG lret = RegOpenKeyEx( HKEY_LOCAL_MACHINE,  "SOFTWARE\\GrgBanking\\SPTrueBack\\CameraInterface", 0, KEY_ALL_ACCESS, &lhkey );
	if ( ERROR_SUCCESS == lret ) {
		DWORD dwSize = liBufferLen;
		long lReturn = RegQueryValueEx( lhkey, "imppath", NULL, NULL, (BYTE*)lpcTempBuffer, &dwSize );
		if ( lReturn == ERROR_SUCCESS )
		{
		
		sIniFile  =   lpcTempBuffer  ;
 
		}

	}

 	strinit.OnBtnRead(m_cmd);

	

	if(strinit.m_resulf=="0")
	{
 
			for(int i=0;i<captureCount;i++)
			{
//			LPCSTR	 strstring[3];
			char szDest[MAX_PATH]={0};
			sprintf(szDest, "%s\\image%03d.bmp", strFolder, i);
			CopyFile(sIniFile,szDest,false);
			}
			strStartAutoCaptureSign=1;
			Recordlog("startAutoCapture Suss"); 
			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
 
			for(int i=0;i<captureCount;i++)
			{
//			LPCSTR	 strstring[3];
			char szDest[MAX_PATH]={0};
			sprintf(szDest, "%s\\image%03d.bmp", strFolder, i);
			CopyFile(sIniFile,szDest,false);
			}
			strStartAutoCaptureSign=1;
			Recordlog("startAutoCapture Suss"); 
				return TRUE;
		}
		else
		{
			Recordlog("startAutoCapture Fail"); 
			return FALSE;
		}
	}
	else
	{
		Recordlog("startAutoCapture Fail"); 
			return FALSE;
	}
}

BOOL STDCALL stopAutoCapture(DWORD DeviceHandle)
{
 Recordlog("Enter startAutoCapture"); 
 mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="13",tem;
 	strinit.OnBtnRead(m_cmd);
	if(strStartAutoCaptureSign!=1)
	{
		 Recordlog("startAutoCapture Fail"); 

	return FALSE;
	}
	if(strinit.m_resulf=="0")
	{
		 Recordlog("startAutoCapture Suss"); 
		strStartAutoCaptureSign=0;
			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			 Recordlog("startAutoCapture Suss"); 
			strStartAutoCaptureSign=0;
				return TRUE;
		}
		else
		{
			 Recordlog("startAutoCapture Fail"); 
			return FALSE;
		}
	}
	else
	{
		 Recordlog("startAutoCapture Fail"); 
			return FALSE;
	}
}

BOOL STDCALL setRotateMode(DWORD DeviceHandle,INT mode)
{
 Recordlog("Enter setRotateMode"); 
 mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="14",tem;
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
	 Recordlog("setRotateMode Suss"); 
			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			Recordlog("setRotateMode Suss");
				return TRUE;
		}
		else
		{
			Recordlog("setRotateMode Fail");
			return FALSE;
		}
	}
	else
	{
		Recordlog("setRotateMode Fail");
			return FALSE;
	}
}
BOOL STDCALL setColorType(DWORD DeviceHandle,INT type)
{
	Recordlog("Enter setColorType"); 
	mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="15",tem;
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
		Recordlog("setColorType Suss");
			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			Recordlog("setColorType Suss");
				return TRUE;
		}
		else
		{
			Recordlog("setColorType Fail");
			return FALSE;
		}
	}
	else
	{
		Recordlog("setColorType Fail");
			return FALSE;
	}
}
		
BOOL STDCALL setPictureQuality(DWORD DeviceHandle,INT qualityRatio)
{
	Recordlog("Enter setPictureQuality");
	 mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="16",tem;
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
		Recordlog("setPictureQuality Suss");
			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			Recordlog("setPictureQuality Suss");
				return TRUE;
		}
		else
		{
			Recordlog("setPictureQuality Fail");
			return FALSE;
		}
	}
	else
	{
		Recordlog("setPictureQuality Fail");
			return FALSE;
	}
}

CString  getDllVersion(DWORD DeviceHandle)
{
	Recordlog("Enter getDllVersion");
	mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="17",tem,m_dllversion="V1.0.3";
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
		Recordlog("getDllVersion Suss");
			return m_dllversion;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			Recordlog("getDllVersion Suss");
				return  m_dllversion;
		}
		else
		{
			Recordlog("getDllVersion Fail");
			return m_cmd;
		}
	}
	else
	{
		Recordlog("getDllVersion Fail");
			return m_cmd;
	}
}

CString  getFirmWareVersion(DWORD DeviceHandle)
{
	Recordlog("Enter getFirmWareVersion");
	 mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="18",tem,m_dllversion="V1.0.0";
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
		Recordlog("getFirmWareVersion Suss");
			return m_dllversion;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			Recordlog("getFirmWareVersion Suss");
				return  m_dllversion;
		}
		else
		{
			Recordlog("getFirmWareVersion Fail");
			return m_cmd;
		}
	}
	else
	{
		Recordlog("getFirmWareVersion Fail");
			return m_cmd;
	}
}
void  SetVideoCallBack(VideoEvent _event)
{
	handler=_event;
//		handler(32768);
//		MessageBox(NULL,"22",NULL,MB_OK);
//		VideoEvent 32772;
//	 	return "0x00";
}

bool  SetVideoParameter(DWORD DeviceHandle,int para1,int para2,long lvalue,long flag)
{	 
  Recordlog("Enter SetVideoParameter");
	mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="22",tem;
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
		Recordlog("SetVideoParameter Suss");
			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			Recordlog("SetVideoParameter Suss");
				return TRUE;
		}
		else
		{
			Recordlog("SetVideoParameter Fail");
			return FALSE;
		}
	}
	else
	{
		Recordlog("SetVideoParameter Fail");
			return FALSE;
	}
}
bool  GetVideoParameter(DWORD DeviceHandle,int para1,int para2,long & min,long & max,long &lvalue,long &ldefault,long &flag)
{
	Recordlog("Enter GetVideoParameter");
	 mINIT strinit;
 //	strinit.DoModal();
	CString m_cmd="20",tem;
 	strinit.OnBtnRead(m_cmd);

	if(strinit.m_resulf=="0")
	{
		Recordlog("GetVideoParameter Suss");
			return TRUE;
	}
	else if(strinit.m_resulf=="1")
	{
        _Dialog(strTemp);
		if (strTemp==1)
		{
			Recordlog("GetVideoParameter Suss");
				return TRUE;
		}
		else
		{
			Recordlog("GetVideoParameter Fail");
			return FALSE;
		}
	}
	else
	{
		Recordlog("GetVideoParameter Fail");
			return FALSE;
	}
}

int STDCALL getVideoState(DWORD DeviceHandle)
{
	Recordlog("Enter getVideoState");	 
	//	return	m_VideoStateFun ;
		if(m_VideoStateFun==0)
		{
 		Recordlog(" VideoState==1");	
		return	1 ;
		}
		else
		{	
			return	m_VideoStateFun ;
		}


}

BOOL CALLBACK _DLGPROC(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
 
	switch(msg)
	{
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
 	 	 strTemp=1;
 			EndDialog(hDlg, 1);
			return TRUE;
		case IDCANCEL:
 	 		strTemp=0;
			EndDialog(hDlg, 0);
			return TRUE;
		}
		break;
	case WM_INITDIALOG:
		return TRUE;
	}
	return FALSE;
}

void _Dialog(int strinit)
{
	HMODULE hMod = ::GetModuleHandle("CameraInterface.dll");

 
	::DialogBoxParam(hMod, MAKEINTRESOURCE(IDD_DIALOGEX), NULL,_DLGPROC,0);
 
}

