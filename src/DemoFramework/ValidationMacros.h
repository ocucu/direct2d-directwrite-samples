#pragma once

// validate CD2DResource-derived objects (CRenderTarget, CD2DBitmap etc.)
#define VERIFY_D2D_RESOURCE(pRes) \
{if (nullptr == pRes){ATLTRACE(#pRes" is null\n"); return;} \
else if (!(pRes)->IsValid()){ATLTRACE(#pRes" is invalid\n"); return;}}

#define VERIFY_D2D_RESOURCE_RET(pRes, retVal) \
{if (nullptr == pRes){ATLTRACE(#pRes" is null\n"); return retVal;} \
else if (!(pRes)->IsValid()){ATLTRACE(#pRes" is invalid\n"); return retVal;}}

#define VERIFY_PTR(p) \
{ \
    if (!p) \
    { \
        ATLTRACE(#p" is NULL"); \
        return; \
    } \
}

#define VERIFY_PTR_RET(p, retVal) \
{ \
    if (!p) \
    { \
        ATLTRACE(#p" is NULL"); \
        return retVal; \
    } \
}

#define VERIFY_HR(f) \
{ \
    HRESULT hr = f; \
    if (FAILED(hr)) \
    { \
        ATLTRACE(#f" FAILED.\nError: 0x%08X\n", hr); \
        return; \
    } \
}

#define VERIFY_HR_RET(f) \
{ \
    HRESULT hr = f; \
    if (FAILED(hr)) \
    { \
        ATLTRACE(#f" FAILED.\nError: 0x%08X\n", hr); \
        return hr; \
    } \
}

#define VERIFY_BOOL(f) \
{ \
    if (!f) \
    { \
        ATLTRACE(#f "FAILED"); \
        return; \
    } \
}

#define VERIFY_BOOL_RET(f, retVal) \
{ \
    if (!f) \
    { \
        ATLTRACE(#f "FAILED"); \
        return retVal; \
    } \
}
