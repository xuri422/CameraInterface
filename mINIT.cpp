// mINIT.cpp : implementation file
//

#include "stdafx.h"
//#include "camerainterface.h"
#include "mINIT.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// mINIT dialog


mINIT::mINIT(CWnd* pParent /*=NULL*/)
	: CDialog(mINIT::IDD, pParent)
{
	//{{AFX_DATA_INIT(mINIT)
	m_iIndex=0;
	//}}AFX_DATA_INIT
}


void mINIT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(mINIT)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(mINIT, CDialog)
	//{{AFX_MSG_MAP(mINIT)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// mINIT message handlers


BOOL mINIT::OnInitDialog() 
{
	m_iIndex=0;
	CDialog::OnInitDialog();
	
 
 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void mINIT::OnUpdateStatus()
{
//	m_ctrList.DeleteAllItems();
	m_iIndex=0;
//	vShowMachineStatus();
//	vShowStackerStatus();
//	vShowCasseteStatus();

}

void  mINIT::OnBtnRead(CString  CmdID)                         // 从INI文件中读取指定的信息   
{  
 
	int Temp_Len=sizeof(score_Chinese);
	int k=0,j=0;
	char  Temp[80] ;
	char* strTamp[6];
	CString m_char,m_disp,tem,tem2; 

	m_char=";"; 

		//读取配置项
	char lpcTempBuffer[256];
	memset(lpcTempBuffer, 0, sizeof(lpcTempBuffer));
	int liBufferLen = sizeof(lpcTempBuffer);
	//读取是否存在卡
	memset( lpcTempBuffer, 0, sizeof(lpcTempBuffer) );
	liBufferLen = sizeof(lpcTempBuffer);
	CString m_strSpVersion;
	CString  sIniFile2;	
		HKEY lhkey;  

    

    LONG lret = RegOpenKeyEx( HKEY_LOCAL_MACHINE,  "SOFTWARE\\GrgBanking\\SPTrueBack\\CameraInterface", 0, KEY_ALL_ACCESS, &lhkey );
	if ( ERROR_SUCCESS == lret ) {
		DWORD dwSize = liBufferLen;
		long lReturn = RegQueryValueEx( lhkey,  "path", NULL, NULL, (BYTE*)lpcTempBuffer, &dwSize );
		if ( lReturn == ERROR_SUCCESS )
		{
		
		sIniFile2 =   lpcTempBuffer  ;
 
		}

	}

//    CString sIniFile = "D:\\GrgVirDev_StampPrt\\Debug\\VirDevConfig\\GrgVirDev_CameraInterface.ini";                   
    
     GetPrivateProfileString(  "GrgVirDev_CameraInterface_CMDAnsStyle" ,CmdID,NULL,score_Chinese.GetBuffer(MAX_PATH),MAX_PATH,sIniFile2);          // read an integer from the specified config file 

//	int n = m_disp.ReverseFind(';') ;
//	m_cmd = m_disp.Left(6);

 m_disp.Format( "%s",score_Chinese); 

  	strcpy(Temp,m_disp);
 //  sprintf(Temp, "%s", m_disp);
	for (int i=0;i<sizeof(Temp);i++)
	{
 		if(Temp[i]!=m_char)
		{

		}
		else
		{
			CString a;
			a= m_disp.Mid(k,i-k) ;
			
			strTamp[j]=(LPSTR)(LPCTSTR)a;

		k=k+(i-k)+1;

		if(j==1)
		{
    	tem=*strTamp[1];
    		if (tem=="0")
			{
			 m_resulf="0";
		 		break;
			}
			else if(tem=="1")
			{
			 m_resulf="1";
		 		break;
			}

		}
		else if (j==3)
		{
		
			tem2=*strTamp[3];
			if (tem=="0")
			{
			 m_resulf="0";
			}
			else if(tem=="6")
			{
				if(tem2=="0")
				{
				m_resulf="0";
				}
				else
				{
				m_resulf="F";
				}
			}
			break;
			}
	  	j++;
		}
		
 	}

}  
  
// store data to config file  
void mINIT::OnBtnwrite()  
{  
  //    WritePrivateProfileString("GrgVirDev_CameraInterface_CMDAnsStyle", "UserName", userName, sIniFile);  
//    MessageBox("Write data to config file successfully!", "Information", MB_OK | MB_ICONEXCLAMATION);  
 
}  
