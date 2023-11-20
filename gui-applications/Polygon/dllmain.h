// dllmain.h : Declaration of module class.

class CPolygonModule : public ATL::CAtlDllModuleT< CPolygonModule >
{
public :
	DECLARE_LIBID(LIBID_PolygonLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_POLYGON, "{2b29deb1-961a-4e0b-aef8-5a85f6f75791}")
};

extern class CPolygonModule _AtlModule;
