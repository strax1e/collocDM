#include "stdafx.h"
#include "DM.h"
#include "standart_functions.h"

#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
std::map<HWND,HACCEL>	l_mAccelTable;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
HWND                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

std::string LPWSTRtoSTR( LPWSTR W )
{
	std::wstring WS;
	char *CH;
	std::string S;

	WS = std::wstring(W);
	CH = new char[WS.length() + 1];
	CH[WS.size()] = '\0';
	WideCharToMultiByte(CP_ACP, 0, WS.c_str(), -1, CH, (int)WS.length(), NULL, NULL);
	return std::string(CH);
}

LPWSTR STRtoLPWSTR( std::string S )
{
	LPWSTR WS;

	S.push_back('\0');
	WS = new TCHAR[S.size()];
	MultiByteToWideChar(CP_ACP, 0, S.data(), -1, WS, (int)S.size());
	return WS;
}

BOOL AddAccelerators(HWND hWnd, HACCEL hAccel)
{
	if ( IsWindow( hWnd ) )
	{
		l_mAccelTable[ hWnd ] = hAccel;
		return TRUE;
	}
	return FALSE;
}

BOOL AddAccelerators( HWND hWnd, LPCTSTR accel )
{
	return AddAccelerators( hWnd, LoadAccelerators( hInst, accel ) );
}

BOOL AddAccelerators(HWND hWnd, int accel)
{
	return AddAccelerators( hWnd, MAKEINTRESOURCE( accel ) );
}

BOOL AddAccelerators( HWND hWnd )
{
	return AddAccelerators( hWnd, HACCEL( NULL ) );
}

void DelAccel(HWND hWnd)
{
	std::map<HWND, HACCEL>::iterator end = l_mAccelTable.end();
	std::map<HWND, HACCEL>::iterator me = l_mAccelTable.find( hWnd );

	if ( me != end )
	{
		if ( me->second )
		{
			DestroyAcceleratorTable( me->second );
		}

		l_mAccelTable.erase( me );
	}
}

BOOL HandleAccelWindow(std::map<HWND,HACCEL>::const_iterator mh, MSG & msg)
{
	const HWND & hWnd = mh->first;
	const HACCEL & hAccel = mh->second;

	if ( !TranslateAccelerator( hWnd, hAccel, &msg ) )
	{
		if ( !IsDialogMessage( hWnd, &msg ) )
		{
			return FALSE;
		}
	}

	return TRUE;
}

BOOL HandleAccelArray( HWND hActive, MSG & msg )
{
	if ( !hActive )
		return FALSE;

	std::map<HWND, HACCEL>::const_iterator mh = l_mAccelTable.find( hActive );
	if ( mh != l_mAccelTable.end() )
	{
		return HandleAccelWindow( mh, msg );
	}

	return FALSE;
}

WPARAM Loop()
{
	// Main message loop:
	MSG msg;
	BOOL bRet = 0;
	while ( bRet = GetMessage( &msg, nullptr, 0, 0 ) )
	{
		if ( -1 == bRet )
			return 0;

		if ( !HandleAccelArray( GetActiveWindow(), msg ) )
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
	}
	return msg.wParam;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_DM, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	HWND hMainWnd = InitInstance( hInstance, nCmdShow );    
	if (!hMainWnd)
		return FALSE;

	AddAccelerators(hMainWnd, IDC_DM);


	WPARAM ret = Loop();


	DelAccel( hMainWnd );

	return (int) ret;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = WndProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DM));
	wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground  = (HBRUSH)(COLOR_BTNFACE+1);
	wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DM);
	wcex.lpszClassName  = szWindowClass;
	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
HWND InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 370, 120, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	SendMessage( hWnd, WM_SETFONT, (WPARAM)GetStockObject( DEFAULT_GUI_FONT ), 1 );

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

INT_PTR CALLBACK NaturalProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	static HWND FieldA = NULL, FieldB = NULL, FieldAns = NULL;

	switch(message)
	{
	case WM_INITDIALOG:
	{
		int cury = -30;
		LPCREATESTRUCT lpcs = (LPCREATESTRUCT)lParam;
		MoveWindow(hWnd, 0, 0, 700, 500, TRUE);
		FieldA = CreateWindow(TEXT( "EDIT" ), TEXT(""), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x204, hInst, NULL);
		CreateWindow(TEXT("STATIC"), TEXT("A:"), WS_CHILDWINDOW | WS_VISIBLE | SS_LEFT, 10, cury, 15, 20, hWnd, (HMENU)0x204, hInst, NULL);
		FieldB = CreateWindow(TEXT( "EDIT" ), TEXT(""), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x205, hInst, NULL);
		CreateWindow(TEXT("STATIC"), TEXT("B:"), WS_CHILDWINDOW | WS_VISIBLE | SS_LEFT, 10, cury, 15, 20, hWnd, (HMENU)0x204, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A + B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x207, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("|A - B|"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x208, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A * B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x209, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A / B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x210, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A % B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x211, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("НОД(A, B)"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x212, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("НОК(A, B)"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x213, hInst, NULL);
		FieldAns = CreateWindow(TEXT( "STATIC" ), TEXT( "Answer" ), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x206, hInst, NULL);
		break;
	}
	case WM_COMMAND:
	{
		if (BN_CLICKED == HIWORD( wParam ) || 1 == HIWORD( wParam ))
		{
			if (LOWORD(wParam) == IDOK || LOWORD( wParam ) == IDCANCEL)
			{
				SendMessage(hWnd, WM_CLOSE, 0, 0);
				DestroyWindow(hWnd);
				break;
			}
			else
			{
				LPWSTR AC, BC;
				std::stringstream buf;
				BigNatural A, B;

				AC = new TCHAR[2001];
				BC = new TCHAR[2001];

				GetWindowText(FieldA, (LPWSTR)AC, 2000);
				GetWindowText(FieldB, (LPWSTR)BC, 2000);
				try
				{
				  A = BigNatural(LPWSTRtoSTR(AC)), B = BigNatural(LPWSTRtoSTR(BC));
				  switch (LOWORD(wParam))
				  {
				  case 0x207:
				  	buf << A + B;
				  	break;
				  case 0x208:
				  	buf << (A > B ? (A - B) : (B - A));
				  	break;
				  case 0x209:
				  	buf << A * B;
				  	break;
				  case 0x210:
				  	buf << A / B;
				  	break;
				  case 0x211:
				  	buf << A % B;
				  	break;
				  case 0x212:
				  	buf << GCD(A, B);
				  	break;
				  case 0x213:
				  	buf << LCM(A, B);
				  	break;
				  }
				}
				catch (std::runtime_error &ex)
				{
					buf << ex.what();
				}
				SetWindowText(FieldAns, STRtoLPWSTR(buf.str()));
			}
		}
		break;
	}
	case WM_DESTROY:
		DelAccel( hWnd );
		break;
	}
	return 0;
}

INT_PTR CALLBACK IntegerProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	static HWND FieldA = NULL, FieldB = NULL, FieldAns = NULL;

	switch(message)
	{
	case WM_INITDIALOG:
	{
		int cury = -30;
		LPCREATESTRUCT lpcs = (LPCREATESTRUCT)lParam;
		MoveWindow(hWnd, 0, 0, 700, 500, TRUE);
		FieldA = CreateWindow(TEXT( "EDIT" ), TEXT(""), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x204, hInst, NULL);
		CreateWindow(TEXT("STATIC"), TEXT("A:"), WS_CHILDWINDOW | WS_VISIBLE | SS_LEFT, 10, cury, 15, 20, hWnd, (HMENU)0x204, hInst, NULL);
		FieldB = CreateWindow(TEXT( "EDIT" ), TEXT(""), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x205, hInst, NULL);
		CreateWindow(TEXT("STATIC"), TEXT("B:"), WS_CHILDWINDOW | WS_VISIBLE | SS_LEFT, 10, cury, 15, 20, hWnd, (HMENU)0x204, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A + B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x207, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A - B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x208, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A * B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x209, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A / B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x210, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A % B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x211, hInst, NULL);
		FieldAns = CreateWindow(TEXT( "EDIT" ), TEXT( "Answer" ), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x206, hInst, NULL);
		break;
	}
	case WM_COMMAND:
	{
		if (BN_CLICKED == HIWORD( wParam ) || 1 == HIWORD( wParam ))
		{
			if (LOWORD(wParam) == IDOK || LOWORD( wParam ) == IDCANCEL)
			{
				PostQuitMessage(0);
				DestroyWindow(hWnd);
				break;
			}
			else
			{
				LPWSTR AC, BC;
				std::stringstream buf;
				BigInteger A, B;

				AC = new TCHAR[2001];
				BC = new TCHAR[2001];

				GetWindowText(FieldA, (LPWSTR)AC, 2000);
				GetWindowText(FieldB, (LPWSTR)BC, 2000);
				try
				{
					A = BigInteger(LPWSTRtoSTR(AC)), B = BigInteger(LPWSTRtoSTR(BC));
					switch (LOWORD(wParam))
					{
					case 0x207:
						buf << A + B;
						break;
					case 0x208:
						buf << A - B;
						break;
					case 0x209:
						buf << A * B;
						break;
					case 0x210:
						buf << A / B;
						break;
					case 0x211:
						buf << A % B;
						break;
					}
				}
				catch (std::runtime_error &ex)
				{
					buf << ex.what();
				}
				SetWindowText(FieldAns, STRtoLPWSTR(buf.str()));
			}
		}
		break;
	}
	case WM_DESTROY:
		DelAccel( hWnd );
		break;
	}
	return 0;
}

INT_PTR CALLBACK RationalProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	static HWND FieldA = NULL, FieldB = NULL, FieldAns = NULL;

	switch(message)
	{
	case WM_INITDIALOG:
	{
		int cury = -30;
		LPCREATESTRUCT lpcs = (LPCREATESTRUCT)lParam;
		MoveWindow(hWnd, 0, 0, 700, 500, TRUE);
		FieldA = CreateWindow(TEXT( "EDIT" ), TEXT(""), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x204, hInst, NULL);
		CreateWindow(TEXT("STATIC"), TEXT("A:"), WS_CHILDWINDOW | WS_VISIBLE | SS_LEFT, 10, cury, 15, 20, hWnd, (HMENU)0x211, hInst, NULL);
		FieldB = CreateWindow(TEXT( "EDIT" ), TEXT(""), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x205, hInst, NULL);
		CreateWindow(TEXT("STATIC"), TEXT("B:"), WS_CHILDWINDOW | WS_VISIBLE | SS_LEFT, 10, cury, 15, 20, hWnd, (HMENU)0x211, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A + B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x207, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A - B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x208, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A * B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x209, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A / B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x210, hInst, NULL);
		FieldAns = CreateWindow(TEXT( "EDIT" ), TEXT( "Answer" ), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x206, hInst, NULL);
		break;
	}
	case WM_COMMAND:
	{
		if (BN_CLICKED == HIWORD( wParam ) || 1 == HIWORD( wParam ))
		{
			if (LOWORD(wParam) == IDOK || LOWORD( wParam ) == IDCANCEL)
			{
				PostQuitMessage(0);
				DestroyWindow(hWnd);
				break;
			}
			else
			{
				LPWSTR AC, BC;
				std::stringstream buf;
				Rational A, B;

				AC = new TCHAR[2001];
				BC = new TCHAR[2001];

				GetWindowText(FieldA, (LPWSTR)AC, 2000);
				GetWindowText(FieldB, (LPWSTR)BC, 2000);
				try
				{
					A = Rational(LPWSTRtoSTR(AC)), B = Rational(LPWSTRtoSTR(BC));
					switch (LOWORD(wParam))
					{
					case 0x207:
						buf << A + B;
						break;
					case 0x208:
						buf << A - B;
						break;
					case 0x209:
						buf << A * B;
						break;
					case 0x210:
						buf << A / B;
						break;
					}
				}
				catch (std::runtime_error &ex)
				{
					buf << ex.what();
				}
				SetWindowText(FieldAns, STRtoLPWSTR(buf.str()));
			}
		}
		break;
	}
	case WM_DESTROY:
		DelAccel( hWnd );
		break;
	}
	return 0;
}

INT_PTR CALLBACK PolynomProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	static HWND FieldA = NULL, FieldB = NULL, FieldPA = NULL, FieldPB = NULL, FieldAns = NULL;

	switch(message)
	{
	case WM_INITDIALOG:
	{
		int cury = -30;
		LPCREATESTRUCT lpcs = (LPCREATESTRUCT)lParam;
		MoveWindow(hWnd, 0, 0, 700, 700, TRUE);
		FieldA = CreateWindow(TEXT( "EDIT" ), TEXT("1, 2, 3"), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x204, hInst, NULL);
		CreateWindow(TEXT("STATIC"), TEXT("A:"), WS_CHILDWINDOW | WS_VISIBLE | SS_LEFT, 10, cury, 15, 20, hWnd, (HMENU)0x204, hInst, NULL);
		FieldPA = CreateWindow(TEXT( "STATIC" ), TEXT( "Polynomial" ), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury + 20, 600, 20, hWnd, (HMENU)0x206, hInst, NULL);
		FieldB = CreateWindow(TEXT( "EDIT" ), TEXT("1, 0, 0"), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x205, hInst, NULL);
		CreateWindow(TEXT("STATIC"), TEXT("B:"), WS_CHILDWINDOW | WS_VISIBLE | SS_LEFT, 10, cury, 15, 20, hWnd, (HMENU)0x204, hInst, NULL);
		FieldPB = CreateWindow(TEXT( "STATIC" ), TEXT( "Polynomial" ), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury + 20, 600, 20, hWnd, (HMENU)0x206, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A + B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x207, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A - B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x208, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A * B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x209, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A / B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x210, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("A % B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 280, cury += 40, 75, 20, hWnd, (HMENU)0x211, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("НОД(A, B)"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 268, cury += 40, 100, 20, hWnd, (HMENU)0x212, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("Производная A"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 218, cury += 40, 200, 20, hWnd, (HMENU)0x213, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("Производная B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 218, cury += 40, 200, 20, hWnd, (HMENU)0x214, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("Кратные корни A в простые"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 218, cury += 40, 200, 20, hWnd, (HMENU)0x215, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("Кратные корни B в простые"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 218, cury += 40, 200, 20, hWnd, (HMENU)0x216, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("НОД числителей / НОК знаменателей A"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 168, cury += 40, 300, 20, hWnd, (HMENU)0x217, hInst, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("НОД числителей / НОК знаменателей B"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 168, cury += 40, 300, 20, hWnd, (HMENU)0x218, hInst, NULL);
		FieldAns = CreateWindow(TEXT( "STATIC" ), TEXT( "Answer" ), WS_CHILDWINDOW | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER, 30, cury += 40, 600, 20, hWnd, (HMENU)0x206, hInst, NULL);
		break;
	}
	case WM_COMMAND:
	{
		if (BN_CLICKED == HIWORD( wParam ) || 1 == HIWORD( wParam ))
		{
			if (LOWORD(wParam) == IDOK || LOWORD( wParam ) == IDCANCEL)
			{
				PostQuitMessage(0);
				DestroyWindow(hWnd);
				break;
			}
			else
			{
				LPWSTR AC, BC;
				std::stringstream buf;
				Polynom A, B;
				bool israt = false;

				AC = new TCHAR[2001];
				BC = new TCHAR[2001];

				GetWindowText(FieldA, (LPWSTR)AC, 2000);
				GetWindowText(FieldB, (LPWSTR)BC, 2000);
				try
				{
					A = Polynom(LPWSTRtoSTR(AC)), B = Polynom(LPWSTRtoSTR(BC));

					buf << A;
					SetWindowText(FieldPA, STRtoLPWSTR(buf.str()));
					buf.str("");
					buf << B;
					SetWindowText(FieldPB, STRtoLPWSTR(buf.str()));
					buf.str("");
					switch (LOWORD(wParam))
					{
					case 0x207:
						buf << A + B;
						break;
					case 0x208:
						buf << A - B;
						break;
					case 0x209:
						buf << A * B;
						break;
					case 0x210:
						buf << A / B;
						break;
					case 0x211:
						buf << A % B;
						break;
					case 0x212:
						buf << GCD(A, B);
						break;
					case 0x213:
						buf << DER(A);
						break;
					case 0x214:
						buf << DER(B);
						break;
					case 0x215:
						buf << NMR(A);
						break;
					case 0x216:
						buf << NMR(B);
						break;
					case 0x217:
						buf << FAC(A);
						break;
					case 0x218:
						buf << FAC(B);
						break;
					}
				}
				catch (std::runtime_error &ex)
				{
					buf << ex.what();
				}
				SetWindowText(FieldAns, STRtoLPWSTR(buf.str()));
			}
		}
		break;
	}
	case WM_DESTROY:
		DelAccel( hWnd );
		break;
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		LPCREATESTRUCT lpcs = (LPCREATESTRUCT)lParam;
		CreateWindow(TEXT( "BUTTON" ), TEXT( "Natural" ), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 10, 10, 75, 20, hWnd, (HMENU)0x200, lpcs->hInstance, NULL);
		CreateWindow(TEXT( "BUTTON" ), TEXT( "Integer" ), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 95, 10, 75, 20, hWnd, (HMENU)0x201, lpcs->hInstance, NULL);
		CreateWindow(TEXT( "BUTTON" ), TEXT( "Rational" ), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 180, 10, 75, 20, hWnd, (HMENU)0x202, lpcs->hInstance, NULL);
		CreateWindow(TEXT( "BUTTON" ), TEXT( "Polynomial" ), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 265, 10, 75, 20, hWnd, (HMENU)0x203, lpcs->hInstance, NULL);
		CreateWindow(TEXT( "BUTTON" ), TEXT( "Help" ), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 132, 40, 75, 20, hWnd, (HMENU)0x204, lpcs->hInstance, NULL);
		break;
	}
	case WM_SETFONT:
	{
		EnumChildWindows( 
			hWnd, 
			[]( HWND hwnd, LPARAM lparam )->BOOL CALLBACK 
			{ 
				SendMessage( hwnd, WM_SETFONT, (WPARAM)lparam, TRUE ); 
				return TRUE; 
			},
			(LPARAM)wParam );
		break;
	}
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case 0x200:
		{
			HWND hDlg = CreateDialog( hInst, MAKEINTRESOURCE( IDD_DIALOG1 ), hWnd, NaturalProc );
			if ( hDlg )
			{
				ShowWindow( hDlg, SW_NORMAL );
				Loop();
				EnableWindow( hWnd, TRUE );
			}
			break;
		}
		case 0x201:
		{
			HWND hDlg = CreateDialog( hInst, MAKEINTRESOURCE( IDD_DIALOG2 ), hWnd, IntegerProc );
			if ( hDlg )
			{
				ShowWindow( hDlg, SW_NORMAL );
				Loop();
				EnableWindow( hWnd, TRUE );
			}
			break;
		}
		case 0x202:
		{
			HWND hDlg = CreateDialog( hInst, MAKEINTRESOURCE( IDD_DIALOG3 ), hWnd, RationalProc );
			if ( hDlg )
			{
				ShowWindow( hDlg, SW_NORMAL );
				Loop();
				EnableWindow( hWnd, TRUE );
			}
			break;
		}
		case 0x203:
		{
			HWND hDlg = CreateDialog( hInst, MAKEINTRESOURCE( IDD_DIALOG4 ), hWnd, PolynomProc );
			if ( hDlg )
			{
				ShowWindow( hDlg, SW_NORMAL );
				Loop();
				EnableWindow( hWnd, TRUE );
			}
			break;
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
