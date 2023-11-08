#pragma once

// Constants for window sizes, class names, and control/menu IDs
constexpr int WINDOW_WIDTH = 400;
constexpr int WINDOW_HEIGHT = 200;
constexpr LPCWSTR MAIN_WINDOW_CLASS_NAME = L"ClockTimerWindowClass";
constexpr UINT_PTR TIMER_ID = 1;

// Global variables
HINSTANCE hInst; // Application instance
HWND hWndMain; // Main window handle
HWND hTabCtrl; // Handle to the tab control
int currentTab = 0; // 0 for clock, 1 for timer
HFONT hFontClock; // Font for clock display
bool timerRunning = false;
DWORD timerStartTime = 0; // In seconds
DWORD timerDuration = 300; // 5 minutes in seconds

// Add these button identifier definitions
constexpr int ID_BUTTON_INC = 101;
constexpr int ID_BUTTON_DEC = 102;
constexpr int ID_BUTTON_START_STOP = 103;
