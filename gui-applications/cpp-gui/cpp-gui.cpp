#include <windows.h>
#include <CommCtrl.h>
#include "globals.h"

#pragma comment(lib, "comctl32.lib")


// Forward declarations
ATOM RegisterMainWindowClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK MainWindowProc(HWND, UINT, WPARAM, LPARAM);

// Other globals
WCHAR szClockTab[] = L"Clock"; // Correct variable name for the Clock tab
WCHAR szTimerTab[] = L"Timer"; // Use a different variable name for the Timer tab


ATOM RegisterMainWindowClass(HINSTANCE hInstance) {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = MainWindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = MAIN_WINDOW_CLASS_NAME;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
	hInst = hInstance; // Store instance handle in our global variable

	hWndMain = CreateWindowW(MAIN_WINDOW_CLASS_NAME, L"Clock Application", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

	if (!hWndMain) {
		return FALSE;
	}

	ShowWindow(hWndMain, nCmdShow);
	UpdateWindow(hWndMain);

	return TRUE;
}

LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE: {
		// Set up the timer to update every second for the clock
		SetTimer(hWnd, TIMER_ID, 1000, nullptr);
		// Create a font for the clock
		LOGFONT lf = { 0 }; // Initialization is inside a block, so it's not skipped
		lf.lfHeight = 48; // Set the size of the font
		wcscpy_s(lf.lfFaceName, LF_FACESIZE, L"Consolas"); // Choose a font face that's available
		lf.lfWeight = FW_BOLD; // Make it bold
		hFontClock = CreateFontIndirect(&lf);
		if (!hFontClock) {
			// Handle error
		}
		// Create the tab control
		INITCOMMONCONTROLSEX icex;
		icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
		icex.dwICC = ICC_TAB_CLASSES;
		InitCommonControlsEx(&icex);

		// Get the client area of the main window
		RECT rcClient;
		GetClientRect(hWnd, &rcClient);  // Use hWnd here, not hWndMain

		// Create the tab control
		hTabCtrl = CreateWindow(WC_TABCONTROL, L"", WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE,
			0, 0, rcClient.right, rcClient.bottom, hWnd, nullptr, hInst, nullptr);

		// Find out the height of the tab items to adjust the height of the tab control
		RECT rcTabItem;
		TabCtrl_GetItemRect(hTabCtrl, 0, &rcTabItem);
		int tabControlHeight = rcTabItem.bottom - rcTabItem.top;

		// Now adjust the size of the tab control to be only as tall as the tabs themselves
		SetWindowPos(hTabCtrl, NULL, 0, 0, rcClient.right, tabControlHeight, SWP_NOMOVE | SWP_NOZORDER);

		// Create buttons in the timer tab
		HWND hWndButtonInc = CreateWindow(
			L"BUTTON",  // Predefined class; Unicode assumed 
			L"+1 Min",      // Button text 
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
			10,         // x position 
			60,         // y position 
			100,        // Button width
			30,         // Button height
			hWnd,       // Parent window
			(HMENU)ID_BUTTON_INC,       // No menu.
			(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
			NULL);      // Pointer not needed.

		// Repeat for the other two buttons
		HWND hWndButtonDec = CreateWindow(L"BUTTON", L"-1 Min", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			120, 60, 100, 30, hWnd, (HMENU)ID_BUTTON_DEC, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

		HWND hWndButtonStartStop = CreateWindow(L"BUTTON", L"Start/Stop", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			230, 60, 100, 30, hWnd, (HMENU)ID_BUTTON_START_STOP, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

		TCITEM tie;
		tie.mask = TCIF_TEXT;
		tie.pszText = szClockTab;
		TabCtrl_InsertItem(hTabCtrl, 0, &tie);
		tie.pszText = szTimerTab;
		TabCtrl_InsertItem(hTabCtrl, 1, &tie);
		break;
	}
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case ID_BUTTON_INC:
			// Increase timer duration by 60 seconds (1 minute)
			if (currentTab == 1 && !timerRunning)
			{
				timerDuration += 60;
				InvalidateRect(hWnd, nullptr, TRUE); // Update window to reflect new timer duration
			}
			break;
		case ID_BUTTON_DEC:
			// Decrease timer duration by 60 seconds (1 minute)
			if (currentTab == 1 && !timerRunning && timerDuration > 60)
			{
				timerDuration -= 60;
				InvalidateRect(hWnd, nullptr, TRUE); // Update window to reflect new timer duration
			}
			break;
		case ID_BUTTON_START_STOP:
			// Start or stop the timer
			if (currentTab == 1)
			{
				timerRunning = !timerRunning;
				if (timerRunning)
				{
					// Save the start time
					timerStartTime = GetTickCount64() / 1000;
				}
				InvalidateRect(hWnd, nullptr, TRUE); // Update window to reflect timer state
			}
			break;
		}
		break;
	}
	case WM_TIMER:
	{
		switch (wParam) {
		case TIMER_ID:
			if (currentTab == 0) {
				// Clock tab is active, just update the time
				InvalidateRect(hWnd, nullptr, TRUE);
			}
			else if (currentTab == 1 && timerRunning) {
				DWORD currentTime = GetTickCount64() / 1000;
				if (currentTime - timerStartTime >= timerDuration) {
					// Timer has finished
					timerRunning = false;
					MessageBeep(MB_OK); // Or any other notification
					// Reset the timerStartTime and timerDuration if you want the timer to stop at 0
					timerStartTime = currentTime;
					timerDuration = 0;
				}
				InvalidateRect(hWnd, nullptr, TRUE);
			}
			break;
		}
		break;
	}
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		// Calculate the area below the tabs to draw the clock or timer
		RECT rcTab;
		TabCtrl_GetItemRect(hTabCtrl, 0, &rcTab);
		int tabHeight = rcTab.bottom - rcTab.top;

		RECT rcClient;
		GetClientRect(hWnd, &rcClient);
		rcClient.top += tabHeight; // Move the top of the client area down to below the tabs

		// Select the font for the clock or timer text
		HFONT hOldFont = (HFONT)SelectObject(hdc, hFontClock);

		// Check which tab is currently selected
		if (currentTab == 0) {
			// Draw clock if the first tab is selected
			SYSTEMTIME st;
			GetLocalTime(&st);
			wchar_t timeString[100];
			wsprintf(timeString, L"%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);
			SetBkMode(hdc, TRANSPARENT);
			DrawText(hdc, timeString, -1, &rcClient, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (currentTab == 1) {
			// Draw timer if the second tab is selected
			DWORD currentTime = GetTickCount() / 1000; // GetTickCount returns milliseconds
			DWORD elapsedTime = timerRunning ? (currentTime - timerStartTime) : 0;
			DWORD remainingTime = timerRunning ? (timerDuration - elapsedTime) : timerDuration;

			// Ensure remaining time never goes below zero
			if (remainingTime > timerDuration) {
				remainingTime = 0;
			}

			// Format the remaining time into a string
			DWORD remainingMinutes = remainingTime / 60;
			DWORD remainingSeconds = remainingTime % 60;
			wchar_t timerString[100];
			wsprintf(timerString, L"%02d:%02d", remainingMinutes, remainingSeconds);
			SetBkMode(hdc, TRANSPARENT);
			DrawText(hdc, timerString, -1, &rcClient, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}

		// Restore the old font
		SelectObject(hdc, hOldFont);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_NOTIFY:
		if (((LPNMHDR)lParam)->hwndFrom == hTabCtrl && ((LPNMHDR)lParam)->code == TCN_SELCHANGE) {
			// Change the current tab
			currentTab = TabCtrl_GetCurSel(hTabCtrl);
			// Invalidate the entire window
			InvalidateRect(hWnd, nullptr, TRUE);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		if (hFontClock) {
			DeleteObject(hFontClock); // Clean up the font object
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// Initialize global strings and register the window class
	RegisterMainWindowClass(hInstance);

	// Perform application initialization
	if (!InitInstance(hInstance, nCmdShow)) {
		return FALSE;
	}

	MSG msg;

	// Main message loop
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}
