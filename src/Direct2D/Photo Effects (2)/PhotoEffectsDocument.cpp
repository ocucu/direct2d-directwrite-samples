#include "pch.h"
#include "PhotoEffectsDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CPhotoEffectsDocument;

IMPLEMENT_DYNCREATE(CPhotoEffectsDocument, CDemoDocument);

#pragma region Overridden
BOOL CPhotoEffectsDocument::CreateD2DResources(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE_RET(pRenderTarget, FALSE);

    CD2DResourceFactory factory(pRenderTarget);
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_KID, L"PNG", m_pBitmap), FALSE);

    return TRUE;
}
#pragma endregion
