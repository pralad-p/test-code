

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for cppatl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __cppatl_i_h__
#define __cppatl_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IBasicWorker_FWD_DEFINED__
#define __IBasicWorker_FWD_DEFINED__
typedef interface IBasicWorker IBasicWorker;

#endif 	/* __IBasicWorker_FWD_DEFINED__ */


#ifndef __BasicWorker_FWD_DEFINED__
#define __BasicWorker_FWD_DEFINED__

#ifdef __cplusplus
typedef class BasicWorker BasicWorker;
#else
typedef struct BasicWorker BasicWorker;
#endif /* __cplusplus */

#endif 	/* __BasicWorker_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IBasicWorker_INTERFACE_DEFINED__
#define __IBasicWorker_INTERFACE_DEFINED__

/* interface IBasicWorker */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IBasicWorker;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3a276aa2-cf0e-4c58-afa3-40654f0291dd")
    IBasicWorker : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ComputeSum( 
            /* [in] */ LONG firstNumber,
            /* [in] */ LONG secondNumber,
            /* [retval][out] */ LONG *sum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBasicWorkerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBasicWorker * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBasicWorker * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBasicWorker * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBasicWorker * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBasicWorker * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBasicWorker * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBasicWorker * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ComputeSum )( 
            IBasicWorker * This,
            /* [in] */ LONG firstNumber,
            /* [in] */ LONG secondNumber,
            /* [retval][out] */ LONG *sum);
        
        END_INTERFACE
    } IBasicWorkerVtbl;

    interface IBasicWorker
    {
        CONST_VTBL struct IBasicWorkerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBasicWorker_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBasicWorker_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBasicWorker_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBasicWorker_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBasicWorker_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBasicWorker_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBasicWorker_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBasicWorker_ComputeSum(This,firstNumber,secondNumber,sum)	\
    ( (This)->lpVtbl -> ComputeSum(This,firstNumber,secondNumber,sum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBasicWorker_INTERFACE_DEFINED__ */



#ifndef __cppatlLib_LIBRARY_DEFINED__
#define __cppatlLib_LIBRARY_DEFINED__

/* library cppatlLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_cppatlLib;

EXTERN_C const CLSID CLSID_BasicWorker;

#ifdef __cplusplus

class DECLSPEC_UUID("685e08a8-f042-425d-99b8-44bfd625c73f")
BasicWorker;
#endif
#endif /* __cppatlLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


