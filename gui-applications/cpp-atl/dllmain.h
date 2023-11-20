// dllmain.h : Declaration of module class.

class CcppatlModule : public ATL::CAtlDllModuleT< CcppatlModule >
{
public :
	DECLARE_LIBID(LIBID_cppatlLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CPPATL, "{8690ceee-aa9e-44fa-b20f-4fe3b8190326}")
};

extern class CcppatlModule _AtlModule;
