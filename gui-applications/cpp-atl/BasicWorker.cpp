// BasicWorker.cpp : Implementation of CBasicWorker

#include "pch.h"
#include "BasicWorker.h"


// CBasicWorker

STDMETHODIMP_(HRESULT __stdcall) CBasicWorker::ComputeSum(LONG firstNumber, LONG secondNumber, LONG* sum)
{
    // Check for a valid pointer
    if (sum == nullptr)
        return E_POINTER;

    // Perform the sum operation
    *sum = firstNumber + secondNumber;

    // Return success
    return S_OK;
}
