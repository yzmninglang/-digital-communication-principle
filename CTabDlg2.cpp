// CTabDlg2.cpp: 实现文件
//

#include "pch.h"
#include "FSK.h"
#include "CTabDlg2.h"
#include "afxdialogex.h"
#include "FSKDlg.h"
#include "SigTranmit.h"

extern SigTranmit Signal;
// CTabDlg2 对话框

IMPLEMENT_DYNAMIC(CTabDlg2, CDialogEx)

CTabDlg2::CTabDlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
		, my_ID(Signal.GetmyID())
	, nFs(Signal.GetFs())
	//, nFc(0)
	, snr(Signal.GetmyIntensity())
	, nLpfc(Signal.GetnLpfc())
	, nBpfc1(Signal.GetnBpfc1())
	, nBpfc2(Signal.GetnBpfc2())
	, nBpfc3(Signal.GetnBpfc3())
	, nBpfc4(Signal.GetnBpfc4())
	, Fc1(Signal.GetFc1())
	, Fc2(Signal.GetFc2())
	, nDesign(_T(""))
{
	//parent = (CFSKDlg*)GetParent()->GetParent();
}

CTabDlg2::~CTabDlg2()
{
}
//CFSKDlg* CTabDlg2::Getparent()
//{
//	return (CFSKDlg*)GetParent()->GetParent();
//}
void CTabDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON_Base2, MXBH);
	DDX_Text(pDX, IDC_Fs, nFs);
	//DDX_Text(pDX, IDC_Fc, nFc);
	DDX_Text(pDX, IDC_SNR, snr);
	DDX_Text(pDX, IDC_LPF_2, nLpfc);
	DDX_Text(pDX, IDC_BPF_1, nBpfc1);
	DDX_Text(pDX, IDC_BPF_2, nBpfc2);
	//DDX_Text(pDX, IDC_BPF3, nBpfc3);
	//DDX_Text(pDX, IDC_BPF4, nBpfc4);
	DDX_Text(pDX, IDC_Fc1, Fc1);
	//DDX_Text(pDX, IDC_Fc2, Fc2);
	DDX_Text(pDX, IDC_myID2, my_ID);
	DDX_CBString(pDX, IDC_Design, nDesign);
	DDX_Control(pDX, IDC_WinFunc, my_Winfunc);
}


BEGIN_MESSAGE_MAP(CTabDlg2, CDialogEx)
//	ON_BN_CLICKED(IDC_BUTTON3, &CTabDlg2::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON_Base, &CTabDlg2::OnBnClickedButtonBase)
ON_BN_CLICKED(IDC_BUTTON_Convert, &CTabDlg2::OnBnClickedButtonConvert)
ON_BN_CLICKED(IDC_BUTTON_Base_lpf, &CTabDlg2::OnBnClickedButtonBaselpf)
ON_BN_CLICKED(IDC_BUTTON_Convert_lpf, &CTabDlg2::OnBnClickedButtonConvertlpf)
ON_BN_CLICKED(IDC_BUTTON_ModulateF1, &CTabDlg2::OnBnClickedButtonModulatef1)
ON_BN_CLICKED(IDC_BUTTON_ModulateF2, &CTabDlg2::OnBnClickedButtonModulatef2)
ON_BN_CLICKED(IDC_BUTTON_2FSK, &CTabDlg2::OnBnClickedButton2fsk)
ON_BN_CLICKED(IDC_BUTTON_Channel, &CTabDlg2::OnBnClickedButtonChannel)
ON_BN_CLICKED(IDC_BUTTON_Noise, &CTabDlg2::OnBnClickedButtonNoise)
ON_BN_CLICKED(IDC_BUTTON_Fc1_bpf, &CTabDlg2::OnBnClickedButtonFc1bpf)
ON_BN_CLICKED(IDC_BUTTON_Fc2_bpf, &CTabDlg2::OnBnClickedButtonFc2bpf)
ON_BN_CLICKED(IDC_BUTTON_DemodulateF1, &CTabDlg2::OnBnClickedButtonDemodulatef1)
ON_BN_CLICKED(IDC_BUTTON_DemodulateF2, &CTabDlg2::OnBnClickedButtonDemodulatef2)
ON_BN_CLICKED(IDC_BUTTON_Lpf1, &CTabDlg2::OnBnClickedButtonLpf1)
ON_BN_CLICKED(IDC_BUTTON_Lpf2, &CTabDlg2::OnBnClickedButtonLpf2)
ON_BN_CLICKED(IDC_BUTTON_Adjust, &CTabDlg2::OnBnClickedButtonAdjust)
ON_BN_CLICKED(IDC_BUTTON_2psk, &CTabDlg2::OnBnClickedButton2psk)
ON_BN_CLICKED(IDC_BUTTON_Adjust_2FSK, &CTabDlg2::OnBnClickedButtonAdjust2fsk)
ON_BN_CLICKED(IDC_BUTTON_ASK, &CTabDlg2::OnBnClickedButtonAsk)
ON_BN_CLICKED(IDC_BUTTON_Adjust_ASK, &CTabDlg2::OnBnClickedButtonAdjustAsk)
ON_CBN_SELCHANGE(IDC_COMBO2, &CTabDlg2::OnCbnSelchangeCombo2)
//ON_BN_CLICKED(IDC_BUTTON_Base2, &CTabDlg2::OnBnClickedButtonBase2)
ON_BN_CLICKED(IDC_BUTTON8, &CTabDlg2::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON_BPF2, &CTabDlg2::OnBnClickedButtonBpf2)
ON_BN_CLICKED(IDC_BUTTON_P, &CTabDlg2::OnBnClickedButtonP)
ON_BN_CLICKED(IDC_BUTTON_LPF, &CTabDlg2::OnBnClickedButtonLpf)
//ON_BN_CLICKED(IDC_MFCBUTTON1, &CTabDlg2::OnBnClickedMfcbutton1)
//ON_BN_CLICKED(IDC_BUTTON6, &CTabDlg2::OnBnClickedButton6)
//ON_BN_CLICKED(IDC_MFCBUTTON_LPF, &CTabDlg2::OnBnClickedMfcbuttonLpf)
ON_BN_CLICKED(IDC_MFCBUTTON3, &CTabDlg2::OnBnClickedMfcbutton3)
ON_BN_CLICKED(IDC_MFCBUTTON4, &CTabDlg2::OnBnClickedMfcbutton4)
//ON_BN_CLICKED(IDC_MFCBUTTON5, &CTabDlg2::OnBnClickedMfcbutton5)
ON_BN_CLICKED(IDC_BUTTON_LPFSHOW, &CTabDlg2::OnBnClickedButtonLpfshow)
END_MESSAGE_MAP()


// CTabDlg2 消息处理程序


void CTabDlg2::OnBnClickedButtonBase()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Basesignal(parent->CTabDlg1.my_ID);
	//Signal.Convert();
	//Signal.Convert();
	Signal.Dft(Signal.GetSa(), 16 * M);
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());

}


void CTabDlg2::OnBnClickedButtonConvert()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Convert(); //翻转信号
	Signal.Dft(Signal.GetSa2(), 16 * M);
	parent->Draw_graph(Signal.GetSa2(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonBaselpf()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	
	Signal.Lpf();
	Signal.Conv(Signal.GetSa(), Signal.GetHl(), Signal.GetSa());
	Signal.Dft(Signal.GetSa(), 16 * M);
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonConvertlpf()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Lpf();
	Signal.Conv(Signal.GetSa2(), Signal.GetHl(), Signal.GetSa2());
	Signal.Dft(Signal.GetSa2(), 16 * M);
	parent->Draw_graph(Signal.GetSa2(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonModulatef1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.modulate(Signal.GetFc1(), 1);
	Signal.Dft(Signal.GetSa(), 16 * M);
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonModulatef2()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.modulate(Signal.GetFc2(), 2);
	Signal.Dft(Signal.GetSa2(), 16 * M);
	parent->Draw_graph(Signal.GetSa2(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButton2fsk()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.FSK(1);//覆盖了原基带信号
	Signal.Dft(Signal.GetSa(), 16 * M);
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonChannel()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Channel();
	Signal.Dft(Signal.GetSa(), 16 * M);
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonNoise()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Noise(Signal.GetmyIntensity());
	Signal.Dft(Signal.GetNo(), 16 * M);
	parent->Draw_graph(Signal.GetNo(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonFc1bpf()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Bpf(1);
	Signal.Conv(Signal.GetSa(), Signal.GetH2(), Signal.GetSaFc1());
	Signal.Dft(Signal.GetSaFc1(), 16 * M);
	parent->Draw_graph(Signal.GetSaFc1(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonFc2bpf()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Bpf(2);
	Signal.Conv(Signal.GetSa(), Signal.GetH2(), Signal.GetSaFc2());
	Signal.Dft(Signal.GetSaFc2(), 16 * M);
	parent->Draw_graph(Signal.GetSaFc2(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonDemodulatef1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Demodulate(Signal.GetFc1(), 1);
	Signal.Dft(Signal.GetSaFc1(), 16 * M);
	parent->Draw_graph(Signal.GetSaFc1(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonDemodulatef2()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Demodulate(Signal.GetFc2(), 2);
	Signal.Dft(Signal.GetSaFc2(), 16 * M);
	parent->Draw_graph(Signal.GetSaFc2(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonLpf1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Lpf();
	Signal.Conv(Signal.GetSaFc1(), Signal.GetHl(), Signal.GetSaFc1());
	Signal.Dft(Signal.GetSaFc1(), 16 * M);
	parent->Draw_graph(Signal.GetSaFc1(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonLpf2()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Lpf();
	Signal.Conv(Signal.GetSaFc2(), Signal.GetHl(), Signal.GetSaFc2());
	Signal.Dft(Signal.GetSaFc2(), 16 * M);
	parent->Draw_graph(Signal.GetSaFc2(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonAdjust()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	//Signal.FSK(2);
	Signal.PSKSigRecover();
	Signal.Dft(Signal.GetSa(), 16 * M);
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButton2psk()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.PSK(1);//覆盖了原基带信号
	Signal.Dft(Signal.GetSa(), 16 * M);
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonAdjust2fsk()
{

	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	//Signal.FSK(2);
	Signal.FSKSigRecover();
	Signal.Dft(Signal.GetSa(), 16 * M);
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonAsk()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.ASK(1);//覆盖了原基带信号
	Signal.Dft(Signal.GetSa(), 16 * M);
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonAdjustAsk()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	//Signal.FSK(2);
	Signal.ASKSigRecover();
	Signal.Dft(Signal.GetSa(), 16 * M);
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码

}


void CTabDlg2::OnBnClickedButtonBase2() 
{
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Convert();
	Signal.Dft(Signal.GetSa(), 16 * M);
	//printf("hello");
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Convert();
	Signal.Dft(Signal.GetSa(), 16 * M);
	//printf("hello");
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonBpf2()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Convert();
	Signal.Dft(Signal.GetSa(), 16 * M);
	//printf("hello");
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonP()
{
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Convert();
	Signal.Dft(Signal.GetSa(), 16 * M);
	//printf("hello");
	//cout << "sa";
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
}


void CTabDlg2::OnBnClickedButtonLpf()
{
	// TODO: 在此添加控件通知处理程序代码
	Signal.Lpf();
	Signal.Dft(Signal.GetHl(), N);
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	parent->Draw_graph_filter(Signal.GetHl(), Signal.GetA());
}


void CTabDlg2::OnBnClickedMfcbutton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CTabDlg2::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Convert();
	Signal.Dft(Signal.GetSa(), 16 * M);
	//printf("hello");
	//cout << "sa";
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());

}


void CTabDlg2::OnBnClickedMfcbuttonLpf()
{
	// TODO: 在此添加控件通知处理程序代码
// TODO: 在此添加控件通知处理程序代码
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	Signal.Convert();
	Signal.Dft(Signal.GetSa(), 16 * M);
	//printf("hello");
	//cout << "sa";
	parent->Draw_graph(Signal.GetSa(), Signal.GetA());
	// TODO: 在此添加控件通知处理程序代码
}


void CTabDlg2::OnBnClickedMfcbutton3()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	//CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	//Signal.Convert();
	//Signal.Dft(Signal.GetSa(), 16 * M);
	////printf("hello");
	////cout << "sa";
	//parent->Draw_graph(Signal.GetSa(), Signal.GetA());



	Signal.Lpf();
	Signal.Dft(Signal.GetHl(), N);
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	parent->Draw_graph_filter(Signal.GetHl(), Signal.GetA());
}


void CTabDlg2::OnBnClickedMfcbutton4()
{
	// TODO: 在此添加控件通知处理程序代码
	Signal.Bpf(1);
	Signal.Dft(Signal.GetHl(), N);
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	parent->Draw_graph_filter(Signal.GetHl(), Signal.GetA());
}




void CTabDlg2::OnBnClickedButtonLpfshow()
{
	// TODO: 在此添加控件通知处理程序代码
	Signal.Lpf();
	Signal.Dft(Signal.GetHl(), N);
	CFSKDlg* parent = (CFSKDlg*)GetParent()->GetParent();//CSensorSysDlg是主对话框对应的类
	parent->Draw_graph_filter(Signal.GetHl(), Signal.GetA());
}
