#include "pch.h"
#include "PhotoEffectsDocument.h"

#define ID_IMAGE_FIRST      ID_IMAGE_CAT
#define ID_IMAGE_LAST       ID_IMAGE_GRAYSCALE

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
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_CAT, L"PNG", m_pCatBitmap), FALSE);
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_PENCIL, L"PNG", m_pPencilBitmap), FALSE);
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_GRAYSCALE, L"PNG", m_pGrayscaleBitmap), FALSE);

    return TRUE;
}
#pragma endregion

#pragma region Implementation

#pragma endregion

#pragma region Message handlers
BEGIN_MESSAGE_MAP(CPhotoEffectsDocument, CDemoDocument)
    ON_UPDATE_COMMAND_UI_RANGE(ID_IMAGE_FIRST, ID_IMAGE_LAST, &CPhotoEffectsDocument::OnImageUpdateCommandUI)
    ON_COMMAND_RANGE(ID_IMAGE_FIRST, ID_IMAGE_LAST, &CPhotoEffectsDocument::OnImageCommand)
END_MESSAGE_MAP()

void CPhotoEffectsDocument::OnImageUpdateCommandUI(CCmdUI* pCmdUI)
{
    const UINT nID = pCmdUI->m_nID;
    const BitmapId bitmapId = static_cast<BitmapId>(nID - ID_IMAGE_FIRST + 1);
    pCmdUI->SetCheck(bitmapId == GetSampleBitmapId());
}

void CPhotoEffectsDocument::OnImageCommand(UINT nID)
{
    SetSampleBitmapId(static_cast<BitmapId>(nID - ID_IMAGE_FIRST + 1));
}
#pragma endregion
