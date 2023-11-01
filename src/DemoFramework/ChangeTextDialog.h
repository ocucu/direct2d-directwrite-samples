// File: ChangeTextDialog.h - CChangeTextDialog class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: dialog window that allows user to change the sample text

#pragma once

class DEMOFRAMEWORK_EXP CChangeTextDialog final : public CDialog
{
public:
    CChangeTextDialog(const CString& strText, CWnd* pParent);
    // Operations
    CString GetText() const { return m_strText; }
private:
    // Overridden
    void DoDataExchange(CDataExchange* pDX) override;
    // Data
    CString m_strText;
    CFont m_font;
    virtual BOOL OnInitDialog();
};
