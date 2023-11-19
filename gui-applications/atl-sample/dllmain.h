// dllmain.h : Declaration of module class.

class CatlsampleModule : public ATL::CAtlDllModuleT< CatlsampleModule >
{
public :
	DECLARE_LIBID(LIBID_atlsampleLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLSAMPLE, "{4d8fe78f-0fd7-409c-b6c9-20bbc9e103e1}")
};

extern class CatlsampleModule _AtlModule;
