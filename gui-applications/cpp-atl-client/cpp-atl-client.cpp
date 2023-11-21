// cpp-atl-client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <atlbase.h>    // For CComPtr
#include <atlcomcli.h>  // For CComPtr

// Import type library
#import "../../cpp-atl/Debug/cppatl.tlb" no_namespace named_guids

int main()
{
	// Initialize COM
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (FAILED(hr))
    {
        std::cerr << "COM initialization failed with error: " << std::hex << hr << std::endl;
        return -1;
    }
    // Create an instance of the COM object
    CComPtr<IBasicWorker> spBasicWorker;
    hr = spBasicWorker.CoCreateInstance(__uuidof(BasicWorker));
    if (FAILED(hr))
    {
        std::cerr << "Failed to create instance of BasicWorker with error: " << std::hex << hr << std::endl;
        CoUninitialize();
        return -1;
    }
    // Call the ComputeSum method and store the result
    LONG result = 0;
    try {
        result = spBasicWorker->ComputeSum(10, 20);
        std::cout << "The sum is: " << result << std::endl;
    }
    catch (_com_error& e) {
        std::cerr << "ComputeSum failed with error: " << e.ErrorMessage() << std::endl;
    }
    // Uninitialize COM
    CoUninitialize();
    return 0;
}

