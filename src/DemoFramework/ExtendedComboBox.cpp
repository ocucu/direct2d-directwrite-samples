// File: ExtendedComboBox.cpp - CExtendedComboBox class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "DemoFramework.h"
#include "ExtendedComboBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNAMIC(CExtendedComboBox, CComboBox)

void CExtendedComboBox::AddItem(LPCTSTR pszText, DWORD_PTR dwItemData)
{
    int nIndex = InsertString(CB_ERR, pszText);
    SetItemData(nIndex, dwItemData);
}

void CExtendedComboBox::AddItem(const CString& strText, DWORD_PTR dwItemData)
{
    int nIndex = InsertString(CB_ERR, strText);
    SetItemData(nIndex, dwItemData);
}

void CExtendedComboBox::SelectItem(LPCTSTR pszText)
{
    int nIndex = FindString(CB_ERR, pszText);
    SetCurSel(nIndex);
}

void CExtendedComboBox::SelectItem(const CString& strText)
{
    int nIndex = FindString(CB_ERR, strText);
    SetCurSel(nIndex);
}

void CExtendedComboBox::SelectItem(DWORD_PTR dwItemData)
{
    SetCurSel(CB_ERR);
    const int nCount = GetCount();
    for (int nIndex = 0; nIndex < nCount; nIndex++)
    {
        const DWORD_PTR dwData = GetItemData(nIndex);
        if (dwData == dwItemData)
        {
            SetCurSel(nIndex);
            break;
        }
    }
}

void CExtendedComboBox::SelectItem(int nItemData)
{
    SelectItem(static_cast<DWORD_PTR>(nItemData));
}

CString CExtendedComboBox::GetSelectedItemText() const
{
    CString strText;
    int nIndex = GetCurSel();
    if (CB_ERR != nIndex)
    {
        GetLBText(nIndex, strText);
    }
    return strText;
}

DWORD_PTR CExtendedComboBox::GetSelectedItemData() const
{
    DWORD_PTR itemData = static_cast<DWORD_PTR>(-1);
    int nIndex = GetCurSel();
    if (CB_ERR != nIndex)
    {
        itemData = GetItemData(nIndex);
    }
    return itemData;
}



