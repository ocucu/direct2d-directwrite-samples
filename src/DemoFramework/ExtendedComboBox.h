// File: ExtendedComboBox.h - CExtendedComboBox class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Extends CComboBox MFC class in order to be easily used in the client application

#pragma once

class DEMOFRAMEWORK_EXP CExtendedComboBox final : public CComboBox
{
	DECLARE_DYNAMIC(CExtendedComboBox)
public:
    void AddItem(LPCTSTR pszText, DWORD_PTR dwItemData = 0);
    void AddItem(const CString& strText, DWORD_PTR dwItemData = 0);
    void SelectItem(LPCTSTR pszText);
    void SelectItem(const CString& strText);
    void SelectItem(DWORD_PTR dwItemData);
    void SelectItem(int nItemData);
    CString GetSelectedItemText() const;
    DWORD_PTR GetSelectedItemData() const;
};


