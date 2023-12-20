#pragma once

#include "SigTranmit.h"
// CTabDlg2 对话框

class CTabDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDlg2)

public:
	CTabDlg2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDlg2();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int my_ID;
	int nFs;
	//	int nFc;
	float snr;
	float nLpfc;
	float nBpfc1;
	float nBpfc2;
	float nBpfc3;
	float nBpfc4;
	int Fc1;
	int Fc2;
	CString nDesign;
	CComboBox my_Winfunc;
	//CFSKDlg* Getparent();
//	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonBase();
	afx_msg void OnBnClickedButtonConvert();
	afx_msg void OnBnClickedButtonBaselpf();
	afx_msg void OnBnClickedButtonConvertlpf();
	afx_msg void OnBnClickedButtonModulatef1();
	afx_msg void OnBnClickedButtonModulatef2();
	afx_msg void OnBnClickedButton2fsk();
	afx_msg void OnBnClickedButtonChannel();
	afx_msg void OnBnClickedButtonNoise();
	afx_msg void OnBnClickedButtonFc1bpf();
	afx_msg void OnBnClickedButtonFc2bpf();
	afx_msg void OnBnClickedButtonDemodulatef1();
	afx_msg void OnBnClickedButtonDemodulatef2();
	afx_msg void OnBnClickedButtonLpf1();
	afx_msg void OnBnClickedButtonLpf2();
	afx_msg void OnBnClickedButtonAdjust();
	afx_msg void OnBnClickedButton2psk();
	afx_msg void OnBnClickedButtonAdjust2fsk();
	afx_msg void OnBnClickedButtonAsk();
	afx_msg void OnBnClickedButtonAdjustAsk();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButtonBase2();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButtonBpf2();
//	CButton MXBH;
	afx_msg void OnBnClickedButtonP();
	afx_msg void OnBnClickedButtonLpf();
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedMfcbuttonLpf();
	afx_msg void OnBnClickedMfcbutton3();
	afx_msg void OnBnClickedMfcbutton4();
	afx_msg void OnBnClickedMfcbutton5();
	afx_msg void OnBnClickedButtonLpfshow();
};
